#ifndef _LOG_H
#define _LOG_H

#include <wx/wx.h>
#include <map>
#include <string>

#include "../Database/SQLHandler.h"
#include "../Database/SQLiteHandler.h"

/**
 * Esta  classe  é responsável pelo gerenciamento das mensagens de log salvas no
 * banco de dados.
 */
class Log {
    private:
        SQLHandler *sql;
        SQLiteHandler *db;
        std::map<int, std::string> descs;
        std::string log_id, user_id;
    public:
        Log(std::string, std::string);

        std::string DateTimeNow();
};

#endif
