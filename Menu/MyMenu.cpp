#include "MyMenu.h"
#include "../App/MyApp.h"

MyMenu::MyMenu() : wxMenuBar() {
}

/**
 * Adiciona  um  `wxMenu`  ao mapa de menus e se a variável `append` for `true`,
 * acopla o menu criado na barra de menus.
 */
void MyMenu::AddMenu(wxString label, bool append) {
    wxMenu *menu = new wxMenu();
    menus[label] = menu;
    
    if (append)
        this->Append(menu, label);
}

/**
 * Acopla um submenu num `wxMenu` que se escontra dentro do mapa de menus.
 */
void MyMenu::AddSubMenu(wxString menuLabel, int ID, wxString label,
    wxString help) {
        
    if (menus.find(menuLabel) != menus.end())
        menus[menuLabel]->Append(ID, label, help);
        
}

/**
 * Acopla um submenu composto num `wxMenu` do mapa de menus.
 */
void MyMenu::AddSubMenu(wxString menuLabel, wxString label, wxString help) {
    if (menus.find(menuLabel) != menus.end()
        && menus.find(label) != menus.end())
        menus[menuLabel]->AppendSubMenu(menus[label], label, help);
}

/**
 * Adiciona um separador (barra horizontal) num `wxMenu` do mapa de menus.
 */
void MyMenu::Separator(wxString menuLabel) {
    if (menus.find(menuLabel) != menus.end())
        menus[menuLabel]->AppendSeparator();
}

/**
 * Tenta  modificar  o  idioma da aplicação e retorna mensagens de erro caso não 
 * consiga.
 */
wxString MyMenu::ChangeAppLang(wxApp* app, long lang) {
    MyApp* myApp = (MyApp*) app;
    
    if (!wxLocale::IsAvailable(lang))
        return _("This language is not supported by your system.");
    
    if (myApp->locale->GetLanguage() == lang)
        return _("This language is already selected!");
    
    myApp->ChangeLang(lang);
    return "";
}

/**
 * Abre  um `wxFileDialog` com titulo, extensões e diretório padrão passados por
 * parâmetro. Retorna uma `wxString` do caminho completo do arquivo selecionado.
 */
wxString MyMenu::FilePath(wxString title, wxString extensions,
    wxString defDir) {
        
    wxFileDialog fd(this, title, defDir, "", extensions,
        wxFD_OPEN | wxFD_FILE_MUST_EXIST);
    
    if (fd.ShowModal() == wxID_CANCEL)
        return "";
    
    return fd.GetPath();
    
}
