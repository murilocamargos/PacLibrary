#include "MyMenu.h"
#include "../App/MyApp.h"

MyMenu::MyMenu() : wxMenuBar() {
}

void MyMenu::AddMenu(wxString label, bool append) {
    wxMenu *menu = new wxMenu();
    menus[label] = menu;
    
    if (append)
        this->Append(menu, label);
}

void MyMenu::AddSubMenu(wxString menuLabel, int ID, wxString label, wxString help) {
    if (menus.find(menuLabel) != menus.end())
        menus[menuLabel]->Append(ID, label, help);
}

void MyMenu::AddSubMenu(wxString menuLabel, wxString label, wxString help) {
    if (menus.find(menuLabel) != menus.end() && menus.find(label) != menus.end())
        menus[menuLabel]->AppendSubMenu(menus[label], label, help);
}

wxMenu* MyMenu::GetFromMap(wxString label) {
    if (menus.find(label) != menus.end())
        return menus[label];
}

void MyMenu::Separator(wxString menuLabel) {
    if (menus.find(menuLabel) != menus.end())
        menus[menuLabel]->AppendSeparator();
}



wxString MyMenu::ChangeAppLang(wxApp* app, long lang) {
    MyApp* myApp = (MyApp*) app;
    
    if (!wxLocale::IsAvailable(lang))
        return _("This language is not supported by your system.");
    
    if (myApp->locale->GetLanguage() == lang)
        return _("This language is already selected!");
    
    myApp->ChangeLang(lang);
    return "";
}

wxString MyMenu::FilePath(wxString title, wxString extensions, wxString defDir) {
    wxFileDialog fd(this, title, defDir, "", extensions, wxFD_OPEN|wxFD_FILE_MUST_EXIST);
    
    if (fd.ShowModal() == wxID_CANCEL)
        return "";
    
    return fd.GetPath();
}
