#ifndef _LOG_H
#define _LOG_H

//! \class Log
//! \brief Gerencia os logs da aplica��o.
//! \details � respons�vel pelo gerenciamento das mensagens de log do sistema.
class Log
{
private:
    std::map<int, std::string> descs;
    std::string log_id, user_id;
public:
    //! \brief Construtor da classe.
    //! \param log_id ID da mensagem de log no banco de dados.
    //! \param user_id ID do usu�rio respons�vel pelo log.
    //! \details O construtor da classe j� recebe os valores do <b>log_id</b>
    //! e do <b>user_id</b> e salva a ocorr�ncia no banco de dados.
    Log(std::string log_id, std::string user_id);

    //! \brief Retorna o instante atual em formato UNIX.
    //! \return Uma string contendo o inteiro que representa o instante atual em formato UNIX.
    std::string DateTimeNow();

    //! \example Log.cpp
};

#endif
