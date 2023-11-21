#ifndef MENU_CONTROLLER_H
#define MENU_CONTROLLER_H

#include<iostream>
#include "G:\Pribadi\Kuliah\Praktikum\C++\Perpustakaan\View\MenuView.h"
#include "RegisterController.h"
#include "BukuController.h"
using namespace std;

class RegisterController;// Forward Declaration
class BukuController;
class MenuController {
public:
    MenuController(BukuController* book,Menu* menu, LoginController* login, RegisterController* regist) :book(book) ,menu(menu), login(login), regist(regist) {}

    void showMenu() {
        menu->MenuWelcome();
        int pil = menu->getPilihan();
       
        switch (pil) {
            case 1:
                login->Login();
                if(login->getUserRole() == "Admin"){
                    cout<<"Halo Admin \n";
                    menu->MenuAdmin();
                    int pil1 = menu->getPiladmin();
                    if(pil1 == 1){
                       menu->MenuManageBuku();
                       int pil2 = menu->getPilBuku();
                       if(pil2 == 1){
                        book->Buku();
                       }else if(pil2 == 2){

                       }
                    }else if(pil1 == 2){
                        menu->MenuMenageUser();
                    }   
                }else if(login->getUserRole() == "user"){
                    cout<<"Halo user";
                }
                break;
            case 2:
                regist->Register();
                if(regist->getRegisterStatus()){
                    //jika register baerhasil maka diarahkan ke login
                    login->Login();
                }else{
                    cout<<"Mari coba lagi";
                    menu->MenuWelcome();
                }
                break;
        }
    }

private:
    Menu* menu;
    LoginController* login;
    RegisterController* regist;
    BukuController* book;
    //RegisterController* regist;
};
#endif 