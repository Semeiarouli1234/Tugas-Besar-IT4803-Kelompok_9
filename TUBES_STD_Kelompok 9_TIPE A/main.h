#ifndef MAIN_H
#define MAIN_H

#include "musik.h"
#include "komposer_relasi.h"
#include <iostream>
using namespace std;

// deklarasi saja, tidak definisi
extern ListMusik LM;
extern ListKomposer LK;

// fungsi menu
void menuUser();
void menuAdmin();
void buatDummyData();

#endif
