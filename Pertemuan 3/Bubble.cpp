#include <iostream>     // Buat fitur input/output kayak cout sama cin
using namespace std;    // Biar nggak perlu nulis std:: di depan cout/cin

int main() {            // Program utama mulai dari sini
    int n;              // Variabel buat nyimpen jumlah data
    cout << "Masukkan jumlah elemen data: ";
    cin >> n;           // Input jumlah data dari user

    int data[n];        // Bikin array dengan ukuran sesuai jumlah data
    cout << "Masukkan elemen-elemen data: \n";
    for (int i = 0; i < n; i++) {  // Loop buat masukin data satu-satu
        cin >> data[i];             // Nyimpen input ke array
    }

    // Proses ngurutin data pake metode Bubble Sort (dari kecil ke gede)
    for (int i = 0; i < n - 1; i++) {          // Loop luar, ngatur berapa kali ngulang
        for (int j = 0; j < n - i - 1; j++) {  // Loop dalam, bandingin elemen bersebelahan
            if (data[j] > data[j + 1]) {       // Kalau yang kiri lebih gede dari kanan
                int temp = data[j];            // Simpen dulu nilai kiri
                data[j] = data[j + 1];         // Tuker posisi kiri sama kanan
                data[j + 1] = temp;            // Masukin nilai yang disimpen ke posisi kanan
            }
        }
    }

    cout << "Data setelah diurutkan dari terkecil hingga terbesar:\n";
    for (int i = 0; i < n; i++) {   // Loop buat nampilin hasil akhirnya
        cout << data[i] << " ";      // Cetak tiap elemen yang udah keurut
    }
    cout << endl;                    // Ganti baris setelah semua data dicetak

    return 0;   // Program selesai tanpa error
}