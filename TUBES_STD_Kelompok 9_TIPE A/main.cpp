#include "main.h"
#include <iostream>
using namespace std;

// definisi global list
ListMusik LM;
ListKomposer LK;

int main() {
    // inisialisasi list
    createListMusik(LM);
    createListKomposer(LK);

    // buat dummy data
    buatDummyData();

    int option;
    do {
        cout << "\n====== Menu Utama ======" << endl;
        cout << "|| 1. Admin Menu       ||" << endl;
        cout << "|| 2. User Menu        ||" << endl;
        cout << "|| 0. Exit             ||" << endl;
        cout << "=======================" << endl;
        cout << "Choose your option : ";
        cin >> option;
        cin.ignore(); // hapus \n yang tersisa di buffer

        switch(option) {
            case 1:
                menuAdmin();
                break;
            case 2:
                menuUser();
                break;
            case 0:
                cout << "Terima kasih, program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
                cout << "Press Enter untuk melanjutkan...";
                cin.get();
                break;
        }
    } while(option != 0);

    return 0;
}
