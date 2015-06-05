#include "../LibraryInc.h"

#include "Help.h"
#include <wx/filesys.h>

Help::Help()
{
    this->AddBook(wxString("Help/HelpTool/LibraryHelp.hhp"), false);
    this->SetTitleFormat(_("Help"));
}

void Help::ShowHelp()
{
    DisplayContents();
}

void Help::OnExit()
{
    delete this;
}
