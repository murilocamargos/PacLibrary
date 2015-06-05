#include "../LibraryInc.h"

#include "LibraryScreen.h"
#include "InsertUserScreen.h"

#include "../App/MyApp.h"

#include "../Database/SQLiteHandler.h"
#include "../Database/SQLHandler.h"

BEGIN_EVENT_TABLE(LibraryScreen, wxFrame)
    EVT_MENU(MENU_FILE_NEW, LibraryScreen::OnMenuFileNew)
    EVT_MENU(MENU_FILE_SAVE, LibraryScreen::OnMenuFileSave)
    EVT_MENU(MENU_FILE_OPEN, LibraryScreen::OnMenuFileOpen)
    EVT_MENU(MENU_FILE_QUIT, LibraryScreen::OnMenuFileQuit)
    EVT_MENU(MENU_USER_NEW, LibraryScreen::OnMenuUserNew)
    EVT_MENU(MENU_HELP, LibraryScreen::OnMenuHelp)
    EVT_MENU(MENU_HELP_ABOUT, LibraryScreen::OnMenuHelpAbout)
    EVT_CLOSE(LibraryScreen::OnExit)
END_EVENT_TABLE()

LibraryScreen::LibraryScreen(const wxString& title, wxApp *app, std::string uid, const wxPoint& position, const wxSize& size):
    wxFrame((wxFrame *) NULL, wxID_ANY, title, position, size)
{
    this->app = app;

    // Obtém todas as informações do usuário que fez o login
    SQLHandler *sql = new SQLHandler();
    SQLiteHandler *db = new SQLiteHandler();

    sql->Table("usuarios")->Where("user_id", uid);
    db->Select(sql);

    this->user_info = db->rows[0];

    this->help = new Help();

    // Taskbar
    this->taskbar = new TaskBar(this);

    //Toolbar
    this->toolbar = CreateToolBar();

    this->toolbar->AddTool(MENU_FILE_OPEN, "", wxBITMAP(FILEBMP), _("Open File."), wxITEM_NORMAL);
    toolbar->Realize();
    this->toolbar->AddTool(MENU_FILE_NEW, "", wxBITMAP(BMP_NEW), _("New File."), wxITEM_NORMAL);
    toolbar->Realize();
    this->toolbar->AddTool(MENU_FILE_SAVE, "", wxBITMAP(SAVEBMP), _("Save File."), wxITEM_NORMAL);
    toolbar->Realize();
    this->toolbar->AddTool(MENU_HELP, "", wxBITMAP(HELPBMP), _("Get Help."), wxITEM_NORMAL);
    toolbar->Realize();

    SetToolBar(this->toolbar);

    // MenuBar
    this->menu = new MyMenu();

    wxString file = _("File"),
             help = _("Help"),
             user = _("User");

    this->menu->AddMenu(file);
    this->menu->AddMenu(help);

    this->menu->AddSubMenu(file, MENU_FILE_NEW, _("New\tCtrl+N"), _("New File."));
    this->menu->AddSubMenu(file, MENU_FILE_OPEN, _("Open\tCtrl+O"), _("Open File."));
    this->menu->AddSubMenu(file, MENU_FILE_SAVE, _("Save\tCtrl+S"), _("Save File."));
    this->menu->Separator(file);
    this->menu->AddSubMenu(file, MENU_FILE_QUIT, _("Quit\tCtrl+Q"), _("Quit App."));
    this->menu->AddSubMenu(help, MENU_HELP, _("Help\tF1"), _("Get Help."));
    this->menu->AddSubMenu(help, MENU_HELP_ABOUT, _("About\tF2"), _("Get to know us better!"));

    // O menu de usuários estará disponível apenas ao administrador, por enquanto
    if (this->user_info["nivel"] == "1") {
        this->menu->AddMenu(user);
        this->menu->AddSubMenu(user, MENU_USER_NEW, _("Add User"), _("Add a new user."));
    }

    SetMenuBar(this->menu);

    //StatusBar
    wxString msg = _("Welcome") + " " + wxString(user_info["nome"]) + " :)";
    CreateStatusBar(2);
    SetStatusText(msg, 1);

};

void LibraryScreen::OnMenuFileNew(wxCommandEvent& event)
{
    wxMessageDialog dlg(this, _("You have created a new file!"), _("File created"), wxICON_INFORMATION);
    dlg.ShowModal();
}

void LibraryScreen::OnMenuFileSave(wxCommandEvent& event)
{
    wxMessageDialog dlg(this, _("Your file was saved with success!"), _("File saved"), wxICON_INFORMATION);
    dlg.ShowModal();
}

void LibraryScreen::OnMenuFileOpen(wxCommandEvent& event)
{
    wxString path = this->menu->FilePath(_("Select a file"), _("All files (*.*)|*.*"));
    if (path != "")
    {
        wxLogMessage(path);
    }
}

void LibraryScreen::OnMenuUserNew(wxCommandEvent& event)
{
    InsertUserScreen *ins = new InsertUserScreen(this->user_info["user_id"], _("Insert User"), this);
    ins->SetIcon(wxICON(ADDUS_IC));
    ins->Show(TRUE);
}

bool LibraryScreen::CloseFrame()
{
    wxMessageDialog dlg(this, _("Do you really want to close the app?"), _("Confirmation"), wxYES_NO | wxCANCEL);

    dlg.SetYesNoCancelLabels(_("Close"), _("Minimize"), _("Cancel"));

    int answer = dlg.ShowModal();

    if (answer != wxID_CANCEL)
    {
        MyApp *app = (MyApp*)this->app;
        app->SetExitOnFrameDelete(bool(answer == wxID_YES));

        if (answer == wxID_NO)
        {
            // Só esconde o frame para não ter de criá-lo novamente
            this->Hide();
            this->taskbar->SetIcon(wxICON(APP_ICON), _("Library"));
        }
        else
        {
            // Salva ultimo idioma utilizado pelo usuário
            wxConfig config(app->GetAppName());
            long language = (app->locale->GetLanguage());
            config.Write(wxT("wxTranslation_Language"), language);
            config.Flush();

            return true;
        }
    }

    return false;
}

void LibraryScreen::OnMenuFileQuit(wxCommandEvent& event)
{
    if (this->CloseFrame())
    {
        this->taskbar->Destroy();
        Destroy();
    }
}

void LibraryScreen::OnExit(wxCloseEvent& event)
{
    if (this->CloseFrame())
    {
        this->taskbar->Destroy();
        Destroy();
        event.Skip();
    }
}

void LibraryScreen::OnMenuHelp(wxCommandEvent& event)
{
    help->ShowHelp();
}

void LibraryScreen::OnMenuHelpAbout(wxCommandEvent & event)
{
    wxMessageDialog dlg(this, _("Developed by Luana Michelly and Murilo Camargos\nComputer Aided Project\nUNIMONTES"), _("About"), wxICON_QUESTION);
    dlg.ShowModal();
}
