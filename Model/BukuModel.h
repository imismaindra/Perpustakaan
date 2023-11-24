#include <iostream>
#include <sstream>
#include <string>
#include <fstream>   // Mengimpor library untuk bekerja dengan file.
#include <vector>    // Mengimpor library untuk menggunakan vektor.
#include <algorithm> // Mengimpor library algoritma, digunakan untuk menghapus catatan.
using namespace std;

class BukuModel{
    public:
    struct Buku
    {
    int id;
    int isbn;
    string judul;
    string sinopsis; 
    int halaman;
    string author;
    int tahunTerbit;
    string publisher; 
    };

    void loadBooks(){
        ifstream file("../Utils/buku.txt");
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                Buku buku;
                stringstream ss(line);
                
                // Gunakan getline untuk membaca setiap bagian terpisah oleh koma
                getline(ss, line, ',');
                buku.id = stoi(line);
                getline(ss, line, ',');
                buku.isbn = stoi(line);
                getline(ss, buku.judul, ',');
                getline(ss, buku.sinopsis, ',');
                
                getline(ss, line, ',');
                buku.halaman = stoi(line);

                getline(ss, buku.author, ',');
                
                getline(ss, line, ',');
                buku.tahunTerbit = stoi(line);

                getline(ss, buku.publisher, ',');

                // Periksa apakah tidak ada kesalahan saat membaca
                if (!ss.fail()) {
                    books.push_back(buku);
                }
            }
            file.close();
        } else {
            cout << "File tidak bisa dibuka\n";
        }
    }
    int getNextId() const {
        if (!books.empty()) {
            return books.back().id + 1;
        } else {
            return 1; // Jika tidak ada data, id dimulai dari 1
        }
    }

    void saveBooks(){
        ofstream file("../Utils/buku.txt");
        if(file.is_open()){
            for(const Buku& buku:books){
            file << buku.id << "," << buku.isbn << "," << buku.judul << "," << buku.sinopsis << "," << buku.halaman << "," << buku.author <<","<< buku.tahunTerbit << "," << buku.publisher<<endl;
            }
            file.close();
        }
    }

    void createBooks(const Buku& buku){
       
        books.push_back(buku);
    }

    void deleteBooks(int id){
        //mngetahui ukuran awal vector books
        auto initialSize = books.size();
        books.erase(remove_if(books.begin(),books.end(),[id](const Buku& buku){return buku.id == id;}),books.end());
        auto finalSize = books.size();
        //mbandingno ukkurane sesudah di hapus 
        if (finalSize < initialSize) {
            cout << "Buku dengan ID " << id << " berhasil dihapus.\n";
        } else {
            cout << "Buku dengan ID " << id << " tidak ditemukan atau gagal dihapus.\n";
        }
    }

    const Buku* getBukuById(int id) const {
        auto it = find_if(books.begin(), books.end(), [id](const Buku& buku) {
            return buku.id == id;
        });

        if (it != books.end()) {
            return &(*it); // Mengembalikan pointer ke buku yang ditemukan
        } else {
            return nullptr; // ID tidak ditemukan
        }
    }


    void updateBooks(int id, const Buku& newBukuInfo){
        const Buku* bukuToUpdate = getBukuById(id);
        if (bukuToUpdate != nullptr) {
            // Jika buku dengan ID ditemukan, lakukan pembaruan informasi
            auto it = find_if(books.begin(), books.end(), [id](const Buku& buku) {
                return buku.id == id;
            });

            *it = newBukuInfo;
            cout << "Buku dengan ID " << id << " berhasil diperbarui.\n";
        } else {
            // Jika buku dengan ID tidak ditemukan
            cout << "Buku dengan ID " << id << " tidak ditemukan.\n";
        }
    }

    
    const vector<Buku>& getBuku() const{
        return books;
    }

    private:
    vector<Buku> books;
    int idBuku;
};