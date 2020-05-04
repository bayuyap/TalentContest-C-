#include "list_juri.h"

#include<iostream>
using namespace std;
void createList(List_juri &L) {
    first(L) = NULL;
}


void createElemen(address_juri &P, string username, string password, string nama) {
    P = new elemen_juri;
    info(P).username = username;
    info(P).pass = password;
    info(P).nama = nama;

    prev(P) = NULL;
    next(P) = NULL;
}
address_juri findElemen(List_juri L, string x) {
    address_juri P = first(L);
    do {
        if (info(P).username == x) {
            return P;
        }
        P = next(P);
    } while (P != first(L));

    return NULL;
}
void update(List_juri L, address_juri &P, string user) {
    int x;
    P = findElemen(L,user);
    if (P!= NULL) {
        menu :
        cout << "Pilih data yang ingin diubah" <<endl;
        cout << "1. Username"<<endl;
        cout << "2. Password" <<endl;
        cout << "3. Nama" <<endl;

        cin >> x;

        if (x == 1) {
            string userbaru;
            cout << "Masukkan data baru :";
            cin >> userbaru;
            info(P).username = userbaru;

        } else if (x == 2) {
            string passbaru;
            cout << "Masukkan data baru :";
            cin >> passbaru;
            info(P).pass = passbaru;


        } else if (x == 3) {
            string namabaru;
            cout << "Masukkan data baru :";
            cin >> namabaru;
            info(P).nama = namabaru;

        } else {
            cout << "Input gagal" <<endl;
            goto menu;
        }

    }else {
        cout << "Maaf Username tidak ditemukan";
    }
}
void deleteFirst(List_juri &L, address_juri P) {
    P = first(L);
    first(L) = next(P);
    prev(first(L)) = prev(P);
    next(prev(P)) = first(L);
    next(P) = NULL;
    prev(P) = NULL;

}
void deleteAfter(List_juri &L, address_juri prec, address_juri P) {
    next(prec)= next(P);
    prev(next(P)) = prec;
    next(P) = NULL;
    prev(P) = NULL;
}
void deleteLast(List_juri &L, address_juri P) {
    P = prev(first(L));
    prev(first(L)) = prev(P);
    next(prev(first(L))) = first(L);
    next(P) = NULL;
    prev(P) = NULL;
}
void dealokasi(List_juri &L, string hapus) {
    address_juri P = findElemen(L, hapus);
    address_juri prec = prev(P);
    if (P == first(L)) {
        deleteFirst(L,P);
    } else if (P == prev(first(L))) {
        deleteLast(L,P);
    } else {
        deleteAfter(L, prec, P);
    }
}
void insertFirst(List_juri &L, address_juri P) {
    if (first(L) == NULL) {
        first(L) = P;
        next(first(L)) = P;
        prev(first(L)) = P;

    } else {
        prev(P) = prev(first(L));
        next(prev(first(L))) = P;
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertAfter(List_juri &L, address_juri P, address_juri prec) {
    prec = prev(P);
    prev(P) = prec;
    next(P) = next(prec);
    next(prec) = P;
    prev(next(P)) = P;
}
void insertLast(List_juri &L, address_juri P) {
        prev(P) = prev(first(L));
        next(P) = first(L);
        next(prev(first(L))) = P;
        prev(first(L)) = P;
}
void insertTerurut(List_juri &L, address_juri P) {
    address_juri last = prev(first(L));
    if (first(L) == NULL) {
        insertFirst(L,P);
    } else {
        if (info(P).username < info(first(L)).username){
            insertFirst(L,P);
        } else if (info(P).username > info(last).username) {
            insertLast(L,P);
        } else if(info(P).username > info(first(L)).username && info(P).username < info(last).username) {
            address_juri prec = first(L);
            while (info(prec).username < info(P).username) {
                prec = next(prec);
            }
            insertAfter(L,P,prec);
        }
    }

}
void lihat_infojuri(List_juri L) {
    cout << endl;
    address_juri P = first(L);
        do {
        cout << info(P).username<<endl;
        cout << info(P).pass<<endl;
        cout << info(P).nama<<endl;
        P = next(P);
    } while (P!= first(L));

    cout << endl;
}
