#ifndef __TASKBAR_H__
#define __TASKBAR_H__
/**
    Classe para criar um ícone de taskbar e atribuir funções a ele
*/
#include <wx/wx.h>
#include <wx/taskbar.h>
#include "../App/MyFrame.h"
#include "../Menu/MyMenu.h"

class TaskBar : public wxTaskBarIcon
{
private:
    wxIcon icone;
    MyMenu *menu;
    MyFrame *frame;
    wxApp *app;
public:
    TaskBar();
    int Set_Icon(wxIcon icone1, wxString tip); //0->Ok, 1->Falha
    int Set_Icon(wxIcon icone1); //0->Ok, 1->Falha
    void ReativaApp(wxTaskBarIconEvent& event);
    void CloseTaskBar();
    int Set_Frame(MyFrame *frame);//0->Ok, 1->Falha

    DECLARE_EVENT_TABLE();
};

#endif
