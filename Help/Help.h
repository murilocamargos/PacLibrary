#ifndef _HELP_H
#define _HELP_H

#include <wx/wx.h>
#include <wx/html/helpctrl.h>
#include <iostream>

class Help : public wxHtmlHelpController
{
private:

public:
    Help();
    void ShowHelp();
    void OnExit();
};

#endif
