#include "list_relasi.h"
#include<iostream>
using namespace std;
bool isEmpty(List_relasi L){
    bool cek;
    if (first(L)==NULL){
        cek = true;
    } else {
        cek = false;
    }
    return cek;

}

void createList(List_relasi &L) {
    first(L) = NULL;
}

void createElemenRelasi(address_relasi &Q , address_parent P , address_child C) {
    Q = new elmlist_relasi;
    child(Q) = C;
    parent(Q) = P;
    next(Q) = NULL;
}

void insertFirst(List_relasi &L, address_relasi P){
    if (isEmpty(L)){
        first(L) = P;
        next(P) = P;
    }
    else{
        address_relasi Q = first(L);
        while(next(Q) != first(L)){
            Q = next(Q);
        }
        next(Q) = P;
        next(P) = first(L);
        first(L) = P;
    }
}
void insertAfter(address_relasi Prec, address_relasi P){
    next(P) = next(Prec);
    next(Prec) = P;
}

void printInfo(List_relasi L) {
    address_relasi P = first(L);
    while(P != first(L)) {
        cout<<infoP(parent(P))<<"->"<<info(child(P))<<endl;
        P = next(P);
    }
}


address_relasi findElm(List_relasi L, infotype_parent x ) {
    address_relasi Q = first(L);
    while(Q != NULL) {
        if(infoP(parent(Q)) == x) {
            return Q;
        }
        Q = next(Q);
    }
    return NULL;
}

void insertLast(List_relasi &L, address_relasi P){
    if (isEmpty(L)) {
        first(L) = P;
        next(P) = P;
    }
    else{
        address_relasi last = first(L);
        while (next(last) != first(L)){
            last = next(last);
        }
        next(last) = P;
        next(P) = first(L);
    }
}

void isiNilai(List_relasi L, address_relasi &P, infotype_parent x){

    P = findElm(L, x);
    if(P != NULL){
        if(info(child(P)) == 0){
            int nilai;
            cout << "Masukkan Nilai = ";
            cin >> nilai;
            info(child(P)) = nilai;
        }
        else if(info(child(P)) != 0){
            int nilailama;
            int nilaibaru;
            nilailama = info(child(P));
            cout << "Masukkan Nilai = ";
            cin >> nilaibaru;
            info(child(P)) = nilailama + nilaibaru;
        }

    }
    else{
        cout << "Peserta Tidak Ditemukan ";
    }
}
void deleteNilai(List_relasi L, address_relasi &P, infotype_parent x){
    P = findElm(L, x);
    if(P != NULL){
        info(child(P)) = 0;
        cout << "Nilai Dihapus ";
    }
    else{
        cout << "Peserta Tidak Ditemukan ";
    }
}

void update_nilai (List_relasi L, address_relasi &P, infotype_parent x){
    P = findElm(L, x);
    if (P != NULL) {
        int nilaibaru;
        cout << "Masukkan Nilai baru = ";
        cin >> nilaibaru;
        info(child(P)) = nilaibaru;
    } else {
        cout << "Nama peserta salah";
    }
}
