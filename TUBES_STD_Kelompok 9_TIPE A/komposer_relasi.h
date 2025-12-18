#ifndef KOMPOSER_RELASI_H
#define KOMPOSER_RELASI_H

#include <iostream>
#include <string>
#include "musik.h"

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

void insertFirstKomposer(ListKomposer &L, adrKomposer P);
void insertRelasiLast(adrKomposer K, adrRelasi R);
void deleteAfterKomposer(adrKomposer Prec, adrKomposer &P);
adrRelasi findRelasi(adrKomposer K, string idMusik);
void showAllKomposer(ListKomposer L);
void showKomposerDanMusik(ListKomposer L);
int countRelasiPerKomposer(adrKomposer K);
int countRelasiPerMusik(ListKomposer L, string idMusik);
void editRelasiMusik(adrKomposer K, string idMusikLama, adrMusik MusikBaru);
void createListKomposer(ListKomposer &L);
adrKomposer newKomposer(InfoKomposer X);
adrRelasi allocateRelasi(adrMusik M);
void deleteRelasiAfter(adrKomposer K, adrRelasi Prec, adrRelasi &R);
void insertLastKomposer(ListKomposer &L, adrKomposer P);
void insertAfterKomposer(adrKomposer Prec, adrKomposer P);
adrKomposer findKomposer(ListKomposer L, string idKomposer);
void deleteFirstKomposer(ListKomposer &L, adrKomposer &P);
void deleteLastKomposer(ListKomposer &L, adrKomposer &P);
void showMusikDariKomposer(adrKomposer K);
void showMusikDanKomposer(ListKomposer L, string idMusik);
int countMusikTanpaRelasi(ListMusik LM, ListKomposer LK);

#endif
