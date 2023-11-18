#ifndef REGISTER_CONTROLLER_H
#define REGISTER_CONTROLLER_H
#include "G:\Pribadi\Kuliah\Praktikum\C++\Perpustakaan\Model\RegisterModel.h"
#include "G:\Pribadi\Kuliah\Praktikum\C++\Perpustakaan\View\RegisterView.h"
#include <string>

class RegisterController{
    public:
        RegisterController(RegisterModel* model, RegisterViews* view): model(model), view(view){};
        void Register(){
            //model->loadRegister();
            int id = model->getNextId();//Mendapatkan ID berdasarkan jumlah data yang sudah ada
            string nama, email, username, password, role;
            view->RegisterView(id, nama, email, username, password, role);
            
            RegisterModel::Register reg = {id, nama, email, username, password, role};
            model->createRegister(reg);
            model->saveRegister();  // Menyimpan data registrasi setelah membuatnya
        }
    private:
        RegisterModel* model;
        RegisterViews* view;
};
#endif