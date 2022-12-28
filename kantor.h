#ifndef kantor_H_INCLUDED
#define kantor_H_INCLUDED

#include <iostream>
using namespace std;

#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define nextDepartment(P) P->nextDepartment
#define info(P) P->info

struct department{
    string nama;
    string kode;
    int jumlahPegawai;
};

struct pegawai{
    string nama;
    string nip;
    string jabatan;
    int gaji;
};

typedef struct department infotypeDepartmen;
typedef struct pegawai infotypePegawai;

typedef struct elmPegawai *alamatPegawai;
typedef struct elmDepartmen *alamatDepartmen;
struct elmDepartmen{
    alamatDepartmen next;
    infotypeDepartmen info;
};

struct elmPegawai{
    alamatPegawai next;
    alamatDepartmen nextDepartment;
    infotypePegawai info;
};

struct listPegawai{
    alamatPegawai first;
    alamatPegawai last;
};

struct listDepartmen{
    alamatDepartmen first;
    alamatDepartmen last;
};

void createListPegawai(listPegawai &L);
void createListDepartmen(listDepartmen &L);
void createElmDepartmen(infotypeDepartmen x, alamatDepartmen &p);
void createElmPegawai(infotypePegawai x, alamatPegawai &p);
void insertLastPegawai(listPegawai &L, alamatPegawai p);
void insertLastDepartmen(listDepartmen &L, alamatDepartmen p);
alamatPegawai searchPegawai(listPegawai L, string nip);
alamatDepartmen searchDepartmen(listDepartmen L, string nama);
void printPegawai(listPegawai L);
void printDepartmen(listDepartmen L);
void printDepartmenbyPegawai(listPegawai LP);
void memasangkanPegawai(listPegawai &LP, listDepartmen &LD,string nama, string nip, string namaDepartmen);
infotypeDepartmen createDepartment(string nama, string kode);
void deletePegawai(listPegawai &LP,  string nip);
void deleteFirstPegawai(listPegawai &L, alamatPegawai &p);
void deleteLastPegawai(listPegawai &L, alamatPegawai &p);
void deleteFirstDepartmen(listDepartmen &L, alamatDepartmen &p);
void menampilkanPegawaiPalingBanyak(listDepartmen LD, listPegawai LP);
void menampilkanPegawaiPalingSedikit(listDepartmen LD, listPegawai LP);

#endif
