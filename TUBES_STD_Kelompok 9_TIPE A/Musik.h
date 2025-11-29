#ifndef MUSIK_H
#define MUSIK_H

#include <string>
using namespace std;

struct Musik {
    string judul;
};

typedef struct elmusik *adrMusik;
struct elmusik {
    Musik info;
    adrMusik next;
};

struct ListMusik {
    adrMusik first;
};

// CREATE
void createListMusik(ListMusik &L);

// NEW ELEMENT
adrMusik newMusik(string judul);

// INSERT = 3
void insertFirstMusik(ListMusik &L, adrMusik P);
void insertLastMusik(ListMusik &L, adrMusik P);
void insertAfterMusik(ListMusik &L, adrMusik Prec, adrMusik P);

// DELETE = 3
void deleteFirstMusik(ListMusik &L, adrMusik &P);
void deleteLastMusik(ListMusik &L, adrMusik &P);
void deleteAfterMusik(ListMusik &L, adrMusik Prec, adrMusik &P);

// FIND
adrMusik findMusik(ListMusik L, string judul);

// SHOW
void showAllMusik(ListMusik L);

#endif
