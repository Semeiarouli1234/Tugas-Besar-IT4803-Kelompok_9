#include "Musik.h"
#include <iostream>

using namespace std;

void createListMusik(ListMusik &L) {
    L.first = nullptr;
    L.last = nullptr;
}

adrMusik newMusik(InfoMusik X) {
    adrMusik P = new NodeMusik;
    P->info = X;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

void insertLastMusik(ListMusik &L, adrMusik P) {
    if (L.first == nullptr) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void insertAfterMusik(ListMusik &L, adrMusik Prec, adrMusik P) {
    if (Prec != nullptr) {
        if (Prec == L.last) {
            insertLastMusik(L, P);
        } else {
            P->next = Prec->next;
            P->prev = Prec;
            Prec->next->prev = P;
            Prec->next = P;
        }
    }
}

void deleteFirstMusik(ListMusik &L, adrMusik &P) {
    if (L.first != nullptr) {
        P = L.first;
        if (L.first == L.last) {
            L.first = nullptr;
            L.last = nullptr;
        } else {
            L.first = P->next;
            L.first->prev = nullptr;
            P->next = nullptr;
        }
    }
}

void deleteLastMusik(ListMusik &L, adrMusik &P) {
    if (L.last != nullptr) {
        P = L.last;
        if (L.first == L.last) {
            L.first = nullptr;
            L.last = nullptr;
        } else {
            L.last = P->prev;
            L.last->next = nullptr;
            P->prev = nullptr;
        }
    }
}

adrMusik findMusik(ListMusik L, string idMusik) {
    adrMusik P = L.first;
    while (P != nullptr) {
        if (P->info.idMusik == idMusik) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}



