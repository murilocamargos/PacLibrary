#include "Database.h"

#include <stdlib.h>
#include <iostream>

using namespace std;

MyBD::MyBD()
{
    rows = 0;
    int aux;
    aux = sqlite3_open("library", &db);
    if(aux)
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
    }
}

MyBD::~MyBD() {
    sqlite3_close(db);
}

bool MyBD::InsertinFile(char *table,char *columns, char *values)
{
    char consulta[100];
    sprintf(consulta, "INSERT INTO %s (%s) VALUES(%s)", table, columns, values);
    sqlite3_exec(db, consulta, NULL, NULL,NULL);
    return true;
}

bool MyBD::ErasefromFile(char *table, char *conditions)
{
    char consulta[100];
    sprintf(consulta,"DELETE FROM %s WHERE %s", table, conditions);
    sqlite3_exec(db,consulta, NULL, NULL, NULL);
    return true;
}

// tirado de http://www.codeproject.com/Tips/378808/Accessing-a-SQLite-Database-with-Cplusplus
int MyBD::NumRows(char *table, char *conds) {
    char query[500];
    sprintf(query, "SELECT COUNT(*) FROM %s %s", table, conds);

    sqlite3_stmt *statement;

    if ( sqlite3_prepare(db, query, -1, &statement, 0 ) == SQLITE_OK )
    {
        int res = sqlite3_step(statement);

        if ( res == SQLITE_ROW )
        {
            string s = (char*)sqlite3_column_text(statement, 0);
            return atoi(s.c_str());
        }
    }

    return 0;
}

int MyBD::Query(char *columns, char *table, char *condition)
{
    sqlite3_stmt *statement;
    vector<vector<string> >results;
    char consulta[100];
    sprintf(consulta,"SELECT %s FROM %s %s", columns,table,condition);

    if(sqlite3_prepare_v2(db, consulta, -1, &statement, 0) == SQLITE_OK)
    {
        int cols = sqlite3_column_count(statement);
        int result = 0;
        int rows_aux = 0;
        while(true)
        {
            result = sqlite3_step(statement);
            if(result == SQLITE_ROW)
            {
                rows++;
            }
            else
            {
                break;
            }
            /** Para exibir resultado
            if(result == SQLITE_ROW)
            {
                vector<string> values;
                for(int col = 0; col < cols; col++)
                {
                    values.push_back((char*)sqlite3_column_text(statement, col));
                }
                results.push_back(values);
            }
            else
            {
                break;
            }
            }
            */
            sqlite3_finalize(statement);
        }
        rows_aux = rows;
        rows = 0;
        return rows_aux;
    }
}
bool MyBD::CloseDB()
{
    sqlite3_close(db);
}
