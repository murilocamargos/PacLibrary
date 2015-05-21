#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <wx/splash.h>

class SplashScreen {
    private:
        wxSplashScreen *splash;
        wxBitmap bitmap;
        long time;
    public:
        SplashScreen();

        void LoadImage(wxString, wxBitmapType = wxBITMAP_TYPE_BMP);
        void LoadImage(wxBitmap);

        void SetTime(long time) { this->time = time; }
        void Show();
};

#endif

