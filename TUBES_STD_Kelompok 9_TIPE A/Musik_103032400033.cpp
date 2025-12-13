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
             << ", Judul: " << P->info.judul
             << ", Durasi: " << P->info.durasi
             << ", Tahun Rilis: " << P->info.tahunRilis
             << endl;
        P = P->next;
        i++;
    }

    cout << "---------------------------------" << endl;
}
