#include "main.h"

void menuUser(ListKomposer &LK, ListMusik &LM) {
    int opt = -1;
    while (opt != 0) {
        system("cls");
        cout << "=== MENU USER (STUDY CASE POIN G-S) ===" << endl;
        cout << "1. Cari Parent/Child/Relasi            " << endl;
        cout << "2. Lihat Musik dari Komposer Tertentu  " << endl;
        cout << "3. Lihat Semua Komposer & Musiknya     " << endl;
        cout << "4. Lihat Setiap Musik & Penciptanya    " << endl;
        cout << "5. Cari Komposer dari Musik Tertentu   " << endl;
        cout << "6. Hitung Relasi per Komposer          " << endl;
        cout << "7. Hitung Komposer per Musik           " << endl;
        cout << "8. Hitung Musik Tanpa Komposer         " << endl;
        cout << "9. Edit/Ganti Relasi Musik             " << endl;
        cout << "0. Kembali" << endl;
        cout << "---------------------------------------" << endl;
        cout << "Pilih: "; cin >> opt; clearBuffer();

        switch(opt) {
            case 1: {
                string id;
                cout << "Cari ID Komposer (Parent): "; getline(cin, id);
                adrKomposer P = findKomposer(LK, id);
                if (P) cout << "Ditemukan: " << P->info.nama << " (" << P->info.negaraAsal << ")" << endl;
                else cout << "Komposer tidak ditemukan." << endl;
                system("pause"); break;
            }
            case 2: {
                adrKomposer P = LK.first; int i = 1;
                if (!P) cout << "Data kosong." << endl;
                else {
                    while (P) { cout << i++ << ". " << P->info.nama << endl; P = P->next; }
                    int n; cout << "Pilih Nomor: "; cin >> n;
                    P = LK.first; for(int j=1; j<n && P; j++) P = P->next;
                    if (P) showMusikDariKomposer(P);
                }
                system("pause"); break;
            }
            case 3:
                showKomposerDanMusik(LK);
                system("pause"); break;
            case 4: {
                adrMusik M = LM.first;
                if (!M) cout << "Data musik kosong." << endl;
                while (M) {
                    cout << "Judul Musik: " << M->info.judul << endl;
                    showMusikDanKomposer(LK, M->info.idMusik);
                    cout << "-----------------------" << endl;
                    M = M->next;
                }
                system("pause"); break;
            }
            case 5: {
                adrMusik M = LM.first; int i = 1;
                while (M) { cout << i++ << ". " << M->info.judul << endl; M = M->next; }
                int n; cout << "Pilih Nomor Musik: "; cin >> n;
                M = LM.first; for(int j=1; j<n && M; j++) M = M->next;
                if (M) showMusikDanKomposer(LK, M->info.idMusik);
                system("pause"); break;
            }
            case 6: {
                adrKomposer P = LK.first;
                while (P) {
                    cout << P->info.nama << " memiliki " << countRelasiPerKomposer(P) << " musik." << endl;
                    P = P->next;
                }
                system("pause"); break;
            }
            case 7: {
                string id; cout << "Masukkan ID Musik: "; getline(cin, id);
                cout << "Musik ini dimiliki oleh " << countRelasiPerMusik(LK, id) << " komposer." << endl;
                system("pause"); break;
            }
            case 8:
                cout << "Jumlah musik yang belum memiliki relasi: " << countMusikTanpaRelasi(LM, LK) << endl;
                system("pause"); break;
            case 9: {
                string idK, idMLama, idMBaru;
                showAllKomposer(LK); cout << "ID Komposer: "; getline(cin, idK);
                adrKomposer K = findKomposer(LK, idK);
                if (K) {
                    showMusikDariKomposer(K);
                    cout << "ID Musik yang ingin diganti: "; getline(cin, idMLama);
                    showAllMusik(LM);
                    cout << "ID Musik pengganti: "; getline(cin, idMBaru);
                    editRelasiMusik(K, idMLama, findMusik(LM, idMBaru));
                }
                system("pause"); break;
            }
        }
    }
}
