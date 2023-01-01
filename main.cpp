#include "kantor.h"

int main()
{
    system("cls");
    listPegawai LP;
    alamatDepartmen dep, searchingDep;
    alamatPegawai peg;
    string nip, kodePemecatan, kodePindah, kodeCari;
    char pemecatan, M;
    int pilihan, N;
    listDepartmen LD;
    createListPegawai(LP);
    createListDepartmen(LD);
    departmentDefault(LD);
    pilihan = menu();
    while (pilihan != 0)
    {

        switch (pilihan)
        {
        case 1:
            system("cls");
            cout << "Q: Apakah anda ingin menambah department? (Y/N) ";
            cin >> M;
            // jkika y maka menambahkan department jika tidak maka kembali ke menu utama
            if ((M == 'Y') || (M == 'y'))
            {
                cout<<"Masukkan jumlah department yang ingin ditambah: ";
                cin >> N;
                menambahDepartment(LD, N);
            }
            break;
        case 2:
            system("cls");
            cout<<"Q: Apakah anda ingin menambah pegawai? (Y/N) ";
            cin>>M;
            if((M == 'Y') || (M == 'y')){
                cout<<"Masukkan jumlah department yang ingin ditambah: ";
                cin >> N;
                menambahkanPegawai(LP, LD, N);
            }
            system("cls");
            break;
        case 3:
            system("cls");
            printPegawai(LP);
            break;
        case 4:
            system("cls");
            printDepartmen(LD, LP);
            break;
        case 5:
            system("cls");
            if(first(LP) != NULL){
                cout<<"Masukkan NIP dari pegawai: ";
                cin>>nip;
                menampilkanPegawaidenganDepartmen(LP, LD, nip);
            }else{
                cout<<"Maaf List Pegawai Kosong"<<endl;
            }
            break;
        case 6:
            system("cls");
            if(first(LD) != NULL){
                cout<< "Masukkan kode department: ";
                cin>> kodeCari;
                menampilkanDepartmentdenganPegawainya(LD, LP, kodeCari);
            }else{
                cout<<"Maaf List Kosong"<<endl;
            }
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
            if(first(LP) == NULL){
                cout<<"Maaf List Pegawai Kosong"<<endl;
            }else{
                cout << "Masukkan NIP pegawai yang ingin dihapus: ";
                cin >> nip;
                deletePegawai(LP, nip);
            }
            break;
        case 10:
            system("cls");
            cout << "Masukkan kode department yang ingin dihapus: ";
            cin >> kodePemecatan;
            searchingDep = searchDepartmen(LD, kodePemecatan);
            while (searchingDep == NULL)
            {
                cout << "Kode department tidak ditemukan!" << endl;
                cout << "Masukkan kode department yang ingin dihapus: ";
                cin >> kodePemecatan;
                searchingDep = searchDepartmen(LD, kodePemecatan);
            }
            cout << "Apakah pegawai semua dipecat? (Y/N): ";
            cin >> pemecatan;
            deleteDepartment(LD, LP, kodePemecatan);
            peg = first(LP);
            if (pemecatan == 'Y' || pemecatan == 'y')
            {
                if(peg != NULL){
                    while(peg != NULL){
                        if(info(nextDepartment(peg)).kode == kodePemecatan){
                            deletePegawai(LP, info(peg).nip);
                        }
                        peg = next(peg);
                    }
                }
            }
            else if (pemecatan == 'N' || pemecatan == 'n')
            {
                peg = first(LP);
                if(peg != NULL)
                {
                        while (peg != NULL)
                        {
                            if (info(nextDepartment(peg)).kode == kodePemecatan)
                            {
                                cout << "Pindahkan kemanapun? (Masukkan kode department): ";
                                cin >> kodePindah;
                                memindahkanPegawai(LP, LD, info(peg).nip, kodePindah);
                                deleteDepartment(LD, LP, kodePemecatan);
                            }
                            peg = next(peg);
                        }
                }else{

                    cout<<"Maaf List Pegawai Kosong"<<endl;
                }

            }
            else
            {
                cout << "Inputan salah!" << endl;
            }
            break;
        default:
            break;
        }
        cout << endl;
        pilihan = menu();
    }

    return 0;
}
