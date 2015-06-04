#include "../LibraryInc.h"

#include "InsertUserScreen.h"

#include "../Database/SQLiteHandler.h"
#include "../Database/SQLHandler.h"
#include "../Encryption/SHA256.h"
#include "../Log/Log.h"

InsertUserScreen::InsertUserScreen( const wxString& title, wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	labelName = new wxStaticText( this, wxID_ANY, _("Name:"), wxDefaultPosition, wxDefaultSize, 0 );
	labelName->Wrap( -1 );
	bSizer1->Add( labelName, 0, wxALL, 10 );

	inputName = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 371,-1 ), 0 );
	bSizer1->Add( inputName, 0, wxALL, 10 );

	wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer( 2, 2, 0, 0 );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	labelLogin = new wxStaticText( this, wxID_ANY, _("Login:"), wxDefaultPosition, wxDefaultSize, 0 );
	labelLogin->Wrap( -1 );
	bSizer2->Add( labelLogin, 0, wxALL, 10 );

	inputLogin = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 175,-1 ), 0 );
	bSizer2->Add( inputLogin, 0, wxALL, 10 );


	gSizer1->Add( bSizer2, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	labelLevel = new wxStaticText( this, wxID_ANY, _("Access Level:"), wxDefaultPosition, wxDefaultSize, 0 );
	labelLevel->Wrap( -1 );
	bSizer3->Add( labelLevel, 0, wxALL, 10 );

	inputLevel = new wxComboBox( this, wxID_ANY, _("Admin"), wxDefaultPosition, wxSize( 175,-1 ), 0, NULL, 0 );
	inputLevel->Append( _("Admin") );
	inputLevel->Append( _("Manager") );
	inputLevel->Append( _("User") );
	bSizer3->Add( inputLevel, 0, wxALL, 10 );


	gSizer1->Add( bSizer3, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );

	labelPassword = new wxStaticText( this, wxID_ANY, _("Password:"), wxDefaultPosition, wxDefaultSize, 0 );
	labelPassword->Wrap( -1 );
	bSizer4->Add( labelPassword, 0, wxALL, 10 );

	inputPassword = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 175,-1 ), wxTE_PASSWORD );
	bSizer4->Add( inputPassword, 0, wxALL, 10 );


	gSizer1->Add( bSizer4, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );

	labelPasswordAgain = new wxStaticText( this, wxID_ANY, _("Password Again:"), wxDefaultPosition, wxDefaultSize, 0 );
	labelPasswordAgain->Wrap( -1 );
	bSizer5->Add( labelPasswordAgain, 0, wxALL, 10 );

	inputPasswordAgain = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 175,-1 ), wxTE_PASSWORD );
	bSizer5->Add( inputPasswordAgain, 0, wxALL, 10 );


	gSizer1->Add( bSizer5, 1, wxEXPAND, 5 );


	bSizer1->Add( gSizer1, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );

	buttonCancel = new wxButton( this, wxID_ANY, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	buttonCancel->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString ) );

	bSizer6->Add( buttonCancel, 0, wxALIGN_BOTTOM|wxALL, 10 );

	buttonSave = new wxButton( this, wxID_ANY, _("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( buttonSave, 0, wxALIGN_BOTTOM|wxALL, 10 );


	bSizer1->Add( bSizer6, 1, wxALIGN_RIGHT|wxRIGHT, 0 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );
}

InsertUserScreen::~InsertUserScreen()
{
}

