#ifndef _DATABASE_H
#define _DATABASE_H

#include <string>
#include <vector>
#include <stdio.h>

#include "SQLHandler.h"
#include "sqlite3.h"

class SQLiteHandler {
private:
    sqlite3 *db;
    bool isOpen;
public:
    std::vector<std::vector<std::string> > rows;

    SQLiteHandler(std::string dbFile);
    ~SQLiteHandler();

    void CloseDB();
    bool OpenDB(std::string dbFile);

    int NumRows(SQLHandler *sql);
    int Select(SQLHandler *sql);
    int Exec(std::string sql);
};

#endif
