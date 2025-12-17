#include "main.h"
#include <limits>

void menuAdmin() {
    int option;
    do {
        system("cls"); // Windows, ganti "clear" di Linux/macOS
        cout << "====== Menu Admin ======" << endl;
        cout << "|| 1. Tambah Musik       ||" << endl;
        cout << "|| 2. Hapus Musik        ||" << endl;
        cout << "|| 3. Lihat Semua Musik  ||" << endl;
        cout << "|| 4. Tambah Komposer    ||" << endl;
        cout << "|| 5. Lihat Semua Komposer||" << endl;
        cout << "|| 0. back               ||" << endl;
        cout << "========================" << endl;
        cout << "Choose your option : ";
        cin >> option;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch(option) {
            case 1: { // Tambah Musik
                InfoMusik X;
                cout << "ID Musik: "; getline(cin, X.idMusik);
                cout << "Judul: "; getline(cin, X.judul);
                cout << "Durasi (menit): "; cin >> X.durasi;
                cout << "Tahun Rilis: "; cin >> X.tahunRilis;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                insertLastMusik(LM, newMusik(X));
                cout << "Musik berhasil ditambahkan.\n";
                cout << "Press Enter to continue...";
                cin.get();
                break;
            }
            case 2: { // Hapus Musik
                string id;
                cout << "ID Musik yang dihapus: "; getline(cin, id);
                adrMusik P = findMusik(LM, id);
                if(P != nullptr) {
                    // cek posisi musik
                    if(P == LM.first) {
                        deleteFirstMusik(LM, P);
                    } else if(P == LM.last) {
                        deleteLastMusik(LM, P);
                    } else {
                        adrMusik prec = LM.first;
                        while(prec != nullptr && prec->next != P) {
                            prec = prec->next;
                        }
                        if(prec != nullptr)
                            deleteAfterMusik(LM, prec, P);
                    }
                    cout << "Musik berhasil dihapus.\n";
                } else {
                    cout << "Musik tidak ditemukan.\n";
                }
                cout << "Press Enter to continue...";
                cin.get();
                break;
            }
            case 3: // Lihat Semua Musik
                cout << "=== Semua Musik ===\n";
                showAllMusik(LM);
                cout << "Press Enter to continue...";
                cin.get();
                break;
            case 4: { // Tambah Komposer
                InfoKomposer K;
                cout << "ID Komposer: "; getline(cin, K.idKomposer);
                cout << "Nama: "; getline(cin, K.nama);
                cout << "Tahun Lahir: "; cin >> K.tahunLahir;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Negara Asal: "; getline(cin, K.negaraAsal);
                insertLastKomposer(LK, newKomposer(K));
                cout << "Komposer berhasil ditambahkan.\n";
                cout << "Press Enter to continue...";
                cin.get();
                break;
            }
            case 5: // Lihat Semua Komposer
                cout << "=== Semua Komposer ===\n";
                showAllKomposer(LK);
                cout << "Press Enter to continue...";
                cin.get();
                break;
            case 0:
                cout << "Kembali ke menu utama...\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
                cout << "Press Enter untuk melanjutkan...";
                cin.get();
                break;
        }
    } while(option != 0);
}
