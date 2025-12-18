#include "komposer_relasi.h"
#include <iostream>

using namespace std;

void insertFirstKomposer(ListKomposer &L, adrKomposer P) {
    P->next = L.first;
    L.first = P;
}

void insertRelasiLast(adrKomposer K, adrRelasi R) {
    if (K == nullptr || R == nullptr) return;
    if (K->firstRelasi == nullptr) {
        K->firstRelasi = R;
    } else {
        adrRelasi Q = K->firstRelasi;
        while (Q->nextRelasi != nullptr) Q = Q->nextRelasi;
        Q->nextRelasi = R;
    }
}


void deleteAfterKomposer(adrKomposer Prec, adrKomposer &P) {
    if (Prec != nullptr && Prec->next != nullptr) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = nullptr;
    }
}

adrRelasi findRelasi(adrKomposer K, string idMusik) {
    if (K == nullptr) return nullptr;
    adrRelasi R = K->firstRelasi;
    while (R != nullptr) {
        if (R->musik->info.idMusik == idMusik) return R;
        R = R->nextRelasi;
    }
    return nullptr;
}

void showAllKomposer(ListKomposer L) {
    adrKomposer P = L.first;
    if (P == nullptr) cout << "List Komposer Kosong." << endl;
    while (P != nullptr) {
        cout << "ID: " << P->info.idKomposer << " | Nama: " << P->info.nama << endl;
        P = P->next;
    }
}

void showKomposerDanMusik(ListKomposer L) {
    adrKomposer P = L.first;
    while (P != nullptr) {
        cout << "Komposer: " << P->info.nama << endl;
        adrRelasi R = P->firstRelasi;
        if (R == nullptr) {
            cout << "  (Belum ada relasi musik)" << endl;
        } else {
            while (R != nullptr) {
                cout << "  -> Musik: " << R->musik->info.judul << endl;
                R = R->nextRelasi;
            }
        }
        P = P->next;
        cout << "-----------------------------------" << endl;
    }
}

int countRelasiPerKomposer(adrKomposer K) {
    int cnt = 0;
    adrRelasi R = K->firstRelasi;
    while (R != nullptr) {
        cnt++;
        R = R->nextRelasi;
    }
    return cnt;
}

int countRelasiPerMusik(ListKomposer L, string idMusik) {
    int cnt = 0;
    adrKomposer P = L.first;
    while (P != nullptr) {
        if (findRelasi(P, idMusik) != nullptr) cnt++;
        P = P->next;
    }
    return cnt;
}


void editRelasiMusik(adrKomposer K, string idMusikLama, adrMusik MusikBaru) {
    if (K == nullptr || MusikBaru == nullptr) return;
    adrRelasi R = findRelasi(K, idMusikLama);
    if (R != nullptr) {
        R->musik = MusikBaru;
        cout << "Berhasil memperbarui relasi musik." << endl;
    } else {
        cout << "Musik lama tidak ditemukan pada komposer ini." << endl;
    }
}
