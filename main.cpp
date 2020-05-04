#include <iostream>
#include "list_admin.h"
#include "list_child.h"
#include "list_juri.h"
#include "list_parent.h"
#include "list_relasi.h"
using namespace std;

int main()
{
    List_child LN;
    List_parent LP;
    List_relasi LR;
    List_juri LJ;
    admin administrator[adminMax];
    address_child AN;
    address_parent AP;
    address_relasi AR;
    address_juri AJ;

    initAdmin(administrator);
    createList(LN);
    createList(LP);
    createList(LJ);
    createList(LR);
    string a,b,c,d;
    int jumlah,i;
    infotype_parent x;
    infotype_child y;
    i = 1;

    cout << "\t\t\t\t\tTALENT CONTEST"<<endl;
    cout << "\t\t\t\t\t------------------------"<<endl;
    cout << "\t\t\t\t\tAndhika Bayu Yudhistira Arda Putra 1301194147"<<endl;
    cout << "\t\t\t\t\tSadam Andhika Putra Darmawan 1301194180"<<endl;

    menuawal:
    cout << "1. Non-Login" <<endl;
    cout << "2. Admin Login" <<endl;
    cout << "3. Juri Login "<< endl;
    cout<< endl;
    int pilihan;
    cout << "Masukkan Pilihan Anda = ";
    cin >> pilihan;
    if (pilihan == 1 ) {

    } else if (pilihan == 2) {
        string admin;
        string passadmin;
        cout << "Masukkan username admin = ";
        cin >> admin;
        cout << "Masukkan password admin= ";
        cin >> passadmin;

        if (loginAdmin(administrator, admin, passadmin) == true) {
            menuutama:
            cout<<endl;
            cout << "1. Buat data Juri"<<endl;
            cout << "2. Lihat data Juri"<<endl;
            cout << "3. Update data Juri"<<endl;
            cout << "4. Delete data Juri"<<endl;
            cout << "5. Lihat data Peserta"<<endl;
            cout << "6. Update data Peserta"<<endl;
            cout << "7. Delete data Peserta"<<endl;
            cout << "8. View total nilai dan detail nilai setiap peserta"<<endl;
            cout << "9. View detail penilaian setiap juri"<< endl;
            cout << endl;
            cout << " - Masukkan pilihan anda = ";
            cin >>pilihan;
            string usernamejuri;
            string namapeserta;
            if (pilihan == 1) {
                cout<<endl;
                cout << " -- Masukkan jumlah juri yang ingin diInput = ";
                cin >> jumlah;

                while (i <= jumlah) {
                    cout<<endl;
                    cout << " --- Masukkan username juri = ";
                    cin >>a;
                    cout << " --- Masukkan password juri = ";
                    cin >>b;
                    cout << " --- Masukkan nama juri = ";
                    cin >>c;
                    cout << " --- Masukkan asal juri = ";
                    cin >>d;

                    if (i == 1) {
                    } else {
                    }
                }
                goto menuutama;

            }else if (pilihan == 2) {
                cout<<endl;
                insertTerurut(LJ, AJ);
                lihat_infojuri(LJ);
                cout<<endl;
                cout << "Ingin kembali ke menu utama ? "<<endl;
                cout << "1. Ya"<<endl;
                cout << "2. Tidak"<<endl;
                cout << " Masukkan pilihan = ";
                cin >>jumlah;
                if (jumlah == 1) {
                    goto menuutama;
                }


            }else if (pilihan == 3) {
                cout<<endl;
                cout<< " -- Masukkan username juri yang ingin diUpdate = ";
                cin >>usernamejuri;
                if (AJ != NULL) {
                    menuupdatejuri:
                    cout << " --- Pilih data yang ingin diubah" <<endl;
                    cout << " --- 1. Username"<<endl;
                    cout << " --- 2. Password" <<endl;
                    cout << " --- 3. Nama" <<endl;
                    cout << " --- 4. Kembali ke menu utama"<<endl;
                    cout <<endl;
                    cout<< " ---- Masukkan pilihan = ";
                    cin >> jumlah;
                    if (jumlah != 4) {
                    goto menuupdatejuri;
                    } else {
                        goto menuutama;
                    }
                } else {
                    cout << "Juri tidak ditemukan"<<endl;
                }

            }else if (pilihan == 4) {
                cout << " -- Masukkan nama juri yang ingin dihapus = ";
                cin >>usernamejuri;
                dealokasi(LJ,usernamejuri);
                goto menuutama;

            }else if (pilihan == 5) {
                printInfo(LP);
                cout<<endl;
                cout << "Ingin kembali ke menu utama ? "<<endl;
                cout << "1. Ya"<<endl;
                cout << "2. Tidak"<<endl;
                cout << " Masukkan pilihan = ";
                cin >>jumlah;
                if (jumlah == 1) {
                    goto menuutama;
                }

            }else if (pilihan == 6) {
                cout<<endl;
                cout << " -- Masukkan nama peserta yang ingin di Update = ";
                cin >> x;
                AP = findElm(LP, x);
                if (AP != NULL) {
                menuupdatepeserta:
                cout << " --- Pilih data yang ingin diubah" <<endl;
                cout << " --- 1. Nama" <<endl;
                cout << " --- 2. Asal" <<endl;
                cout << " --- 3. Umur" <<endl;
                cout << " --- 4. Kembali ke menu utama"<<endl;
                cout<<endl;
                cout << " ---- Masukkan pilihan =";
                cin >> jumlah;
                if (jumlah != 4) {
                goto menuupdatepeserta;
                }else {
                    goto menuutama;
                }
                } else {
                    cout << " -- Nama peserta salah";
                    goto menuutama;
                }

            }else if (pilihan == 7) {
                cout << " -- Masukkan nama peserta yang ingin dihapus = ";
                cin >>namapeserta;
                dealokasi_peserta(LP,namapeserta);
                goto menuutama;

            }else if (pilihan == 8) {
                printInfo(LR);
                cin.get();
                goto menuutama;
            }else if (pilihan == 9){
                lihat_infojuri(LJ);
                cin.get();
                goto menuutama;
            }else {
                goto menuawal;

            }
        } else {
            cout << "Username atau password admin salah";
        }

    }else if (pilihan == 3) {
        string username;
        string passjuri;
        cout << "Masukkan username juri = ";
        cin >>username;
        cout << "Masukkan password juri = ";
        cin >>passjuri;

        if (AJ != NULL) {
            if (info(AJ).pass != passjuri) {
                cout << "Maaf password salah";
            } else {
                string namapeserta;
                menuutamapeserta:
                cout<<endl;
                cout << "1. Buat peserta"<<endl;
                cout << "2. Input Nilai"<<endl;
                cout << "3. Update Nilai"<<endl;
                cout << "4. Lihat daftar peserta yang sudah dinilai"<<endl;
                cout << "5. Lihat daftar peserta yang belum dinilai"<<endl;
                cout << "6. Hapus Nilai peserta"<<endl;
                cout << "Masukkan pilihan anda = ";
                cin >> pilihan;
                if (pilihan == 1) {
                    cout<<endl;
                    cout << " -- Masukkan jumlah peserta yang ingin diInput = ";
                    cin >>jumlah;
                    i = 1;
                    while (i <= jumlah) {
                        cout<<endl;
                        cout << " --- Masukkan nama peserta = ";
                        cin >>a;
                        createElemenParent(AP, x);
                        insertLast(LP, AP);
                        createElemenRelasi(AR,AP,AN);
                        insertFirst(LR, AR);
                        i++;
                }
                goto menuutamapeserta;

                }
                else if (pilihan == 2) {
                    cout << " Masukkan nama peserta = ";
                    cin >>x;
                    isiNilai(LR, AR, x);
                    goto menuutamapeserta;

                }else if (pilihan == 3) {
                    cout << " Masukkan nama peserta = ";
                    cin >>x;
                    update_nilai(LR, AR, x);
                    goto menuutamapeserta;

                }else if (pilihan == 4) {
                    printInfo(LR);
                }else if (pilihan == 5) {
                    printInfo(LR);

                }else if (pilihan == 6) {
                    cout << "Masukkan nama peserta = ";
                    cin >> x ;
                    deleteNilai(LR, AR, x);
                    goto menuutamapeserta;

                }
            }

        } else {
            cout << "Maaf akun tidak ditemukan";
        }
    return 0;
}
}
