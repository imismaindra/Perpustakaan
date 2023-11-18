#ifndef MENU_CONTROLLER_H
#define MENU_CONTROLLER_H

#include<iostream>
#include "G:\Pribadi\Kuliah\Praktikum\C++\Perpustakaan\View\MenuView.h"
#include "RegisterController.h"
using namespace std;

class RegisterController;// Forward Declaration
class MenuController {
public:
    MenuController(Menu* menu, LoginController* login, RegisterController* regist) : menu(menu), login(login), regist(regist) {}

    void showMenu() {
        menu->MenuWelcome();
        int pil = menu->getPilihan();

        switch (pil) {
            case 1:
                login->Login();
                break;
            case 2:
                regist->Register();
                break;
        }
    }

private:
    Menu* menu;
    LoginController* login;
    RegisterController* regist;
    //RegisterController* regist;
};
#endif 