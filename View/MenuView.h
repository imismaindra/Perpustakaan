#include<iostream>
using namespace std;
class Menu{
    public:
    void MenuWelcome(){
        cout<<"========================================="<<endl;
        cout<<"=    Selamat Datang di Perpustakaan     ="<<endl;
        cout<<"========================================="<<endl;
        cout<<"=   MENU                                ="<<endl;
        cout<<"=---------------------------------------="<<endl;
        cout<<"=-  1.Login                            -="<<endl;
        cout<<"=-  2.Register                         -="<<endl;
        cout<<"=---------------------------------------="<<endl;
        cout<<"========================================="<<endl;
        cout<<"Pilih: ";cin>>pilihan;
    }
    
    int getPilihan(){
        return pilihan;
    }
    private:
    int pilihan;
};
