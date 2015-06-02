#include "TaskBar.h"

BEGIN_EVENT_TABLE(TaskBar, wxTaskBarIcon)
    EVT_TASKBAR_LEFT_DOWN(TaskBar::ShowFrame)
END_EVENT_TABLE()

TaskBar::TaskBar(wxWindow *parent)
{
    this->parent = parent;
}

void TaskBar::ShowFrame(wxTaskBarIconEvent& event)
{
    this->parent->Show(true);
}
