#include "SplashScreen.h"

/**
 * O construtor define um segundo como tempo padr�o de exebi��o da imagem na te-
 * la.
 */
SplashScreen::SplashScreen() {
    this->time = 1000; // 1 seg.
}


/**
 * Carrega imagens � partir do caminho dado.
 */
void SplashScreen::LoadImage(wxString filePath, wxBitmapType type) {
    // Esta fun��o s� funciona com imagens em BMP, ainda n�o consegui arrumar um
    // jeito de carregar imagens de outras extens�es atrav�s do caminho delas.
    this->bitmap.LoadFile(filePath, type);
}

/**
 * Caso o usu�rio j� tenha um objeto do tipo wxBitmap, ele poder� utiliz�-lo.
 */
void SplashScreen::LoadImage(wxBitmap bitmap) {
    this->bitmap = bitmap;
}

/**
 * Mostra efetivamente a imagem na tela.
 */
void SplashScreen::Show() {
    if (this->bitmap.IsOk()) {
        this->splash = new wxSplashScreen(bitmap,
            wxSPLASH_CENTRE_ON_SCREEN | wxSPLASH_TIMEOUT,
            this->time, NULL, -1, wxDefaultPosition, wxDefaultSize,
            wxBORDER_NONE|wxSTAY_ON_TOP);
    }
}
