#ifndef MYMENU_H
#define MYMENU_H

//! \class MyMenu
//! \brief Cria a barra de menus e algumas de suas fun��es.
//! \details Facilita a cria��o de menus e submenus se
//! comportando como um <i>wrapper</i> da classe <b>wxMenuBar</b>.
//! Serve tamb�m para reaproveitamento de c�digo de algumas
//! funcionalidades que podem se repetir em diversos aplicativos.
class MyMenu: public wxMenuBar
{
private:
    std::map<wxString, wxMenu*> menus;
public:
    MyMenu();

    //! \brief Adiciona um menu.
    //! \param label T�tulo do menu adicionado.
    //! \param append Acopla ou n�o o novo menu � barra de menus.
    //! \return void
    //! \details Inicialmente, o menu ser� inserido num mapa de menus.
    //! Caso o usu�rio queria que este seja um menu principal, ele pode
    //! acopl�-lo � barra de menus atrav�s do par�metro <b>append</b>.
    void AddMenu(wxString label, bool append = true);

    //! \brief Adiciona um submenu.
    //! \param menuLabel T�tulo do submenu adicionado.
    //! \param ID Constante que liga o submenu � uma fun��o.
    //! \param label T�tulo do menu ao qual este submenu ser� acoplado.
    //! \param help Mensagem de ajuda do submenu.
    //! \return void
    void AddSubMenu(wxString menuLabel, int ID, wxString label, wxString help);

    //! \brief Adiciona um submenu.
    //! \param menuLabel T�tulo do menu ao qual este submenu ser� acoplado.
    //! \param label T�tulo do submenu adicionado.
    //! \param help Mensagem de ajuda do submenu.
    //! \return void
    //! \detail Neste caso, o submenu adicionado ser� um menu pr�viamente
    //! inserido no dicion�rio mas n�o acoplado � barra de menus. O efeito
    //! disso � a cria��o de um submenu que possui seus submenus.
    void AddSubMenu(wxString menuLabel, wxString label, wxString help);

    //! \brief Adiciona um separador num dos menus.
    //! \param menuLabel T�tulo do menu onde o separador ser� inserido.
    //! \return void
    void Separator(wxString menuLabel);

    //! \brief Formul�rio para sele��o de um arquivo do computador.
    //! \param title Titulo da nova janela.
    //! \param extensions Extens�es de arquivo que o formul�rio ir� suportar.
    //! \param defDir Diret�rio inicial.
    //! \return O caminho completo do arquivo selecionado em forma de string.
    //! \details Abre  um `wxFileDialog` com titulo, extens�es e diret�rio padr�o
    //! passados por par�metro. Retorna uma `wxString` do caminho completo do
    //! arquivo selecionado.
    wxString FilePath(wxString title, wxString extensions, wxString defDir = "");

    //! \example MyMenu.cpp
};

#endif

