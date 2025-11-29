#include "komposer.h"

void insertLastKomposer(ListKomposer &L, addressK P) {
    // I.S : L mungkin kosong atau tidak
    // F.S : P menjadi elemen terakhir pada list
    if (L.first == NULL) {
        L.first = P;
    } else {
        addressK Q = L.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void insertAfterKomposer(addressK Prec, addressK P) {
    // I.S : Prec adalah elemen valid pada list
    // F.S : P disisipkan setelah Prec
    if (Prec != NULL) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

void deleteFirstKomposer(ListKomposer &L, addressK &P) {
    // I.S : L mungkin kosong atau tidak
    // F.S : P berisi elemen pertama yang dihapus
    if (L.first != NULL) {
        P = L.first;
        L.first = P->next;
        P->next = NULL;
    } else {
        P = NULL;
    }
}

void deleteLastKomposer(ListKomposer &L, addressK &P) {
    // I.S : L mungkin kosong atau tidak
    // F.S : P berisi elemen terakhir yang dihapus
    if (L.first == NULL) {
        P = NULL;

    } else if (L.first->next == NULL) {
        P = L.first;
        L.first = NULL;

    } else {
        addressK Q = L.first;
        while (Q->next->next != NULL) {
            Q = Q->next;
        }
        P = Q->next;
        Q->next = NULL;
    }
}

addressK findElmKomposer(ListKomposer L, string x) {
    // I.S : L terdefinisi
    // F.S : Mengembalikan alamat elemen dengan info x,
    //       atau NULL jika tidak ditemukan
    addressK P = L.first;
    while (P != NULL && P->info != x) {
        P = P->next;
    }
    return P;
}
