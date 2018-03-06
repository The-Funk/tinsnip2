//
// Created by The-Funk on 3/4/18.
//

#ifndef TINSNIP_TDATABASE_H
#define TINSNIP_TDATABASE_H

#include <string>
#include "zdb/zdb.h"

class t_database {

private:
    ConnectionPool_T pool;      //Connection pool to be used by database manager
    bool cleanup;               //Corresponds with switch for wiping database on exit
    int maxDBSize;              //Set maximum size of database


public:

    t_database();                           //Default constructor
    void openDB(std::string dbName);        //Open chosen DB on startup
    void cleanDB();                         //Delete the contents of the working DB on exit
    void importDB();                        //Import another tinsnip generated SQLite DB on startup
    void exportDB();                        //Export the contents of the working DB on exit
    void closeDB();                         //Close the DB connection on exit

};


#endif //TINSNIP_TDATABASE_H
