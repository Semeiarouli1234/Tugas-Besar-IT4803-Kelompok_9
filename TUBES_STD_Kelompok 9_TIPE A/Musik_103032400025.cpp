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
    P->prev = nullptr;
    P->next = nullptr;
    return P;
}

void insertLastMusik(ListMusik &L, adrMusik P) {
    if (L.first == nullptr) {
        L.first = P;
        L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

void insertAfterMusik(ListMusik &L, adrMusik Prec, adrMusik P) {
    if (Prec != nullptr) {
        P->next = Prec->next;
        P->prev = Prec;
        if (Prec->next != nullptr) {
            Prec->next->prev = P;
        } else {
            L.last = P;
        }
        Prec->next = P;
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
        }
        P->next = nullptr;
        P->prev = nullptr;
    } else {
        P = nullptr;
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
        }
        P->next = nullptr;
        P->prev = nullptr;
    } else {
        P = nullptr;
    }
}

void deleteAfterMusik(ListMusik &L, adrMusik Prec, adrMusik &P) {
    if (Prec != nullptr && Prec->next != nullptr) {
        P = Prec->next;
        Prec->next = P->next;
        if (P->next != nullptr) {
            P->next->prev = Prec;
        } else {
            L.last = Prec;
        }
        P->next = nullptr;
        P->prev = nullptr;
    } else {
        P = nullptr;
    }
}
