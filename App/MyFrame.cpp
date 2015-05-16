#include "MyFrame.h"

BEGIN_EVENT_TABLE(MyFrame, wxFrame)
END_EVENT_TABLE()

MyFrame::MyFrame(const wxString& title, const wxPoint& position, const wxSize& size)
: wxFrame((wxFrame *) NULL, wxID_ANY, title, position, size) {

};
