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

class Mahasiswa
{
private:
    string nama;
    int NIM;
    float nilai;

public:
    Mahasiswa(string nama, int NIM) : nama(nama), NIM(NIM), nilai(0) {}

    friend class Dosen; // agar Dosen bisa mengatur nilai

    void tampil()
    {
        cout << "Mahasiswa: " << nama << " (NIM: " << NIM << ") -> Nilai: " << nilai << endl;
    }
};

void Dosen::beriNilai(Mahasiswa *m, float nilai)
{
    m->nilai = nilai;
}

class Staff private : string nama;
int ID;
float gaji;
