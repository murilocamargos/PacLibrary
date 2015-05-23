#include "Login.h"

LoginScreen::LoginScreen(wxWindow* parent, wxWindowID id, const wxString& title,
    const wxPoint& pos, const wxSize& size, long style):
        wxDialog(parent, id, title, pos, size, style) {

this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* generalSizer;
	generalSizer = new wxBoxSizer( wxVERTICAL );

	wxGridSizer* textFieldSizer;
	textFieldSizer = new wxGridSizer( 1, 3, 0, 0 );

	wxBoxSizer* usernameSizer;
	usernameSizer = new wxBoxSizer( wxVERTICAL );

	labelUsername = new wxStaticText( this, wxID_ANY, _("Username:"), wxPoint( -1,-1 ), wxSize( -1,-1 ), 0 );
	labelUsername->Wrap( -1 );
	usernameSizer->Add( labelUsername, 0, wxALL, 5 );

	inputUsername = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 150,-1 ), 0 );
	usernameSizer->Add( inputUsername, 0, wxALL, 5 );


	textFieldSizer->Add( usernameSizer, 1, wxEXPAND, 5 );

	wxBoxSizer* passwordSizer;
	passwordSizer = new wxBoxSizer( wxVERTICAL );

	labelPassword = new wxStaticText( this, wxID_ANY, _("Password:"), wxDefaultPosition, wxDefaultSize, 0 );
	labelPassword->Wrap( -1 );
	passwordSizer->Add( labelPassword, 0, wxALL, 5 );

	inputPassword = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 150,-1 ), wxTE_PASSWORD );
	passwordSizer->Add( inputPassword, 0, wxALL, 5 );


	textFieldSizer->Add( passwordSizer, 1, wxEXPAND, 5 );

	wxBoxSizer* languageSizer;
	languageSizer = new wxBoxSizer( wxVERTICAL );

	labelLanguage = new wxStaticText( this, wxID_ANY, _("Language:"), wxDefaultPosition, wxDefaultSize, 0 );
	labelLanguage->Wrap( -1 );
	languageSizer->Add( labelLanguage, 0, wxALL, 5 );

	inputLanguage = new wxComboBox( this, wxID_ANY, _("English"), wxDefaultPosition, wxSize( 150,-1 ), 0, NULL, 0 );
	inputLanguage->Append( _("English") );
	inputLanguage->Append( _("French") );
	inputLanguage->Append( _("Portuguese") );
	inputLanguage->Append( _("Spanish") );
	languageSizer->Add( inputLanguage, 0, wxALL, 5 );


	textFieldSizer->Add( languageSizer, 1, wxEXPAND, 5 );


	generalSizer->Add( textFieldSizer, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* buttonSizer;
	buttonSizer = new wxBoxSizer( wxHORIZONTAL );

	buttonCancel = new wxButton( this, wxID_ANY, _("Cancel"), wxDefaultPosition, wxSize( 90,-1 ), 0 );
	buttonSizer->Add( buttonCancel, 0, wxALL, 5 );

	buttonLogin = new wxButton( this, wxID_ANY, _("Login"), wxDefaultPosition, wxSize( 90,-1 ), 0 );
	buttonSizer->Add( buttonLogin, 0, wxALL, 5 );


	generalSizer->Add( buttonSizer, 1, wxALIGN_RIGHT|wxALL, 5 );


	this->SetSizer( generalSizer );
	this->Layout();

	this->Centre( wxBOTH );
}

LoginScreen::~LoginScreen()
{
}
