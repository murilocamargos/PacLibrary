#ifndef _MYAPP_H
#define _MYAPP_H

#include <wx/wx.h>
#include "MyFrame.h"
#include "../TaskBar/TaskBar.h" //Criar um arquivo de includes

/**
 * Esta  é  a definição da classe que inicializa o frame da aplicação utilizando
 * o método `OnInit` para isso.
 */
class MyApp : public wxApp
{
private:
    MyFrame *frame;
    TaskBar *taskbar;
public:
    wxLocale *locale;

    virtual bool OnInit();
    virtual int OnExit();

    long LoadLang();
    bool SetLocale(long);
    bool CreateGUI();
    bool ChangeLang(long);
};

DECLARE_APP(MyApp)

#endif
