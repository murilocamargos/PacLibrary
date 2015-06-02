#ifndef _LibraryScreen_H
#define _LibraryScreen_H

#include <wx/wx.h>
#include <wx/taskbar.h>

#include "../Menu/MyMenu.h"
#include "../TaskBar/TaskBar.h"

#include <string>
#include <map>

class LibraryScreen : public wxFrame {
    private:
        MyMenu *menu;
        TaskBar *taskbar;
        wxApp *app;
        std::map<std::string, std::string> user_info;

    public:

        LibraryScreen(const wxString& title,
            wxApp *app,
            std::string uid,
            const wxPoint& position = wxPoint(100, 100),
            const wxSize& size = wxSize(800, 600));

        //Define se a janela fechará ou minimizará (false e true, respectivamente)
        bool flag;

        void OnMenuFileNew(wxCommandEvent &);
        void OnMenuFileSave(wxCommandEvent &);
        void OnMenuFileOpen(wxCommandEvent &);
        void OnMenuFileQuit(wxCommandEvent &);

        void OnExit(wxCloseEvent& event);

        bool CloseFrame();

        enum {
            MENU_FILE_NEW,
            MENU_FILE_SAVE,
            MENU_FILE_OPEN,
            MENU_FILE_QUIT
        };

        DECLARE_EVENT_TABLE();
};

#endif
