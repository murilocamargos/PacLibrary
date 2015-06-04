#ifndef _INSERTUSERSCREEN_H
#define _INSERTUSERSCREEN_H

//! \class InsertUserScreen
//! \brief Tela de adi��o de usu�rios.
//! \details Esta tela est� dispon�vel apenas para usu�rios
//! cujo n�vel de acesso seja de administrador.
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

    //! \brief Construtor.
    //! \param uid ID do usu�rio que abriu a janela.
    //! \param title T�tulo da janela.
    //! \param *parent Ponteiro para o wxWindow pai desta janela.
    //! \param id ID da janela.
    //! \param pos Posi��o inicial da janela.
    //! \param size Tamanho da janela.
    //! \param style Estilo da janela.
    //! \details � no construtor que todos os campos e suas posi��es s�o inicializados.
    InsertUserScreen( std::string uid,
                      const wxString& title,
                      wxWindow* parent,
                      wxWindowID id = wxID_ANY,
                      const wxPoint& pos = wxDefaultPosition,
                      const wxSize& size = wxSize( 400,326 ),
                      long style = wxDEFAULT_DIALOG_STYLE);

    ~InsertUserScreen();

    /// Enumera��o das a��es dos bot�es presentes na janela.
    enum
    {
        CANCEL,
        SAVE
    };

    //! \brief Cancela preenchimento.
    //! \param event Evento que ocorre ao clicar num `wxButton`.
    //! \details Este m�todo limpa tudo que o admin tenha digitado em
    //! todos os campos presentes na janela.
    void Cancel(wxCommandEvent& event);

    //! \brief Faz o cadastro do usu�rio.
    //! \param event Evento que ocorre ao clicar num `wxButton`.
    //! \details Antes de salvar um usu�rio no banco, o m�todo faz as seguintes
    //! checagens:
    //! - Verifica se todos os campos foram preenchidos;
    //! - Verifica se as senhas digitadas s�o iguais;
    //! - Verifica se o login informado j� n�o est� cadastrado.
    //!
    //! Caso as informa��es fornecidas pelo usu�rio passe nos tr�s testes,
    //! elas ser�o adicionadas ao banco. Uma entrada de Log tamb�m � adicionada.
    void Save(wxCommandEvent& event);

    DECLARE_EVENT_TABLE();

};

#endif
