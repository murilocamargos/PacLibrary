#ifndef _MYFRAME_H
#define _MYFRAME_H

#include <wx/wx.h>
#include "../Menu/MyMenu.h"
#include <wx/taskbar.h>
//#include <sqlite3.h>

class MyFrame : public wxFrame {
    private:
        MyMenu *menu;
        wxApp *app;
    public:

        MyFrame(const wxString& title, const wxPoint& position,
            const wxSize& size, wxApp *app);
        bool flag;//Define se a janela fechará ou minimizará (false e true, respectivamente)
        void OnMenuAboutLangPT(wxCommandEvent &);
        void OnMenuAboutLangEN(wxCommandEvent &);
        void OnMenuAboutLangFR(wxCommandEvent &);

        void OnMenuFileNew(wxCommandEvent &);
        void OnMenuFileSave(wxCommandEvent &);
        void OnMenuFileOpen(wxCommandEvent &);
        void OnMenuFileQuit(wxCommandEvent &);

        MyMenu *Get_Menu();
        void HideOnTaskBar(wxIconizeEvent &event);
        wxApp *Get_App();

        enum {
            MENU_ABOUT_LANG_EN,
            MENU_ABOUT_LANG_PT,
            MENU_ABOUT_LANG_FR,
            MENU_FILE_NEW,
            MENU_FILE_SAVE,
            MENU_FILE_OPEN,
            MENU_FILE_QUIT
        };

        DECLARE_EVENT_TABLE();
};

#endif
