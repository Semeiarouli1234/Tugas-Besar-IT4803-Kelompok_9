#ifndef MUSIK_H
#define MUSIK_H

#include <iostream>
using namespace std;

struct InfoMusik {
    string idMusik;
    string judul;
    float durasi;
    int tahunRilis;
};

typedef struct NodeMusik *adrMusik;

struct NodeMusik {
    InfoMusik info;
    adrMusik prev;
    adrMusik next;
};

struct ListMusik {
    adrMusik first;
    adrMusik last;
};

void createListMusik(ListMusik &L);
adrMusik newMusik(InfoMusik X);

void insertFirstMusik(ListMusik &L, adrMusik P);
void insertLastMusik(ListMusik &L, adrMusik P);
void insertAfterMusik(ListMusik &L, adrMusik Prec, adrMusik P);

void deleteFirstMusik(ListMusik &L, adrMusik &P);
void deleteLastMusik(ListMusik &L, adrMusik &P);
void deleteAfterMusik(ListMusik &L, adrMusik Prec, adrMusik &P);

adrMusik findMusik(ListMusik L, string idMusik);
void showAllMusik(ListMusik L);

#endif
