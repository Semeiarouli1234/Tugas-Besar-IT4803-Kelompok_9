#include "Musik.h"
#include <iostream>
using namespace std;

void createListMusik(ListMusik &L) {
    L.first = NULL;
    L.last = NULL;
}

adrMusik newMusik(string id, string judul) {
    adrMusik P = new elmusik;   // pastikan struct ini sesuai dengan header
    P->info.idMusik = id;
    P->info.judul = judul;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void insertLastMusik(ListMusik &L, adrMusik P) {
    if (L.first == NULL) {
        L.first = L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

void insertAfterMusik(ListMusik &L, adrMusik Prec, adrMusik P) {
    if (Prec != NULL) {
        P->next = Prec->next;

        if (Prec->next != NULL)
            Prec->next->prev = P;

        P->prev = Prec;
        Prec->next = P;

        if (Prec == L.last)
            L.last = P;
    }
}

void deleteFirstMusik(ListMusik &L, adrMusik &P) {
    if (L.first != NULL) {
        P = L.first;

        if (L.first == L.last) {
            L.first = L.last = NULL;
        } else {
            L.first = P->next;
            L.first->prev = NULL;
        }

        P->next = NULL;
        P->prev = NULL;
    }
}

void deleteLastMusik(ListMusik &L, adrMusik &P) {
    if (L.last != NULL) {
        P = L.last;

        if (L.first == L.last) {
            L.first = L.last = NULL;
        } else {
            L.last = P->prev;
            L.last->next = NULL;
        }

        P->next = NULL;
        P->prev = NULL;
    }
}

adrMusik findMusik(ListMusik L, string id) {
    adrMusik P = L.first;
    while (P != NULL) {
        if (P->info.idMusik == id)
            return P;
        P = P->next;
    }
    return NULL;
}
