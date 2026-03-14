#include <stdio.h>
#include <string.h>

typedef struct{
    char nama[50];
    int harga;
}Menu;

/* ================= DATA MENU ================= */

Menu makanan[]={
{"Nasi Goreng",15000},{"Soto",12000},{"Mie Ayam",12000},
{"Batagor",10000},{"Kentang Goreng",15000},{"Piscok",10000},
{"Roti Isi Ayam",15000},{"Tela Tela",10000},{"Nugget",15000},
{"Sosis",15000},{"Tempe Goreng",10000},{"Bakwan",10000},{"Tahu Goreng",10000}
};

Menu kopi[]={
{"Kopi Hitam",12000},{"Sanger",15000},{"Hazelnut",15000},
{"Espresso",17000},{"Americano",20000},{"Caffe Latte",25000},
{"Cappuccino",15000},{"Mochaccino",18000},{"Caramel Macchiato",20000},
{"Dalgona Coffee",25000}
};

/* ================= FUNGSI ================= */

void tampilMenuMakanan(){
    printf("\n=== MENU MAKANAN ===\n");
    for(int i=0;i<13;i++){
        printf("%d. %s - Rp%d\n",i+1,makanan[i].nama,makanan[i].harga);
    }
}

void tampilMenuMinuman(){
    printf("\n=== MENU MINUMAN ===\n");
    printf("1. Kopi\n");
    printf("2. Matcha - Rp15000\n");
    printf("3. Sogem - Rp10000\n");
    printf("4. Teh Manis - Rp8000\n");
}

void tampilMenuKopi(){
    printf("\n=== JENIS KOPI ===\n");
    for(int i=0;i<10;i++){
        printf("%d. %s - Rp%d\n",i+1,kopi[i].nama,kopi[i].harga);
    }
}

void hitungWaktu(int jam,int menit){

    int min1=menit+20;
    int min2=menit+30;
    int jam1=jam;
    int jam2=jam;

    if(min1>=60){
        jam1++;
        min1-=60;
    }

    if(min2>=60){
        jam2++;
        min2-=60;
    }

    printf("Estimasi pengambilan : %02d:%02d - %02d:%02d\n",
           jam1,min1,jam2,min2);
}

/* ================= MAIN ================= */

int main(){

    int pilihMakanan,porsi;
    int pilihMinuman,jumlahMinuman;
    int jenisKopi;
    int gula;
    int pembayaran;
    int jam,menit;

    char namaMinuman[50];
    int hargaMinuman=0;

    printf("=================================\n");
    printf(" SISTEM KAFETARIA IT DEL\n");
    printf("=================================\n");

    /* ===== INPUT MAKANAN ===== */

    tampilMenuMakanan();

    do{
        printf("\nPilih nomor makanan : ");
        scanf("%d",&pilihMakanan);
    }while(pilihMakanan<1 || pilihMakanan>13);

    printf("Jumlah porsi : ");
    scanf("%d",&porsi);

    /* ===== INPUT MINUMAN ===== */

    tampilMenuMinuman();

    do{
        printf("\nPilih nomor minuman : ");
        scanf("%d",&pilihMinuman);
    }while(pilihMinuman<1 || pilihMinuman>4);

    if(pilihMinuman==1){

        tampilMenuKopi();

        do{
            printf("Pilih jenis kopi : ");
            scanf("%d",&jenisKopi);
        }while(jenisKopi<1 || jenisKopi>10);

        strcpy(namaMinuman,kopi[jenisKopi-1].nama);
        hargaMinuman=kopi[jenisKopi-1].harga;
    }
    else if(pilihMinuman==2){
        strcpy(namaMinuman,"Matcha");
        hargaMinuman=15000;
    }
    else if(pilihMinuman==3){
        strcpy(namaMinuman,"Sogem");
        hargaMinuman=10000;
    }
    else{
        strcpy(namaMinuman,"Teh Manis");
        hargaMinuman=8000;
    }

    printf("Jumlah minuman : ");
    scanf("%d",&jumlahMinuman);

    /* ===== OPSI GULA ===== */

    printf("\nPilihan gula\n");
    printf("1. Less Sugar\n");
    printf("2. No Sugar\n");
    printf("3. Normal\n");
    printf("Pilihan : ");
    scanf("%d",&gula);

    /* ===== WAKTU ===== */

    printf("\nMasukkan waktu pemesanan (jam menit) : ");
    scanf("%d %d",&jam,&menit);

    /* ===== PEMBAYARAN ===== */

    printf("\nJenis pembayaran\n");
    printf("1. Transfer\n");
    printf("2. Cash\n");
    printf("Pilihan : ");
    scanf("%d",&pembayaran);

    /* ===== PERHITUNGAN ===== */

    int totalMakanan=makanan[pilihMakanan-1].harga*porsi;
    int totalMinuman=hargaMinuman*jumlahMinuman;
    int total=totalMakanan+totalMinuman;

    /* ===== OUTPUT ===== */

    printf("\n=================================\n");
    printf(" STRUK PEMESANAN\n");
    printf("=================================\n");

    printf("\nMakanan : %s\n",makanan[pilihMakanan-1].nama);
    printf("Jumlah  : %d porsi\n",porsi);
    printf("Harga   : Rp%d\n",totalMakanan);

    printf("\nMinuman : %s\n",namaMinuman);
    printf("Jumlah  : %d\n",jumlahMinuman);
    printf("Harga   : Rp%d\n",totalMinuman);

    if(gula==1) printf("Gula    : Less Sugar\n");
    else if(gula==2) printf("Gula    : No Sugar\n");
    else printf("Gula    : Normal\n");

    if(pembayaran==1)
        printf("\nPembayaran : Transfer\n");
    else
        printf("\nPembayaran : Cash\n");

    printf("\n");
    hitungWaktu(jam,menit);

    printf("\nTotal Bayar : Rp%d\n",total);

    printf("\nTerima kasih telah memesan!\n");

    return 0;
}