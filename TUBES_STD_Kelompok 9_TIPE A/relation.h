#ifndef RELASI_H
#define RELASI_H

#include <iostream>
#include <string>

typedef struct NodeMusik *adrMusik;
typedef struct NodeKomposer *adrKomposer;
typedef struct ListMusik ListMusik;
typedef struct ListKomposer ListKomposer;

using namespace std;

typedef struct NodeRelasi *adrRelasi;
struct NodeRelasi {
    adrMusik toMusik;
    adrRelasi prev;
    adrRelasi next;
};

adrRelasi newRelasi(adrMusik P_musik);

void insertRelasiFirst(adrKomposer P_komposer, adrRelasi P_relasi);
void insertRelasiLast(adrKomposer P_komposer, adrRelasi P_relasi);
void insertRelasiAfter(adrKomposer P_komposer, adrRelasi Prec, adrRelasi P_relasi);

void deleteRelasiFirst(adrKomposer P_komposer, adrRelasi &P_relasi_deleted);
void deleteRelasiLast(adrKomposer P_komposer, adrRelasi &P_relasi_deleted);
void deleteRelasiAfter(adrKomposer P_komposer, adrRelasi Prec, adrRelasi &P_relasi_deleted);
void deleteRelasiByMusik(adrKomposer P_komposer, adrMusik P_musik, adrRelasi &P_relasi_deleted);

adrRelasi findRelasi(adrKomposer P_komposer, adrMusik P_musik);

void showChildOfParent(adrKomposer P_komposer);
void showParentsOfChild(ListKomposer L_komposer, adrMusik P_musik);
void showAllParentAndChild(ListKomposer L_komposer);
void showAllChildAndParent(ListKomposer L_komposer, ListMusik L_musik);

int countRelationOfParent(adrKomposer P_komposer);
int countRelationOfChild(ListKomposer L_komposer, adrMusik P_musik);
int countChildWithoutParent(ListMusik L_musik, ListKomposer L_komposer);

void editRelasi(adrKomposer P_komposer, adrMusik P_musik_lama, adrMusik P_musik_baru);

#endif // RELASI_H
