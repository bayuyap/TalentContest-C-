#ifndef LIST_RELASI_H_INCLUDED
#define LIST_RELASI_H_INCLUDED

#include "list_relasi.h"
#include "list_child.h"
#include "list_parent.h"

#include <iostream>
using namespace std;

#define next(P) P->next
#define first(L) L.first
#define child(P) P->child
#define parent(P) P->parent

typedef struct elmlist_relasi *address_relasi;

struct elmlist_relasi{
    address_relasi next;
    address_child child;
    address_parent parent;
};

struct List_relasi{
    address_relasi first;
};

void createList(List_relasi &L);
void insertFirst(List_relasi &L, address_relasi P);
void insertLast(List_relasi &L, address_relasi P);
void insertAfter(address_relasi Prec, address_relasi P);
void update_nilai ( List_relasi L, address_relasi &P, infotype_parent x);
void isiNilai(List_relasi L, address_relasi &P, string x);
void deleteNilai(List_relasi L, address_relasi &P, string x);
void createElemenRelasi(address_relasi &Q, address_parent P, address_child C);
address_relasi findElm(List_relasi L, address_parent P, address_child C);
void printInfo(List_relasi L);



#endif // LIST_RELASI_H_INCLUDED
