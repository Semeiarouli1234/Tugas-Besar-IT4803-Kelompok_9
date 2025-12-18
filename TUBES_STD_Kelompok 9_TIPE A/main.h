#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <iostream>
#include <string>
#include <cstdlib>
#include "komposer_relasi.h"
#include "musik.h"

using namespace std;

void clearBuffer();
void inputDummyData(ListKomposer &LK, ListMusik &LM);

void menuAdmin(ListKomposer &LK, ListMusik &LM);
void menuParent(ListKomposer &LK);
void menuChild(ListMusik &LM, ListKomposer &LK);

void menuUser(ListKomposer &LK, ListMusik &LM);

#endif
