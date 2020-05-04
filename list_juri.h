#ifndef LIST_JURI_H_INCLUDED
#define LIST_JURI_H_INCLUDED
#include <iostream>
using namespace std;
#define next(P) P -> next
#define prev(P) P -> prev
#define info(P) P -> info
#define first(L) L.first

struct Data_Juri {
    string nama;
    string username, pass;
};
typedef struct elemen_juri *address_juri;

struct elemen_juri {
    Data_Juri info;
    address_juri next;
    address_juri prev;
};

struct List_juri {
    address_juri first;
};

void createList(List_juri &L);
void createElemen(address_juri &P, string username, string password, string nama);
address_juri findElemen(List_juri L, string x);//cari sesuai username
void update(List_juri L, address_juri &P, string user);
void deleteFirst(List_juri &L, address_juri P);
void deleteAfter(List_juri &L, address_juri P);
void deleteLast(List_juri &L, address_juri P);
void dealokasi(List_juri &L, string hapus);//cari sesuai username
void insertFirst(List_juri &L, address_juri P);
void insertAfter(List_juri &L, address_juri P,address_juri prec);
void insertLast(List_juri &L, address_juri P);
void insertTerurut(List_juri &L, address_juri P);
void lihat_infojuri(List_juri L);

#endif // LIST_JURI_H_INCLUDED
