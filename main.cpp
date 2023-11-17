#include <iostream>
#include "G:\Pribadi\Kuliah\Praktikum\C++\Perpustakaan\Controller\Controller.h"
#include "G:\Pribadi\Kuliah\Praktikum\C++\Perpustakaan\Controller\MenuController.h"
using namespace std;
int main() {
    Menu menu; 
    LoginModel model;
    LoginView view;
    LoginController controller(&model, &view);
    MenuController mainmenu(&menu, &controller);
    
    mainmenu.showMenu();
     
    //  controller.Login();

    return 0;
}