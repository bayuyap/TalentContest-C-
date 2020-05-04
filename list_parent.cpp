#include "list_parent.h"
#include <iostream>
using namespace std;

void createList(List_parent &L) {
    first(L) = NULL;
    last(L) = NULL;
}
bool isEmpty(List_parent L){
    bool kosong;
    if(first(L) == NULL && last(L) == NULL){
        kosong = true;
    }
    else{
        kosong = false;
    }
    return kosong;
}
void createElemenParent(address_parent &P, infotype_parent x) {
    P = new elmlist_parent;
    infoP(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
}


void printInfo(List_parent L) {
    address_parent P = first(L);
    while(P !=NULL) {
        cout<<"->"<<infoP(P)<<endl;
        P = next(P);
    }
}


address_parent findElm(List_parent L, infotype_parent x) {
    address_parent P = first(L);
    while(P != NULL) {
        if(infoP(P)==x) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void update_data(List_parent L, address_parent &P, infotype_parent nama){

    P = findElm(L, nama);
    if(P != NULL){
        cout << infoP(P);
        infotype_parent databaru;
        cout << "Masukkan Data Baru : ";
        cin >> databaru;
        infoP(P) = databaru;
    }
    else{
        cout << "Data Tidak Ditemukan";
    }

   /* string pilihan;
    P = findElm(L, nama);
    menu :
        cout << "Update Data ? (Y/N)" ;
        cin >> pilihan;
    if (pilihan == "Y || y"){
        string namabaru;
        cout << "Masukkan data baru :";
        cin >> namabaru;
        infoP(P) = namabaru;
    }
    else{
        goto awal;
    }
        SEMENTARA DISINI NANTI DI Taruh Di MAIN */
}
void insertLast(List_parent &L, address_parent P){
    if(isEmpty(L) == true){
        first(L) = P;
        last(L) = P;
    }
    else{
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }
}
void insertAfter(address_parent Prec, address_parent P){
   List_parent L;
   if(isEmpty(L) == true){
        cout << "List Kosong";
   }
   if(next(Prec) == NULL){
        prev(P) = Prec;
        next(Prec) = P;
        last(L) = P;
   }
   else{
        next(P) = next(Prec);
        next(Prec) = P;
        prev(next(P)) = P;
        prev(P) = Prec;
   }

}

void dealokasi_peserta(List_parent &L, infotype_parent x) {
    address_parent P = findElm(L, x);
    address_parent prec = prev(P);
    if (P == NULL) {
        cout << "Tidak ada peserta";
    }else {
        if (P == first(L)) {
            deleteFirst(L,P);
        } else if (P == prev(first(L))) {
            deleteLast(L,P);
        } else {
            deleteAfter(P,prec);
        }
        cout << "Peserta berhasil dihapus";
    }
}
void deleteFirst(List_parent &L, address_parent &P){
    if(isEmpty(L) == true){
        first(L) = NULL;
        last(L) = NULL;
    }
    else{
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
        prev(first(L)) = NULL;
    }
}
void deleteLast(List_parent &L, address_parent &P){
    P = last(L);
    last(L) = prev(P);
    prev(P) = NULL;
    next(last(L)) = NULL;
}
void deleteAfter(address_parent Prec, address_parent &P){
    P = next(Prec);
    next(Prec) = next(P);
    prev(next(P)) = Prec;
    next(P) = NULL;
    prev(P) = NULL;
}




