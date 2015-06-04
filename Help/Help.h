#ifndef _HELP_H
#define _HELP_H

#include <wx/html/helpctrl.h>

//! \class Help
//! \brief Configura a ajuda ao usu�rio.
//! \details Define o diret�rio onde se encontra os arquivos
//! de ajuda ao usu�rio.
class Help : public wxHtmlHelpController
{
private:

public:
    //! \brief Contrutor.
    //! \details Define o diret�rio dos arquivos de ajuda.
    Help();

    //! \brief Mostra o conte�do na tela.
    void ShowHelp();

    //! \brief Destr�i o objeto que representa a janela de ajuda.
    void OnExit();
};

#endif
