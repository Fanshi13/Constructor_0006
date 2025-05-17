#include <iostream>
#include <string>
using namespace std;

class Mahasiswa;

class Dosen
{
private:
    string nama;
    string NIDN;
    string pangkat;
    float gaji;

public:
    Dosen(string nama, string nidn, string pangkat, float gaji)
        : nama(nama), NIDN(nidn), pangkat(pangkat), gaji(gaji) {}

    friend class Staff;                    // agar Staff bisa mengubah pangkat
    friend float aksesGajiDosen(Dosen *d); // hanya akses gaji, tidak semua data
    void beriNilai(Mahasiswa *m, float nilai);
};

class Mahasiswa private : string nama;
int NIM;
float nilai;
