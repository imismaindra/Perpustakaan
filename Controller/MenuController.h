#include<iostream>
#include "G:\Pribadi\Kuliah\Praktikum\C++\Perpustakaan\View\MenuView.h"
using namespace std;

class MenuController {
public:
    MenuController(Menu* menu, LoginController* login) : menu(menu), login(login) {}
    void showMenu() {
        menu->MenuWelcome();
        int pil = menu->getPilihan();

        switch (pil) {
            case 1:
                login->Login();
                break;
            case 2:
                cout << "ini 2";
                break;
        }
    }

private:
    Menu* menu;
    LoginController* login;
};
