#include "komposer_relasi.h"
#include <iostream>

using namespace std;

void insertFirstKomposer(ListKomposer &L, adrKomposer P) {
    if (L.first == nullptr) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}

bool isRelasiExist(adrKomposer K, string idMusik) {
    adrRelasi R = K->firstRelasi;
    while (R != nullptr) {
        if (R->musik->info.idMusik == idMusik) {
            return true;
        }
        R = R->nextRelasi;
    }
    return false;
}

void addRelasiLast(adrKomposer K, adrMusik M) {
    if (K == nullptr || M == nullptr) {
        return;
    }

    if (isRelasiExist(K, M->info.idMusik)) {
        return;
    }

    adrRelasi R = newRelasi(M);

    if (K->firstRelasi == nullptr) {
        K->firstRelasi = R;
    } else {
        adrRelasi Q = K->firstRelasi;
        while (Q->nextRelasi != nullptr) {
            Q = Q->nextRelasi;
        }
        Q->nextRelasi = R;
    }
}

void deleteAfterKomposer(ListKomposer &L, adrKomposer Prec, adrKomposer &P) {
    if (Prec != nullptr && Prec->next != nullptr) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = nullptr;
    } else {
        P = nullptr;
    }
}

void showAllKomposer(ListKomposer L) {
    cout << "\n--- Daftar Komposer ---" << endl;

    if (L.first == nullptr) {
        cout << "List Komposer kosong." << endl;
        return;
    }

    adrKomposer P = L.first;
    int i = 1;
    while (P != nullptr) {
        cout << i << ". ID: " << P->info.idKomposer
             << ", Nama: " << P->info.nama
             << ", Tahun Lahir: " << P->info.tahunLahir
             << ", Negara: " << P->info.negaraAsal << endl;
        P = P->next;
        i++;
    }

    cout << "---------------------------------" << endl;
}

void showKomposerDariMusik(ListKomposer L, string idMusik) {
    adrKomposer K = L.first;
    while (K != nullptr) {
        if (isRelasiExist(K, idMusik)) {
            cout << K->info.idKomposer << " "
                 << K->info.nama << endl;
        }
        K = K->next;
    }
}


int countMusikTanpaKomposer(ListMusik LM, ListKomposer LK) {
    int count = 0;
    adrMusik M = LM.first;
    while (M != nullptr) {
        if (countKomposerMusik(LK, M->info.idMusik) == 0) {
            count++;
        }
        M = M->next;
    }
    return count;
}

void editRelasiMusik(adrKomposer K, string idMusikLama, adrMusik MusikBaru) {
    if (K == nullptr || MusikBaru == nullptr) {
        return;
    }

    adrRelasi R = K->firstRelasi;
    while (R != nullptr) {
        if (R->musik->info.idMusik == idMusikLama) {
            R->musik = MusikBaru;
            return;
        }
        R = R->nextRelasi;
    }
}
