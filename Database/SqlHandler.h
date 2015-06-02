#ifndef _SQLHandler_H
#define _SQLHandler_H

#include <string>
#include <vector>
#include <map>

class SQLHandler  {
    private:
        std::string _table;
        std::vector<std::string> _where;
        std::vector<std::string> _column;
        std::map<std::string, std::string> _vars;

    public:
        SQLHandler();

        SQLHandler* Table(std::string);

        SQLHandler* Column(std::string);
        std::string GetColumn();

        SQLHandler* Where(std::string, std::string);
        SQLHandler* Where(std::string, std::string, std::string);
        SQLHandler* WhereOr(std::string, std::string);
        SQLHandler* WhereOr(std::string, std::string, std::string);
        std::string DefineWhere(std::string, std::string, std::string);
        std::string GetWhere();

        SQLHandler* Set(std::string, std::string);

        std::string Select();
        std::string Delete();
        std::string Insert();
        std::string Update();
        std::string Count();
};

#endif
