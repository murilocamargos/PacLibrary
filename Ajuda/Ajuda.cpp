#include "Ajuda.h"
#include <wx/filesys.h>

Ajuda::Ajuda()
{
    this->AddBook(wxString("C:\\Users\\Luana\\Documents\\Estudos\\Faculdade\\PAC\\pac-tpii\\Ajuda\\HelpTool\\LibraryHelp.hhp"), false);
    this->SetTitleFormat(_("Library Help"));
}

void Ajuda::ShowHelp()
{
    DisplayContents();
}

void Ajuda::OnExit()
{
    delete this;
}
