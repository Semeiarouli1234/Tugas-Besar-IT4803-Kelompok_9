#ifndef KOMPOSER_H
#define KOMPOSER_H

#include <iostream>
using namespace std;

struct elrelasi;     // forward declaration
typedef elrelasi *adrRelasi;

struct infotypeKomposer {
    string idKomposer;
    string nama;
};

typedef struct elkomposer *adrKomposer;

struct elkomposer {
    infotypeKomposer info;
    adrKomposer next;
    adrRelasi firstRelasi;   // pointer ke relasi
};

struct ListKomposer {
    adrKomposer first;
};

// KONSTRUKTOR
void createListKomposer(ListKomposer &L);
adrKomposer newKomposer(string id, string nama);

// INSERT
void insertFirstKomposer(ListKomposer &L, adrKomposer P);
void insertLastKomposer(ListKomposer &L, adrKomposer P);
void insertAfterKomposer(ListKomposer &L, adrKomposer Prec, adrKomposer P);

// DELETE
void deleteFirstKomposer(ListKomposer &L, adrKomposer &P);
void deleteLastKomposer(ListKomposer &L, adrKomposer &P);
void deleteAfterKomposer(ListKomposer &L, adrKomposer Prec, adrKomposer &P);

// SEARCH
adrKomposer findKomposer(ListKomposer L, string id);

// SHOW
void showAllKomposer(ListKomposer L);

#endif
