#ifndef _LibraryScreen_H
#define _LibraryScreen_H

#include "../Menu/MyMenu.h"
#include "../TaskBar/TaskBar.h"
#include "../Help/Help.h"

//! \class LibraryScreen
//! \brief Frame principal da aplica��o.
//! \details � o frame acessado atrav�s da tela de login.
class LibraryScreen : public wxFrame
{
private:
    MyMenu *menu;
    TaskBar *taskbar;
    wxToolBar *toolbar;
    wxApp *app;
    std::map<std::string, std::string> user_info;
    Help *help;
public:

    //! \brief Construtor.
    //! \param title T�tulo do frame.
    //! \param *app Ponteiro para a aplica��o que executa o frame.
    //! \param uid ID do usu�rio que abriu o frame (atrav�s da tela de login)
    //! \param position Posi��o do frame na tela.
    //! \param size Tamaho do frame.
    //! \details O construtor � repons�vel por salvar na mem�ria todas as
    //! informa��es do usu�rio que o acessou, inicializar a TaskBar, a barra
    //! de menus (MyMenu), a barra de ferramentas e a barra de status.
    LibraryScreen(const wxString& title,
                  wxApp *app,
                  std::string uid,
                  const wxPoint& position = wxPoint(100, 100),
                  const wxSize& size = wxSize(800, 600));

    //! \brief Abrir arquivo.
    //! \param event Evento que ocorre ao clicar num item da barra de menus.
    //! \details Este m�todo utiliza MyMenu::FilePath para abrir o `wxFileDialog`
    //! e retorna o caminho do arquivo selecionado.
    void OnMenuFileOpen(wxCommandEvent &event);

    //! \brief Fechar aplica��o.
    //! \param event Evento que ocorre ao clicar num item da barra de menus.
    //! \details Tanto este m�todo, quando o LibraryScreen::OnExit utilizam o
    //! LibraryScreen::CloseFrame para fechar a aplica��o. Neste caso, o
    //! fechamento se d� pelo item na barra de menus.
    void OnMenuFileQuit(wxCommandEvent &event);

    //! \brief Adicionar usu�rio.
    //! \param event Evento que ocorre ao clicar num item da barra de menus.
    //! \details Abre a janela de inser��o de usu�rios no sistema. Atualmente
    //! apenas administradores t�m acesso a esta funcionalidade.
    void OnMenuUserNew(wxCommandEvent &event);

    //! \brief Novo arquivo.
    //! \param event Evento que ocorre ao clicar num item da barra de menus.
    //! \details Mostra uma mensagem informando que um novo arquivo foi criado.
    void OnMenuFileNew(wxCommandEvent &event);

    //! \brief Salvar arquivo.
    //! \param event Evento que ocorre ao clicar num item da barra de menus.
    //! \details Mostra uma mensagem informando que um novo arquivo foi salvo.
    void OnMenuFileSave(wxCommandEvent &event);

    //! \brief Mostrar ajuda.
    //! \param event Evento que ocorre ao clicar num item da barra de menus.
    //! \details Abre o assistente de ajuda com toda a especifica��o funcional
    //! da aplica��o.
    void OnMenuHelp(wxCommandEvent &);

    //! \brief Mostrar tela informativa sobre os desenvolvedores.
    //! \param event Evento que ocorre ao clicar num item da barra de menus.
    void OnMenuHelpAbout(wxCommandEvent &);

    //! \brief Fechar aplica��o.
    //! \param event Evento que ocorre ao fechar a aplica��o.
    //! \details Neste caso, o fechamento se d� pelo clique no bot�o <b>x</b>
    //! no canto superior direito da aplica��o.
    void OnExit(wxCloseEvent& event);

    //! \brief Exibe uma confima��o para fechar ou n�o a aplica��o.
    //! \return Valor l�gico caso o usu�rio deseje fechar a aplica��o ou n�o.
    //! \details O usu�rio possui tr�s op��es, pode fechar a aplica��o completamente,
    //! pode cancelar a caixa de di�log aberta e pode minimizar a aplica��o para a
    //! barra de tarefas do windows.
    //!
    //! Caso o usu�rio escolha fechar completamente a aplica��o, este m�todo ir� salvar
    //! no registro do windows o idioma utilizado pelo usu�rio, para que na pr�xima vez
    //! que ele abrir a aplica��o, o idioma se preserve.
    //!
    //! Caso ele queira apenas minimizar a aplica��o, o m�todo ir� <b>esconder</b> o
    //! frame principal e criar� um �cone da aplica��o na barra de tarefas. Ao clicar
    //! neste �cone, o usu�rio ir� restaurar o frame.
    bool CloseFrame();

    /// Enumera as fun��es dos itens dos menus para a tabela de eventos.
    enum
    {
        MENU_FILE_NEW,
        MENU_FILE_SAVE,
        MENU_FILE_OPEN,
        MENU_FILE_QUIT,
        MENU_USER_NEW,
        MENU_HELP,
        MENU_HELP_ABOUT
    };

    DECLARE_EVENT_TABLE();
};

#endif
