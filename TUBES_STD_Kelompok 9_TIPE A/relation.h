#ifndef RELASI_H
#define RELASI_H

#include "musik.h"
#include "komposer.h"

typedef struct elrelasi *adrRelasi;
struct elrelasi {
    adrKomposer parent;   // Komposer = parent
    adrMusik child;       // Musik = child
    adrRelasi next;
};

struct ListRelasi {
    adrRelasi first;
};

// CREATE
void createListRelasi(ListRelasi &L);

// NEW ELEMENT
adrRelasi newRelasi(adrKomposer P, adrMusik C);

// INSERT = 3
void insertFirstRelasi(ListRelasi &L, adrRelasi R);
void insertLastRelasi(ListRelasi &L, adrRelasi R);
void insertAfterRelasi(ListRelasi &L, adrRelasi Prec, adrRelasi R);

// DELETE = 3
void deleteFirstRelasi(ListRelasi &L, adrRelasi &R);
void deleteLastRelasi(ListRelasi &L, adrRelasi &R);
void deleteAfterRelasi(ListRelasi &L, adrRelasi Prec, adrRelasi &R);

// FIND
adrRelasi findRelasi(ListRelasi L, adrKomposer P, adrMusik C);

#endif
