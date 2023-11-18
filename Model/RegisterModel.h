#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class RegisterModel{
    public:
    struct Register{
        int id;
        string nama;
        string email;
        string username;
        string password;
        string role;
    };

   void loadRegister() {
        ifstream file("../Utils/login.txt");
        if (file.is_open()) {
             Register daftar;
            while (file >> daftar.id >> daftar.nama >> daftar.email >> daftar.username >> daftar.password >> daftar.role) {
                registers.push_back(daftar);
            }

            if (file.bad()) {
                cerr << "Error reading file.\n";
            }

            file.close();
        } else {
            cout << "File tidak bisa dibuka\n";
        }
    }
    int getNextId() const {
        if (!registers.empty()) {
            return registers.back().id + 1;
        } else {
            return 1; // Jika tidak ada data, id dimulai dari 1
        }
    }
    bool saveRegister(){
        ofstream file("../Utils/login.txt");
        if(file.is_open()) {
            for(const Register& daftar:registers) {
                file << daftar.id << " " << daftar.nama << " " << daftar.nama << " " << daftar.email << " " << daftar.username << " " << daftar.password << " " << daftar.role <<endl;
            }
            file.close();
            cout<<"Save berhasil";
            return true;  
        }else{
            cout<<"Save Gagal.";
            return false;
        }
    }

    bool createRegister(const Register& reg){
        registers.push_back(reg);
    }

    const vector<Register>& getDaftar() const{
        return registers;
    }

    private:
    vector<Register> registers;
};
