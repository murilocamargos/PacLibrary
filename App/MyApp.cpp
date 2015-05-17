#include "MyApp.h"
#include <wx/config.h>

IMPLEMENT_APP(MyApp)

/**
 * Este m�todo � respons�vel pela inicializa��o da aplica��o. Ele ir� criar um frame ou
 * dialog e ir� mostr�-lo na tela.
 */
bool MyApp::OnInit() {
    this->SetLocale(this->LoadLang());
    return this->CreateGUI();
}

int MyApp::OnExit() {
    wxConfig config(GetAppName());
    long language = this->locale->GetLanguage();
    config.Write(wxT("wxTranslation_Language"), language);
    config.Flush();
    return 0;
}

long MyApp::LoadLang() {
    wxConfig config(GetAppName());
    long language;
    if(!config.Read(wxT("wxTranslation_Language"), &language, wxLANGUAGE_PORTUGUESE)) {
        language = wxLANGUAGE_PORTUGUESE;
    }
    return language;
}

bool MyApp::SetLocale(long lang) {
    // A internacionaliza��o s� ir� funcionar se a pasta ./Languages estiver no mesmo
    // diret�rio que o execut�vel. Nos testes, o execut�vel se encontra em ./Output/MingW
    this->locale = new wxLocale(lang);
    // add locale search paths
    this->locale->AddCatalogLookupPathPrefix(wxT("./Languages"));
    this->locale->AddCatalogLookupPathPrefix(wxT("../../Languages"));
    this->locale->AddCatalog(wxT("myapp"));
    
    return this->locale->IsOk();
}

bool MyApp::CreateGUI() {
	this->frame = new MyFrame("Library", wxPoint(100, 100), wxSize(800, 600), this);
	
    this->frame->SetIcon(wxICON(APP_ICON));
	this->frame->Show(TRUE);
	
    SetTopWindow(this->frame);

	return true;
}

bool MyApp::ChangeLang(long lang) {
    // Para mudar o idioma da aplica��o em tempo de execu��o, a solu��o encontrada
    // foi destruir o frame principal e criar outro com o novo idioma.
    
    if (this->SetLocale(lang)) {
        SetTopWindow(NULL);
        this->frame->Destroy();
        this->CreateGUI();
        return true;
    }
    
    return false;
}
