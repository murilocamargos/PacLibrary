#include "MyApp.h"
#include <wx/config.h>

IMPLEMENT_APP(MyApp)

/**
 * Este método é responsável pela inicialização da aplicação. Ele irá criar um frame ou
 * dialog e irá mostrá-lo na tela.
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
    // A internacionalização só irá funcionar se a pasta ./Languages estiver no mesmo
    // diretório que o executável. Nos testes, o executável se encontra em ./Output/MingW
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
    // Para mudar o idioma da aplicação em tempo de execução, a solução encontrada
    // foi destruir o frame principal e criar outro com o novo idioma.
    
    if (this->SetLocale(lang)) {
        SetTopWindow(NULL);
        this->frame->Destroy();
        this->CreateGUI();
        return true;
    }
    
    return false;
}
