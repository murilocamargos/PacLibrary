#include "MyFrame.h"
#include "MyApp.h"

BEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(MENU_ABOUT_LANG_PT, MyFrame::OnMenuAboutLangPT)
    EVT_MENU(MENU_ABOUT_LANG_EN, MyFrame::OnMenuAboutLangEN)
    EVT_MENU(MENU_FILE_NEW, MyFrame::OnMenuFileNew)
    EVT_MENU(MENU_FILE_SAVE, MyFrame::OnMenuFileSave)
    EVT_MENU(MENU_FILE_OPEN, MyFrame::OnMenuFileOpen)
    EVT_MENU(MENU_FILE_QUIT, MyFrame::OnMenuFileQuit)
END_EVENT_TABLE()

MyFrame::MyFrame(const wxString& title, const wxPoint& position, const wxSize& size, wxApp *app)
: wxFrame((wxFrame *) NULL, wxID_ANY, title, position, size) {
    
    this->app = app;
    
    // MenuBar
    this->menu = new MyMenu();
    
    wxString file = _("File"),
             help = _("Help"),
             lang = _("Languages");
             
    // Cria o menu de idiomas sem adicioná-lo à barra de menus.
    this->menu->AddMenu(lang, false);
    this->menu->AddSubMenu(lang, MENU_ABOUT_LANG_EN, _("English"), _("Change the app language to english!"));
    this->menu->AddSubMenu(lang, MENU_ABOUT_LANG_PT, _("Portuguese"), _("Change the app language to portuguese!"));             
    
    this->menu->AddMenu(file);
    this->menu->AddMenu(help);
    
    this->menu->AddSubMenu(file, MENU_FILE_NEW, _("New\tCtrl+N"), _("New File."));
    this->menu->AddSubMenu(file, MENU_FILE_OPEN, _("Open\tCtrl+O"), _("Open File."));
    this->menu->AddSubMenu(file, MENU_FILE_SAVE, _("Save\tCtrl+S"), _("Save File."));
    this->menu->Separator(file);
    this->menu->AddSubMenu(file, MENU_FILE_QUIT, _("Quit\tCtrl+Q"), _("Quit App."));
    
    this->menu->AddSubMenu(help, -1, _("Help\tF1"), _("Get Help."));
    this->menu->AddSubMenu(help, -1, _("About\tF1"), _("Get to know us better!"));
    this->menu->Separator(help);
    this->menu->AddSubMenu(help, lang, _("Change the app language."));
    
    SetMenuBar(this->menu);

};


void MyFrame::OnMenuAboutLangPT(wxCommandEvent& event) {
    wxString msg = this->menu->ChangeAppLang(this->app, wxLANGUAGE_PORTUGUESE);
    if (msg != "")
        wxLogMessage(msg);
}

void MyFrame::OnMenuAboutLangEN(wxCommandEvent& event) {
    wxString msg = this->menu->ChangeAppLang(this->app, wxLANGUAGE_ENGLISH);
    if (msg != "")
        wxLogMessage(msg);
}

void MyFrame::OnMenuFileNew(wxCommandEvent& event) {
    wxLogMessage(_("You have created a new file!"));
}

void MyFrame::OnMenuFileSave(wxCommandEvent& event) {
    wxLogMessage(_("Your file was saved with success!"));
}

void MyFrame::OnMenuFileOpen(wxCommandEvent& event) {
    wxString path = this->menu->FilePath(_("Select a file"), _("All files (*.*)|*.*"));
    if (path != "")
        wxLogMessage(path);
}

void MyFrame::OnMenuFileQuit(wxCommandEvent& event) {
    int answer = wxMessageBox(_("Do you really want to close the app?"), _("Confirmation"), wxYES_NO | wxCANCEL, NULL);
    if (answer == wxYES)
        Close(true);
}
