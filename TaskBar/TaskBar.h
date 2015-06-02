#ifndef __TASKBAR_H__
#define __TASKBAR_H__

#include <wx/wx.h>
#include <wx/taskbar.h>

/**
    Classe para criar um �cone de taskbar e atribuir fun��es a ele
*/
class TaskBar : public wxTaskBarIcon
{
private:
    wxIcon icone;
    wxWindow *parent;
public:
    TaskBar(wxWindow *parent);
    void ShowFrame(wxTaskBarIconEvent& event);

    DECLARE_EVENT_TABLE();
};

#endif
