#include "kantor.h"
#include <cstring>

int main()
{
    listPegawai LP;
    listDepartmen LD;
    createListPegawai(LP);
    createListDepartmen(LD);
    infotypeDepartmen x;
    alamatDepartmen p;
    //membuat departmen keuangan
    x = createDepartment("Keuangan", "KUG");
    createElmDepartmen(x, p);
    insertLastDepartmen(LD, p);
    //membuat departmen SDM
    x = createDepartment("Sumber Daya Manusia", "SDM");
    createElmDepartmen(x, p);
    insertLastDepartmen(LD, p);
    //membuat departmen Administrasi
    x = createDepartment("Administrasi", "ADM");
    createElmDepartmen(x, p);
    insertLastDepartmen(LD, p);
    infotypePegawai y;
    //proses input pegawai dan memasangkannya ke departmen berdasar nip
    for(int i = 0; i < 2; i++){
        cout << "Masukkan nama pegawai: ";
        cin >> y.nama;
        cout << "Masukkan nip pegawai: ";
        cin >> y.nip;
        cout << "Masukkan jabatan pegawai: ";
        cin >> y.jabatan;
        cout << "Masukkan gaji pegawai: ";
        cin >> y.gaji;
        alamatPegawai q;
        createElmPegawai(y, q);
        insertLastPegawai(LP, q);
        char *cstr = new char[y.nip.length() + 1];
        strcpy(cstr, y.nip.c_str());
        if(cstr[0] == '2'){
            memasangkanPegawai(LP, LD,y.nama, y.nip, "SDM");
        }else if(cstr[0] == '3'){
            memasangkanPegawai(LP, LD,y.nama, y.nip, "KUG");
        }else{
            memasangkanPegawai(LP, LD,y.nama, y.nip, "ADM");
        }
    }
    printDepartmen(LD);
    printPegawai(LP);
    cout<<endl;
    printDepartmenbyPegawai(LP);
    cout<<endl;
    string NIP;
    cout<<"Pegawai yang keluar";
    cin>>NIP;
    deletePegawai(LP,  NIP);
    printDepartmen(LD);
    printPegawai(LP);
    cout<<endl;
    menampilkanPegawaiPalingSedikit(LD, LP);
    cout<<endl;
    menampilkanPegawaiPalingBanyak(LD, LP);
    return 0;
}
