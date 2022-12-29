#include "kantor.h"
int main()
{
    system("cls");
    listPegawai LP;
    alamatDepartmen dep;
    alamatPegawai peg;
    string nip, kodePemecatan, kodePindah;
    char pemecatan;
    int pilihan, N;
    listDepartmen LD;
    createListPegawai(LP);
    createListDepartmen(LD);
    departmentDefault(LD);
    pilihan = menu();
    while(pilihan != 0){

        switch(pilihan){
            case 1:
                system("cls");
                cout<<"Masukkan jumlah Department yang ingin ditambah: ";
                cin>>N;
                menambahDepartment(LD, N);
                break;
            case 2:
                system("cls");
                cout<<"Masukkan jumlah Pegawai yang ingin ditambah: ";
                cin>>N;
                menambahkanPegawai(LP, LD, N);
                system("cls");
                break;
            case 3:
                system("cls");
                printPegawai(LP);
                break;
            case 4:
                system("cls");
                printDepartmen(LD);
                break;
            case 5:
                system("cls");
                sortingDepartmentByPegawaiPalingBanyak(LD, LP);
                break;
            case 6:
                system("cls");
                sortingDepartmentByPegawaiPalingSedikit(LD, LP);
                break;
            case 7:
                system("cls");
                menampilkanPegawaiPalingSedikit(LD, LP);
                break;
            case 8:
                system("cls");
                menampilkanPegawaiPalingBanyak(LD, LP);
                break;
            case 9:
                system("cls");
                cout<<"Masukkan NIP pegawai yang ingin dihapus: ";
                cin>>nip;
                deletePegawai(LP, nip);
                break;
            case 10:
                system("cls");
                cout<<"Masukkan kode department yang ingin dihapus: ";
                cin>>kodePemecatan;
                cout<<"Apakah pegawai semua dipecat? (Y/N): ";
                cin>>pemecatan;
                if(pemecatan == 'Y' || pemecatan == 'y'){
                    deleteDepartment(LD, LP, kodePemecatan);
                }else if(pemecatan == 'N' || pemecatan == 'n'){
                    peg = first(LP);
                    while(peg != NULL){
                        if(info(nextDepartment(peg)).kode == kodePemecatan){
                            cout<<"Pindahkan kemanapun? (Masukkan kode department): ";
                            cin>>kodePindah;
                            memindahkanPegawai(LP, LD, info(peg).nip, kodePindah);
                            deleteDepartment(LD, LP, kodePemecatan);
                        }
                        peg = next(peg);
                    }

                }else{
                    cout<<"Inputan salah!"<<endl;
                }
                break;
            default:
                break;
        }
        cout<<endl;
        pilihan = menu();
    }

    return 0;
}
