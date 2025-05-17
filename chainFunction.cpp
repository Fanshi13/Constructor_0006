#include <iostream>
using namespace std;

class Buku
{
    string judul;

public:
    Buku &setJudul(string judul)
    {
        this->judul = judul;
        return *this;
    }

    string getJudul()
    {
        return this->judul;
    }
};

int main()
{
    Buku bukunya;
    cout << bukunya.setJudul("Matematika").getJudul(); // chain function calls
    return 0;
}
