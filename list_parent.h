#ifndef LIST_PARENT_H_INCLUDED
#define LIST_PARENT_H_INCLUDED

#include <iostream>
using namespace std;
#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last
#define infoP(P) P->info

typedef string infotype_parent;
typedef struct elmlist_parent *address_parent;

struct elmlist_parent{
    infotype_parent info;
    address_parent next;
    address_parent prev;
};

struct List_parent{
    address_parent first;
    address_parent last;
};

void createList(List_parent &L);
void update_data(List_parent L, address_parent &P, string nama);
void insertLast(List_parent &L, address_parent P);
void deleteFirst(List_parent &L, address_parent &P);
void deleteLast(List_parent &L, address_parent &P);
void deleteAfter(address_parent Prec, address_parent &P);
bool isEmpty(List_parent L);
void dealokasi_peserta(List_parent &L, infotype_parent x);
void createElemenParent(address_parent &P, infotype_parent x);
address_parent findElm(List_parent L, infotype_parent x);
void printInfo(List_parent L);

#endif // LIST_PARENT_H_INCLUDED
