#ifndef _MYAPP_H
#define _MYAPP_H

#include <wx/wx.h>


/**
 * Esta � a defini��o da classe que inicializa o frame da aplica��o utilizando o m�todo
 * `OnInit` para isso.
 */
class MyApp : public wxApp {
    public:
        virtual bool OnInit();
};

DECLARE_APP(MyApp)

#endif
