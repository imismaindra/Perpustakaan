#include <iostream>
#include <fstream>

using namespace std;

// Fungsi untuk menyimpan data pinjaman ke dalam file
void simpanDataPinjam(const string& nama, const string& isbn, const string& judul) {
    // Buka file untuk menambahkan data ke dalamnya
    ofstream filePinjam("pinjam.txt", ios::app);

    // Periksa apakah file berhasil dibuka
    if (!filePinjam.is_open()) {
        cout << "Gagal membuka file pinjam.txt" << endl;
        return;
    }

    // Simpan data ke dalam file
    filePinjam << "Nama: " << nama << ", ISBN: " << isbn << ", Judul: " << judul << ", Status: Dipinjam" << endl;

    // Tutup file setelah selesai
    filePinjam.close();

    cout << "Data berhasil disimpan ke dalam pinjam.txt" << endl;
}

int main() {
    // Variabel untuk menyimpan input dari pengguna
    string nama, isbn, judul;

    // Minta input dari pengguna
    cout << "Masukkan nama Anda: ";
    getline(cin, nama);

    // Minta input dan simpan data buku (maksimal 3 buku)
    for (int i = 0; i < 3; ++i) {
        cout << "Masukkan nomor ISBN buku ke-" << i + 1 << ": ";
        getline(cin, isbn);

        cout << "Masukkan judul buku ke-" << i + 1 << ": ";
        getline(cin, judul);

        // Simpan data buku ke dalam file
        simpanDataPinjam(nama, isbn, judul);
    }

    return 0;
}
