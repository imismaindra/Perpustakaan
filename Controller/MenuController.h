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
                        do{
                            menu->MenuManageBuku();
                            int pil2 = menu->getPilBuku();
                            
                            if(pil2 == 1){
                                book->Buku();
                            }else if(pil2 == 2){
                                book->HapusBuku();
                            }else if(pil2 == 3){
                                book->UbahBuku();
                            }else if(pil2 == 4){
                                book->tampilBuku();
                            }
                        }while(menu->getPilBuku() < 1 || menu->getPilBuku() > 8);
                    }else if(pil1 == 2){
                        menu->MenuMenageUser();
                    }   
                }else if(login->getUserRole() == "user"){
                    cout<<"Halo user \n";
                    menu->MenuUser();
                    int pilihanUser = menu->getPilihanUser();
                    if(pilihanUser == 1){
                        book->tampilBuku();
                    }else if(pilihanUser == 2){

                    }
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