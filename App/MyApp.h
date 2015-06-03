#ifndef _MYAPP_H
#define _MYAPP_H

//! \class MyApp
//! \brief Declara e executa a aplica��o.
//! \details � respons�vel por definir o idioma da aplica��o e
//! abrir a tela de login e o frame principal.
class MyApp : public wxApp
{
public:
    /// Vari�vel que armazena as propriedades de idioma da aplica��o
    wxLocale *locale;

    //! \brief M�todo chamado sempre que a aplica��o � inicializada.
    //! \return Valor l�gico sempre verdadeiro.
    //! \details Mostra o SplashScreen na tela por dois segundos, carrega
    //! o �ltimo idioma utilizado na aplica��o e abre o formul�rio de login.
    virtual bool OnInit();

    //! \brief Carrega o �ltimo idioma usado na aplica��o.
    //! \return Uma constante inteira que representa o idioma.
    //! \details Esta fun��o faz uso da biblioteca wxConfig para procurar o
    //! registro do windows salvo na �ltima utiliza��o da aplica��o, contento
    //! o �ltimo idioma usado. Caso n�o haja nenhum registro ainda, utiliza o
    //! Portugu�s como idioma padr�o.
    long LoadLang();

    //! \brief Define qual dicion�rio o sistema dever� utilizar.
    //! \param  lang Inteiro que representa o idioma a ser carregado.
    //! \return Valor l�gico que determina se o dicion�rio foi carregado com
    //! sucesso ou n�o.
    //! \details Define o idioma a ser utilizado e procura pelo dicion�rio numa
    //! pasta de dicion�rios pr�-definida.
    bool SetLocale(long lang);

    //! \brief Abre o frame principal da aplica��o.
    //! \param uid ID do usu�rio que est� tentanto abrir o frame.
    //! \param lang Idioma que o usu�rio escolheu na tela de login.
    //! \return Um valor l�gico sempre verdadeiro.
    //! \details Define o idioma escolhido e abre o frame passando o id do usu�rio
    //! por par�metro.
    bool OpenFrame(std::string uid, long lang);
};

DECLARE_APP(MyApp)

#endif
