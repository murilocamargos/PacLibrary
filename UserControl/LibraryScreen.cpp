#include "LibraryScreen.h"

#include "../App/MyApp.h"

#include "../Database/SQLiteHandler.h"
#include "../Database/SQLHandler.h"

BEGIN_EVENT_TABLE(LibraryScreen, wxFrame)
    EVT_MENU(MENU_FILE_NEW, LibraryScreen::OnMenuFileNew)
    EVT_MENU(MENU_FILE_SAVE, LibraryScreen::OnMenuFileSave)
    EVT_MENU(MENU_FILE_OPEN, LibraryScreen::OnMenuFileOpen)
    EVT_MENU(MENU_FILE_QUIT, LibraryScreen::OnMenuFileQuit)
    EVT_CLOSE(LibraryScreen::OnExit)
END_EVENT_TABLE()

LibraryScreen::LibraryScreen(const wxString& title, wxApp *app, std::string uid, const wxPoint& position,
                             const wxSize& size) : wxFrame((wxFrame *) NULL, wxID_ANY, title,
                                                           position, size)
{

    // Define a query sql a ser executada
    SQLHandler *sql = new SQLHandler();
    sql->Table("usuarios")->Where("user_id", uid);
    // Executa a query
    SQLiteHandler *db = new SQLiteHandler(((MyApp*)app)->dbName);
    db->Select(sql);
    user_info = db->rows[0];

    this->taskbar = new TaskBar(this);

    this->app = app;

    // MenuBar
    this->menu = new MyMenu();

    wxString file = _("File"),
             help = _("Help");

    this->menu->AddMenu(file);
    this->menu->AddMenu(help);

    this->menu->AddSubMenu(file, MENU_FILE_NEW, _("New\tCtrl+N"),
                           _("New File."));
    this->menu->AddSubMenu(file, MENU_FILE_OPEN, _("Open\tCtrl+O"),
                           _("Open File."));
    this->menu->AddSubMenu(file, MENU_FILE_SAVE, _("Save\tCtrl+S"),
                           _("Save File."));
    this->menu->Separator(file);
    this->menu->AddSubMenu(file, MENU_FILE_QUIT, _("Quit\tCtrl+Q"),
                           _("Quit App."));

    this->menu->AddSubMenu(help, -1, _("Help\tF1"),
                           _("Get Help."));
    this->menu->AddSubMenu(help, -1, _("About\tF2"),
                           _("Get to know us better!"));
    this->menu->Separator(help);

    SetMenuBar(this->menu);

    //StatusBar
    wxString msg = _("Welcome ") + wxString(user_info["nome"]) + " :)";
    CreateStatusBar(2);
    SetStatusText(msg, 0);

};

void LibraryScreen::OnMenuFileNew(wxCommandEvent& event)
{
    wxLogMessage(_("You have created a new file!"));
}

void LibraryScreen::OnMenuFileSave(wxCommandEvent& event)
{
    wxLogMessage(_("Your file was saved with success!"));
}

void LibraryScreen::OnMenuFileOpen(wxCommandEvent& event)
{
    wxString path = this->menu->FilePath(_("Select a file"),
                                         _("All files (*.*)|*.*"));
    if (path != "")
        wxLogMessage(path);
}

bool LibraryScreen::CloseFrame() {
    wxMessageDialog dlg(this, _("Do you really want to close the app?"),
                        _("Confirmation"), wxYES_NO | wxCANCEL);

    dlg.SetYesNoCancelLabels(_("Close"), _("Minimize"), _("Cancel"));

    int answer = dlg.ShowModal();

    if (answer != wxID_CANCEL) {
        MyApp *app = (MyApp*)this->app;

        // Salva ultimo idioma utilizado pelo usuário
        wxConfig config(app->GetAppName());
        long language = (app->locale->GetLanguage());
        config.Write(wxT("wxTranslation_Language"), language);
        config.Flush();

        app->SetExitOnFrameDelete(bool(answer == wxID_YES));

        if (answer == wxID_NO) {
            // Só esconde o frame para não ter de criá-lo novamente
            this->Hide();
            this->taskbar->SetIcon(wxICON(APP_ICON), _("Your application is here!"));
        } else {
            return true;
        }
    }

    return false;
}

/**
 * Este  método  pode ser visto como o destrutor do aplicativo. Ao ser acionado,
 * ele  irá  guardar  o  último  idioma  definido  pelo  usuário num registro do
 * windows.
 */
void LibraryScreen::OnMenuFileQuit(wxCommandEvent& event)
{
    if (this->CloseFrame()) {
        this->taskbar->Destroy();
        Destroy();
    }
}

void LibraryScreen::OnExit(wxCloseEvent& event) {
    if (this->CloseFrame()) {
        this->taskbar->Destroy();
        Destroy();
        event.Skip();
    }
}
