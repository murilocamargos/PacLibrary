#include "../LibraryInc.h"

#include "MyApp.h"

#include "../UserControl/LoginScreen.h"
#include "../UserControl/LibraryScreen.h"
#include "../SplashScreen/SplashScreen.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    SplashScreen *splash = new SplashScreen();
    splash->LoadImage(wxBITMAP(SPLBMP));
    splash->SetTime(2000);
    splash->Show();

    this->SetLocale(this->LoadLang());

    // Tela de login
    LoginScreen *login = new LoginScreen(_("Login"), this);

    login->SetIcon(wxICON(LOGIN_IC));
    login->Show(TRUE);

    SetTopWindow(login);

    return true;
}

int MyApp::OnExit()
{
    // Salva ultimo idioma utilizado pelo usuário
    wxConfig config(GetAppName());
    long language = (this->locale->GetLanguage());
    config.Write(wxT("wxTranslation_Language"), language);
    config.Flush();

    return 1;
}

long MyApp::LoadLang()
{
    wxConfig config(GetAppName());
    long language;
    if(!config.Read(wxT("wxTranslation_Language"), &language, wxLANGUAGE_PORTUGUESE))
    {
        language = wxLANGUAGE_PORTUGUESE;
    }
    return language;
}

bool MyApp::SetLocale(long lang)
{
    // A  internacionalização só irá funcionar se a pasta ./Languages estiver no
    // mesmo  diretório  que  o executável. Nos testes, o executável se encontra
    // em ./Output/MingW
    this->locale = new wxLocale(lang);

    // Busca pelos arquivos de tradução nos diretórios abaixo.
    this->locale->AddCatalogLookupPathPrefix(wxT("./Languages"));
    this->locale->AddCatalogLookupPathPrefix(wxT("../../Languages"));

    this->locale->AddCatalog(wxT("myapp"));

    return this->locale->IsOk();
}

bool MyApp::OpenFrame(std::string uid, long lang)
{
    this->SetLocale(lang);

    LibraryScreen *frame = new LibraryScreen(_("Library"), this, uid);
    frame->SetIcon(wxICON(APP_ICON));
    frame->Show(TRUE);

    SetTopWindow(frame);

    return true;
}
