#ifndef MUSIK_H
#define MUSIK_H

#include <iostream>
using namespace std;

struct infotypeMusik {
    string idMusik;
    string judul;
};

typedef struct elmusi *adrMusik;

struct elmusi {
    infotypeMusik info;
    adrMusik next;
    adrMusik prev;
};

struct ListMusik {
    adrMusik first;
    adrMusik last;
};

// KONSTRUKTOR
void createListMusik(ListMusik &L);
adrMusik newMusik(string id, string judul);

// INSERT
void insertFirstMusik(ListMusik &L, adrMusik P);
void insertLastMusik(ListMusik &L, adrMusik P);
void insertAfterMusik(ListMusik &L, adrMusik Prec, adrMusik P);

// DELETE
void deleteFirstMusik(ListMusik &L, adrMusik &P);
void deleteLastMusik(ListMusik &L, adrMusik &P);
void deleteAfterMusik(ListMusik &L, adrMusik Prec, adrMusik &P);

// SEARCH
adrMusik findMusik(ListMusik L, string id);

// SHOW
void showAllMusik(ListMusik L);

#endif
