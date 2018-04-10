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
python generate_nforum_post_from_nlab_edit.py [params]
deactivate

author_to_user file
-------------------

Should consist of two columns, separated by whitespace. The first column of a
row should be an nLab author, the second column of the row should be the 'Name'
of a corresponding nForum user. No nLab author entries should be repeated.

The file must exist at the path specified in the NLAB_AUTHOR_TO_USER_FILE
environment variable.

Environment variables
---------------------

The script relies on the following environment variables being set.

NLAB_AUTHOR_TO_USER_FILE
NLAB_DATABASE_USER
NLAB_DATABASE_PASSWORD
NLAB_DATABASE_NAME
NLAB_LOG_DIRECTORY

These should be set in .bash_profile for use when developing, and in

/etc/default/unicorn

for when the script is caled from Instiki.

Compilation
-----------

cp generate_nforum_post_from_nlab_edit.py generate_nforum_post_from_nlab_edit.pyx

#The --embed option causes a main() function to be added to the created C file
cython generate_nforum_post_from_nlab_edit.pyx --embed

#All three of the -I,-L, and -l parameters are needed. The -I parameter
#adds directory in which Python.h can be found. The -L parameter adds directory
#where the libpython3.6m.so library can be found. The -l must be the same
#as the name of the .so file with the 'lib' at the beginning removed.
gcc -I /usr/include/python3.4m -L /usr/lib64 -l python3.4m generate_nforum_post_from_nlab_edit.c -o generate_nforum_post_from_nlab_edit

Deployment
----------

cp generate_nforum_post_from_nlab_edit ~/www/nlab-prod/script/
