#include <string>
#include <fstream>
using namespace std;
class LoginModel {
public:
    bool checkLogin(const string& username, const string& password) {
        ifstream file("../Utils/login.txt"); // membaca file login.txt
        int id;
        string Nama, Email, storedUsername, storedPassword,role;

        while (file >>id >> Nama >> Email >> storedUsername >> storedPassword >> role) {
            if (username == storedUsername && password == storedPassword) {
                file.close();
                return true; // Username dan password cocok
            }
        }
        file.close();
        return false; // Username atau password tidak cocok
    }

};