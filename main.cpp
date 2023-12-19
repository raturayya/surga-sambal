#include <iostream>
#include <string>

using namespace std;

const int MAX_MENU = 5;
const int MAX_PESANAN = 10;

struct Menu {
    string nama;
    int harga;
};

void tampilkanMenu(const Menu menu[], int jumlahMenu);
void pesanMenu(Menu menu[], int jumlahMenu, int pesanan[], int& totalPesanan);
void hitungTotalPembayaran(const Menu menu[], int pesanan[], int totalPesanan);
int linearSearch(const Menu menu[], int jumlahMenu, const string& namaMenu);

int main() {
    Menu daftarMenu[MAX_MENU] = {{"Sambal Matah", 15000},
                                 {"Sambal Bawang", 12000},
                                 {"Sambal Tomat", 10000},
                                 {"Sambal Mangga", 18000},
                                 {"Sambal Jeruk", 20000}};

    int jumlahPesan[MAX_MENU] = {0};
    int totalPesanan = 0;

    cout << "=== Selamat Datang di Surga Sambal ===\n";

    do {
        cout << "\n1. Pemesanan\n";
        cout << "2. Pembayaran\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu (0-2): ";

        int pilihan;
        cin >> pilihan;

        if (pilihan == 1) {
            pesanMenu(daftarMenu, MAX_MENU, jumlahPesan, totalPesanan);
        } else if (pilihan == 2) {
            if (totalPesanan > 0) {
                hitungTotalPembayaran(daftarMenu, jumlahPesan, totalPesanan);
            } else {
                cout << "Anda belum memesan apa-apa.\n";
            }
        } else if (pilihan == 0) {
            cout << "Batal\n";
        } else {
            cout << "Pilihan tidak valid." << endl;
        }

    } while (totalPesanan > 0);

    cout << "\nTerima kasih atas pesanannya!\n";
    return 0;
}

void tampilkanMenu(const Menu menu[], int jumlahMenu) {
    cout << "=== Menu Surga Sambal ===\n";
    cout << "No\tNama Menu\tHarga\n";
    for (int i = 0; i < jumlahMenu; ++i) {
        cout << i + 1 << "\t" << menu[i].nama << "\t\t" << menu[i].harga << "\n";
    }
}

void pesanMenu(Menu menu[], int jumlahMenu, int pesanan[], int& totalPesanan) {
    do {
        cout << "\n=== Pemesanan ===\n";
        tampilkanMenu(menu, jumlahMenu);

        int nomorMenu;
        int jumlahPesan;

        cout << "Masukkan nomor menu yang ingin dipesan (0 untuk selesai): ";
        cin >> nomorMenu;

        if (nomorMenu >= 1 && nomorMenu <= jumlahMenu) {
            nomorMenu--;  // Ubah nomorMenu menjadi indeks array (dimulai dari 0)

            cout << "Masukkan jumlah pesanan: ";
            cin >> jumlahPesan;

            pesanan[nomorMenu] += jumlahPesan;
            totalPesanan += jumlahPesan;

            cout << "Pesan menu lagi (y/n)? ";
            char lanjut;
            cin >> lanjut;

            if (lanjut != 'y' && lanjut != 'Y') {
                break;
            }
        } else if (nomorMenu != 0) {
            cout << "Nomor menu tidak valid. Silakan masukkan nomor menu yang benar.\n";
        }

    } while (true);
}


void hitungTotalPembayaran(const Menu menu[], int pesanan[], int totalPesanan) {
    int total = 0;
    cout << "\n=== Struk Pesanan ===\n";
    for (int i = 0; i < MAX_MENU; ++i) {
        if (pesanan[i] > 0) {
            cout << pesanan[i] << " x " << menu[i].nama << " = " << pesanan[i] * menu[i].harga << "\n";
            total += pesanan[i] * menu[i].harga;
        }
    }
    cout << "---------------------\n";
    cout << "Total Pembayaran: " << total << "\n";
}

int linearSearch(const Menu menu[], int jumlahMenu, const string& namaMenu) {
    for (int i = 0; i < jumlahMenu; ++i) {
        if (namaMenu == menu[i].nama) {
            return i;
        }
    }
    return -1;  // Menu tidak ditemukan
}
