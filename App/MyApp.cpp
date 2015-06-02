#include "MyApp.h"

#include "../UserControl/LoginScreen.h"
#include "../UserControl/LibraryScreen.h"
#include "../SplashScreen/SplashScreen.h"

IMPLEMENT_APP(MyApp)

/**
 * Este  método  irá  inicializar a aplicação com um idioma que será carregado a
 * partir do registro do windows.
 */

bool MyApp::OnInit()
{
    SplashScreen *splash = new SplashScreen();
    splash->LoadImage(wxBITMAP(SPLBMP));
    splash->SetTime(2000);
    splash->Show();

    // Database
    this->dbName = "library";

    this->SetLocale(this->LoadLang());

    // Tela de login
    LoginScreen *login = new LoginScreen(_("Login"), this);

    login->SetIcon(wxICON(APP_ICON));
    login->Show(TRUE);

    SetTopWindow(login);

    return true;
}

/**
 * Este  método  tentará carregar o último idioma definido pelo usuário que está
 * salvo  no  registro  do  windows.  Caso não consiga, utiliza o idioma padrão:
 * Português.
 */
long MyApp::LoadLang()
{
    wxConfig config(GetAppName());
    long language;
    if(!config.Read(wxT("wxTranslation_Language"), &language,
                    wxLANGUAGE_PORTUGUESE))
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

bool MyApp::OpenFrame(std::string uid, long lang) {
    this->SetLocale(lang);

    LibraryScreen *frame = new LibraryScreen(_("Library"), this, uid);
    frame->SetIcon(wxICON(APP_ICON));
    frame->Show(TRUE);

    /** \brief
     *
     * \param frame
     *
     */
    SetTopWindow(frame);

    return true;
}
