#include "Log.h"
#include <stdlib.h>
#include <sstream>

Log::Log(std::string log_id, std::string user_id) {
    this->log_id  = log_id;
    this->user_id = user_id;

    this->db  = new SQLiteHandler();
    this->sql = new SQLHandler();

    sql->Table("logs")->Set("log_id", this->log_id)
                      ->Set("user_id", this->user_id)
                      ->Set("ocorrencia", this->DateTimeNow());

    this->db->Exec(sql->Insert());
}

std::string Log::DateTimeNow() {
    wxDateTime now = wxDateTime::Now();
    std::stringstream ss;
    ss << now.GetTicks();
    return ss.str();
}
