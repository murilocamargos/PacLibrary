#ifndef _MYFRAME_H
#define _MYFRAME_H

#include <wx/wx.h>

class MyFrame : public wxFrame {
    private:
        wxApp *app;
    public:
        MyFrame(const wxString& title, const wxPoint& position, const wxSize& size, wxApp *app);
        
        void OnMenuAboutLangPT(wxCommandEvent &);
        void OnMenuAboutLangEN(wxCommandEvent &);
        
        enum {
            MENU_ABOUT_LANG_EN,
            MENU_ABOUT_LANG_PT
        };
        
        DECLARE_EVENT_TABLE();
};

#endif
