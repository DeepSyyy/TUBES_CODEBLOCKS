#ifndef kantor_H_INCLUDED
#define kantor_H_INCLUDED

#include <iostream>
using namespace std;

#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define nextDepartment(P) P->nextDepartment
#define prev(P) P->prev
#define info(P) P->info

struct department{
    string nama;
    string kode;
    int jumlahPegawai;
};

struct pegawai{
    string nama;
    string nip;
    int gaji;
};

typedef struct department infotypeDepartmen;
typedef struct pegawai infotypePegawai;

typedef struct elmPegawai *alamatPegawai;
typedef struct elmDepartmen *alamatDepartmen;
struct elmDepartmen{
    alamatDepartmen next;
    alamatDepartmen prev;
    infotypeDepartmen info;
};

struct elmPegawai{
    alamatPegawai next;
    alamatPegawai prev;
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
void printDepartmen(listDepartmen L, listPegawai LP);
void printDepartmenbyPegawai(listPegawai LP);
void memasangkanPegawai(listPegawai &L, listDepartmen &D, string nama, string kodeDepartmen);
infotypeDepartmen createDepartment(string nama, string kode);
void deletePegawai(listPegawai &LP,  string nip);
void deleteFirstPegawai(listPegawai &L, alamatPegawai &p);
void deleteLastPegawai(listPegawai &L, alamatPegawai &p);
void deleteLastDepartment(listDepartmen &L, alamatDepartmen &p);
void deleteFirstDepartmen(listDepartmen &L, alamatDepartmen &p);
void menampilkanPegawaiPalingBanyak(listDepartmen LD, listPegawai LP);
void menampilkanPegawaiPalingSedikit(listDepartmen LD, listPegawai LP);
void menambahDepartment(listDepartmen &LD, int N);
void departmentDefault(listDepartmen &LD);
void menambahkanPegawai(listPegawai &LP, listDepartmen &LD, int N);
void memindahkanPegawai(listPegawai &LP, listDepartmen &LD, string nip, string kodeDepartmen);
void deleteDepartment(listDepartmen &LD, listPegawai &LP, string kode);
bool isSameNIP(listPegawai LP);
void menampilkanDepartmentdenganPegawainya(listDepartmen &LD, listPegawai &LP, string kode);
void menampilkanPegawaidenganDepartmen(listPegawai &LP, listDepartmen &LD, string nip);
int menu();

#endif
