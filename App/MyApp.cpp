#include "MyApp.h"

IMPLEMENT_APP(MyApp)

/**
 * Este método é responsável pela inicialização da aplicação. Ele irá criar um frame ou
 * dialog e irá mostrá-lo na tela.
 */
bool MyApp::OnInit() {
    return this->CreateGUI();
}

bool MyApp::CreateGUI(long lang) {
    // A internacionalização só irá funcionar se a pasta ./Languages estiver no mesmo
    // diretório que o executável. Nos testes, o executável se encontra em ./Output/MingW
    this->locale = new wxLocale(lang);
    // add locale search paths
    this->locale->AddCatalogLookupPathPrefix(wxT("./Languages"));
    this->locale->AddCatalogLookupPathPrefix(wxT("../../Languages"));
    this->locale->AddCatalog(wxT("myapp"));
    
	this->frame = new MyFrame("Library", wxPoint(100, 100), wxSize(800, 600), this);

	this->frame->SetIcon(wxICON(APP_ICON));
	this->frame->Show(TRUE);

	SetTopWindow(this->frame);

	return true;
}

void MyApp::ChangeLang(long lang) {
    SetTopWindow(NULL);
    this->frame->Destroy();
    this->CreateGUI(lang);
}
