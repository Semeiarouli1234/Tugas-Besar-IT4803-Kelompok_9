#include "Musik.h"
#include <iostream>

using namespace std;

void insertFirstMusik(ListMusik &L, adrMusik P) {
    if (L.first == nullptr) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void deleteAfterMusik(ListMusik &L, adrMusik Prec, adrMusik &P) {
    if (Prec != nullptr && Prec->next != nullptr) {
        P = Prec->next;
        if (P == L.last) {
            deleteLastMusik(L, P);
        } else {
            Prec->next = P->next;
            P->next->prev = Prec;
            P->next = nullptr;
            P->prev = nullptr;
        }
    }
}


void showAllMusik(ListMusik L) {
    adrMusik P = L.first;
    if (P == nullptr) {
        cout << "List Musik Kosong." << endl;
    } else {
        while (P != nullptr) {
            cout << "ID: " << P->info.idMusik << " | Judul: " << P->info.judul;
            cout << " | Durasi: " << P->info.durasi << " | Tahun: " << P->info.tahunRilis << endl;
            P = P->next;
        }
    }
}
