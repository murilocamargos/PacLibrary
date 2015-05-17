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
    
    wxString file = _("File"),
             help = _("Help"),
             lang = _("Languages");
             
    // Cria o menu de idiomas sem adicioná-lo à barra de menus.
    menu->AddMenu(lang, false);
    menu->AddSubMenu(lang, MENU_ABOUT_LANG_EN, _("English"), _("Change the app language to english!"));
    menu->AddSubMenu(lang, MENU_ABOUT_LANG_PT, _("Portuguese"), _("Change the app language to portuguese!"));             
    
    menu->AddMenu(file);
    menu->AddMenu(help);
    
    menu->AddSubMenu(file, -1, _("New\tCtrl+N"), _("New File."));
    menu->AddSubMenu(file, -1, _("Open\tCtrl+O"), _("Open File."));
    menu->AddSubMenu(file, -1, _("Save\tCtrl+S"), _("Save File."));
    menu->Separator(file);
    menu->AddSubMenu(file, -1, _("Quit\tCtrl+Q"), _("Quit App."));
    
    menu->AddSubMenu(help, -1, _("Help\tF1"), _("Get Help."));
    menu->AddSubMenu(help, -1, _("About\tF1"), _("Get to know us better!"));
    menu->Separator(help);
    menu->AddSubMenu(help, lang, _("Change the app language."));
    
    SetMenuBar(menu);

};


void MyFrame::OnMenuAboutLangPT(wxCommandEvent& event) {
    MyMenu* menu = (MyMenu*) GetMenuBar();
    wxString msg = menu->ChangeAppLang(this->app, wxLANGUAGE_PORTUGUESE);
    if (msg != "")
        wxLogMessage(msg);
}

void MyFrame::OnMenuAboutLangEN(wxCommandEvent& event) {
    MyMenu* menu = (MyMenu*) GetMenuBar();
    wxString msg = menu->ChangeAppLang(this->app, wxLANGUAGE_ENGLISH);
    if (msg != "")
        wxLogMessage(msg);
}
