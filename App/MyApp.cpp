#include "MyApp.h"
#include <wx/config.h>
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

    database = new MyBD();

    // TaskBar
    taskbar = new TaskBar();
    this->SetLocale(this->LoadLang());
    return this->CreateGUI();
}

/**
 * Este  método  pode ser visto como o destrutor do aplicativo. Ao ser acionado,
 * ele  irá  guardar  o  último  idioma  definido  pelo  usuário num registro do
 * windows.
 */
int MyApp::OnExit()
{
    // Minimizada a tela
    if(frame->flag)
    {
        // Aplicaçao nao irá fechar quando o último frame for deletado.
        this->SetExitOnFrameDelete(false);
        // Taskbar visivel para reiniar aplicaçao.
        taskbar->SetIcon(wxICON(APP_ICON));
    }
    // Destroi a aplicação
    else
    {
        // Aplicaçao irá fechar quando o último frame for deletado.
        this->SetExitOnFrameDelete(true);
    }

    // Salva ultimo idioma utilizado pelo usuário
    this->database->CloseDB();
    wxConfig config(GetAppName());
    long language = this->locale->GetLanguage();
    config.Write(wxT("wxTranslation_Language"), language);
    config.Flush();

    return 0;
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

/**
 * Este método é responsável pela criação e exibição do frame principal.
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
    // Para  mudar  o  idioma  da  aplicação  em  tempo  de  execução, a solução
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
