#ifndef __LOGIN_H__
#define __LOGIN_H__

#include <wx/wx.h>

class LoginScreen : public wxDialog {
	private:

	protected:
		wxStaticText* labelUsername;
		wxTextCtrl* inputUsername;
		wxStaticText* labelPassword;
		wxTextCtrl* inputPassword;
		wxStaticText* labelLanguage;
		wxComboBox* inputLanguage;
		wxButton* buttonCancel;
		wxButton* buttonLogin;

	public:
		LoginScreen(wxWindow* parent, wxWindowID id = wxID_ANY,
              const wxString& title = _("Login"),
              const wxPoint& pos = wxDefaultPosition,
              const wxSize& size = wxSize(495,144),
              long style = wxDEFAULT_DIALOG_STYLE);

		~LoginScreen();

};

#endif //__LOGIN_H__

