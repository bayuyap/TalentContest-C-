#include "list_admin.h"
#include <iostream>
using namespace std;


void initAdmin(admin admins[adminMax]){
    admins[0].username = "Sadam";
    admins[0].password = "123456";
    admins[1].username = "Andhika";
    admins[1].password = "1301194147";
}

bool loginAdmin(admin administrator[adminMax], string username, string password){
    bool check = false;
    int i = 0;
    while (i < 2 && !check){
        if(username == administrator[i].username && password == administrator[i].password){
            check = true;
        }
        else{
            check = false;
            i++;
        }
    }
    return check;
}
