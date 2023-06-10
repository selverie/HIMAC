#include <stdio.h> // untuk fungsi input-output standar
#include <stdlib.h> // untuk fungsi exit()
#include <string.h> // untuk fungsi pemrosesan string

// Definiskan sebuah struct invoice yang memiliki beberapa variabel seperti di bawah ini
struct Invoice {
    char struk[100];
    char admin[100];
    char nama_penyewa[100];
    char nik[100];
    char nomor_telepon[100];
    char jenis_mobil[100];
    char plat_nomor[100];
    int durasi_sewa;
    float harga_sewa_per_hari;
    float diskon;
    char tanggal_sewa[100];
    char batas_sewa[100];
};

// Fungsi InvoiceSewa untuk mencetak detail invoice sewa sesuai dengan data yang disimpan dalam struct Invoice 
void printInvoiceSewa(struct Invoice invoice) {
    printf("%s\n", invoice.struk);
    printf("%s\n", invoice.admin);
    printf("-----------------------------");
    
    printf("\nNama Penyewa    : %s\n", invoice.nama_penyewa);
    printf("NIK             : %s\n", invoice.nik);
    printf("Nomor Telepon   : %s\n", invoice.nomor_telepon);
    printf("-----------------------------");
    
    printf("\nJenis Mobil     : %s\n", invoice.jenis_mobil);
    printf("Plat Nomor      : %s\n", invoice.plat_nomor);
    printf("Durasi Sewa     : %d hari\n", invoice.durasi_sewa);
    printf("Harga Sewa/hari : %.2f\n", invoice.harga_sewa_per_hari);
    printf("Diskon          : %.2f%%\n", invoice.diskon);
    printf("Tanggal Sewa    : %s\n", invoice.tanggal_sewa);
    printf("Batas Sewa      : %s\n", invoice.batas_sewa);
}

// Fungsi InvoiceKembali mencetak detail invoice pengembalian beserta jumlah pembayaran dan kembalian.
void printInvoiceKembali(struct Invoice invoice, float jumlah_pembayaran) {
    printf("-----------------------------");
    printf("\n       Struk Pembayaran");
    printf("\n     Sewa Mobil Pak Fajar");
    printf("\nJl.Magelang Km.12 No.5 Sleman\n\n");
    printf("%s\n", invoice.struk);
    printf("%s\n", invoice.admin);
    printf("-----------------------------");
    
    printf("\nNama Penyewa      : %s\n", invoice.nama_penyewa);
    printf("NIK               : %s\n", invoice.nik);
    printf("Nomor Telepon     : %s\n", invoice.nomor_telepon);
    printf("-----------------------------");
    
    printf("\nJenis Mobil       : %s\n", invoice.jenis_mobil);
    printf("Plat Nomor        : %s\n", invoice.plat_nomor);
    printf("Durasi Sewa       : %d Hari\n", invoice.durasi_sewa);
    printf("Harga Sewa/hari   : %.2f\n", invoice.harga_sewa_per_hari);
    printf("\nDiskon            : %.2f%%\n", invoice.diskon);
    printf("Tanggal Sewa      : %s\n", invoice.tanggal_sewa);
    printf("Batas Sewa        : %s\n", invoice.batas_sewa);
    printf("-----------------------------");
    
    printf("\nJumlah Pembayaran : %.2f\n", jumlah_pembayaran);
    float total_sewa = (invoice.harga_sewa_per_hari * invoice.durasi_sewa) - ((invoice.diskon / 100) * (invoice.harga_sewa_per_hari * invoice.durasi_sewa));
    printf("Total Pembayaran  : %.2f\n", total_sewa);
    float kembalian = jumlah_pembayaran - total_sewa;
    printf("Kembalian         : %.2f\n", kembalian);
    printf("-----------------------------\n");
}

// Di dalam fungsi main, terdapat variabel-variabel yang digunakan untuk menyimpan input dan menu yang dipilih. 
int main() {
    struct Invoice invoice; // Variabel invoice bertipe struct untuk menyimpan data invoice yang sedang diproses
    int menu; // Variabel menu untuk menyimpan pilihan menu yang dipilih pengguna.
    char nomor_struk[100]; // Variabel nomor_struck untuk menyimpan nomor struk yang diinput pengguna saat menu pengembalian dipilih
    float jumlah_pembayaran; // Variabel jumlah_pembayaran untuk menyimpan jumlah pembayaran yang diinput pengguna saat menu pengembalian dipilih. 
    
    // Menggunakan while agar selama program berjalan. Pada setiap iterasi loop, program akan menampilkan menu utama.
    while (1) {
        printf("-----------------------------");
        printf("\n         Menu Utama\n");
        printf("-----------------------------\n");
        printf("1. Menu Sewa\n");
        printf("2. Menu Pengembalian\n");
        printf("3. Exit\n");
        printf("Pilih Menu : ");
        scanf("%d", &menu);
        
        // Menggunakan switch case dalam program ini untuk menangani beberapa pilihan menu yang berbeda. 
        switch (menu) {
            case 1:
                printf("-----------------------------");
                printf("\n       Input Data Sewa\n");
                printf("-----------------------------\n");
                printf("Nomor Struk     : ");
                scanf(" %[^\n]s", invoice.struk);
                printf("Nama Admin      : ");
                scanf(" %[^\n]s", invoice.admin);
                printf("-----------------------------\n");
                printf("Nama Penyewa    : ");
                scanf(" %[^\n]s", invoice.nama_penyewa);
                printf("NIK             : ");
                scanf(" %[^\n]s", invoice.nik);
                printf("Nomor Telepon   : ");
                scanf(" %[^\n]s", invoice.nomor_telepon);
                printf("-----------------------------\n");
                printf("Jenis Mobil     : ");
                scanf(" %[^\n]s", invoice.jenis_mobil);
                printf("Plat Nomor      : ");
                scanf(" %[^\n]s", invoice.plat_nomor);
                printf("Durasi Sewa     : ");
                scanf("%d", &invoice.durasi_sewa);
                printf("Harga Sewa/hari : ");
                scanf("%f", &invoice.harga_sewa_per_hari);
                printf("Diskon          : ");
                scanf("%f", &invoice.diskon);
                printf("Tanggal Sewa    : ");
                scanf(" %[^\n]s", invoice.tanggal_sewa);
                printf("Batas Sewa      : ");
                scanf(" %[^\n]s", invoice.batas_sewa);
                printf("-----------------------------\n\n");
                
                printf("\n-----------------------------");
                printf("\n     Detail Invoice Sewa\n");
                printf("-----------------------------\n");
                printInvoiceSewa(invoice);
                printf("-----------------------------\n\n");
                break;
                
            case 2:
                printf("Nomor Struk: ");
                scanf(" %[^\n]s", nomor_struk);
                printf("Jumlah Pembayaran: ");
                scanf("%f", &jumlah_pembayaran);
                
                // Untuk mengecek apakah nomor struk sesuai dengan data yang tersimpan.
                if (strcmp(nomor_struk, invoice.struk) == 0) {
                    printf("\n\nDetail Invoice Kembali :\n");
                    printInvoiceKembali(invoice, jumlah_pembayaran);
                } else {
                    printf("Data tidak ditemukan.\n");
                }
                break;
                
            case 3:
                printf("Terima kasih. Program selesai.\n");
                exit(0);
                
            default:
                printf("Pilihan tidak valid. Silakan pilih menu yang tersedia.\n");
                break;
        }
        
        printf("\n");
    }
    
    return 0;
}
