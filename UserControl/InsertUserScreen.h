#ifndef _INSERTUSERSCREEN_H
#define _INSERTUSERSCREEN_H

class InsertUserScreen : public wxDialog
{
private:
    std::map<std::string, std::string> levels;
    std::string uid;

protected:
    wxStaticText* labelName;
    wxTextCtrl* inputName;
    wxStaticText* labelLogin;
    wxTextCtrl* inputLogin;
    wxStaticText* labelLevel;
    wxComboBox* inputLevel;
    wxStaticText* labelPassword;
    wxTextCtrl* inputPassword;
    wxStaticText* labelPasswordAgain;
    wxTextCtrl* inputPasswordAgain;
    wxButton* buttonCancel;
    wxButton* buttonSave;

public:

    InsertUserScreen( std::string uid,
                      const wxString& title,
                      wxWindow* parent,
                      wxWindowID id = wxID_ANY,
                      const wxPoint& pos = wxDefaultPosition,
                      const wxSize& size = wxSize( 400,326 ),
                      long style = wxDEFAULT_DIALOG_STYLE);

    ~InsertUserScreen();

    enum
    {
        CANCEL,
        SAVE
    };

    void Cancel(wxCommandEvent& event);
    void Save(wxCommandEvent& event);

    DECLARE_EVENT_TABLE();

};

#endif
