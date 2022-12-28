#include "kantor.h"

void createListPegawai(listPegawai &L){
    first(L) = NULL;
    last(L) = NULL;
}

void createListDepartmen(listDepartmen &L){
    first(L) = NULL;
    last(L) = NULL;
}
infotypeDepartmen createDepartment(string nama, string kode){
    infotypeDepartmen x;
    x.nama = nama;
    x.kode = kode;
    x.jumlahPegawai = 0;
    return x;
}
void createElmDepartmen(infotypeDepartmen x, alamatDepartmen &p){
    p = new elmDepartmen;
    info(p) = x;
    next(p) = NULL;
}

void createElmPegawai(infotypePegawai x, alamatPegawai &p){
    p = new elmPegawai;
    info(p) = x;
    next(p) = NULL;
    nextDepartment(p) = NULL;
}

void insertLastPegawai(listPegawai &L, alamatPegawai p){
    if(first(L) == NULL){
        first(L) = p;
        last(L) = p;
    }else{
        next(last(L)) = p;
        last(L) = p;
    }
}

void deleteFirstPegawai(listPegawai &L, alamatPegawai &p){
    if(first(L) != NULL){
        if(first(L) == last(L)){
            p = first(L);
            first(L) = NULL;
            last(L) = NULL;
        }else{
            p = first(L);
            first(L) = next(p);
            next(p) = NULL;
        }
    }
}

void deleteLastPegawai(listPegawai &L, alamatPegawai &p){
    if(first(L) != NULL){
        if(first(L) == last(L)){
            p = first(L);
            first(L) = NULL;
            last(L) = NULL;
        }else{
            alamatPegawai q = first(L);
            while(next(next(q)) != NULL){
                q = next(q);
            }
            p = next(q);
            next(q) = NULL;
            last(L) = q;
        }
    }
}

void deleteAfterPegawai(listPegawai &L, alamatPegawai prec, alamatPegawai &p){
    if(first(L) != NULL){
        if(first(L) == last(L)){
            p = first(L);
            first(L) = NULL;
            last(L) = NULL;
        }else{
            p = next(prec);
            next(prec) = next(p);
            next(p) = NULL;
        }
    }
}

void insertLastDepartmen(listDepartmen &L, alamatDepartmen p){
    if(first(L) == NULL){
        first(L) = p;
        last(L) = p;
    }else{
        next(last(L)) = p;
        last(L) = p;
    }
}

alamatPegawai searchPegawai(listPegawai L, string nip){
	alamatPegawai p = first(L);
	while (p != NULL){
		if (info(p).nip == nip){
			return p;
		}
		p = next(p);
	}
	return NULL;
}

alamatDepartmen searchDepartmen(listDepartmen L, string kode){
	alamatDepartmen p = first(L);
	while (p != NULL){
		if (info(p).kode == kode){
			return p;
		}
		p = next(p);
	}
	return NULL;
}

void printPegawai(listPegawai L){
	cout<<"=========== Data Pegawai ==========="<<endl;
    if (first(L) == NULL){
		cout << "list kosong" << endl;
	} else {
		alamatPegawai p = first(L);
		while (p != NULL){
			cout << "nama : " << info(p).nama << endl;
			cout << "nip : " << info(p).nip << endl;
			cout << "jabatan : " <<  info(p).jabatan << endl;
			cout << "gaji : " << info(p).gaji << endl;

			p = next(p);
		}
	}
}

void printDepartmen(listDepartmen L){
	cout<<"=========== Data Departmen ==========="<<endl;
    if (first(L) == NULL){
		cout << "list kosong" << endl;
	} else {
		alamatDepartmen p = first(L);
		while (p != NULL){
			cout << "nama : " << info(p).nama << endl;
			cout << "kode departemen : " << info(p).kode << endl;
			cout << "jumlah pegawai : " << info(p).jumlahPegawai << endl;

			p = next(p);
		}
	}
}

void printDepartmenbyPegawai(listPegawai L){
	alamatPegawai p = first(L);
	alamatDepartmen d;
	while (p!= NULL){
        infotypePegawai x = info(p);
        cout << "departmen milik " << x.nama << " dengan " << x.nip << " adalah : "<< endl;
	    cout << "nama : " << info(nextDepartment(p)).nama << endl;
	    cout << "kode departemen : " << info(nextDepartment(p)).kode << endl;
		p = next(p);
	}
}

void memasangkanPegawai(listPegawai &L, listDepartmen &D, string nama, string nip, string namaDepartmen){
    alamatPegawai p = searchPegawai(L, nip);
    alamatDepartmen d = searchDepartmen(D, namaDepartmen);
    if ((p != NULL) && (d != NULL)){
        nextDepartment(p) = d;
        info(d).jumlahPegawai = info(d).jumlahPegawai + 1;
    } else {
        cout << "data tidak ditemukan" << endl;
    }
}

//menghapus pegawai dari departmen
void deletePegawai(listPegawai &L, string nip){
    alamatPegawai p = searchPegawai(L, nip);
    alamatDepartmen d = nextDepartment(p);
    if ((p != NULL) && (d != NULL)){
        nextDepartment(p) = NULL;
        info(d).jumlahPegawai = info(d).jumlahPegawai - 1;
        if(p == first(L)){
            deleteFirstPegawai(L, p);
        } else if (p == last(L)){
            deleteLastPegawai(L, p);
        } else {
            alamatPegawai q = first(L);
            while (next(q) != p){
                q = next(q);
            }
            deleteAfterPegawai(L, q, p);
        }
    } else {
        cout << "data tidak ditemukan" << endl;
    }
}

//menampilkan data yang paling banyak multi linked list
int menghitungJumlahPegawai(listDepartmen LD, listPegawai LP, string kode){
    alamatPegawai p = first(LP);
    int jumlah = 0;
    while(p != NULL){
        alamatDepartmen d = nextDepartment(p);
        if (info(d).kode == kode)
        {
            jumlah = jumlah + 1;
        }

        p = next(p);
    }
    return jumlah;
}

void menampilkanPegawaiPalingBanyak(listDepartmen LD, listPegawai LP){
    alamatDepartmen p = first(LD);
    int jumlah = 0;
    string kode;
    while(p != NULL){
        int jumlahPegawai = menghitungJumlahPegawai(LD, LP, info(p).kode);
        if (jumlahPegawai > jumlah){
            jumlah = jumlahPegawai;
            kode = info(p).kode;
        }
        p = next(p);
    }
    cout << "departmen dengan jumlah pegawai terbanyak adalah : " << endl;
    cout << "nama : " << info(searchDepartmen(LD, kode)).nama << endl;
    cout << "kode departemen : " << info(searchDepartmen(LD, kode)).kode << endl;
}

void menampilkanPegawaiPalingSedikit(listDepartmen LD, listPegawai LP){
    alamatDepartmen p = first(LD);
    int jumlah = 100;
    string kode;
    while(p != NULL){
        int jumlahPegawai = menghitungJumlahPegawai(LD, LP, info(p).kode);
        if (jumlahPegawai < jumlah){
            jumlah = jumlahPegawai;
            kode = info(p).kode;
        }
        p = next(p);
    }
    cout << "departmen dengan jumlah pegawai tersedikit adalah : " << endl;
    cout << "nama : " << info(searchDepartmen(LD, kode)).nama << endl;
    cout << "kode departemen : " << info(searchDepartmen(LD, kode)).kode << endl;
}
