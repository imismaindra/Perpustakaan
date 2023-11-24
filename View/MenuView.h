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
    void MenuAdmin(){
        cout<<"========================================="<<endl;
        cout<<"===------------MENU ADMIN--------------=="<<endl;
        cout<<"========================================="<<endl;
        cout<<"== 1. Manage Buku                      =="<<endl;
        cout<<"== 2. Manage User                      =="<<endl;
        cout<<"========================================="<<endl;
        cout<<"Pilih: ";cin>>pil1;
    }
    int getPiladmin(){
        return pil1;
    }

    void MenuManageBuku(){
        cout<<"========================================="<<endl;
        cout<<"===------------MENU BUKU--------------=="<<endl;
        cout<<"========================================="<<endl;
        cout<<"== 1. Tambah Buku                      =="<<endl;
        cout<<"== 2. Hapus Buku                       =="<<endl;
        cout<<"== 3. Ubah Buku                        =="<<endl;
        cout<<"== 4. List Buku                        =="<<endl;
        cout<<"== 5. Cek Peminjaman Buku              =="<<endl;
        cout<<"== 6. Cek Pengembalian Buku            =="<<endl; 
        cout<<"== 7. Kembali                          =="<<endl; 
        cout<<"== 8. Exit                             =="<<endl;
        cout<<"========================================="<<endl;
        cout<<"Pilihan: ";cin>>pil2;
    }
    int getPilBuku(){
        return pil2;
    }

    void MenuMenageUser(){
        cout<<"========================================="<<endl;
        cout<<"===------------MENU ADMIN--------------=="<<endl;
        cout<<"========================================="<<endl;
        cout<<"== 1. Tambah User                      =="<<endl;
        cout<<"== 2. Hapus User                       =="<<endl;
        cout<<"== 3. Ubah User                        =="<<endl;
        cout<<"== 4. List User                        =="<<endl;
        cout<<"== 5. Kembali                          =="<<endl;
        cout<<"== 6. Exit                             =="<<endl;
        cout<<"========================================="<<endl;

    }
    private:
    int pilihan;
    int pil1;
    int pil2;
    int pil3;
};
