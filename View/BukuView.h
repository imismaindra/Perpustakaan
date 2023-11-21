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
};