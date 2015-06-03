MyMenu *menu = new MyMenu();

wxString file = _("File"),
         help = _("Help"),
         lang = _("Languages");

menu->AddMenu(file);
menu->AddMenu(help);
menu->AddMenu(lang, false); // Veja que o menu ainda não foi acoplado à barra

// Começo a tratar o submenu `lang` como se fosse um menu e adiciono
// submenus a ele.
menu->AddSubMenu(lang, MENU_LANG_EN, _("English"), _("Change to english."));
menu->AddSubMenu(lang, MENU_LANG_PT, _("Portuguese"), _("Change to portuguese."));


menu->AddSubMenu(file, MENU_FILE_NEW, _("New\tCtrl+N"), _("New File."));
menu->AddSubMenu(file, MENU_FILE_OPEN, _("Open\tCtrl+O"), _("Open File."));
menu->AddSubMenu(file, MENU_FILE_SAVE, _("Save\tCtrl+S"), _("Save File."));
menu->Separator(file);
menu->AddSubMenu(file, MENU_FILE_QUIT, _("Quit\tCtrl+Q"), _("Quit App."));


menu->AddSubMenu(help, -1, _("Help\tF1"), _("Get Help."));
menu->AddSubMenu(help, -1, _("About\tF2"), _("Get to know us better!"));
menu->Separator(help);
// Ao usar essa definição de AddSubMenu, acoplei o menu `lang` como um submenu de `help`
menu->AddSubMenu(help, lang, _("Change languages!"));

/* Os menus vão ficar da seguinte forma:

File
  New   Ctrl+N
  Open  Ctrl+O
  Save  Ctrl+S
  ------------
  Quit  Ctrl+Q

Help
  Help      F1
  About     F2
  ------------
  Languages
    English
    Portuguese

*/
