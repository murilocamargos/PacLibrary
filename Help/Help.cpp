#include "Help.h"
#include <wx/filesys.h>

Help::Help()
{
    this->AddBook(wxString("C:\\Users\\Luana\\Documents\\Estudos\\Faculdade\\PAC\\pac-tpii\\Help\\HelpTool\\LibraryHelp.hhp"), false);
    this->SetTitleFormat(_("Library Help"));
}

void Help::ShowHelp()
{
    DisplayContents();
}

void Help::OnExit()
{
    delete this;
}
