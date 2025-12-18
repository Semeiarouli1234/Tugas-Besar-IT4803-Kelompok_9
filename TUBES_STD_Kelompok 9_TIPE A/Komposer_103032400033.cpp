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

adrRelasi allocateRelasi(adrMusik M) {
    if (M == nullptr) return nullptr;
    adrRelasi R = new NodeRelasi;
    R->musik = M;
    R->nextRelasi = nullptr;
    return R;
}

void deleteRelasiAfter(adrKomposer K, adrRelasi Prec, adrRelasi &R) {
    if (Prec != nullptr && Prec->nextRelasi != nullptr) {
        R = Prec->nextRelasi;
        Prec->nextRelasi = R->nextRelasi;
        R->nextRelasi = nullptr;
    }
}

void insertLastKomposer(ListKomposer &L, adrKomposer P) {
    if (L.first == nullptr) {
        L.first = P;
    } else {
        adrKomposer Q = L.first;
        while (Q->next != nullptr) Q = Q->next;
        Q->next = P;
    }
}

void insertAfterKomposer(adrKomposer Prec, adrKomposer P) {
    if (Prec != nullptr) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

adrKomposer findKomposer(ListKomposer L, string idKomposer) {
    adrKomposer P = L.first;
    while (P != nullptr) {
        if (P->info.idKomposer == idKomposer) return P;
        P = P->next;
    }
    return nullptr;
}

void deleteFirstKomposer(ListKomposer &L, adrKomposer &P) {
    if (L.first != nullptr) {
        P = L.first;
        L.first = P->next;
        P->next = nullptr;
        // Catatan: Idealnya menghapus semua relasi di dalamnya dulu (f)
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
        while (Q->next->next != nullptr) Q = Q->next;
        P = Q->next;
        Q->next = nullptr;
    }
}

void showMusikDariKomposer(adrKomposer K) {
    if (K == nullptr) return;
    cout << "Daftar Musik karya " << K->info.nama << ":" << endl;
    adrRelasi R = K->firstRelasi;
    while (R != nullptr) {
        cout << "  - " << R->musik->info.judul << " [" << R->musik->info.idMusik << "]" << endl;
        R = R->nextRelasi;
    }
}

void showMusikDanKomposer(ListKomposer L, string idMusik) {
    adrKomposer P = L.first;
    bool found = false;
    cout << "Komposer yang terhubung dengan musik ID " << idMusik << ":" << endl;
    while (P != nullptr) {
        if (findRelasi(P, idMusik) != nullptr) {
            cout << "- " << P->info.nama << endl;
            found = true;
        }
        P = P->next;
    }
    if (!found) cout << "Tidak ada komposer untuk musik ini." << endl;
}

int countMusikTanpaRelasi(ListMusik LM, ListKomposer LK) {
    int cnt = 0;
    adrMusik M = LM.first;
    while (M != nullptr) {
        if (countRelasiPerMusik(LK, M->info.idMusik) == 0) cnt++;
        M = M->next;
    }
    return cnt;
}
