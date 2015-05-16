#include "MyApp.h"
#include "MyFrame.h"

IMPLEMENT_APP(MyApp)

/**
 * Este método é responsável pela inicialização da aplicação. Ele irá criar um frame ou
 * dialog e irá mostrá-lo na tela.
 */
bool MyApp::OnInit() {
	MyFrame *frame = new MyFrame("Library", wxPoint(100, 100), wxSize(800, 600));

	frame->SetIcon(wxICON(APP_ICON));
	frame->Show(TRUE);

	SetTopWindow(frame);

	return true;
}
