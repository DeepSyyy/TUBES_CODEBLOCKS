#include "kantor.h"

void createListPegawai(listPegawai &L)
{
    /*I.S.
    F.S.*/
    first(L) = NULL;
    last(L) = NULL;
}

void createListDepartmen(listDepartmen &L)
{
    /*I.S.
    F.S.*/
    first(L) = NULL;
    last(L) = NULL;
}
infotypeDepartmen createDepartment(string nama, string kode)
{
    infotypeDepartmen x;
    x.nama = nama;
    x.kode = kode;
    x.jumlahPegawai = 0;
    return x;
}
void createElmDepartmen(infotypeDepartmen x, alamatDepartmen &p)
{
    /*I.S.
    F.S.*/
    p = new elmDepartmen;
    info(p) = x;
    next(p) = NULL;
}

void createElmPegawai(infotypePegawai x, alamatPegawai &p)
{
    /*I.S.
    F.S.*/
    p = new elmPegawai;
    info(p) = x;
    next(p) = NULL;
    nextDepartment(p) = NULL;
}

infotypePegawai createPegawai(string nama, string nip, string jabatan, int gaji)
{
    /**/
    infotypePegawai x;
    x.nama = nama;
    x.nip = nip;
    x.jabatan = jabatan;
    x.gaji = gaji;
    return x;
}

void insertLastPegawai(listPegawai &L, alamatPegawai p)
{
    /*I.S.
    F.S.*/
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
    /*I.S.
    F.S.*/
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
    /*I.S.
    F.S.*/
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
    /*I.S.
    F.S.*/
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
    /*I.S.

    F.S*/
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

void deleteAfterDepartmen(listDepartmen &L, alamatDepartmen prec, alamatDepartmen &p)
{
    /*I.S.
    F.S.*/
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
    /* */
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
    /* */
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
    /*I.S. L terdefinisi bisa kosong
    F.S*/
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
            cout << "nama : " << info(p).nama << endl;
            cout << "nip : " << info(p).nip << endl;
            cout << "jabatan : " << info(p).jabatan << endl;
            cout << "gaji : " << info(p).gaji << endl;

            p = next(p);
        }
    }
}

void printDepartmenbyPegawai(listPegawai L)
{
    /*I.S.
    F.S. */
    alamatPegawai p = first(L);
    alamatDepartmen d;
    while (p != NULL)
    {
        infotypePegawai x = info(p);
        cout << "departmen dari " << x.nama << " dengan NIP" << x.nip << " adalah : " << endl;
        cout << "nama : " << info(nextDepartment(p)).nama << endl;
        cout << "kode departemen : " << info(nextDepartment(p)).kode << endl;
        p = next(p);
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
    /*I.S.
    F.S.*/
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
            cout << "nama : " << info(p).nama << endl;
            cout << "kode departemen : " << info(p).kode << endl;
            cout << "jumlah pegawai : " << menghitungJumlahPegawai(L, LP, info(p).kode) << endl;

            p = next(p);
        }
    }
}

void memasangkanPegawai(listPegawai &L, listDepartmen &D, string nip, string kodeDepartmen)
{
    /*I.S.
    F.S.*/
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
    /*I.S.
    F.S*/
    alamatDepartmen p = first(LD);
    int jumlah = 0;
    string kode;
    while (p != NULL)
    {
        int jumlahPegawai = menghitungJumlahPegawai(LD, LP, info(p).kode);
        if (jumlahPegawai > jumlah)
        {
            jumlah = jumlahPegawai;
            kode = info(p).kode;
        }
        p = next(p);
    }
    cout << "departmen dengan jumlah pegawai terbanyak adalah : " << endl;
    cout << "nama : " << info(searchDepartmen(LD, kode)).nama << endl;
    cout << "kode departemen : " << info(searchDepartmen(LD, kode)).kode << endl;
    cout << "Jumlah pegawai : " << jumlah << endl;
}

void menampilkanPegawaiPalingSedikit(listDepartmen LD, listPegawai LP)
{
    /*I.S
    F.S*/
    alamatDepartmen p = first(LD);
    int jumlah = 100;
    string kode;
    while (p != NULL)
    {
        int jumlahPegawai = menghitungJumlahPegawai(LD, LP, info(p).kode);
        if (jumlahPegawai < jumlah)
        {
            jumlah = jumlahPegawai;
            kode = info(p).kode;
        }
        p = next(p);
    }
    cout << "departmen dengan jumlah pegawai tersedikit adalah : " << endl;
    cout << "nama : " << info(searchDepartmen(LD, kode)).nama << endl;
    cout << "kode departemen : " << info(searchDepartmen(LD, kode)).kode << endl;
    cout << "jumlah pegawai : " << jumlah << endl;
}

void menambahDepartment(listDepartmen &LD)
{
    /*I.S.
    F.S.*/
    infotypeDepartmen x;
    string nama, kode;
    alamatDepartmen p;
    cout << "Masukkan nama departmen : ";
    cin >> nama;
    cout << "Masukkan kode departmen : ";
    cin >> kode;

    x = createDepartment(nama, kode);
    createElmDepartmen(x, p);
    insertLastDepartmen(LD, p);
}

void departmentDefault(listDepartmen &LD)
{
    /*I.S
    F.S*/
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

void sortingDepartmentByPegawaiPalingSedikit(listDepartmen &LD, listPegawai LP)
{
    /*I.S.
    F.S.*/
    alamatDepartmen p = first(LD);
    alamatDepartmen q = next(p);
    while (p != NULL)
    {
        while (q != NULL)
        {
            int jumlahPegawaiP = menghitungJumlahPegawai(LD, LP, info(p).kode);
            int jumlahPegawaiQ = menghitungJumlahPegawai(LD, LP, info(q).kode);
            if (jumlahPegawaiP < jumlahPegawaiQ)
            {
                infotypeDepartmen temp = info(p);
                info(p) = info(q);
                info(q) = temp;
            }
            q = next(q);
        }
        p = next(p);
    }
    cout << "Program Berhasil" << endl;
}

void sortingDepartmentByPegawaiPalingBanyak(listDepartmen &LD, listPegawai LP)
{
    /*I.S.
    F.S.*/
    alamatDepartmen p = first(LD);
    alamatDepartmen q = next(p);
    while (p != NULL)
    {
        while (q != NULL)
        {
            int jumlahPegawaiP = menghitungJumlahPegawai(LD, LP, info(p).kode);
            int jumlahPegawaiQ = menghitungJumlahPegawai(LD, LP, info(q).kode);
            if (jumlahPegawaiP > jumlahPegawaiQ)
            {
                infotypeDepartmen temp = info(p);
                info(p) = info(q);
                info(q) = temp;
            }
            q = next(q);
        }
        p = next(p);
    }
}

int menu()
{
    int pilihan;
    cout << "1. Menambahkan data N department" << endl;
    cout << "2. Menambahkan data N pegawai" << endl;
    cout << "3. Menampilkan data pegawai" << endl;
    cout << "4. Menampilkan data departmen" << endl;
    cout << "5. Mensorting data departmen berdasarkan jumlah pegawai paling sedikit" << endl;
    cout << "6. Mensorting data department berdasarkan jumlah pegawai paling banyak" << endl;
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
    /*I.S.
    F.S.*/
    infotypePegawai x;
    string kodeDepartmen, nama, nip, jabatan;
    int gaji;
    alamatPegawai p;
    for (int i = 0; i < N; i++)
    {
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
        cout << "Masukkan jabatan pegawai : ";
        cin >> jabatan;
        cout << "Masukkan gaji pegawai : ";
        cin >> gaji;
        cout << "Masukkan kode department pegawai : ";
        cin >> kodeDepartmen;
        if (first(LD) != NULL)
        {
            while (searchDepartmen(LD, kodeDepartmen) == NULL)
            {
                cout << "Kode department tidak ada, masukkan kode department yang ada : ";
                cin >> kodeDepartmen;
            }
        }
        x = createPegawai(nama, nip, jabatan, gaji);
        createElmPegawai(x, p);
        insertLastPegawai(LP, p);
        memasangkanPegawai(LP, LD, nip, kodeDepartmen);
    }
}

// delete department and pegawai yang ada pada department
void deleteDepartment(listDepartmen &LD, listPegawai &LP, string kode)
{
    /*I.S.
    F.S.*/
    alamatDepartmen p = searchDepartmen(LD, kode);
    alamatPegawai q = first(LP);
    while (q != NULL)
    {
        if (info(nextDepartment(q)).kode == kode)
        {
            deletePegawai(LP, info(q).nip);
        }
        q = next(q);
    }
    deleteAfterDepartmen(LD, prev(p), p);
}

void memindahkanPegawai(listPegawai &LP, listDepartmen &LD, string nip, string kodeDepartmen)
{
    /*I.S.
    F.S.*/
    alamatPegawai p = searchPegawai(LP, nip);
    alamatDepartmen q = searchDepartmen(LD, kodeDepartmen);
    if (p != NULL && q != NULL)
    {
        nextDepartment(p) = q;
        info(q).jumlahPegawai = info(q).jumlahPegawai + 1;
    }
    else
    {
        cout << "Data tidak ditemukan" << endl;
        cout << "Masukkan nip : ";
        cin >> nip;
        cout << "Masukkan kode departmen : ";
        cin >> kodeDepartmen;
        memindahkanPegawai(LP, LD, nip, kodeDepartmen);
    }
}

void deletePegawai(listPegawai &LP, string nip)
{
    /*I.S.
    F.S.*/
    alamatPegawai p = searchPegawai(LP, nip);
    if (p != NULL)
    {
        deleteAfterPegawai(LP, prev(p), p);
    }
    else
    {
        cout << "Data tidak ditemukan" << endl;
        cin >> nip;
        deletePegawai(LP, nip);
    }
}
