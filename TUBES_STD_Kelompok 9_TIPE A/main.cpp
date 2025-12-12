#include <iostream>
#include "komposer_relasi.h"
#include "Musik.h"

using namespace std;

void menu(ListKomposer &LKomposer, ListMusik &LMusik) {
    int pilihan;
    string idKomposer, idMusik;
    adrKomposer komposer;
    adrMusik musik;

    do {
        cout << "\n--- Menu ---" << endl;
        cout << "1. Tambah Komposer" << endl;
        cout << "2. Tambah Musik" << endl;
        cout << "3. Tambah Relasi Komposer dan Musik" << endl;
        cout << "4. Tampilkan Semua Komposer" << endl;
        cout << "5. Tampilkan Semua Musik" << endl;
        cout << "6. Hapus Komposer" << endl;
        cout << "7. Hapus Musik" << endl;
        cout << "8. Hapus Relasi Komposer dan Musik" << endl;
        cout << "9. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            {
                // Menambah Komposer
                InfoKomposer infoKomposer;
                cout << "Masukkan ID Komposer: ";
                cin >> infoKomposer.idKomposer;
                cout << "Masukkan Nama Komposer: ";
                cin >> infoKomposer.nama;
                cout << "Masukkan Tahun Lahir: ";
                cin >> infoKomposer.tahunLahir;
                cout << "Masukkan Negara Asal: ";
                cin >> infoKomposer.negaraAsal;

                adrKomposer newK = newKomposer(infoKomposer);
                insertLastKomposer(LKomposer, newK);
                break;
            }
        case 2:
            {
                // Menambah Musik
                InfoMusik infoMusik;
                cout << "Masukkan ID Musik: ";
                cin >> infoMusik.idMusik;
                cout << "Masukkan Judul Musik: ";
                cin >> infoMusik.judul;
                cout << "Masukkan Durasi Musik: ";
                cin >> infoMusik.durasi;
                cout << "Masukkan Tahun Rilis: ";
                cin >> infoMusik.tahunRilis;

                adrMusik newM = newMusik(infoMusik);
                insertLastMusik(LMusik, newM);
                break;
            }
        case 3:
            {
                // Menambah Relasi antara Komposer dan Musik
                cout << "Masukkan ID Komposer: ";
                cin >> idKomposer;
                komposer = findKomposer(LKomposer, idKomposer);

                if (komposer != nullptr) {
                    cout << "Masukkan ID Musik: ";
                    cin >> idMusik;
                    musik = findMusik(LMusik, idMusik);

                    if (musik != nullptr) {
                        adrRelasi relasi = newRelasi(musik);
                        addRelasi(komposer, musik);
                        cout << "Relasi antara Komposer " << komposer->info.nama << " dan Musik " << musik->info.judul << " berhasil ditambahkan!" << endl;
                    } else {
                        cout << "Musik tidak ditemukan!" << endl;
                    }
                } else {
                    cout << "Komposer tidak ditemukan!" << endl;
                }
                break;
            }
        case 4:
            // Tampilkan semua komposer
            showAllKomposer(LKomposer);
            break;
        case 5:
            // Tampilkan semua musik
            showAllMusik(LMusik);
            break;
        case 6:
            {
                // Hapus Komposer
                cout << "Masukkan ID Komposer yang ingin dihapus: ";
                cin >> idKomposer;
                komposer = findKomposer(LKomposer, idKomposer);

                if (komposer != nullptr) {
                    deleteFirstKomposer(LKomposer, komposer);
                    cout << "Komposer " << komposer->info.nama << " berhasil dihapus!" << endl;
                } else {
                    cout << "Komposer tidak ditemukan!" << endl;
                }
                break;
            }
        case 7:
            {
                // Hapus Musik
                cout << "Masukkan ID Musik yang ingin dihapus: ";
                cin >> idMusik;
                musik = findMusik(LMusik, idMusik);

                if (musik != nullptr) {
                    deleteFirstMusik(LMusik, musik);
                    cout << "Musik " << musik->info.judul << " berhasil dihapus!" << endl;
                } else {
                    cout << "Musik tidak ditemukan!" << endl;
                }
                break;
            }
        case 8:
            {
                // Hapus Relasi Komposer dan Musik
                cout << "Masukkan ID Komposer: ";
                cin >> idKomposer;
                komposer = findKomposer(LKomposer, idKomposer);

                if (komposer != nullptr) {
                    cout << "Masukkan ID Musik yang ingin dihapus dari relasi: ";
                    cin >> idMusik;
                    deleteRelasi(komposer, idMusik);
                    cout << "Relasi antara Komposer dan Musik berhasil dihapus!" << endl;
                } else {
                    cout << "Komposer tidak ditemukan!" << endl;
                }
                break;
            }
        case 9:
            cout << "Keluar dari program." << endl;
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
        }

    } while (pilihan != 9);
}

int main() {
    ListKomposer LKomposer;
    ListMusik LMusik;

    createListKomposer(LKomposer);
    createListMusik(LMusik);

    menu(LKomposer, LMusik);

    return 0;
}
