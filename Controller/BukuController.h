#ifndef BUKU_CONTROLLER_H
#define BUKU_CONTROLLER_H

#include "G:\Pribadi\Kuliah\Praktikum\C++\Perpustakaan\Model\BukuModel.h"
#include "G:\Pribadi\Kuliah\Praktikum\C++\Perpustakaan\View\BukuView.h"
#include <iostream>
#include <string>

class BukuController{
    public:
    BukuController(BukuModel* model, BukuView* view): model(model), view(view){};
    void Buku(){
        int id = model->getNextId();
        int isbn, halaman,tahunTerbit;
        string judul,sinopsis,author,publisher;
        view->addBukuView(id,isbn, judul, sinopsis,halaman, author, tahunTerbit, publisher);
       BukuModel::Buku buku = {id,isbn, judul, sinopsis,halaman, author, tahunTerbit, publisher};
       model->createBooks(buku);
       model->saveBooks();
    }

    void HapusBuku(){
        view->deleteBukuView(id);
        model->deleteBooks(id);
        model->saveBooks();
    }

    void UbahBuku(){
        // mendapatkan id dari user
        int Bukuid = view->GetIdBukuView();
         // Mendapatkan informasi buku berdasarkan ID
        const BukuModel::Buku* bukuToUpdate = model->getBukuById(Bukuid);

        if (bukuToUpdate != nullptr) {
            // Menampilkan informasi buku yang akan diubah
            view->showBukuInfo(*bukuToUpdate);

            // Mendapatkan input baru dari pengguna
            int newIsbn, newHalaman, newTahunTerbit;
            string newJudul, newSinopsis, newAuthor, newPublisher;

            view->editBukuView(newIsbn, newJudul, newSinopsis, newHalaman, newAuthor, newTahunTerbit, newPublisher);

            // Membuat objek buku baru dengan informasi yang diperbarui
            BukuModel::Buku updatedBuku = {
                Bukuid,
                newIsbn,
                newJudul,
                newSinopsis,
                newHalaman,
                newAuthor,
                newTahunTerbit,
                newPublisher
            };

            // Memperbarui informasi buku
            model->updateBooks(Bukuid, updatedBuku);

            // Menyimpan perubahan ke file
            model->saveBooks();

            cout << "Informasi buku berhasil diperbarui.\n";
        } else {
            // Jika buku dengan ID tidak ditemukan
            cout << "Buku dengan ID " << Bukuid << " tidak ditemukan.\n";
        }
    }
    void tampilBuku(){
        view->listBukuView();
        model->listBuku();
    }

    private:
    BukuModel* model;
    BukuView* view;
    int id;

};
#endif
