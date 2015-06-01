#include "SqlHandler.h"
#include <iostream>
SqlHandler::SqlHandler() {

}

SqlHandler* SqlHandler::Table(std::string tableName) {
    this->_table = tableName;
    return this;
}

SqlHandler* SqlHandler::Set(std::string column, std::string value) {
    this->_vars[column] = value;
    return this;
}

SqlHandler* SqlHandler::Column(std::string columnName) {
    this->_column.push_back(columnName);
    return this;
}
std::string SqlHandler::GetColumn() {
    std::string clm = "";
    int sz = this->_column.size();

    if (sz == 0) {
        return "*";
    }

    for (int i = 0; i < sz; i++) {
        clm += this->_column[i] + ", ";
    }

    return clm.substr(0, clm.size() - 2);
}

std::string SqlHandler::DefineWhere(std::string column, std::string signal, std::string value) {
    std::string whr = column + " " + signal + " '" + value + "'";

    return whr;
}

SqlHandler* SqlHandler::Where(std::string column, std::string value) {
    this->_where.push_back("AND " + this->DefineWhere(column, "=", value));
    return this;
}

SqlHandler* SqlHandler::Where(std::string column, std::string signal, std::string value) {
    this->_where.push_back("AND " + this->DefineWhere(column, signal, value));
    return this;
}

SqlHandler* SqlHandler::WhereOr(std::string column, std::string value) {
    this->_where.push_back("OR  " + this->DefineWhere(column, "=", value));
    return this;
}

SqlHandler* SqlHandler::WhereOr(std::string column, std::string signal, std::string value) {
    this->_where.push_back("OR  " + this->DefineWhere(column, signal, value));
    return this;
}

std::string SqlHandler::GetWhere() {
    std::string whr = "WHERE ";
    int sz = this->_where.size();

    if (sz == 0) {
        return "";
    }

    whr += this->_where[0].substr(4);
    for (int i = 1; i < sz; i++) {
        whr += " " + this->_where[i];
    }

    return whr;
}

std::string SqlHandler::Select() {
    std::string sql;

    sql = "SELECT " + this->GetColumn() + " FROM " + this->_table + " " + this->GetWhere();

    return sql;
}


std::string SqlHandler::Delete() {
    std::string sql;

    sql = "DELETE FROM " + this->_table + " " + this->GetWhere();

    return sql;
}

std::string SqlHandler::Insert() {
    std::string sql, cols = "", vals = "";
    std::map<std::string, std::string>::iterator it;

    for (it = this->_vars.begin(); it != this->_vars.end(); it++) {
        cols += it->first + ", ";
        vals += it->second + "', '";
    }
    cols = cols.substr(0, cols.size() - 2);
    vals = vals.substr(0, vals.size() - 3);

    sql = "INSERT INTO " + this->_table + " (" + cols + ") VALUES ('" + vals + ")";

    return sql;
}


std::string SqlHandler::Update() {
    std::string sql = "UPDATE " + this->_table + " SET ";
    std::map<std::string, std::string>::iterator it;

    for (it = this->_vars.begin(); it != this->_vars.end(); it++) {
        sql += it->first + " = '" + it->second + "', ";
    }

    return sql.substr(0, sql.size() - 2) + " " + this->GetWhere();
}
