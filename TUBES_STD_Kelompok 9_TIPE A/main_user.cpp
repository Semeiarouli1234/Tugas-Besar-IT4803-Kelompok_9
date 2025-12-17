#include "main.h"
#include <limits>

void menuUser() {
    int option;
    do {
        system("cls"); // Windows, ganti "clear" untuk Linux
        cout << "====== Menu User ======" << endl;
        cout << "|| 1. Lihat Semua Musik     ||" << endl;
        cout << "|| 2. Lihat Semua Komposer  ||" << endl;
        cout << "|| 3. Lihat Musik Komposer  ||" << endl;
        cout << "|| 0. back                  ||" << endl;
        cout << "==============================" << endl;
        cout << "Choose your option : ";
        cin >> option;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch(option) {
            case 1:
                cout << "=== Semua Musik ===\n";
                showAllMusik(LM);
                cout << "Press Enter to continue...";
                cin.get();
                break;
            case 2:
                cout << "=== Semua Komposer ===\n";
                showAllKomposer(LK);
                cout << "Press Enter to continue...";
                cin.get();
                break;
            case 3: {
                string idKomp;
                cout << "ID Komposer: "; getline(cin, idKomp);
                adrKomposer K = findKomposer(LK, idKomp);
                if(K != nullptr) {
                    cout << "=== Musik dari Komposer " << K->info.nama << " ===\n";
                    showMusikDariKomposer(K);
                } else {
                    cout << "Komposer tidak ditemukan.\n";
                }
                cout << "Press Enter to continue...";
                cin.get();
                break;
            }
            case 0:
                cout << "Kembali ke menu utama...\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
                cout << "Press Enter to continue...";
                cin.get();
                break;
        }
    } while(option != 0);
}

// dummy data realistis
void buatDummyData() {
    // Musik
    InfoMusik m1 = {"M001", "Shape of You", 4.24, 2017};
    InfoMusik m2 = {"M002", "Perfect", 4.23, 2017};
    InfoMusik m3 = {"M003", "Star Wars Theme", 5.0, 1977};
    InfoMusik m4 = {"M004", "Time", 4.35, 2010};
    InfoMusik m5 = {"M005", "Photograph", 4.19, 2015};
    insertLastMusik(LM, newMusik(m1));
    insertLastMusik(LM, newMusik(m2));
    insertLastMusik(LM, newMusik(m3));
    insertLastMusik(LM, newMusik(m4));
    insertLastMusik(LM, newMusik(m5));

    // Komposer
    InfoKomposer k1 = {"K001", "Ed Sheeran", 1991, "UK"};
    InfoKomposer k2 = {"K002", "John Williams", 1932, "USA"};
    InfoKomposer k3 = {"K003", "Hans Zimmer", 1957, "Germany"};
    adrKomposer pk1 = newKomposer(k1);
    adrKomposer pk2 = newKomposer(k2);
    adrKomposer pk3 = newKomposer(k3);
    insertLastKomposer(LK, pk1);
    insertLastKomposer(LK, pk2);
    insertLastKomposer(LK, pk3);

    // Relasi musik-komposer
    addRelasiLast(pk1, findMusik(LM, "M001")); // Shape of You -> Ed Sheeran
    addRelasiLast(pk1, findMusik(LM, "M002")); // Perfect -> Ed Sheeran
    addRelasiLast(pk1, findMusik(LM, "M005")); // Photograph -> Ed Sheeran
    addRelasiLast(pk2, findMusik(LM, "M003")); // Star Wars Theme -> John Williams
    addRelasiLast(pk3, findMusik(LM, "M004")); // Time -> Hans Zimmer
}
