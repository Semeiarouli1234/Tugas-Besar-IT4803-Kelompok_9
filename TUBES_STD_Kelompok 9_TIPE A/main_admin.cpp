#include "main.h"

void menuAdmin(ListKomposer &LK, ListMusik &LM) {
    int opt = -1;
    while (opt != 0) {
        system("cls");
        cout << "=== MENU ADMIN (POIN a-f, j, k) ===" << endl;
        cout << "1. Kelola Komposer (Parent)\n2. Kelola Musik (Child)\n0. Kembali\nPilih: ";
        cin >> opt; clearBuffer();
        if (opt == 1) menuParent(LK);
        else if (opt == 2) menuChild(LM, LK);
    }
}

void menuParent(ListKomposer &LK) {
    int opt = -1;
    while (opt != 0) {
        system("cls");
        cout << "=== MANAJEMEN KOMPOSER (PARENT) ===" << endl;
        cout << "1. Insert First\n2. Insert Last\n3. Insert After\n";
        cout << "4. Delete First\n5. Delete Last\n6. Delete After\n";
        cout << "7. Show All Parent\n0. Kembali\nPilih: ";
        cin >> opt; clearBuffer();

        if (opt >= 1 && opt <= 3) {
            if (opt == 3) {
                cout << "\n--- Senarai Komposer Semasa ---" << endl;
                showAllKomposer(LK);
            }
            InfoKomposer X;
            cout << "ID Baru: "; getline(cin, X.idKomposer);
            cout << "Nama: "; getline(cin, X.nama);
            cout << "Tahun Lahir: "; cin >> X.tahunLahir; clearBuffer();
            cout << "Negara: "; getline(cin, X.negaraAsal);
            adrKomposer P = newKomposer(X);

            if (opt == 1) insertFirstKomposer(LK, P);
            else if (opt == 2) insertLastKomposer(LK, P);
            else {
                string idPrec;
                cout << "Masukkan ID Komposer SEBELUM posisi baru: "; getline(cin, idPrec);
                adrKomposer Prec = findKomposer(LK, idPrec);
                if (Prec) insertAfterKomposer(Prec, P);
                else cout << "ID tidak dijumpai!" << endl;
            }
            system("pause");
        } else if (opt >= 4 && opt <= 6) {
            cout << "\n--- Senarai Komposer Semasa ---" << endl;
            showAllKomposer(LK);
            adrKomposer P = nullptr;
            if (opt == 4) deleteFirstKomposer(LK, P);
            else if (opt == 5) deleteLastKomposer(LK, P);
            else {
                string idPrec;
                cout << "Masukkan ID Komposer SEBELUM yang ingin dihapus: "; getline(cin, idPrec);
                adrKomposer Prec = findKomposer(LK, idPrec);
                if (Prec) deleteAfterKomposer(Prec, P);
            }
            if (P) cout << "Berhasil membuang: " << P->info.nama << endl;
            else cout << "Gagal membuang data." << endl;
            system("pause");
        } else if (opt == 7) {
            showAllKomposer(LK); system("pause");
        }
    }
}

void menuChild(ListMusik &LM, ListKomposer &LK) {
    int opt = -1;
    while (opt != 0) {
        system("cls");
        cout << "=== MANAJEMEN MUSIK (CHILD) ===" << endl;
        cout << "1. Insert First\n2. Insert Last\n3. Insert After\n";
        cout << "4. Delete First\n5. Delete Last\n6. Delete After\n";
        cout << "7. Insert Relation (c)\n8. Show All Musik\n0. Kembali\nPilih: ";
        cin >> opt; clearBuffer();

        if (opt >= 1 && opt <= 3) {
            if (opt == 3) {
                cout << "\n--- Senarai Musik Semasa ---" << endl;
                showAllMusik(LM);
            }
            InfoMusik X;
            cout << "ID Baru: "; getline(cin, X.idMusik);
            cout << "Judul: "; getline(cin, X.judul);
            cout << "Durasi: "; cin >> X.durasi;
            cout << "Tahun: "; cin >> X.tahunRilis; clearBuffer();
            adrMusik P = newMusik(X);

            if (opt == 1) insertFirstMusik(LM, P);
            else if (opt == 2) insertLastMusik(LM, P);
            else {
                string idPrec;
                cout << "Masukkan ID Musik SEBELUM posisi baru: "; getline(cin, idPrec);
                adrMusik Prec = findMusik(LM, idPrec);
                if (Prec) insertAfterMusik(LM, Prec, P);
                else cout << "ID tidak dijumpai!" << endl;
            }
            system("pause");
        } else if (opt >= 4 && opt <= 6) {
            cout << "\n--- Senarai Musik Semasa ---" << endl;
            showAllMusik(LM);
            adrMusik P = nullptr;
            if (opt == 4) deleteFirstMusik(LM, P);
            else if (opt == 5) deleteLastMusik(LM, P);
            else {
                string idPrec;
                cout << "Masukkan ID Musik SEBELUM yang ingin dihapus: "; getline(cin, idPrec);
                adrMusik Prec = findMusik(LM, idPrec);
                if (Prec) deleteAfterMusik(LM, Prec, P);
            }
            if (P) cout << "Berhasil membuang: " << P->info.judul << endl;
            else cout << "Gagal membuang data." << endl;
            system("pause");
        } else if (opt == 7) {
            string idK, idM;
            cout << "ID Parent: "; getline(cin, idK);
            cout << "ID Child: "; getline(cin, idM);
            adrKomposer K = findKomposer(LK, idK);
            adrMusik M = findMusik(LM, idM);
            if (K && M) insertRelasiLast(K, allocateRelasi(M));
            else cout << "Gagal menghubungkan relasi." << endl;
            system("pause");
        } else if (opt == 8) {
            showAllMusik(LM); system("pause");
        }
    }
}
