#ifndef _MYFRAME_H
#define _MYFRAME_H

#include <wx/wx.h>

class MyFrame : public wxFrame {
    public:
        MyFrame(const wxString& title, const wxPoint& position, const wxSize& size);
        
        DECLARE_EVENT_TABLE();
};

#endif
