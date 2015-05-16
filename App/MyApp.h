#ifndef _MYAPP_H
#define _MYAPP_H

#include <wx/wx.h>


/**
 * Esta é a definição da classe que inicializa o frame da aplicação utilizando o método
 * `OnInit` para isso.
 */
class MyApp : public wxApp {
    public:
        virtual bool OnInit();
};

DECLARE_APP(MyApp)

#endif
