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

class Staff
{
private:
    string nama;
    int ID;
    float gaji;

public:
    Staff(string nama, int ID, float gaji)
        : nama(nama), ID(ID), gaji(gaji) {}

    void ubahPangkat(Dosen *d, string pangkatBaru)
    {
        d->pangkat = pangkatBaru;
    }

    friend float lihatGajiStaff(Staff *s);
};

float aksesGajiDosen(Dosen *d)
{
    return d->gaji;
}

float lihatGajiStaff(Staff *s)
{
    return s->gaji;
}

// Universitas bukan friend class dari Dosen atau Staff
class Universitas
{
public:
    void infoGajiDosen(Dosen *d)
    {
        cout << "[Universitas] Gaji Dosen: " << aksesGajiDosen(d) << endl;
    }

    void infoGajiStaff(Staff *s)
    {
        cout << "[Universitas] Gaji Staff: " << lihatGajiStaff(s) << endl;
    }
};

int main()

    Mahasiswa mhs("Budi", 12345);
