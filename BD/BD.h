#ifndef __BD_H__
#define __BD_H__

#include <string>
#include <vector>
#include <stdio.h>
#include "../SQLite/sqlite3.h"

///Exemplo de uso ao final deste arquivo !!
class MyBD
{
private:
    sqlite3 *db;
    int rows;
    //char *filename;
public:
    MyBD();//Open the database

    bool InsertinFile(char *table,char *columns, char *values);
    bool ErasefromFile(char *table, char *conditions);
    int Query(char * columns,char *table, char *condition);
    bool CloseDB();
    int The_Callback(void *a_param, int argc, char **argv, char **column);
};
/**
//Observar como enviar dados para cada função, isso é apenas um exemplo!
db->query("CREATE TABLE a (a INTEGER, b INTEGER);");
db->query("INSERT INTO a VALUES(1, 2);");
db->query("INSERT INTO a VALUES(5, 4);");
vector<vector<string> > result = db->query("SELECT a, b FROM a;");
for(vector<vector<string> >::iterator it = result.begin(); it < result.end(); ++it)
{
    vector<string> row = *it;
    cout << "Values: (A=" << row.at(0) << ", B=" << row.at(1) << ")" << endl;
}
db->close();
*/

#endif // __BD_H__
