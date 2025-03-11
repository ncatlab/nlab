Setting up the nlab
===================

Here are instructions for installing the nlab on a standard Linux server.

Getting the codebase
--------------------

We start by checking out the [codebase](https://github.com/ncatlab/nlab).
The most recent version of the code this document is known to be compatible with to is recorded as branch [setup-documented](https://github.com/ncatlab/nlab/tree/setup-documented).
We check this branch out in a directory NLAB_DIR.
All uppercase identifiers in this document are metavariables unless stated otherwise.
```bash
git clone --branch setup-documented git@github.com:ncatlab/nlab.git NLAB_DIR
```

Setting up MySQL
----------------

We assume that a recent version of MariaDB is installed and running as a service.

We connect to the database using `mysql --user root` and execute the below queries.
Be sure to substitute the metavariables according to your choice.
First, we create the database and database user:
```sql
create database NLAB_DATABASE;
create user NLAB_USER@localhost identified by NLAB_PASSWORD;
grant all privileges on NLAB_DATABASE.* to NLAB_USER@localhost;
```
Next, we import the database dump.
We assume it resides in a file NLAB_DATABASE_DUMP.
```sql
connect NLAB_DATABASE;
set global wait_timeout=3600;
set global max_allowed_packet=10000000000;
source NLAB_DATABASE_DUMP;
```
This will take about 15 minutes.
Now we close the SQL session.

An database dump with all tables but no data is provided [here](schema.sql).

Configuring environment variables
---------------------------------

In `NLAB_DIR/config`, copy the file `environment_variables.rb.template` by removing the suffix.
These environment variables are only used by the Python scripts (which are called from the Ruby code).
Fill in the values for the database environment variables according to your choices in the previous section.

Create the directory specified by the environment variable NLAB_LOG_DIRECTORY.
Note that this only specifies the log directory for the Python scripts.

Setting up itex2MML
-------------------

Fetch the [source code for itex2MML](https://golem.ph.utexas.edu/~distler/blog/itex2MML.html) (version at least 1.6.0) somewhere temporary.
Compile it by running `make` in its subdirectory `itex-src`.
Make sure the environment variable RUN_COMMAND_FOR_LATEX_COMPILER in `config/environment_variables_static.rb` points to this the generated executable, for example by copying it to the default location `script/itex2MML`.

Creating directories
--------------------

In NLAB_DIR, we create the following needed subdirectories for generated data:
```bash
mkdir -p page_content/{maruku,submitted_announcements,submitted_edits}
mkdir -p sequential_queue/{completed,control,jobs}
```

Create a subdirectory `log` of NLAB_DIR.
This will be used by default by unicorn (unless configured otherwise).

Setting up Ruby
---------------

We assume that the system has a Ruby installation between Ruby 2.4 and 3.1.

If this is not the case, you can use [RVM](https://rvm.io/):
```bash
rvm install ruby-3.1
rvm use ruby-3.1  # whenever we want to use this version
```

We configure gem dependencies to be installed locally to `NLAB_DIR` by running this command in there:
```bash
bundle config set --local path 'vendor/bundle'
```
(With RVM, you may also instead use a gemset.)

We install the Ruby dependencies of the nlab by executing
```
bundle install
```
If you get version complains, you can try removing `Gemfile.lock`, causing bundler to try to find compatible versions on its own. 

Setting up Python
-----------------

The Python scrips called by the nlab require Python 3 (at least 3.7).
We assume now that it is installed and that the Python package manager pip is available.

If we wish to isolate a virtual Python environment for the nlab, we can do that using venv (TODO: document).

We install the required packages:
```bash
pip install lxml mysqlclient mistletoe requests
```

The Python scripts also require the following programs to be available (some of this may be configurable via [environment variables](config/environment_variables_static.rb)):
* pdflatex with at least the XY-Pic, TikZ, and the standalone packages
* pdftocairo

Optional: copying non-database storage
--------------------------------------

This is only necessary if we are trying to set up an actual production environment.

* Copy over the directory `webs` from the previous installation.
  This contains the uploaded files for all webs.

* Copy over the directory `page_content` from the previous installation.
  This contains pages rendered by the Python renderer.
  These are generated only on page edit.
  So if you skip this step, your installation will initially use the old renderer for all pages, which more recent page sources are incompatible with.

* To speed up diagram rendering, copy over the previous diagram rendering cache in the directory `diagram_cache`.

* If the server domains are identical, it is possible to copy the nlab-rails page cache in the directory `cache`.
  This is not necessary and not expected to give a big initial speed boost.
  It may be counterproductive and hinder testing.

Serving the nlab
----------------

We use unicorn to serve the nlab.

Create a file `NLAB_DIR/config/database.yml` with the following content:
```
production:
  adapter: mysql2
  database: NLAB_DATABASE
  username: NLAB_USER
  password: NLAB_PASSWORD
  encoding: utf8
```

Next, we create a configuration file NLAB_UNICORN_CONF for unicorn with content as below.
This is just for manual testing (running unicorn as a service will use a different configuration).
Make sure to choose NLAB_PORT in the range of user-usable ports (not below 1024).
```ruby
listen NLAB_PORT

# Uncomment to store information in log files instead of printing it on standard output/error.
#stderr_path "log/unicorn.err.log"
#stdout_path "log/unicorn.out.log"

worker_processes 6
timeout 600
preload_app true

before_fork do |server, worker|
  # Disconnect since the database connection will not carry over
  if defined? ActiveRecord::Base
    ActiveRecord::Base.connection.disconnect!
  end
end

after_fork do |server, worker|
  ##
  # Unicorn master loads the app then forks off workers - because of the way
  # Unix forking works, we need to make sure we aren't using any of the parent's
  # sockets, e.g. db connection
  ActiveRecord::Base.establish_connection
end
```

Finally, we can serve the nlab:
```
unicorn_rails -c NLAB_UNICORN_CONF -E production
```

Connect to https://localhost:NLAB_PORT/nlab/show/Sandbox and see if you can edit the page!

By default, unicorn writes it logs to the subdirectory `log` of NLAB_DIR.
This is also where the Python scripts write their logs, unless you have configured the environment variable NLAB_LOG_DIRECTORY above differently.

Setting up services
-------------------

For production, we can set up unicorn as a system service that runs as the user under which the above setup has been performed (we will call it nlab here).

We modify the start of NLAB_UNICORN_CONF as follows, removing the listening directory:
```
stderr_path "log/unicorn.err.log"
stdout_path "log/unicorn.out.log"
```

We create a file `/etc/systemd/system/nlab.socket`:
```
[Socket]
ListenStream=5000

[Install]
WantedBy=sockets.target
```
(choose your desired listening address or Unix-domain socket path).

We create a `/etc/systemd/system/nlab.service`:
```
[Unit]
Description=The nLab (production service)
Requires=nlab.socket
After=nlab.socket

[Service]
User=nlab
Group=nlab
SyslogIdentifier=nlab
Type=exec
WorkingDirectory=NLAB_DIR
ExecStart=bundle exec --keep-file-descriptors unicorn_rails -c NLAB_UNICORN_CONF production

# From https://yhbt.net/unicorn/examples/unicorn%40.service :
#
# > NonBlocking MUST be true if using socket activation with unicorn.
# > Otherwise, there's a small window in-between when the non-blocking
# > flag is set by us and our accept4 call where systemd can momentarily
# > make the socket blocking, causing us to block on accept4:
NonBlocking=true
Sockets=nlab.socket

# Python scripts started in the sequential queue cannot handle graceful shutdown.
# We have to wait for them to expire independently.
# Currently, there is no mechanism for tracking that.
KillMode=process

# From https://yhbt.net/unicorn-public/20150625232626.GA23882@dcvr.yhbt.net/ :
# 
# > With socket activation, you should just be able to kill unicorn using
# > SIGQUIT (just master, or even all workers) and restart without ever
# > dropping a connection.  I do NOT suggest using SIGTERM for unicorn,
# > since that'll cause the master to kill all workers ASAP.
KillSignal=SIGQUIT

[Install]
WantedBy=multi-user.target
```
(don't forget to substitute NLAB_DIR and NLAB_UNICORN_CONF).

We enable the socket and service:
```
sudo systemctl enable nlab.socket nlab
```

We reboot the system or start the service:
```
sudo systemctl start nlab
```
This implicitly starts the dependency `nlab.socket`.

To top the service completely, we run:
```
sudo systemctl stop nlab.socket
```

**Note:**
Due to the design of the Python renderer and the so-called sequential queue, Python scripts may continue running and even continue to be started(!) even after the unicorn nLab instance has shut down.
These may look as follows:
```
python3 script/src/renderer/renderer.py 16595 -f 192 -q 20220702145153278416
```
Each individual entry in the sequential queue has a timeout, for example 10 minutes.
You can check running jobs by looking in `sequential_queue/jobs`.

### Upgrading

Whenever we want to upgrade the nLab Ruby installation, we run the following commands:
```
sudo systemctl stop nlab
git pull
sudo systemctl start nlab 
```
The socket `nlab.socket` continues to run during that time.
This makes sure that no connections are dropped during the upgrade.

**Note:**
Due to the behaviour described in the previous note, there is a race condition involving the execution of Python scripts during the above command `git pull`.
If you want to be safe, make sure that `sequential_queue/jobs` is empty.
