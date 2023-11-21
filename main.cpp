#include <iostream>
#include "G:\Pribadi\Kuliah\Praktikum\C++\Perpustakaan\Controller\Controller.h"
#include "G:\Pribadi\Kuliah\Praktikum\C++\Perpustakaan\Controller\MenuController.h"
#include "G:\Pribadi\Kuliah\Praktikum\C++\Perpustakaan\Controller\RegisterController.h"
#include "G:\Pribadi\Kuliah\Praktikum\C++\Perpustakaan\Controller\BukuController.h"
using namespace std;
int main() {
    
    //MODEL 
    LoginModel model;
    RegisterModel regmodel;
    BukuModel bookmodel;

    //VIEW
    LoginView view;
    Menu menu;
    RegisterViews regview;
    BukuView bookview;

    //COntroller
    LoginController controller(&model, &view);
    RegisterController regcontrol(&regmodel, &regview);
    BukuController bookcontrol(&bookmodel, &bookview);
    MenuController mainmenu(&bookcontrol ,&menu, &controller,&regcontrol);
    //membaca isi database
    regmodel.loadRegister();
    bookmodel.loadBooks();
    //memunculkan menu
    mainmenu.showMenu();
     
    //controller.Login();

    return 0;
}