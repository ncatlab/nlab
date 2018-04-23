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

cp detect_nforum_discussion.py detect_nforum_discussion.pyx

#The --embed option causes a main() function to be added to the created C file
cython detect_nforum_discussion.pyx --embed

#All three of the -I,-L, and -l parameters are needed. The -I parameter
#adds directory in which Python.h can be found. The -L parameter adds directory
#where the libpython3.6m.so library can be found. The -l must be the same
#as the name of the .so file with the 'lib' at the beginning removed.
gcc -I /usr/include/python3.4m -L /usr/lib64 -l python3.4m detect_nforum_discussion.c -o detect_nforum_discussion

Environment variables
---------------------

The script relies on the following environment variables being set.

NLAB_DATABASE_USER
NLAB_DATABASE_PASSWORD
NLAB_DATABASE_NAME
NLAB_LOG_DIRECTORY

Currently these are hardcoded in config/environment_variables.rb (not in git).

Deployment
----------

cp detect_nforum_discussion ~/www/nlab-prod/script/
