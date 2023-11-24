#include <iostream>
#include <limits>
using namespace std;

class BukuView{
    public:
    void addBukuView(int& id, int&isbn, string& judul, string& sinopsis, int& halaman, string& author, int& tahunTerbit, string& publisher){
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
       
        cout << "Tambah Buku" << endl;
        cout << "Nomor ISBN    : "; cin >>isbn;

        // Membersihkan buffer setelah membaca angka
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Judul Buku    : "; getline(cin, judul);
        cout << "Sinopsis Buku : "; getline(cin, sinopsis);
        cout << "Total Halaman : "; cin >> halaman;

        // Membersihkan buffer setelah membaca angka
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Author        : "; getline(cin, author);
        cout << "Tahun Terbit  : "; cin >> tahunTerbit;

        // Membersihkan buffer setelah membaca angka
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Penerbit      : "; getline(cin, publisher);
    }

    int GetIdBukuView(){
        int id;
        cout<<"Masukkan Id Buku yang inign di Update: "; cin >> id;
        return id;
    }

    void showBukuInfo(const BukuModel::Buku& buku) const{
        cout << "ID      : " << buku.id << endl;
        cout << "ISBN    : " << buku.isbn << endl;
        cout << "Judul   : " << buku.judul << endl;
        cout << "Sinopsis: " << buku.sinopsis << endl;
        cout << "Halaman : " << buku.halaman << endl;
        cout << "Author  : " << buku.author << endl;
        cout << "Tahun   : " << buku.tahunTerbit << endl;
        cout << "Penerbit: " << buku.publisher << endl;
    }

    void editBukuView(int& newIsbn, string& newJudul, string& newSinopsis, int& newHalaman,
    string& newAuthor, int& newTahunTerbit, string& newPublisher) {
        
        cout << "Masukkan informasi baru untuk buku:\n";

        cout << "ISBN baru    : "; cin >> newIsbn;
        cin.ignore(); // Membersihkan newline di buffer
        cout << "Judul baru   : "; getline(cin, newJudul);
        cout << "Sinopsis baru: "; getline(cin, newSinopsis);
        cout << "Halaman baru : "; cin >> newHalaman;
        cin.ignore();
        cout << "Author baru  : "; getline(cin, newAuthor);
        cout << "Tahun baru   : "; cin >> newTahunTerbit;
        cin.ignore();
        cout << "Penerbit baru: "; getline(cin, newPublisher);
    }


    void deleteBukuView(int& id){
        system("cls");
        cout<<"Masukkan Id buku yang ingin dihapus: ";cin >> id;
    }
};