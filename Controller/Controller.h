#include "G:\Pribadi\Kuliah\Praktikum\C++\Perpustakaan\Model\LoginModel.h"
#include "G:\Pribadi\Kuliah\Praktikum\C++\Perpustakaan\View\LoginView.h"

using namespace std;
class LoginController {
public:
    LoginController(LoginModel* model, LoginView* view) : model(model), view(view) {}

    // void login(const string& username, const string& password) {
    //     view->ProsesLogin();
    //     if (model->checkLogin(username, password)) {
    //         view->sukses();
    //     } else {
    //         view->gagal();
    //     }
    // }

    void Login(){
        view->ProsesLogin();
        if(model->checkLogin(view->getUsername(), view->getPassword())){
            view->sukses();

        }else{
            view->gagal();
        }
    }
private:

    LoginModel* model;
    LoginView* view;
};