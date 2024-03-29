Development
-----------

Setup virtual environment (only needs to be done once).

python -m venv venv
source venv/bin/activate
pip install --upgrade pip
pip install mysqlclient
deactivate

After this, whenever wish to run (note that cannot use ./ syntax):

source venv/bin/activate
python detect_nforum_discussion.py [params]
deactivate

Compilation
-----------

cp bib_entry.py bib_entry.pyx

#The --embed option causes a main() function to be added to the created C file
cython bib_entry.pyx --embed

#All three of the -I,-L, and -l parameters are needed. The -I parameter
#adds directory in which Python.h can be found. The -L parameter adds directory
#where the libpython3.6m.so library can be found. The -l must be the same
#as the name of the .so file with the 'lib' at the beginning removed.
gcc -I /usr/include/python3.4m -L /usr/lib64 -l python3.4m bib_entry.c -o bib_entry

Environment variables
---------------------

The script relies on the following environment variable being set.

NLAB_DATABASE_USER
NLAB_DATABASE_PASSWORD
NLAB_DATABASE_NAME
NLAB_LOG_DIRECTORY
NLAB_URL

Currently these are hardcoded in config/environment_variables.rb (not in git).

Deployment
----------

cp bib_entry ~/www/nlab-prod/script/
