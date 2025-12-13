#include "komposer_relasi.h"
#include <iostream>

using namespace std;

void insertFirstKomposer(ListKomposer &L, adrKomposer P) {
    if (L.first == nullptr) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}

void deleteAfterKomposer(ListKomposer &L, adrKomposer Prec, adrKomposer &P) {
    if (Prec != nullptr && Prec->next != nullptr) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = nullptr;
    } else {
        P = nullptr;
    }
}

void showAllKomposer(ListKomposer L) {
    cout << "\n--- Daftar Komposer ---" << endl;

    if (L.first == nullptr) {
        cout << "List Komposer kosong." << endl;
        return;
    }

    adrKomposer P = L.first;
    int i = 1;
    while (P != nullptr) {
        cout << i << ". ID: " << P->info.idKomposer
             << ", Nama: " << P->info.nama
             << ", Tahun Lahir: " << P->info.tahunLahir
             << ", Negara: " << P->info.negaraAsal << endl;
        P = P->next;
        i++;
    }
    cout << "------------------------------------" << endl;
}

void insertRelasi(adrKomposer K, adrRelasi R) {
    if (K->firstRelasi == nullptr) {
        K->firstRelasi = R;
    } else {
        R->nextRelasi = K->firstRelasi;
        K->firstRelasi = R;
    }
}

void showRelasiPerKomposer(adrKomposer K) {
    adrRelasi R = K->firstRelasi;
    while (R != nullptr) {
        cout << R->musik->info.idMusik << " - "
             << R->musik->info.judul << endl;
        R = R->nextRelasi;
    }
}
