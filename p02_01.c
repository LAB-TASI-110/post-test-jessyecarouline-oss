#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define DISCOUNT 0.10

// struktur data kota
typedef struct {
    char kode[4];
    char nama[20];
    int harga;
    char kategori[15];
} Kota;

// daftar kota
Kota daftarKota[] = {
    {"MDN", "Medan", 8000, "Dalam Pulau"},
    {"BLG", "Balige", 5000, "Dalam Pulau"},
    {"JKT", "Jakarta", 12000, "Luar Pulau"},
    {"SBY", "Surabaya", 13000, "Luar Pulau"}
};

int jumlahKota = 4;


// fungsi mencari kota berdasarkan kode
int cariKota(char kode[]) {
    for(int i = 0; i < jumlahKota; i++) {
        if(strcmp(kode, daftarKota[i].kode) == 0) {
            return i;
        }
    }
    return -1;
}


// fungsi menghitung berat ucok
float hitungBeratUcok(float beratButet) {
    return 1.5 * beratButet;
}


// fungsi menghitung ongkir
float hitungOngkir(float totalBerat, int harga) {
    return totalBerat * harga;
}


// fungsi mencetak struk
void cetakStruk(char kota[], float butet, float ucok, float totalBerat, float ongkir, int luarPulau, int diskon) {

    printf("\n========== STRUK PEMBAYARAN ==========\n");
    printf("Kota Tujuan          : %s\n", kota);
    printf("Berat Paket Butet    : %.2f kg\n", butet);
    printf("Berat Paket Ucok     : %.2f kg\n", ucok);
    printf("Total Berat          : %.2f kg\n", totalBerat);

    if(diskon) {
        float potongan = ongkir * DISCOUNT;
        ongkir -= potongan;
        printf("Diskon Lebaran       : 10%% (%.0f)\n", potongan);
    } else {
        printf("Diskon Lebaran       : Tidak ada\n");
    }

    printf("Total Ongkos Kirim   : %.0f\n", ongkir);

    if(luarPulau)
        printf("Promo                : Asuransi GRATIS\n");
    else
        printf("Promo                : Tidak ada\n");

    printf("======================================\n\n");
}


int main() {

    char kode[10];

    while(1) {

        printf("Masukkan kode kota (atau END untuk selesai): ");
        scanf("%s", kode);

        if(strcmp(kode, "END") == 0)
            break;

        int index = cariKota(kode);

        if(index == -1) {
            printf("Kode kota tidak ditemukan!\n\n");
            continue;
        }

        float beratButet;

        printf("Masukkan berat paket Butet (kg): ");
        if(scanf("%f", &beratButet) != 1 || beratButet <= 0) {
            printf("Input berat tidak valid!\n");
            while(getchar()!='\n');
            continue;
        }

        float beratUcok = hitungBeratUcok(beratButet);
        float totalBerat = beratButet + beratUcok;

        float ongkir = hitungOngkir(totalBerat, daftarKota[index].harga);

        int diskon = 0;
        if(totalBerat > 10)
            diskon = 1;

        int luarPulau = 0;
        if(strcmp(daftarKota[index].kategori, "Luar Pulau") == 0)
            luarPulau = 1;

        cetakStruk(
            daftarKota[index].nama,
            beratButet,
            beratUcok,
            totalBerat,
            ongkir,
            luarPulau,
            diskon
        );
    }

    printf("\nProgram selesai.\n");

    return 0;
}