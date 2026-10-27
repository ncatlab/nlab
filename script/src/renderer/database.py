#!/usr/bin/env python3

"""
Library for querying the nLab database
"""

import MySQLdb
import os

_database_connection = None

def _connection():
    global _database_connection
    if _database_connection is None:
        _database_connection = MySQLdb.connect(
            user = os.environ["NLAB_DATABASE_USER"],
            password = os.environ["NLAB_DATABASE_PASSWORD"],
            db = os.environ["NLAB_DATABASE_NAME"],
            charset = "utf8",
            use_unicode = True)
    return _database_connection

"""
For a single database query
"""
def execute_single_with_parameters(query, parameters):
    database_connection = _connection()
    try:
        with database_connection.cursor() as cursor:
            cursor.execute(query, parameters)
            results = cursor.fetchall()
        database_connection.commit()
    except MySQLdb.Error as e:
        database_connection.rollback()
        raise e
    return results
