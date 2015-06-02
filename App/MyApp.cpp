#include "MyApp.h"

#include "../UserControl/LoginScreen.h"
#include "../UserControl/LibraryScreen.h"
#include "../SplashScreen/SplashScreen.h"

IMPLEMENT_APP(MyApp)

/**
 * Este  m�todo  ir�  inicializar a aplica��o com um idioma que ser� carregado a
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
 * Este  m�todo  tentar� carregar o �ltimo idioma definido pelo usu�rio que est�
 * salvo  no  registro  do  windows.  Caso n�o consiga, utiliza o idioma padr�o:
 * Portugu�s.
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
    // A  internacionaliza��o s� ir� funcionar se a pasta ./Languages estiver no
    // mesmo  diret�rio  que  o execut�vel. Nos testes, o execut�vel se encontra
    // em ./Output/MingW
    this->locale = new wxLocale(lang);

    // Busca pelos arquivos de tradu��o nos diret�rios abaixo.
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
