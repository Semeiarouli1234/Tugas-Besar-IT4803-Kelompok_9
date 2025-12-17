#include "Musik.h"
#include <iostream>

using namespace std;

void insertFirstMusik(ListMusik &L, adrMusik P) {
    if (L.first == nullptr) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

adrMusik findMusik(ListMusik L, string idMusik) {
    adrMusik P = L.first;
    while (P != nullptr && P->info.idMusik != idMusik) {
        P = P->next;
    }
    return P;
}

void showAllMusik(ListMusik L) {
    adrMusik P = L.first;
    while (P != nullptr) {
        cout << P->info.idMusik << " "
             << P->info.judul << " "
             << P->info.durasi << " "
             << P->info.tahunRilis << endl;
        P = P->next;
    }
}
