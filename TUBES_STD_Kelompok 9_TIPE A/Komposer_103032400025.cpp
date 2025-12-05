#include "komposer.h"
#include "relation.h"
#include <iostream>

using namespace std;

void insertFirstKomposer(ListKomposer &L, adrKomposer P) {
    if (P == NULL) return;
    P->next = NULL;
    P->firstRelasi = NULL;

    if (L.first == NULL) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}

void deleteAfterKomposer(ListKomposer &L, adrKomposer Prec, adrKomposer &P) {
    P = NULL;
    if (Prec == NULL || Prec->next == NULL) return;

    P = Prec->next;
    Prec->next = P->next;
    P->next = NULL;
}

void showAllKomposer(ListKomposer L) {
    adrKomposer P = L.first;

    if (P == NULL) {
        cout << "Tidak ada komposer.\n";
        return;
    }

    cout << "=== Daftar Komposer ===\n";
    while (P != NULL) {
        cout << "ID: " << P->info.idKomposer
             << " | Nama: " << P->info.nama << endl;

        P = P->next;
    }
}
