#ifndef __TASKBAR_H__
#define __TASKBAR_H__

#include <wx/wx.h>
#include <wx/taskbar.h>

//! \class TaskBar
//! \brief Minimiza a aplica��o para a TaskBar.
//! \details Esta classe define o menu e as a��es do �cone
//! na barra de tarefas.
class TaskBar : public wxTaskBarIcon
{
private:
    wxIcon icone;
    wxWindow *parent;
    wxMenu *menu;
public:
    //! \brief Construtor.
    //! \param parent* Ponteiro para a janela 'pai'.
    TaskBar(wxWindow *parent);

    //! \brief Mostra a janela 'pai'.
    //! \param event Evento que ocorre quando se clica no �cone da taskbar.
    //! \details Este m�todo ser� chamado quando o usu�rio clicar com o
    //! bot�o esquerdo do mouse no �cone da aplica��o na taskbar.
    void ShowFrame(wxTaskBarIconEvent& event);

    //! \brief Mostra um menu de op��es.
    //! \param event Evento que ocorre quando se clica no �cone da taskbar.
    //! \details Este m�todo ser� chamado quando o usu�rio clicar com o
    //! bot�o direito do mouse no �cone da aplica��o na taskbar.
    void ShowMenu(wxTaskBarIconEvent& event);

    //! \brief Fecha completamente a aplica��o.
    //! \param event Evento que ocorre quando se clica num `wxMenu`.
    void Close(wxCommandEvent& event);

    //! \brief Mostra novamente a aplica��o na tela.
    //! \param event Evento que ocorre quando se clica num `wxMenu`.
    void Open(wxCommandEvent& event);

    /// Constantes que ligam os menusda taskbar �s suas a��es.
    enum
    {
        MENU_TASK_OPEN,
        MENU_TASK_CLOSE
    };

    DECLARE_EVENT_TABLE();
};

#endif
