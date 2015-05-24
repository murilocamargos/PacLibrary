#include "TaskBar.h"

BEGIN_EVENT_TABLE(TaskBar, wxTaskBarIcon)
    EVT_TASKBAR_LEFT_DOWN(TaskBar::ReativaApp)
END_EVENT_TABLE()

TaskBar::TaskBar()
{
    ///Inicializando variaveis
//    icone = new wxIcon(); //Controi um objeto icon sem dados;
    this->frame = NULL;
    this->app = NULL;

}
int TaskBar::Set_Icon(wxIcon icone1)
{
    this->icone = icone1;
    this->SetIcon(icone);

    if(!this->IsIconInstalled())
    {
        wxMessageBox(_("Your icon could not be set. "));
        return 1;
    }
    return 0;
}

int TaskBar::Set_Icon(wxIcon icone1, wxString tip)
{
    icone = icone1;
    this->SetIcon(icone,tip);

    if(!this->IsIconInstalled())
    {
        wxMessageBox(_("Your icon could not be set. "));
        return 1;
    }

    return 0;
}

void TaskBar::ReativaApp(wxTaskBarIconEvent& event)
{
    app->OnInit();//Inicia novamente a aplicação;
    CloseTaskBar();
}

void TaskBar::CloseTaskBar()
{
    this->Destroy();
}

int TaskBar::Set_Frame(MyFrame *frame)
{
    this->frame = frame;
    this->app = this->frame->Get_App();
    return 0;
}
