#include "MyApp.h"

IMPLEMENT_APP(MyApp)

/**
 * Este m�todo � respons�vel pela inicializa��o da aplica��o. Ele ir� criar um frame ou
 * dialog e ir� mostr�-lo na tela.
 */
bool MyApp::OnInit() {
    return this->CreateGUI();
}

bool MyApp::CreateGUI(long lang) {
    // A internacionaliza��o s� ir� funcionar se a pasta ./Languages estiver no mesmo
    // diret�rio que o execut�vel. Nos testes, o execut�vel se encontra em ./Output/MingW
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
