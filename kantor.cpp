#include "kantor.h"

void createListPegawai(listPegawai &L)
{
    /*I.S.
    F.S. Membuat list kosong*/
    first(L) = NULL;
    last(L) = NULL;
}

void createListDepartmen(listDepartmen &L)
{
    /*I.S.
    F.S. Membuat List Kosong*/
    first(L) = NULL;
    last(L) = NULL;
}
infotypeDepartmen createDepartment(string nama, string kode)
{
    /*Mengembalikan sebuah infotype dari parameter
    */
    infotypeDepartmen x;
    x.nama = nama;
    x.kode = kode;
    x.jumlahPegawai = 0;
    return x;
}
void createElmDepartmen(infotypeDepartmen x, alamatDepartmen &p)
{
    /*I.S. Terdefinisi sebuah data department
    F.S. element yang berisi data department disimpan dalan
    pointer*/
    p = new elmDepartmen;
    info(p) = x;
    next(p) = NULL;
}

void createElmPegawai(infotypePegawai x, alamatPegawai &p)
{
    /*I.S. Terdefinisi sebuah dara pegawai
    F.S. element yang berisi data pegawai yang disimpan dalam
    pointer*/
    p = new elmPegawai;
    info(p) = x;
    next(p) = NULL;
    nextDepartment(p) = NULL;
}

infotypePegawai createPegawai(string nama, string nip, int gaji)
{
    /* Membungkus parameter menjadi infotype
    */
    infotypePegawai x;
    x.nama = nama;
    x.nip = nip;
    x.gaji = gaji;
    return x;
}

void insertLastPegawai(listPegawai &L, alamatPegawai p)
{
    /*I.S. Terdefinisi List (bisa kosong)
    F.S. Element List baru akan ditambahkan dipaling belakang*/
    if (first(L) == NULL)
    {
        first(L) = p;
        last(L) = p;
    }
    else
    {
        if (info(p).nip == info(last(L)).nip)
        {
            cout << "NIP sudah ada" << endl;
        }
        else
        {
            next(last(L)) = p;
            prev(p) = last(L);
            last(L) = p;
        }
    }
}

void deleteFirstPegawai(listPegawai &L, alamatPegawai &p)
{
    /*I.S. Terdefinisi List(mungkin kosong)
    F.S. Menhapus bagian pertama dari List dan simipan pada pointer*/
    if (first(L) != NULL)
    {
        if (first(L) == last(L))
        {
            p = first(L);
            first(L) = NULL;
            last(L) = NULL;
        }
        else
        {
            p = first(L);
            first(L) = next(p);
            next(p) = NULL;
            prev(first(L)) = NULL;
        }
    }
}

void deleteLastPegawai(listPegawai &L, alamatPegawai &p)
{
    /*I.S. Terdefinisi List (mungkin kosong)
    F.S. Menhapus bagian List paling akhir dan disimpan pada pointer*/
    if (first(L) != NULL)
    {
        if (first(L) == last(L))
        {
            p = first(L);
            first(L) = NULL;
            last(L) = NULL;
        }
        else
        {
            p = last(L);
            last(L) = prev(p);
            prev(p) = NULL;
            next(last(L)) = NULL;
        }
    }
}

void deleteAfterPegawai(listPegawai &L, alamatPegawai prec, alamatPegawai &p)
{
    /*I.S. Terdefinisi List (mungkin kosong)
    F.S. Menghapus bagian list yang ingin dihapus dan disimpan paada pointer*/
    if (first(L) != NULL)
    {
        if (first(L) == last(L))
        {
            p = first(L);
            first(L) = NULL;
            last(L) = NULL;
        }
        else
        {
            p = next(prec);
            next(prec) = next(p);
            prev(next(p)) = prec;
            next(p) = NULL;
            prev(p) = NULL;
        }
    }
}

void insertLastDepartmen(listDepartmen &L, alamatDepartmen p)
{
     /*I.S. Terdefinisi List (bisa kosong)
    F.S. Element List baru akan ditambahkan dipaling belakang*/
    if (first(L) == NULL)
    {
        first(L) = p;
        last(L) = p;
    }
    else
    {
        alamatDepartmen q = first(L);
        while (q != NULL)
        {
            if (info(q).kode == info(p).kode)
            {
                cout << "Department sudah ada" << endl;
                break;
            }
            q = next(q);
        }
        next(last(L)) = p;
        prev(p) = last(L);
        last(L) = p;
    }
}

void deleteFirstDepartmen(listDepartmen &LD, alamatDepartmen &p){
    /*I.S. Terdefinisi List(mungkin kosong)
    F.S. Menhapus bagian pertama dari List dan simipan pada pointer*/
    if (first(LD) != NULL)
    {
        if (first(LD) == last(LD))
        {
            p = first(LD);
            first(LD) = NULL;
            last(LD) = NULL;
        }
        else
        {
            p = first(LD);
            first(LD) = next(p);
            next(p) = NULL;
            prev(first(LD)) = NULL;
        }
    }
}

void deleteLastDepartment(listDepartmen &L, alamatDepartmen &p){
     /*I.S. Terdefinisi List (mungkin kosong)
    F.S. Menhapus bagian List paling akhir dan disimpan pada pointer*/
    if (first(L) != NULL)
    {
        if (first(L) == last(L))
        {
            p = first(L);
            first(L) = NULL;
            last(L) = NULL;
        }
        else
        {
            p = last(L);
            last(L) = prev(p);
            prev(p) = NULL;
            next(last(L)) = NULL;
        }
    }
}

void deleteAfterDepartmen(listDepartmen &L, alamatDepartmen prec, alamatDepartmen &p)
{
    /*I.S. Terdefinisi List (mungkin kosong)
    F.S. Menghapus bagian list yang ingin dihapus dan disimpan paada pointer*/
    if (first(L) != NULL)
    {
        if (first(L) == last(L))
        {
            p = first(L);
            first(L) = NULL;
            last(L) = NULL;
        }
        else
        {
            p = next(prec);
            next(prec) = next(p);
            prev(next(p)) = prec;
            next(p) = NULL;
            prev(p) = NULL;
        }
    }
}

alamatPegawai searchPegawai(listPegawai L, string nip)
{
    /*Mengembalikan alamat sebuah alamat jika ditemukan, jika tidak\
    menge,balikan NULL */
    alamatPegawai p = first(L);
    while (p != NULL)
    {
        if (info(p).nip == nip)
        {
            return p;
        }
        p = next(p);
    }
    return NULL;
}

alamatDepartmen searchDepartmen(listDepartmen L, string kode)
{
    /*Mengembalikan alamat sebuah alamat jika ditemukan, jika tidak\
    menge,balikan NULL */
    alamatDepartmen p = first(L);
    while (p != NULL)
    {
        if (info(p).kode == kode)
        {
            return p;
        }
        p = next(p);
    }
    return NULL;
}

void printPegawai(listPegawai L)
{
    /*I.S. L terdefinisi List bisa kosong
    F.S Menampilkan data dari pegawai*/
    int i = 1;
    cout << "=========== Data Pegawai ===========" << endl;
    if (first(L) == NULL)
    {
        cout << "list kosong" << endl;
    }
    else
    {
        alamatPegawai p = first(L);
        while (p != NULL)
        {
            cout<< "Data Pegawai ke-"<<i<<endl;
            cout << "nama : " << info(p).nama << endl;
            cout << "nip : " << info(p).nip << endl;
            cout << "gaji : " << info(p).gaji << endl;
            i = i + 1;
            p = next(p);
            cout<<endl;
            cout<<endl;
        }
    }
}



int menghitungJumlahPegawai(listDepartmen LD, listPegawai LP, string kode)
{
    /*mengembalikan jumlah pegawai*/
    alamatPegawai p = first(LP);
    int jumlah = 0;
    if (first(LD) == NULL)
    {
        return 0;
    }
    else
    {
        while (p != NULL)
        {
            alamatDepartmen d = nextDepartment(p);
            if (info(d).kode == kode)
            {
                jumlah = jumlah + 1;
            }

            p = next(p);
        }
        return jumlah;
    }
}

void printDepartmen(listDepartmen L, listPegawai LP)
{
    /*I.S. L terdefinisi List bisa kosong
    F.S Menampilkan data dari Department*/
    int i = 1;
    cout << "=========== Data Departmen ===========" << endl;
    if (first(L) == NULL)
    {
        cout << "list kosong" << endl;
    }
    else
    {
        alamatDepartmen p = first(L);
        while (p != NULL)
        {
            cout<< "Data department ke-"<<i<<endl;
            cout << "nama : " << info(p).nama << endl;
            cout << "kode departemen : " << info(p).kode << endl;
            cout << "jumlah pegawai : " << menghitungJumlahPegawai(L, LP, info(p).kode) << endl;
            i = i+1;
            p = next(p);
            cout<<endl;
        }
    }
}

void memasangkanPegawai(listPegawai &L, listDepartmen &D, string nip, string kodeDepartmen)
{
    /*I.S. Terdefinisi List (munkin kosong)
    F.S. Memasangkan Pegawai dengan Department berdasar kode Department*/
    alamatPegawai p = searchPegawai(L, nip);
    alamatDepartmen d = searchDepartmen(D, kodeDepartmen);
    if ((p != NULL) && (d != NULL))
    {
        nextDepartment(p) = d;
    }
    else
    {
        cout << "data tidak ditemukan" << endl;
    }
}

void menampilkanPegawaiPalingBanyak(listDepartmen LD, listPegawai LP)
{
    /*I.S. Terdefinisi List (mungkin kosong)
    F.S. Menampilkan Department dengan jumlah pegawai paling banyak*/
    cout<< "======Data Department======" << endl;
    alamatDepartmen p = first(LD);
    alamatDepartmen q = next(p);
    int jumlahPegawaiP = menghitungJumlahPegawai(LD, LP, info(p).kode);
    int jumlahPegawaiQ = menghitungJumlahPegawai(LD, LP, info(q).kode);
    while (p != NULL)
    {
        while (q != NULL)
        {
            if (jumlahPegawaiP < jumlahPegawaiQ)
            {
                jumlahPegawaiP = jumlahPegawaiQ;
            }
            q = next(q);
        }
        p = next(p);
    }
    p = first(LD);
    while (p != NULL)
    {
        if (jumlahPegawaiP == menghitungJumlahPegawai(LD, LP, info(p).kode))
        {
            cout << "Kode : " << info(p).kode << endl;
            cout << "Nama : " << info(p).nama << endl;
            cout << "Jumlah Pegawai : " << menghitungJumlahPegawai(LD, LP, info(p).kode) << endl;
        }
        p = next(p);
    }
}

void menampilkanPegawaiPalingSedikit(listDepartmen LD, listPegawai LP)
{
    /*I.S. Terdefinisi List (mungkin kosong)
    F.S. Menampilkan Department dengan Jumlah pegawai paling sedikit*/
    cout<< "======Data Department======" << endl;

    alamatDepartmen p = next(first(LD));
    alamatDepartmen minAdr = first(LD);
    int minPegawai = countPegawai(LP,p);

    while (p!=NULL){
        int temp = countPegawai(LP,p);
        if (temp<minPegawai){
            minPegawai = temp;
            minAdr = p;
        }
        p = next(p);
    }

    int minimumPegawai = minPegawai;
    alamatDepartmen x = first(LD);
    while (x!=NULL){
        if(countPegawai(LP,x)==minimumPegawai){
            cout << "Kode : " << info(x).kode << endl;
            cout << "Nama : " << info(x).nama << endl;
            cout << "Jumlah Pegawai : " << countPegawai(LP,x) << endl;
            cout << endl;
        }
        x = next(x);
    }



}

void menambahDepartment(listDepartmen &LD, int N)
{
    /*I.S. Terdefinisi List (mungkin kosong)
    F.S. Menambah department kedalam List dengan jumlah tertentu*/
    for(int i = 1; i <= N; i++){
        cout<<"Data["<<i<<"]"<<endl;
        infotypeDepartmen x;
        string nama, kode;
        alamatDepartmen p;
        cout << "Masukkan nama departmen : ";
        cin >> nama;
        cout << "Masukkan kode departmen : ";
        cin >> kode;
        if(first(LD) != NULL){
            while(searchDepartmen(LD, kode) != NULL){
                cout<<"Kode department sudah ada, masukkan kode department yang baru: "<<endl;
                cin>> kode;
            }
        }
        x = createDepartment(nama, kode);
        createElmDepartmen(x, p);
        insertLastDepartmen(LD, p);
    }

}

void departmentDefault(listDepartmen &LD)
{
    /*I.S. Terdefinisi List
    F.S. Membuat daftar department yang sudah ada di dalam List*/
    string nama, kode;
    infotypeDepartmen x;
    alamatDepartmen p;
    nama = "IT";
    kode = "IT";
    x = createDepartment(nama, kode);
    createElmDepartmen(x, p);
    insertLastDepartmen(LD, p);

    nama = "HRD";
    kode = "HRD";
    x = createDepartment(nama, kode);
    createElmDepartmen(x, p);
    insertLastDepartmen(LD, p);

    nama = "Finance";
    kode = "Finance";
    x = createDepartment(nama, kode);
    createElmDepartmen(x, p);
    insertLastDepartmen(LD, p);
}

void menampilkanDepartmentdenganPegawainya(listDepartmen &LD, listPegawai &LP, string kode)
{
    /*I.S. Terdefinisi List (mungkin kosong)
    F.S. Menampilkan satu department berdasar kode department*/
    alamatDepartmen p = searchDepartmen(LD, kode);
    if (p != NULL)
    {
        cout << "Kode departmen : " << info(p).kode << endl;
        cout << "Nama departmen : " << info(p).nama << endl;
        cout << "Jumlah pegawai : " << menghitungJumlahPegawai(LD, LP, info(p).kode)<< endl;
        cout << "Daftar pegawai : " << endl;
        alamatPegawai q = first(LP);
        while (q != NULL)
        {
            if (info(nextDepartment(q)).kode == info(p).kode)
            {
                cout << "Nama : " << info(q).nama << endl;
                cout << "NIP : " << info(q).nip << endl;
            }
            q = next(q);
        }
    }else{
        if(first(LD) == NULL){
            cout<<"List Kosong"<<endl;
        }else{
            cout<< "Kode tidak temukan"<<endl;
            cin>>kode;
            menampilkanDepartmentdenganPegawainya(LD,LP,kode);
        }
    }
}



int menu()
{
    /*Mengembalikan angka untuk menu
    */
    int pilihan;
    cout<< "==============================" <<endl;
    cout<< "||         MENU UTAMA       ||" <<endl;
    cout<< "==============================" <<endl;
    cout << "1. Menambahkan data N department" << endl;
    cout << "2. Menambahkan data N pegawai" << endl;
    cout << "3. Menampilkan data pegawai" << endl;
    cout << "4. Menampilkan data departmen" << endl;
    cout << "5. Menampilkan pegawai berdasar NIP beserta departmentnya"<<endl;
    cout << "6. Menampilkan data depatment beserta pegawainya"<<endl;
    cout << "7. Menampilkan department dengan jumlah pegawai paling sedikit" << endl;
    cout << "8. Menampilkan department dengan jumlah pegawai paling banyak" << endl;
    cout << "9. Menghapus pegawai dari departmen" << endl;
    cout << "10. Menghapus departmen" << endl;
    cout << "0. Keluar" << endl;
    cout << "Masukkan pilihan : ";
    cin >> pilihan;
    return pilihan;
}

void menambahkanPegawai(listPegawai &LP, listDepartmen &LD, int N)
{
    /*I.S. Terdefinisi List (mungkin kosong)
    F.S. Menambahkan sejumlah N pegawai*/
    infotypePegawai x;
    string kodeDepartmen, nama, nip, jabatan;
    int gaji;
    alamatPegawai p;
    for (int i = 1; i <= N; i++)
    {
        cout<< "Data Pegawai ke-"<<i<<endl;
        cout << "Masukkan nama pegawai : ";
        cin >> nama;
        cout << "Masukkan nip pegawai : ";
        cin >> nip;
        if (first(LP) != NULL)
        {
            while (searchPegawai(LP, nip) != NULL)
            {
                cout << "NIP sudah ada, masukkan NIP yang lain : ";
                cin >> nip;
            }
        }
        cout << "Masukkan gaji pegawai : ";
        cin >> gaji;
        cout << "Masukkan kode department pegawai : ";
        cin >> kodeDepartmen;
        if (first(LD) != NULL)
        {
            while (searchDepartmen(LD, kodeDepartmen) == NULL)
            {
                printDepartmen(LD, LP);
                cout << "Kode department tidak ada, masukkan kode department yang ada : ";
                cin >> kodeDepartmen;
            }
        }
        x = createPegawai(nama, nip, gaji);
        createElmPegawai(x, p);
        insertLastPegawai(LP, p);
        memasangkanPegawai(LP, LD, nip, kodeDepartmen);
    }
}

void deleteDepartment(listDepartmen &LD, listPegawai &LP, string kode)
{
    /*I.S. Terdefinisi L (mungkin kosong)
    F.S. Menghapus department berdasar kode department*/
    alamatDepartmen d = searchDepartmen(LD, kode);
    if(d != NULL){
        if(d == first(LD)){
            deleteFirstDepartmen(LD, d);
        }else if(d == last(LD)){
            deleteLastDepartment(LD, d);
        }else{
            alamatDepartmen prec = prev(d);
            deleteAfterDepartmen(LD, prec, d);
        }
    }
}

void memindahkanPegawai(listPegawai &LP, listDepartmen &LD, string nip, string kodeDepartmen)
{
    /*I.S. Terdefinisi List (mungkin kosong)
    F.S. Memindahkan pegawai dari department lama ke department baru
    berdasarkan kode department da nip*/
    alamatPegawai p = searchPegawai(LP, nip);
    alamatDepartmen q = searchDepartmen(LD, kodeDepartmen);
    if (p != NULL && q != NULL)
    {
        nextDepartment(p) = q;
    }
    else if(p != NULL)
    {
        printDepartmen(LD, LP);
        cout << "Masukkan kode departmen untuk pemindahan : ";
        cin >> kodeDepartmen;
        memindahkanPegawai(LP, LD, nip, kodeDepartmen);
    }else{
        printPegawai(LP);
        cout<<"Masukkan NIP Pegawai dengan tepat: ";
        cin>>nip;
        cout<<endl;
        printDepartmen(LD, LP);
        cout<<"Msukkan kode department untuk pemindahan: ";
        cin>>kodeDepartmen;
        memindahkanPegawai(LP, LD, nip, kodeDepartmen);
    }
}

void deletePegawai(listPegawai &LP, string nip)
{
    /*I.S. Terdefinisi List (mungkin kosong)
    F.S. Menghapus pegawau berdasar nip*/
    alamatPegawai p = searchPegawai(LP, nip);
    if (p != NULL){
        if(p == first(LP)){
            deleteFirstPegawai(LP, p);
        }else if(p == last(LP)){
            deleteLastPegawai(LP, p);
        }else{
            alamatPegawai prec = prev(p);
            deleteAfterPegawai(LP, prec, p);
        }

    }else{
        cout<<"NIP tidak ditemukan"<<endl;
        cin>>nip;
        deletePegawai(LP, nip);
    }
}

void menampilkanPegawaidenganDepartmen(listPegawai &LP, listDepartmen &LD, string nip)
{
    /*I.S. Terdefinisi List (mungkin kosong)
    F.S. Menampilkan data pegawai beserta departmentnya berdasarkan NIP pegawai*/
    alamatPegawai p = searchPegawai(LP, nip);
    if (p != NULL)
    {
        cout << "Nama : " << info(p).nama << endl;
        cout << "NIP : " << info(p).nip << endl;
        cout << "Gaji : " << info(p).gaji << endl;
        cout << "Kode Department : " << info(nextDepartment(p)).kode << endl;
        cout << "Nama Department : " << info(nextDepartment(p)).nama << endl;
    }
    else
    {
        if(first(LP) == NULL){
            cout<<"List Kosong"<<endl;
        }else{
            cout << "Data tidak ditemukan" << endl;
            cout << "Masukkan nip : ";
            cin >> nip;
            menampilkanPegawaidenganDepartmen(LP, LD, nip);
        }

    }
}

int countPegawai(listPegawai LP, alamatDepartmen AD){
    int counter = 0;
    if (first(LP)==NULL || AD == NULL){
        return 0;
    }else{
        alamatPegawai AP = first(LP);
        while (AP!=NULL){
            if (nextDepartment(AP)==AD){
                counter++;
            }
            AP = next(AP);
        }
        return counter;
    }
}
