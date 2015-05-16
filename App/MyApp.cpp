#include "MyApp.h"
#include "MyFrame.h"

IMPLEMENT_APP(MyApp)

/**
 * Este m�todo � respons�vel pela inicializa��o da aplica��o. Ele ir� criar um frame ou
 * dialog e ir� mostr�-lo na tela.
 */
bool MyApp::OnInit() {
	MyFrame *frame = new MyFrame("Library", wxPoint(100, 100), wxSize(800, 600));

	frame->SetIcon(wxICON(APP_ICON));
	frame->Show(TRUE);

	SetTopWindow(frame);

	return true;
}
