#include <iostream>
#include "G:\Pribadi\Kuliah\Praktikum\C++\Perpustakaan\Controller\Controller.h"

using namespace std;
int main() {
    LoginModel model;
    LoginView view;
    LoginController controller(&model, &view);
    
    controller.Login();

    return 0;
}