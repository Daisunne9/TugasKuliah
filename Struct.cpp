#include <iostream>
using namespace std;

int main(){
    struct datanazril{
        string nama;
        string nim;
        string prodi;
    };

    datanazril mahasiswa;

    cout << "Masukkan Nama: ";
    getline(cin, mahasiswa.nama);

    cout << "Masukkan NIM: ";
    cin >> mahasiswa.nim;
    
    cin.ignore();

    cout << "Masukkan Prodi: ";
    getline(cin, mahasiswa.prodi);

    system("cls");
    cout << "\nData Mahasiswa" << endl;
    cout << "Nama: " << mahasiswa.nama << endl;
    cout << "NIM: " << mahasiswa.nim << endl;
    cout << "Prodi: " << mahasiswa.prodi << endl;
    
    return 0;
}