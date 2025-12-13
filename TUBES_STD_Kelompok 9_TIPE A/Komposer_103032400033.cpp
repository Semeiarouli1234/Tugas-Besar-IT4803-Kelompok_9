#include "komposer_relasi.h"
#include <iostream>

using namespace std;

void createListKomposer(ListKomposer &L) {
    L.first = nullptr;
}

adrKomposer newKomposer(InfoKomposer X) {
    adrKomposer P = new NodeKomposer;
    P->info = X;
    P->next = nullptr;
    P->firstRelasi = nullptr;
    return P;
}

adrRelasi newRelasi(adrMusik M) {
    adrRelasi R = new NodeRelasi;
    R->musik = M;
    R->nextRelasi = nullptr;
    return R;
}

void deleteRelasi(adrKomposer K, string idMusik) {
    adrRelasi R = K->firstRelasi;
    adrRelasi Prec = nullptr;

    while (R != nullptr && R->musik->info.idMusik != idMusik) {
        Prec = R;
        R = R->nextRelasi;
    }

    if (R != nullptr) {
        if (Prec == nullptr) {
            K->firstRelasi = R->nextRelasi;
        } else {
            Prec->nextRelasi = R->nextRelasi;
        }
        delete R;
    }
}

void insertLastKomposer(ListKomposer &L, adrKomposer P) {
    if (L.first == nullptr) {
        L.first = P;
    } else {
        adrKomposer Q = L.first;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void insertAfterKomposer(ListKomposer &L, adrKomposer Prec, adrKomposer P) {
    if (Prec != nullptr) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

adrKomposer findKomposer(ListKomposer L, string idKomposer) {
    adrKomposer P = L.first;
    while (P != nullptr && P->info.idKomposer != idKomposer) {
        P = P->next;
    }
    return P;
}

void deleteFirstKomposer(ListKomposer &L, adrKomposer &P) {
    if (L.first == nullptr) {
        P = nullptr;
    } else {
        P = L.first;
        L.first = P->next;
        P->next = nullptr;
    }
}

void deleteLastKomposer(ListKomposer &L, adrKomposer &P) {
    if (L.first == nullptr) {
        P = nullptr;
    } else if (L.first->next == nullptr) {
        P = L.first;
        L.first = nullptr;
    } else {
        adrKomposer Q = L.first;
        while (Q->next->next != nullptr) {
            Q = Q->next;
        }
        P = Q->next;
        Q->next = nullptr;
    }
}
