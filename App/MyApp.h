#ifndef _MYAPP_H
#define _MYAPP_H

#include <stdio.h>
#include <string>

#include <wx/wx.h>
#include <wx/config.h>

/**
 * Esta  é  a definição da classe que inicializa o frame da aplicação utilizando
 * o método `OnInit` para isso.
 */
class MyApp : public wxApp
{
public:
    bool minimize;
    std::string dbName;
    wxLocale *locale;

    virtual bool OnInit();

    long LoadLang();
    bool SetLocale(long);
    bool OpenFrame(std::string uid, long lang);
};

DECLARE_APP(MyApp)

#endif
