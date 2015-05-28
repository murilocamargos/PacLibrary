#ifndef _LOG_H
#define _LOG_H

#include <wx/wx.h>
#include <map>

/**
 * Esta  classe  é responsável pelo gerenciamento das mensagens de log salvas no
 * banco de dados.
 */
class Log {
    public:
        Log();

        std::map<int, wxString> GetLogDesc();
};

#endif
