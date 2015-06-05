#ifndef _LibraryScreen_H
#define _LibraryScreen_H

#include "../Menu/MyMenu.h"
#include "../TaskBar/TaskBar.h"
#include "../Help/Help.h"

//! \class LibraryScreen
//! \brief Frame principal da aplicação.
//! \details É o frame acessado através da tela de login.
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
    //! \param title Título do frame.
    //! \param *app Ponteiro para a aplicação que executa o frame.
    //! \param uid ID do usuário que abriu o frame (através da tela de login)
    //! \param position Posição do frame na tela.
    //! \param size Tamaho do frame.
    //! \details O construtor é reponsável por salvar na memória todas as
    //! informações do usuário que o acessou, inicializar a TaskBar, a barra
    //! de menus (MyMenu), a barra de ferramentas e a barra de status.
    LibraryScreen(const wxString& title,
                  wxApp *app,
                  std::string uid,
                  const wxPoint& position = wxPoint(100, 100),
                  const wxSize& size = wxSize(800, 600));

    //! \brief Abrir arquivo.
    //! \param event Evento que ocorre ao clicar num item da barra de menus.
    //! \details Este método utiliza MyMenu::FilePath para abrir o `wxFileDialog`
    //! e retorna o caminho do arquivo selecionado.
    void OnMenuFileOpen(wxCommandEvent &event);

    //! \brief Fechar aplicação.
    //! \param event Evento que ocorre ao clicar num item da barra de menus.
    //! \details Tanto este método, quando o LibraryScreen::OnExit utilizam o
    //! LibraryScreen::CloseFrame para fechar a aplicação. Neste caso, o
    //! fechamento se dá pelo item na barra de menus.
    void OnMenuFileQuit(wxCommandEvent &event);

    //! \brief Adicionar usuário.
    //! \param event Evento que ocorre ao clicar num item da barra de menus.
    //! \details Abre a janela de inserção de usuários no sistema. Atualmente
    //! apenas administradores têm acesso a esta funcionalidade.
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
    //! \details Abre o assistente de ajuda com toda a especificação funcional
    //! da aplicação.
    void OnMenuHelp(wxCommandEvent &);

    //! \brief Mostrar tela informativa sobre os desenvolvedores.
    //! \param event Evento que ocorre ao clicar num item da barra de menus.
    void OnMenuHelpAbout(wxCommandEvent &);

    //! \brief Fechar aplicação.
    //! \param event Evento que ocorre ao fechar a aplicação.
    //! \details Neste caso, o fechamento se dá pelo clique no botão <b>x</b>
    //! no canto superior direito da aplicação.
    void OnExit(wxCloseEvent& event);

    //! \brief Exibe uma confimação para fechar ou não a aplicação.
    //! \return Valor lógico caso o usuário deseje fechar a aplicação ou não.
    //! \details O usuário possui três opções, pode fechar a aplicação completamente,
    //! pode cancelar a caixa de diálog aberta e pode minimizar a aplicação para a
    //! barra de tarefas do windows.
    //!
    //! Caso o usuário escolha fechar completamente a aplicação, este método irá salvar
    //! no registro do windows o idioma utilizado pelo usuário, para que na próxima vez
    //! que ele abrir a aplicação, o idioma se preserve.
    //!
    //! Caso ele queira apenas minimizar a aplicação, o método irá <b>esconder</b> o
    //! frame principal e criará um ícone da aplicação na barra de tarefas. Ao clicar
    //! neste ícone, o usuário irá restaurar o frame.
    bool CloseFrame();

    /// Enumera as funções dos itens dos menus para a tabela de eventos.
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
