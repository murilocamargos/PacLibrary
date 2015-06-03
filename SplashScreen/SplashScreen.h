#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

//! \class SplashScreen
//! \brief Manipula��o de SplashScreen.
//! \details Mostra uma imagem antes que o programa abra
//! por completo. Geralmente a imagem ir� permanecer na tela
//! at� que todos os componentos da aplica��o sejam carregados.
class SplashScreen
{
private:
    wxSplashScreen *splash;
    wxBitmap bitmap;
    long time;
public:
    //! \brief Contrutor.
    //! \details Define o tempo em que a SplashScreen ficar� na
    //! tela com um padr�o de 1seg.
    SplashScreen();

    //! \brief Define qual imagem ir� aparecer.
    //! \param filePath Caminho da imagem.
    //! \param type Tipo da imagem a ser usada (Ex.: wxBITMAP_TYPE_BMP)
    //! \details Esta fun��o s� funciona com imagens cuja extens�o seha BMP.
    void LoadImage(wxString filePath, wxBitmapType type = wxBITMAP_TYPE_BMP);

    //! \brief Define qual imagem ir� aparecer.
    //! \param bitmap wxBitmap j� carregado pr�viamente com o caminho da imagem.
    void LoadImage(wxBitmap);

    //! \brief Define um tempo de exibi��o qualquer.
    //! \param time tempo em milisegundos.
    void SetTime(long time)
    {
        this->time = time;
    }

    //! \brief Mostra a imagem na tela.
    void Show();

    //! \example SplashScreen.cpp
};

#endif

