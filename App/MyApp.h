#ifndef _MYAPP_H
#define _MYAPP_H

#include <wx/wx.h>
#include "MyFrame.h"

/**
 * Esta � a defini��o da classe que inicializa o frame da aplica��o utilizando o m�todo
 * `OnInit` para isso.
 */
class MyApp : public wxApp {
    private:
        MyFrame *frame;
    public:
        wxLocale *locale;
        
        virtual bool OnInit();
        bool CreateGUI(long = wxLANGUAGE_PORTUGUESE);
        void ChangeLang(long);
};

DECLARE_APP(MyApp)

#endif
