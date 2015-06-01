#include "MyApp.h"
#include <wx/config.h>
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

    database = new MyBD();

    // TaskBar
    taskbar = new TaskBar();
    this->SetLocale(this->LoadLang());
    return this->CreateGUI();
}

/**
 * Este  m�todo  pode ser visto como o destrutor do aplicativo. Ao ser acionado,
 * ele  ir�  guardar  o  �ltimo  idioma  definido  pelo  usu�rio num registro do
 * windows.
 */
int MyApp::OnExit()
{
    // Minimizada a tela
    if(frame->flag)
    {
        // Aplica�ao nao ir� fechar quando o �ltimo frame for deletado.
        this->SetExitOnFrameDelete(false);
        // Taskbar visivel para reiniar aplica�ao.
        taskbar->SetIcon(wxICON(APP_ICON));
    }
    // Destroi a aplica��o
    else
    {
        // Aplica�ao ir� fechar quando o �ltimo frame for deletado.
        this->SetExitOnFrameDelete(true);
    }

    // Salva ultimo idioma utilizado pelo usu�rio
    this->database->CloseDB();
    wxConfig config(GetAppName());
    long language = this->locale->GetLanguage();
    config.Write(wxT("wxTranslation_Language"), language);
    config.Flush();

    return 0;
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

/**
 * Este m�todo � respons�vel pela cria��o e exibi��o do frame principal.
 */
bool MyApp::CreateGUI()
{
    this->frame = new MyFrame(_("Library"), wxPoint(100, 100), wxSize(800, 600),
                              this);
    this->frame->SetIcon(wxICON(APP_ICON));
    this->frame->Show(TRUE);

    SetTopWindow(this->frame);

    taskbar->Set_Frame(this->frame);
    return true;
}

bool MyApp::ChangeLang(long lang)
{
    // Para  mudar  o  idioma  da  aplica��o  em  tempo  de  execu��o, a solu��o
    // encontrada  foi  destruir  o  frame  principal  e  criar outro com o novo
    // idioma.

    if (this->SetLocale(lang))
    {
        SetTopWindow(NULL);
        this->frame->Destroy();
        // Recria o frame com o novo idioma.
        this->CreateGUI();
        return true;
    }

    return false;
}
