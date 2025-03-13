#include<iostream>
#include<string>
#include<queue>
#define max 5

using namespace std;

struct lagu {
    string judul;
    string penyanyi;
};

//array untuk menyimmpan daftar lagu
lagu listlagu[max];

//variabel untuk FIFO dan LIFO
int front, rear, top;

//fungsi untuk menginisialisasi queue dan stack
//-1 agar berada diluar queue
void create() {
    front = -1;
    rear = -1;
    top = -1;
}

//untuk mengecek apakah queue penuh atau tidak
//bernilai full jika nilai rear mencapai batas max(define max 5)
bool isFull() {
    return (rear == max - 1);
}

//untuk mengecek apakah queue kosong atau tidak
//bernilai kosong jika front -1 atau front >rear (5 dalam kasus ini)
bool isEmpty() {
    return (front == -1 || front > rear);
}

void tambah_lagu();
void fifo();
void lifo();
void print();
void hapus();


int main(){
    system("cls");
    int pilihan;
    create(); 

    do {
        cout << "======Menu Pilihan======" << endl;
        cout << "1. Tambah Lagu" << endl;
        cout << "2. Hapus Lagu Pertama Ditambahkan" << endl;
        cout << "3. Hapus Lagu Terakhir Ditambahkan" << endl;
        cout << "4. Tampilkan List Lagu" << endl;
        cout << "5. Hapus Semua Lagu" << endl;
        cout << "Masukkan Pilihan (1/2/3/4/5): ";
        cin >> pilihan;

    switch (pilihan){
        case 1: tambah_lagu(); break;
        case 2: fifo(); break;
        case 3: lifo(); break;
        case 4: print(); break;
        case 5: hapus(); break;
        }
    } while (pilihan != (1,5));
    return 0;
}

//fungsi tambah lagu
void tambah_lagu(){
    if (isFull()) {
        cout << "List musik penuh!" << endl;
        return;
    }

    lagu lagubaru;
    cout << "Masukkan Judul Lagu: ";
    cin.ignore();//membersihkan buffer
    getline(cin, lagubaru.judul);
    cout << "Masukkan Nama Penyanyi: ";
    getline(cin, lagubaru.penyanyi);

    if (front == -1) front = 0;
    rear++;
    listlagu[rear] = lagubaru; //listlagu[0] diisi data lagu baru tadi

    // Push ke stack
    top = rear;

    system("cls");
    cout << "Lagu berhasil ditambahkan!" << endl;
}

void fifo() {
    if (isEmpty()) {
        cout << "List musik kosong!" << endl;
        return;
    }

    system("cls");
    cout << "Menghapus Lagu Pertama Ditambahkan: " << listlagu[front].judul << " oleh " << listlagu[front].penyanyi << endl;
    front++; 

    if (front > rear) {
        create();
    }
}

void lifo() {
    if (isEmpty()) {
        cout << "List musik kosong!" << endl;
        return;
    }

    system("cls");
    cout << "Menghapus Lagu Terakhir Ditambahkan: " << listlagu[top].judul << " oleh " << listlagu[top].penyanyi << endl;
    top--;
    rear--;

    if (top < front) { 
        create();
    }
}

void hapus() {
    create();
    system("cls");
    cout << "Semua data musik telah dihapus!" << endl;
}

void print() {
    system("cls");
    if (isEmpty()) {
        cout << "List musik kosong!" << endl;
        return;
    }

    cout << "\nDaftar Musik:\n";
    for (int i = front; i <= rear; i++) {
        cout << i + 1 << ". " << listlagu[i].judul << " - " << listlagu[i].penyanyi << endl;
    }
}