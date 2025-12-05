#include "Musik.h"
#include <iostream>
using namespace std;

void insertFirstMusik(ListMusik &L, adrMusik P) {
    if (L.first == NULL) {
        L.first = L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void deleteAfterMusik(ListMusik &L, adrMusik Prec, adrMusik &P) {
    if (Prec != NULL && Prec->next != NULL) {
        P = Prec->next;
        Prec->next = P->next;
        if (P->next != NULL)
            P->next->prev = Prec;
        else
            L.last = Prec;  // kalau P adalah elemen terakhir

        P->next = NULL;
        P->prev = NULL;
    }
}

void showAllMusik(ListMusik L) {
    adrMusik P = L.first;

    if (P == NULL) {
        cout << "Tidak ada musik.\n";
        return;
    }
    while (P != NULL) {
        cout << "ID: " << P->info.idMusik
             << " | Judul: " << P->info.judul << endl;
        P = P->next;
    }
}
