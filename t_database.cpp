//
// Created by The-Funk on 3/4/18.
//

#include "t_database.h"
#include "zdb/zdb.h"

using namespace std;

//Default constructor
t_database::t_database(){}

//Create zdb connection pool using dbName
void t_database::openDB(std::string dbName) {
    string connString = "sqlite://" + dbName + "?synchronous=normal&heap_limit=8000&foreign_keys=on";
    URL_T url = URL_new(connString.c_str());
    this->pool = ConnectionPool_new(url);
    ConnectionPool_start(this->pool);
}