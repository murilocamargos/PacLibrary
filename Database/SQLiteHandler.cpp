#include "SQLiteHandler.h"

#include <stdlib.h>
#include <iostream>

SQLiteHandler::SQLiteHandler(std::string dbFile) {
    this->isOpen = OpenDB(dbFile);
}

bool SQLiteHandler::OpenDB(std::string dbFile) {
    if(sqlite3_open(dbFile.c_str(), &this->db)) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(this->db));
        sqlite3_close(this->db);
        return false;
    }
    return true;
}

void SQLiteHandler::CloseDB() {
    if (this->isOpen) {
        sqlite3_close(this->db);
        this->isOpen = false;
    }
}

SQLiteHandler::~SQLiteHandler() {
    this->CloseDB();
}

// tirado de http://www.codeproject.com/Tips/378808/Accessing-a-SQLite-Database-with-Cplusplus
int SQLiteHandler::NumRows(SQLHandler *sql) {
    sqlite3_stmt *statement;

    if (sqlite3_prepare(this->db, sql->Count().c_str(), -1, &statement, 0) == SQLITE_OK) {
        // Pega a pr�xima linha da consulta e verifica se � uma linha v�lida.
        // Nesse caso, a primeira e �nica.
        if (sqlite3_step(statement) == SQLITE_ROW) {
            // Pega o valor da primeira coluna da primeira linha da consulta e converte
            // em inteiro.
            return atoi((char*) sqlite3_column_text(statement, 0));
        }
    }

    return 0;
}

int SQLiteHandler::Exec(std::string sql) {
    sqlite3_stmt *statement;
    return sqlite3_prepare_v2(this->db, sql.c_str(), -1, &statement, 0);
}

int SQLiteHandler::Select(SQLHandler *sql) {
    sqlite3_stmt *statement;
    std::string col_name, col_val;

    int prepare = sqlite3_prepare_v2(this->db, sql->Select().c_str(), -1, &statement, 0);

    if (prepare == SQLITE_OK) {
        int cols = sqlite3_column_count(statement);
        while(true) {
            // Insere cada linha (vetor de strings) no vetor `rows`
            if(sqlite3_step(statement) == SQLITE_ROW) {
                std::map<std::string, std::string> row;
                for(int col = 0; col < cols; col++) {
                    col_name = std::string((char*) sqlite3_column_name(statement, col));
                    col_val = std::string((char*) sqlite3_column_text(statement, col));
                    row[col_name] = col_val;
                }
                this->rows.push_back(row);
            } else {
                break;
            }
        }
        sqlite3_finalize(statement);
    }

    return prepare;
}
