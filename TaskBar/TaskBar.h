#ifndef __TASKBAR_H__
#define __TASKBAR_H__

#include <wx/wx.h>
#include <wx/taskbar.h>

/**
    Classe para criar um ícone de taskbar e atribuir funções a ele
*/
class TaskBar : public wxTaskBarIcon
{
private:
    wxIcon icone;
    wxWindow *parent;
    wxMenu *menu;
public:
    TaskBar(wxWindow *parent);
    void ShowFrame(wxTaskBarIconEvent& event);
    void ShowMenu(wxTaskBarIconEvent& event);
    void Close(wxCommandEvent& event);
    void Open(wxCommandEvent& event);
    enum
    {
        MENU_TASK_OPEN,
        MENU_TASK_CLOSE
    };
    DECLARE_EVENT_TABLE();
};

#endif
