#ifndef KOMPOSER_H
#define KOMPOSER_H

#include <string>
using namespace std;

struct Komposer {
    string nama;
};

typedef struct elkomposer *adrKomposer;
struct elkomposer {
    Komposer info;
    adrKomposer next;
};

struct ListKomposer {
    adrKomposer first;
};

void createListKomposer(ListKomposer &L);
adrKomposer newKomposer(string nama);

// INSERT = 3
void insertFirstKomposer(ListKomposer &L, adrKomposer P);
void insertLastKomposer(ListKomposer &L, adrKomposer P);
void insertAfterKomposer(ListKomposer &L, adrKomposer Prec, adrKomposer P);

// DELETE = 3
void deleteFirstKomposer(ListKomposer &L, adrKomposer &P);
void deleteLastKomposer(ListKomposer &L, adrKomposer &P);
void deleteAfterKomposer(ListKomposer &L, adrKomposer Prec, adrKomposer &P);

// FIND
adrKomposer findKomposer(ListKomposer L, string nama);

// SHOW
void showAllKomposer(ListKomposer L);

#endif
