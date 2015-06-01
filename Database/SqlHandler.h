#ifndef _SQLHANDLER_H
#define _SQLHANDLER_H

#include <string>
#include <vector>
#include <map>

class SqlHandler  {
    private:
        std::string _table;
        std::vector<std::string> _where;
        std::vector<std::string> _column;
        std::map<std::string, std::string> _vars;

    public:
        SqlHandler();

        SqlHandler* Table(std::string);

        SqlHandler* Column(std::string);
        std::string GetColumn();

        SqlHandler* Where(std::string, std::string);
        SqlHandler* Where(std::string, std::string, std::string);
        SqlHandler* WhereOr(std::string, std::string);
        SqlHandler* WhereOr(std::string, std::string, std::string);
        std::string DefineWhere(std::string, std::string, std::string);
        std::string GetWhere();

        SqlHandler* Set(std::string, std::string);

        std::string Select();
        std::string Delete();
        std::string Insert();
        std::string Update();
};

#endif
