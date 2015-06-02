#ifndef _LOGIN_H
#define _LOGIN_H

#include <wx/wx.h>

#include <map>

class LoginScreen : public wxDialog {
	private:
        std::map<long, wxString> langs;
        long lang;
        wxApp *app;

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
		LoginScreen(const wxString& title,
              wxApp *app,
              wxWindow* parent = NULL,
              wxWindowID id = wxID_ANY,
              const wxPoint& pos = wxDefaultPosition,
              const wxSize& size = wxSize(495,144),
              long style = wxDEFAULT_DIALOG_STYLE);

		~LoginScreen();
		void OnExit(wxCloseEvent& event);

        enum {
            CANCEL,
            LOGIN
        };

		void Cancel(wxCommandEvent& event);
		void Login(wxCommandEvent& event);

		DECLARE_EVENT_TABLE();

};

#endif

