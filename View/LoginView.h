#include <iostream>
class LoginView {
public:
    void ProsesLogin(){
        cout << "Masukkan username: ";
        cin >> username; // Menambahkan input untuk username
        cout << "Masukkan password: ";
        cin >> password; // Menambahkan input untuk password
    }
    
    void sukses(){
        cout<<"Login Berhasil\n";
    }
    void gagal(){
        cout<<"Username atau Password salah!\n";
    }

    string getUsername() {
        return username;
    }

    string getPassword() {
        return password;
    }

private:
    string username;
    string password;
};