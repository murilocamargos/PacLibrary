#ifndef MYMENU_H
#define MYMENU_H

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <map>

class MyMenu: public wxMenuBar {
    private:
        std::map<wxString, wxMenu*> menus;
    public:
        MyMenu();

        void AddMenu(wxString label, bool append = true);
        void AddSubMenu(wxString menuLabel, int ID, wxString label,
            wxString help);
        void AddSubMenu(wxString menuLabel, wxString label, wxString help);
        void Separator(wxString menuLabel);

        wxString FilePath(wxString title, wxString extensions,
            wxString defDir = "");
};

#endif

