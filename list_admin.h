#ifndef LIST_ADMIN_H_INCLUDED
#define LIST_ADMIN_H_INCLUDED
#include <iostream>
using namespace std;

const int adminMax = 2;
struct admin {
    string username;
    string password;
};

void initAdmin(admin admins[adminMax]);
bool loginAdmin(admin administrator[adminMax], string username, string password);

#endif // LIST_ADMIN_H_INCLUDED
