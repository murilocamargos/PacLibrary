#ifndef _MYAPP_H
#define _MYAPP_H

#include <wx/wx.h>
#include <wx/taskbar.h>
#include "MyFrame.h"

/**
 * Esta  �  a defini��o da classe que inicializa o frame da aplica��o utilizando
 * o m�todo `OnInit` para isso.
 */
class MyApp : public wxApp {
    private:
        MyFrame *frame;
    public:
        wxLocale *locale;

        virtual bool OnInit();
        virtual int OnExit();

        wxTaskBarIcon *taskbar;

        long LoadLang();
        bool SetLocale(long);
        bool CreateGUI();
        bool ChangeLang(long);
};

DECLARE_APP(MyApp)

#endif
