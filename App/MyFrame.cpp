#include "MyFrame.h"
#include "MyApp.h"
#include "../Menu/MyMenu.h"

BEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(MENU_ABOUT_LANG_PT, MyFrame::OnMenuAboutLangPT)
    EVT_MENU(MENU_ABOUT_LANG_EN, MyFrame::OnMenuAboutLangEN)
END_EVENT_TABLE()

MyFrame::MyFrame(const wxString& title, const wxPoint& position, const wxSize& size, wxApp *app)
: wxFrame((wxFrame *) NULL, wxID_ANY, title, position, size) {
    
    this->app = app;
    
    // MenuBar
    MyMenu *menu = new MyMenu();
    
    wxMenu *file = new wxMenu();
    wxMenu *about = new wxMenu();
    wxMenu *langs = new wxMenu();
    
    langs->Append(MENU_ABOUT_LANG_EN, _("English"), _("Change to english!"));
    langs->Append(MENU_ABOUT_LANG_PT, _("Portuguese"), _("Change to portuguese!"));
    
    file->Append(-1, _("New\tCtrl+N"), _("New File"));
    file->Append(-1, _("Open\tCtrl+O"), _("Open File"));
    file->Append(-1, _("Save\tCtrl+S"), _("Save File"));
    file->AppendSeparator();
    file->Append(-1, _("Quit\tCtrl+Q"), _("Quit App"));
    
    about->Append(-1, _("Help\tF1"), _("Get Help"));
    about->AppendSeparator();
    about->AppendSubMenu(langs, _("Languages"), _("Change the app language."));
    
    menu->Append(file, _("File"));
    menu->Append(about, _("About"));
    
    SetMenuBar(menu);

};


void MyFrame::OnMenuAboutLangPT(wxCommandEvent& event) {
    MyApp* myApp = (MyApp*) this->app;
    if (myApp->locale->GetLanguage() != wxLANGUAGE_PORTUGUESE)
        myApp->ChangeLang(wxLANGUAGE_PORTUGUESE);
}

void MyFrame::OnMenuAboutLangEN(wxCommandEvent& event) {
    MyApp* myApp = (MyApp*) this->app;
    if (myApp->locale->GetLanguage() != wxLANGUAGE_ENGLISH)
        myApp->ChangeLang(wxLANGUAGE_ENGLISH);
}
