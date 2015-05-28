#include "Log.h"

Log::Log() {
}

/**
 * Obt�m  a descri��o das mensagens de log armazenadas no banco de dados. O mapa
 * retornado  possui  uma chave inteira que representa o `id` da descri��o salva
 * no banco.
 */
std::map<int, wxString> Log::GetLogDesc() {
    std::map<int, wxString> log_desc;

    log_desc[1] = "Adi��o de usu�rio";
    log_desc[2] = "Edi��o de usu�rio";
    log_desc[3] = "Exclus�o de usu�rio";
    log_desc[4] = "Login realizado";
    log_desc[5] = "Logout realizado";

    return log_desc;
}
