#include "Musik.h"

// Insert Musik di akhir (Insert Last)
void insertLastMusic(int id,string judul,string genre,double durasi){
    Music* baru = new Music{id,judul,genre,durasi,nullptr,nullptr};

    if(headMusic==nullptr){
        headMusic = baru;
    } else {
        Music* cur = headMusic;
        while(cur->next != nullptr) cur = cur->next;
        cur->next = baru;
    }
}

// Insert After -> tambah musik setelah ID tertentu
void insertAfterMusic(int targetID,int id,string judul,string genre,double durasi){
    Music* cur = headMusic;
    while(cur != nullptr && cur->id != targetID) cur = cur->next;

    if(cur != nullptr){
        Music* baru = new Music{id,judul,genre,durasi,nullptr,nullptr};
        baru->next = cur->next;
        cur->next = baru;
    }
}

// Delete First
void deleteFirstMusic(){
    if(headMusic == nullptr) return;
    Music* del = headMusic;
    headMusic = headMusic->next;
    delete del;
}

// Delete Last
void deleteLastMusic(){
    if(headMusic == nullptr) return;

    if(headMusic->next == nullptr){
        delete headMusic;
        headMusic = nullptr;
        return;
    }

    Music* cur = headMusic;
    while(cur->next->next != nullptr) cur = cur->next;

    delete cur->next;
    cur->next = nullptr;
}

// View All Music
void viewAllMusic(){
    cout << "\n===== LIST MUSIK =====\n";
    Music* cur = headMusic;
    if(cur==nullptr){
        cout<<"(Kosong)\n";
        return;
    }

    while(cur!=nullptr){
        cout<<"ID: "<<cur->id<<" | Judul: "<<cur->judul<<" | Genre: "<<cur->genre<<" | Durasi: "<<cur->durasi<<" menit\n";
        cur = cur->next;
    }
}
