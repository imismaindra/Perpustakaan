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

    void clearRegisters() {
        registers.clear();
    }
   void loadRegister(){
        clearRegisters();
        ifstream file("../Utils/login.txt");
        if(file.is_open()){
            while(!file.eof()){
                Register daftar;
                file >> daftar.id >> daftar.nama >> daftar.email >> daftar.username >> daftar.password >> daftar.role;
                if(!file.fail()) {
                    registers.push_back(daftar);
                }
            }
            file.close();
        } else {
            cout<<"File tidak bisa dibuka \n";
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
                file << daftar.id << " " << daftar.nama << " " << daftar.email << " " << daftar.username << " " << daftar.password << " " << daftar.role <<endl;
            }
            file.close();
            cout<<"Save berhasil"<<endl;
            return true;  
        }else{
            cout<<"Save Gagal, coba lagi."<<endl;
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
