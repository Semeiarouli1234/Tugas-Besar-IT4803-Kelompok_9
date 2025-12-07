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
    if (Prec != nullptr) {
        P = Prec->next;
        if (P != nullptr) {
            Prec->next = P->next;
            if (P->next != nullptr) {
                P->next->prev = Prec;
            } else {
                L.last = Prec;
            }
            P->next = nullptr;
            P->prev = nullptr;
        }
    }
}

void showAllMusik(ListMusik L) {
    cout << "\n--- Daftar Musik ---" << endl;

    if (L.first == nullptr) {
        cout << "List Musik kosong." << endl;
        return;
    }

    adrMusik P = L.first;
    int i = 1;
    while (P != nullptr) {
        cout << i << ". ID: " << P->info.idMusik
             << ", Judul: " << P->info.Judul
             << ", Durasi: " << P->info.Durasi
             << ", Tahun Rilis: " << P->info.Tahun_Rilis
             << endl;
        P = P->next;
        i++;
    }

    cout << "---------------------------------" << endl;
}
