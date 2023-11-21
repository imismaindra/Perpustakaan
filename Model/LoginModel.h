#include <string>
#include <fstream>
using namespace std;
class LoginModel {
public:
    string checkLogin(const string& username, const string& password) {
        ifstream file("../Utils/login.txt"); // membaca file login.txt
        int id;
        string Nama, Email, storedUsername, storedPassword,role;

        while (file >>id >> Nama >> Email >> storedUsername >> storedPassword >> role) {
            if (username == storedUsername && password == storedPassword) {
                file.close();
                return role; // Username dan password cocok
            }
        }
        file.close();
        return ""; // Username atau password tidak cocok
    }

};