#ifndef _LOGIN_H
#define _LOGIN_H

#include <wx/wx.h>

#include <map>

//! \class LoginScreen
//! \brief Tela de login da aplica��o.
//! \details Tela inicial da aplica��o, onde o usu�rio informa seu login, senha e o idioma desejado.
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
	    //! \brief Construtor.
        //! \param title T�tulo do frame.
        //! \param title	T�tulo da janela.
        //! \param *app	Ponteiro para a aplica��o que executa a janela.
        //! \param *parent	Ponteiro para o wxWindow pai desta janela.
        //! \param id	ID da janela.
        //! \param pos	Posi��o inicial da janela.
        //! \param size	Tamanho da janela.
        //! \param style	Estilo da janela.
        //! \details � no construtor que todos os campos e suas posi��es s�o inicializados.
		LoginScreen(const wxString& title,
              wxApp *app,
              wxWindow* parent = NULL,
              wxWindowID id = wxID_ANY,
              const wxPoint& pos = wxDefaultPosition,
              const wxSize& size = wxSize(495,144),
              long style = wxDEFAULT_DIALOG_STYLE);

		~LoginScreen();

		//! \brief Fecha a janela.
		//! \param event Evento que ocorre ao fechar a janela.
		//! \details Fecha a janela e a aplica��o por completo.
		void OnExit(wxCloseEvent& event);

        /// Enumera��o das a��es dos bot�es presentes na janela.
        enum {
            CANCEL,
            LOGIN
        };

        //! \brief Cancela preenchimento.
        //! \param event Evento que ocorre ao clicar num `wxButton`.
        //! \details Este m�todo simplesmente limpa tudo que o usu�rio digitou
        //! nos campos de login e senha, e set o idioma padr�o no wxComboBox.
		void Cancel(wxCommandEvent& event);

		//! \brief Faz o login do usu�rio.
		//! \param event Evento que ocorre ao clicar num `wxButton`.
		//! \details Este m�todo verifica o login e a senha digitados pelo usu�rio.
		//! Com a classe SHA256 obt�m-se o hash da senha e ent�o verifica-se se aquela
		//! combina��o de login e senha existe no banco. Caso exista, o metodo
		//! MyApp::OpenFrame � chamado com os par�metros de inicializa��o. Tamb�m �
		//! registrado um Log dessa a��o.
		void Login(wxCommandEvent& event);

		DECLARE_EVENT_TABLE();

};

#endif

