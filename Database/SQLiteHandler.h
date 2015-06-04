#ifndef _DATABASE_H
#define _DATABASE_H

#include "SQLHandler.h"
#include "sqlite3.h"

//! \class SQLiteHandler
//! \brief API para lidar com o sqlite3.
//! \details Esta classe pode ser vista como uma API
//! para que o usu�rio n�o tenha que lidar diretamente
//! com as fun��es da API para C do sqlite3. Funciona
//! como um `wrapper` do sqlite3 facilitando a obte��o de
//! resultados com a menor quantidade de c�gidos poss�vel.
class SQLiteHandler {
private:
    sqlite3 *db;
    bool isOpen;
public:
    //! Esta vari�vel armazena os resultados de uma consulta
    //! SQL. � um vetor de mapas. Basicamente, cada linha do
    //! resultado da consulta � um elemento no vetor; elemento
    //! este que � representado por um mapa cuja chave � o nome
    //! da coluna e o valor associado � esta chave � o valor
    //! daquela coluna naquela linha dentro do banco.
    std::vector<std::map<std::string, std::string> > rows;

    //! \brief Construtor.
    //! \details O construtor faz a conex�o com o banco, atrav�s
    //! do m�todo SQLiteHandler::OpenDB.
    SQLiteHandler();
    ~SQLiteHandler();

    //! \brief Fecha a conex�o com o banco.
    void CloseDB();

    //! \brief Abre a conex�o com o banco.
    //! \param dbFile nome do arquivo que representa o banco.
    //! \return Valor l�gico que define se a conex�o teve sucesso ou n�o.
    bool OpenDB(std::string dbFile);

    //! \brief Obt�m o n�mero de linhas afetadas por uma consulta.
    //! \param *sql Ponteiro para um objeto SQLHandler.
    //! \return N�mero de linhas afetadas por uma consulta.
    int NumRows(SQLHandler *sql);

    //! \brief Realiza uma consulta de sele��o.
    //! \param *sql Ponteiro para um objeto SQLHandler.
    //! \return Valor l�gico que define se a consulta foi um sucesso ou n�o.
    //! \details Realiza a consulta e armazena os resultados na vari�vel
    //! rows.
    int Select(SQLHandler *sql);

    //! \brief Executa um query SQL no banco.
    //! \param sql std::string da consulta em quest�o.
    //! \return Valor l�gico que define se a consulta foi um sucesso ou n�o.
    int Exec(std::string sql);

    //! \example SQLiteHandlerNumRows.cpp
    //! \example SQLiteHandlerSelect.cpp
    //! \example SQLiteHandlerExec.cpp
};

#endif
