#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// fungsi untuk validasi input integer
int inputInt(const char *message) {
    int value;
    int check;

    do {
        printf("%s", message);
        check = scanf("%d", &value);

        while(getchar() != '\n'); // membersihkan buffer

        if(check != 1) {
            printf("Input tidak valid! Masukkan angka.\n");
        }

    } while(check != 1);

    return value;
}

// fungsi menghitung total stok berdasarkan kategori
int hitungTotalKategori(int stok[], int kategori[], int n, int kodeKategori) {
    int total = 0;

    for(int i = 0; i < n; i++) {
        if(kategori[i] == kodeKategori) {
            total += stok[i];
        }
    }

    return total;
}

// fungsi menampilkan kategori
void tampilKategori() {
    printf("\nDaftar Kategori:\n");
    printf("1. Dasi SD\n");
    printf("2. Gula\n");
    printf("3. Rok Pramuka\n");
    printf("4. Minyak\n");
}

int main() {

    int N;
    int stok[MAX];
    int kategori[MAX];
    int kodeCari;
    int total;

    printf("=== Program Perhitungan Stok Gudang ===\n");

    // input jumlah data
    do {
        N = inputInt("Masukkan jumlah total data (N): ");

        if(N <= 0 || N > MAX) {
            printf("Jumlah data harus antara 1 - %d\n", MAX);
        }

    } while(N <= 0 || N > MAX);

    // input data stok
    for(int i = 0; i < N; i++) {

        printf("\nData ke-%d\n", i+1);

        stok[i] = inputInt("Masukkan jumlah stok: ");

        do {
            tampilKategori();
            kategori[i] = inputInt("Masukkan kode kategori: ");

            if(kategori[i] < 1 || kategori[i] > 4) {
                printf("Kode kategori tidak valid!\n");
            }

        } while(kategori[i] < 1 || kategori[i] > 4);
    }

    // kategori yang ingin dihitung
    tampilKategori();
    kodeCari = inputInt("\nMasukkan kode kategori yang ingin dihitung total stoknya: ");

    // hitung total
    total = hitungTotalKategori(stok, kategori, N, kodeCari);

    printf("\nTotal stok untuk kategori %d = %d pcs\n", kodeCari, total);

    return 0;
}
