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

void deleteRelasiAfter(adrKomposer K, string idMusik) {
    if (K == nullptr || K->firstRelasi == nullptr) {
        return;
    }

    adrRelasi Prec = K->firstRelasi;

    while (Prec->nextRelasi != nullptr &&
           Prec->nextRelasi->musik->info.idMusik != idMusik) {
        Prec = Prec->nextRelasi;
    }

    if (Prec->nextRelasi != nullptr) {
        adrRelasi P = Prec->nextRelasi;
        Prec->nextRelasi = P->nextRelasi;
        P->nextRelasi = nullptr;
        delete P;
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
    if (L.first != nullptr) {
        P = L.first;
        L.first = P->next;
        P->next = nullptr;
    } else {
        P = nullptr;
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

void showMusikDariKomposer(adrKomposer K) {
    if (K == nullptr) {
        return;
    }

    adrRelasi R = K->firstRelasi;
    while (R != nullptr) {
        cout << R->musik->info.idMusik << " "
             << R->musik->info.judul << endl;
        R = R->nextRelasi;
    }
}

int countKomposerMusik(ListKomposer L, string idMusik) {
    int count = 0;
    adrKomposer K = L.first;
    while (K != nullptr) {
        if (isRelasiExist(K, idMusik)) {
            count++;
        }
        K = K->next;
    }
    return count;
}

int countKomposerTanpaMusik(ListKomposer L) {
    int count = 0;
    adrKomposer K = L.first;
    while (K != nullptr) {
        if (K->firstRelasi == nullptr) {
            count++;
        }
        K = K->next;
    }
    return count;
}

