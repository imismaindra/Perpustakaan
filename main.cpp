#include <iostream>
#include "G:\Pribadi\Kuliah\Praktikum\C++\Perpustakaan\Controller\Controller.h"
#include "G:\Pribadi\Kuliah\Praktikum\C++\Perpustakaan\Controller\MenuController.h"
#include "G:\Pribadi\Kuliah\Praktikum\C++\Perpustakaan\Controller\RegisterController.h"
using namespace std;
int main() {
    
    //MODEL 
    LoginModel model;
    RegisterModel regmodel;

    //VIEW
    LoginView view;
    Menu menu;
    RegisterViews regview;

    //COntroller
    LoginController controller(&model, &view);
    RegisterController regcontrol(&regmodel, &regview);
    MenuController mainmenu(&menu, &controller,&regcontrol);
    
    regmodel.loadRegister();
    mainmenu.showMenu();
     
    //  controller.Login();

    return 0;
}