#ifndef KOMPOSER_RELASI_H
#define KOMPOSER_RELASI_H

#include <iostream>
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

void createListKomposer(ListKomposer &L);
adrKomposer newKomposer(InfoKomposer X);

void insertFirstKomposer(ListKomposer &L, adrKomposer P);
void insertLastKomposer(ListKomposer &L, adrKomposer P);
void insertAfterKomposer(ListKomposer &L, adrKomposer Prec, adrKomposer P);

void deleteFirstKomposer(ListKomposer &L, adrKomposer &P);
void deleteLastKomposer(ListKomposer &L, adrKomposer &P);
void deleteAfterKomposer(ListKomposer &L, adrKomposer Prec, adrKomposer &P);

adrKomposer findKomposer(ListKomposer L, string idKomposer);

adrRelasi newRelasi(adrMusik M);
void addRelasiLast(adrKomposer K, adrMusik M);
void deleteRelasiAfter(adrKomposer K, string idMusik);
bool isRelasiExist(adrKomposer K, string idMusik);

void showAllKomposer(ListKomposer L);
void showMusikDariKomposer(adrKomposer K);
void showKomposerDariMusik(ListKomposer L, string idMusik);

int countMusikKomposer(adrKomposer K);
int countKomposerMusik(ListKomposer L, string idMusik);
int countMusikTanpaKomposer(ListMusik LM, ListKomposer LK);
int countKomposerTanpaMusik(ListKomposer L);

void editRelasiMusik(adrKomposer K, string idMusikLama, adrMusik MusikBaru);

#endif
