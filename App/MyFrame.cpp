#include "MyFrame.h"
#include "../Menu/MyMenu.h"

BEGIN_EVENT_TABLE(MyFrame, wxFrame)
END_EVENT_TABLE()

MyFrame::MyFrame(const wxString& title, const wxPoint& position, const wxSize& size)
: wxFrame((wxFrame *) NULL, wxID_ANY, title, position, size) {
    
    // MenuBar
    MyMenu *menu = new MyMenu();
    
    wxMenu *file = new wxMenu();
    wxMenu *about = new wxMenu();
    
    file->Append(-1, _("New\tCtrl+N"), _("New File"));
    file->Append(-1, _("Open\tCtrl+O"), _("Open File"));
    file->Append(-1, _("Save\tCtrl+S"), _("Save File"));
    file->Append(-1, _("Quit\tCtrl+Q"), _("Quit App"));
    
    about->Append(-1, _("Help\tF1"), _("Get Help"));
    
    menu->Append(file, _("File"));
    menu->Append(about, _("About"));
    
    SetMenuBar(menu);

};
