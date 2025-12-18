#include "main.h"

void clearBuffer() {
    cin.clear();
    cin.ignore(1000, '\n');
}

void inputDummyData(ListKomposer &LK, ListMusik &LM) {
    createListKomposer(LK);
    createListMusik(LM);

    insertLastMusik(LM, newMusik({"M01", "Bohemian Rhapsody", 5.55f, 1975}));
    insertLastMusik(LM, newMusik({"M02", "Gajah", 4.00f, 2014}));
    insertLastMusik(LM, newMusik({"M03", "Rayuan Pulau Kelapa", 4.15f, 1944}));
    insertLastMusik(LM, newMusik({"M04", "Interaksi", 3.50f, 2022}));

    insertLastKomposer(LK, newKomposer({"K01", "Freddie Mercury", 1946, "Zanzibar"}));
    insertLastKomposer(LK, newKomposer({"K02", "Tulus", 1987, "Indonesia"}));
    insertLastKomposer(LK, newKomposer({"K03", "Ismail Marzuki", 1914, "Indonesia"}));

    adrKomposer K1 = findKomposer(LK, "K01");
    adrKomposer K2 = findKomposer(LK, "K02");
    adrKomposer K3 = findKomposer(LK, "K03");

    if (K1) insertRelasiLast(K1, allocateRelasi(findMusik(LM, "M01")));
    if (K2) {
        insertRelasiLast(K2, allocateRelasi(findMusik(LM, "M02")));
        insertRelasiLast(K2, allocateRelasi(findMusik(LM, "M04")));
    }
    if (K3) insertRelasiLast(K3, allocateRelasi(findMusik(LM, "M03")));
}

int main() {
    ListKomposer LK;
    ListMusik LM;
    inputDummyData(LK, LM);

    int option = -1;
    while (option != 0) {
        system("cls");
        cout << "===========================================" << endl;
        cout << "    PROGRAM MANAJEMEN KOMPOSER & MUSIK     " << endl;
        cout << "===========================================" << endl;
        cout << "1. Menu Admin                              " << endl;
        cout << "2. Menu User                               " << endl;
        cout << "0. Keluar" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "Pilih: ";

        if (!(cin >> option)) {
            clearBuffer();
            continue;
        }

        switch(option) {
            case 1:
                menuAdmin(LK, LM);
                break;
            case 2:
                menuUser(LK, LM);
                break;
            case 0:
                cout << "\nProgram selesai." << endl;
                break;
            default:
                cout << "\nPilihan tidak valid!" << endl;
                system("pause");
                break;
        }
    }
    return 0;
}
