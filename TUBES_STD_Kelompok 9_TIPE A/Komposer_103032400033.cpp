#include "komposer.h"
#include "relation.h"
#include <iostream>

using namespace std;

void createListKomposer(ListKomposer &L) {
    L.first = NULL;
}

void insertLastKomposer(ListKomposer &L, adrKomposer P) {
    if (L.first == NULL) {
        L.first = P;
    } else {
        adrKomposer Q = L.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void insertAfterKomposer(ListKomposer &L, adrKomposer Prec, adrKomposer P) {
    if (Prec != NULL) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

void deleteFirstKomposer(ListKomposer &L, adrKomposer &P) {
    if (L.first != NULL) {
        P = L.first;
        L.first = P->next;
        P->next = NULL;
    }
}

void deleteLastKomposer(ListKomposer &L, adrKomposer &P) {
    if (L.first != NULL) {
        if (L.first->next == NULL) {
            P = L.first;
            L.first = NULL;
        } else {
            adrKomposer Q = L.first;
            while (Q->next->next != NULL) {
                Q = Q->next;
            }
            P = Q->next;
            Q->next = NULL;
        }
    }
}

adrKomposer findKomposer(ListKomposer L, string id) {
    adrKomposer P = L.first;
    while (P != NULL) {
        if (P->info.idKomposer == id) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

adrKomposer newKomposer(string id, string nama) {
    adrKomposer P = new elkomposer;
    P->info.idKomposer = id;
    P->info.nama = nama;
    P->next = NULL;
    P->firstRelasi = NULL;
    return P;
}
