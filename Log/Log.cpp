#include "Log.h"

Log::Log() {
}

/**
 * Obtém  a descrição das mensagens de log armazenadas no banco de dados. O mapa
 * retornado  possui  uma chave inteira que representa o `id` da descrição salva
 * no banco.
 */
std::map<int, wxString> Log::GetLogDesc() {
    std::map<int, wxString> log_desc;

    log_desc[1] = "Adição de usuário";
    log_desc[2] = "Edição de usuário";
    log_desc[3] = "Exclusão de usuário";
    log_desc[4] = "Login realizado";
    log_desc[5] = "Logout realizado";

    return log_desc;
}
