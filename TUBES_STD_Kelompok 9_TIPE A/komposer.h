#ifndef KOMPOSER_H
#define KOMPOSER_H

#include <iostream>
using namespace std;

typedef struct elmKomposer *addressK;

struct elmKomposer {
    string info;         // data komposer (nama / id)
    addressK next;       // pointer ke elemen berikutnya
};

struct ListKomposer {
    addressK first;
};


void createListKomposer(ListKomposer &L);
addressK alokasiKomposer(string x);
void dealokasiKomposer(addressK P);
void insertFirstKomposer(ListKomposer &L, addressK P);
void insertLastKomposer(ListKomposer &L, addressK P);
void insertAfterKomposer(addressK Prec, addressK P);
void deleteFirstKomposer(ListKomposer &L, addressK &P);
void deleteLastKomposer(ListKomposer &L, addressK &P);
void deleteAfterKomposer(addressK Prec, addressK &P);
addressK findElmKomposer(ListKomposer L, string x);
void printInfoKomposer(ListKomposer L);

#endif
