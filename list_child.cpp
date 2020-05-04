#include "list_child.h"

void createList(List_child &L) {
    first(L) = NULL;
    last(L) = NULL;
}
bool isEmpty(List_child L){
    bool kosong;
    if(first(L) == NULL && last(L) == NULL){
        kosong = true;
    }
    else{
        kosong = false;
    }
    return kosong;
}
void createElemenChild(address_child &P, infotype_child x) {
    P = new elmlist_child;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
}

void insertFirst(List_child &L, address_child P) {
    if(first(L) == NULL) {
        last(L) = P;
        first(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void printInfo(List_child L) {
    address_child P = first(L);
    while(P !=NULL) {
        cout<<"->"<<info(P)<<endl;
        P = next(P);
    }
}


address_child findElm(List_child L, infotype_child x) {
    address_child P = first(L);
    while(P != NULL) {
        if(info(P)==x) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}




