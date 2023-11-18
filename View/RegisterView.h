#include <iostream>
#include <limits>
using namespace std;

class RegisterViews{
    public:
    void RegisterView(int& id, string& nama, string& email,string& username, string& password, string& role){
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"Nama     : "; getline(cin, nama);
        cout<<"Email    : "; getline(cin, email);
        cout<<"Username : "; getline(cin, username);
        cout<<"Password : "; getline(cin, password);
        role = "user";
    }
};