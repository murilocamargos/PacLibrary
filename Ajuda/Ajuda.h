#ifndef _AJUDA_H
#define _AJUDA_H

#include <wx/wx.h>
#include <wx/html/helpctrl.h>
#include <iostream>

class Ajuda : public wxHtmlHelpController
{
private:

public:
    Ajuda();
    void ShowHelp();
    void OnExit();
};

#endif
