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

    private:
    BukuModel* model;
    BukuView* view;


};
#endif
