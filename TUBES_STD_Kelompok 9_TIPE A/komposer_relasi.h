#ifndef KOMPOSER_RELASI_H
#define KOMPOSER_RELASI_H

#include <iostream>
#include "Musik.h"

using namespace std;

struct InfoKomposer {
    string idKomposer;
    string nama;
    int tahunLahir;
    string negaraAsal;
};

typedef struct NodeKomposer *adrKomposer;
typedef struct NodeRelasi *adrRelasi;

struct NodeRelasi {
    adrMusik musik;
    adrRelasi nextRelasi;
};

struct NodeKomposer {
    InfoKomposer info;
    adrKomposer next;
    adrRelasi firstRelasi;
};

struct ListKomposer {
    adrKomposer first;
};

void createListKomposer(ListKomposer &L);
adrKomposer newKomposer(InfoKomposer X);
void insertFirstKomposer(ListKomposer &L, adrKomposer P);
void insertLastKomposer(ListKomposer &L, adrKomposer P);
void insertAfterKomposer(ListKomposer &L, adrKomposer Prec, adrKomposer P);
adrKomposer findKomposer(ListKomposer L, string idKomposer);
void deleteFirstKomposer(ListKomposer &L, adrKomposer &P);
void deleteLastKomposer(ListKomposer &L, adrKomposer &P);
void deleteAfterKomposer(ListKomposer &L, adrKomposer Prec, adrKomposer &P);
void showAllKomposer(ListKomposer L);

adrRelasi newRelasi(adrMusik M);
void addRelasi(adrKomposer K, adrMusik M);
void deleteRelasi(adrKomposer K, string idMusik);

#endif
