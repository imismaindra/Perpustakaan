#include "G:\Pribadi\Kuliah\Praktikum\C++\Perpustakaan\Model\LoginModel.h"
#include "G:\Pribadi\Kuliah\Praktikum\C++\Perpustakaan\View\LoginView.h"

using namespace std;
class LoginController {
public:
    LoginController(LoginModel* model, LoginView* view) : model(model), view(view) {}

    void Login() {
        view->ProsesLogin();
        string role = model->checkLogin(view->getUsername(), view->getPassword());
        if (!role.empty()) {
            // Login berhasil, role bisa digunakan sesuai kebutuhan
            view->sukses();
            //cout << "Role: " << role << endl; // Contoh: Menampilkan role ke layar
            userRole = role;
        } else {
            view->gagal();
        }
    }

    string getUserRole(){
        return userRole;
    }
private:

    LoginModel* model;
    LoginView* view;
    string userRole; // Variable untuk menyimpan role pengguna yang login
};