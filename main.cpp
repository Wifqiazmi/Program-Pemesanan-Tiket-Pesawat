#include <iostream>
#include <iomanip>
#include <unistd.h>

using namespace std;

struct pesawat {
    int jml_pnp, asal, tujuan, kls_pen, pil_pen, rin_harga, tot_harga, bayar, bank, elek, konf, biaya_kelas, biaya_maskapai, biaya_perjalanan, biaya_perorang, biaya_total, jml_anak, biaya_anak ;
    string nama, tgl, nama_depan, nama_belakang, no_telp, email, kota, kota_asal, kota_tujuan, kode_penerbangan, maskapai_penerbangan, seat, waktu_penerbangan, kelas_penerbangan ;
    int edell[5] = {1,5,4,2,3};

    pesawat *next;
};

pesawat krt;
pesawat *tiket, *hapus, *newtiket, *tail;
pesawat *pmbyrn;

void kota(int a)
{
    switch (a)
    {
        case 1:
        krt.kota = "Surabaya";
        break;
         case 2:
        krt.kota = "Jakarta";
        break;
         case 3:
        krt.kota = "Medan";
        break;
         case 4:
        krt.kota = "Semarang";
        break;
    }
}

void infoPerjalanan(string kota_asal, string kota_tujuan)//untuk menyeleksi kota asal dan kota tujuan
{
    if(kota_asal == "Jakarta")
    {
        if(kota_tujuan == "Surabaya")
        {
            krt.biaya_perjalanan = 13900;
        }
        else if(kota_tujuan == "Medan")
        {
            krt.biaya_perjalanan = 18600;
        }
        else if(kota_tujuan == "Semarang")
        {
            krt.biaya_perjalanan = 27700;
        }
    }
    else if(kota_asal == "Surabaya")
    {
         if(kota_tujuan == "Jakarta")
        {
            krt.biaya_perjalanan = 12600;
        }
        else if(kota_tujuan == "Medan")
        {
            krt.biaya_perjalanan = 28600;
        }
        else if(kota_tujuan == "Semarang")
        {
            krt.biaya_perjalanan = 23100;
        }
    }
     else if(kota_asal == "Medan")
    {
         if(kota_tujuan == "Jakarta")
        {
            krt.biaya_perjalanan = 17800;
        }
        else if(kota_tujuan == "Surabaya")
        {
            krt.biaya_perjalanan = 27303;
        }
        else if(kota_tujuan == "Semarang")
        {
            krt.biaya_perjalanan = 32700;
        }
    }
     else if(kota_asal == "Semarang")
    {
         if(kota_tujuan == "Medan")
        {
            krt.biaya_perjalanan = 236200;
        }
        else if(kota_tujuan == "Jakarta")
        {
            krt.biaya_perjalanan = 81200;
        }
        else if(kota_tujuan == "Surabaya")
        {
            krt.biaya_perjalanan = 17000;
        }
    }

}

void kelas(int v)
{
    switch(v)
    {
        case 1:
            krt.kelas_penerbangan = "Kelas Economy";
            krt.biaya_kelas = 10000;
            krt.seat = "0015";
            break;
        case 2:
            krt.kelas_penerbangan = "Kelas Premium";
            krt.biaya_kelas = 15000;
            krt.seat = "0023";
            break;
        case 3:
            krt.kelas_penerbangan = "Kelas Business";
            krt.biaya_kelas = 20000;
            krt.seat = "0071";
            break;
        case 4:
            krt.kelas_penerbangan = "Kelas First Class";
            krt.biaya_kelas = 25000;
            krt.seat = "0031";
            break;
    }
}

void maskapai(int z)
{
    switch(z)
    {
    case 1:
        krt.maskapai_penerbangan = "Batik Air";
        krt.biaya_maskapai = 12500;
        krt.kode_penerbangan = "ID" ;
;       krt.waktu_penerbangan = "09.30";
        break;
     case 2:
        krt.maskapai_penerbangan = "Garuda Indonesia";
        krt.biaya_maskapai = 15900 ;
        krt.kode_penerbangan = "GA";
        krt.waktu_penerbangan = "02.30";
        break;
     case 3:
        krt.maskapai_penerbangan = "Lion Air";
        krt.biaya_maskapai = 12400;
        krt.kode_penerbangan = "JT";
        krt.waktu_penerbangan = "05.25";
        break;

    }
}

void pemesanan (int i)
{
    //string r;
    cout << " ----------------------------------------"<<endl;
    cout << " >>    SILAHKAN INPUT DATA PESANAN     <<"<<endl;
    cout << " ----------------------------------------"<<endl;
    cout << endl;
    cout << " Nama Depan        : "; cin >> krt.nama_depan;
    cout << " Nama Belakang     : "; cin >> krt.nama_belakang;
    cout << " Nomor Telepon     : "; cin >> krt.no_telp;
    cout << " Alamat E-mail     : "; cin >> krt.email;
    cout << endl;

}

void rin_harga(int k)
{
    cout <<endl;
    cout << " Maskapai Penerbangan      : " << krt.maskapai_penerbangan <<endl;
    cout << " Waktu    Penerbangan      : " << krt.waktu_penerbangan <<endl;
    cout << " Kelas    Penerbangan      : " << krt.kelas_penerbangan << endl;
    cout << " Asal     Penerbangan      : " << krt.kota_asal <<endl;
    cout << " Tujuan   Penerbangan      : " << krt.kota_tujuan <<endl;
    cout << endl;
    krt.biaya_perorang = (krt.biaya_perjalanan + krt.biaya_maskapai + krt.biaya_kelas );
    krt.biaya_anak = krt.biaya_perorang - 15000;
    krt.biaya_total = krt.biaya_perorang + krt.biaya_anak;
    cout << " __________________________________________"<<endl;
    cout << endl;
    cout << " Biaya Total " << k << " penumpang = " << krt.biaya_total <<endl;
    cout << " __________________________________________"<<endl;

    cout << endl;
    cout << " Silahkan di cek kembali  apakah pemesanan sudah benar ?"<<endl;



}


int pembayaran (int r)
{
    //string k;
    pmbyrn = new pesawat();
    int bayar, lanjut;
    cout << " --------------------------------------------------"<<endl;
    cout << " >>    SILAHKAN PILIH MENU MRTODE PEMBAYARAN     <<"<<endl;
    cout << " --------------------------------------------------"<<endl;
    cout << endl;
    cout << "  1.Pembayaran E-Wallet                 "<<endl;
    cout << "  2.Tranfer Bank                        "<<endl;
    cout << endl;
    cout << " ---------------------------------------"<<endl;
    cout << endl;
    cout << " Pilih : "; cin >> bayar;
    cout <<endl;
    if(bayar==1){
        cout << " __________________________________________________________________________"<<endl;
        cout << endl;
        cout << "                    CARA PEMBAYARAN VIA GOPAY/OVO/DANA                     "<<endl;
        cout << " __________________________________________________________________________"<<endl;
        cout << endl;
        cout << " 1. pertama-tama masukan kode pembayaran ke menu pada transaksi"<<endl;
        cout << "    masing-masing aplikasi pembayaran dengan total yang sudah tertera"<<endl;
        cout << endl;
        cout << " 2. Setelah pembayaran sukses, di mohon untuk mengonfirmasikan PEMBAYARAN "<<endl;
        cout << "    Kode Pembayaran : TXT" << krt.no_telp <<endl;
        cout << endl;
    }
    else
    if (bayar==2){
        cout << " __________________________________________________________________________"<<endl;
        cout << endl;
        cout << "                    CARA PEMBAYARAN TRANSFER BANK                          "<<endl;
        cout << " __________________________________________________________________________"<<endl;
        cout << endl;
        cout << " 1. ( BCA ) : - Silahkan pilih M-Transfer > BCA Virtual Account "<<endl;
        cout << "              - Masukkan nomor Virtual Account 126 08238xxxxx dan pilih send"<<endl;
        cout << "              - Pilih menu 'Lanjutkan' "<<endl;
        cout << "              - Ikuti cara pembayaran yang tersedia "<<endl;
        cout << " 2. ( BNI ) : - Silahkan pilih Metode pembayaran Virtual Account "<<endl;
        cout << "              - Masukkan nomor Virtual Account 126 08238xxxxx dan pilih send"<<endl;
        cout << "              - Pilih menu 'Lanjutkan' "<<endl;
        cout << "              - Ikuti cara pembayaran yang tersedia "<<endl;
        cout << endl;
        cout << " Setelah pembayaran sukses, di mohon untuk mengonfirmasikan PEMBAYARAN "<<endl;
        cout << endl;
    }
    return 0;
}

void push(string nama_depan, string nama_belakang, string email, string no_telp, string k_asal, string k_tujuan, int jpnp, int jank, string tggl, string kel_pen, int biaya_perorang, int biaya_anak, int biaya_total, string maskapai_penerbangan, string waktu_penerbangan, string kode_penerbangan, string seat)
{
    if (tiket == NULL)
    {
        tiket = new pesawat();
        tiket->nama_depan = nama_depan;
        tiket->nama_belakang = nama_belakang;
        tiket->email = email;
        tiket->kota_asal = k_asal;
        tiket->kota_tujuan = k_tujuan;
        tiket->jml_pnp = jpnp;
        tiket->jml_anak = jank;
        tiket->tgl = tggl;
        tiket->kelas_penerbangan = kel_pen;
        tiket->biaya_perorang = biaya_perorang;
        tiket->maskapai_penerbangan = maskapai_penerbangan;
        tiket->no_telp = no_telp;
        tiket->biaya_anak = biaya_anak;
        tiket->biaya_total = biaya_total;
        tiket->waktu_penerbangan = waktu_penerbangan;
        tiket->kode_penerbangan = kode_penerbangan;
        tiket->seat = seat;
        tiket->next = NULL;
        tail = tiket;
    }
    else
    {
        newtiket = new pesawat();
        newtiket = new pesawat();
        newtiket->nama_depan = nama_depan;
        newtiket->nama_belakang = nama_belakang;
        newtiket->email = email;
        newtiket->kota_asal = k_asal;
        newtiket->kota_tujuan = k_tujuan;
        newtiket->jml_pnp = jpnp;
        newtiket->jml_anak = jank;
        newtiket->tgl = tggl;
        newtiket->kelas_penerbangan = kel_pen;
        newtiket->biaya_perorang = biaya_perorang;
        newtiket->biaya_anak = biaya_anak;
        newtiket->biaya_total = biaya_total;
        newtiket->waktu_penerbangan = waktu_penerbangan;
        newtiket->kode_penerbangan = kode_penerbangan;
        newtiket->seat = seat;
        newtiket->next = NULL;
        tail = tiket;

    }
}

void pop()//batal
{
    hapus = tiket;
    tiket = tiket->next;
    delete hapus;
}

void rin_pesanan(int q)

{
    cout << " ---------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout << " |      Nama      |   No Telepon  |   kota Asal   |    Kota Tujuan  |  Jumlah Penumpang  |  Tanggal Keberangkatan  |    Kelas Penerbangan   |"<<endl;
    cout << " ---------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
             cout << setw(8) << tiket->nama_depan << " " << tiket ->nama_belakang << setw(19) << tiket->no_telp << setw(18) << tiket->kota_asal << setw(17) << tiket->kota_tujuan << setw(19) << tiket->jml_pnp << setw(20) << tiket->tgl << setw(30) << tiket->kelas_penerbangan << setw(20);
    cout << endl;
    cout << endl;
    cout << " -------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout << " |  Maskapai Penerbangan  |   Waktu Penerbangan   |  Kode Penerbangan  |   Nomer Penerbangan   |   Biaya Dewasa   |    Biaya Anak    |   Biaya Total   |"<<endl;
    cout << " -------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
         cout << setw(19) << tiket->maskapai_penerbangan << setw(20) << tiket ->waktu_penerbangan << setw(20) << tiket->kode_penerbangan << setw(20) << tiket->seat << setw(19) << tiket->biaya_perorang << setw(19) << tiket->biaya_anak << setw(20) << tiket->biaya_total << setw(20);
    cout << endl;
    cout << " -------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout << endl;
}

void domestik()
{
    int lanjut, inputmenu2;
    cout << " ========================"<<endl;
    cout << "      Pemesanan Tiket    "<<endl;
    cout << "        PENERBANGAN      "<<endl;
    cout << " ========================"<<endl;
    cout << endl;
    cout << " ------------------------"<<endl;
    cout << " >>     Asal Kota      <<"<<endl;
    cout << " ------------------------"<<endl;
    cout << endl;
    cout << " 1. Surabaya  (SRB)"<<endl;
    cout << " 2. Jakarta   (JKT)"<<endl;
    cout << " 3. Medan     (MDN)"<<endl;
    cout << " 4. Semarang  (SRG)"<<endl;
    cout << endl;
    cout << " pilih : "; cin >> krt.asal;
    kota(krt.asal);
    krt.kota_asal = krt.kota;
    cout << endl;
    cout << " ------------------------"<<endl;
    cout << " >>    Kota Tujuan     <<"<<endl;
    cout << " ------------------------"<<endl;
    cout << " 1. Surabaya  (SRB)"<<endl;
    cout << " 2. Jakarta   (JKT)"<<endl;
    cout << " 3. Medan     (MDN)"<<endl;
    cout << " 4. Semarang  (SRG)"<<endl;
    cout << endl;

    cout << " pilih : "; cin >> krt.tujuan;
    kota(krt.tujuan);
    krt.kota_tujuan = krt.kota;
    infoPerjalanan(krt.kota_asal, krt.kota_tujuan);
    cout << endl;
    cout << " Tanggal Keberangkatan : "; cin >> krt.tgl;
    cout << endl;
    cout << " ---------------------------"<<endl;
    cout << " >>    Jumlah Penumpang   <<"<<endl;
    cout << " ---------------------------"<<endl;
    cout << endl;
    cout << " Penumpang Dewasa : "; cin >> krt.jml_pnp;
    cout << " Penumpang Anak   : "; cin >> krt.jml_anak;
    cout << endl;
    cout << " ------------------------------"<<endl;
    cout << " >>     Kelas Penerbangan    <<"<<endl;
    cout << " ------------------------------"<<endl;
    cout << endl;
    cout << " 1. Kelas Economy "<<endl;
    cout << " 2. Kelas Premium "<<endl;
    cout << " 3. Kelas Bussines "<<endl;
    cout << " 4. Kelas First Class "<<endl;
    cout << endl;
    cout << " pilih : "; cin >> krt.kls_pen;
    kelas(krt.kls_pen);
    cout << endl;
    cout << " ------------------------------------------------------------"<<endl;
    cout << " >>                   Maskapai Penerbangan                 <<"<<endl;
    cout << " ------------------------------------------------------------"<<endl;
    cout << endl;
    cout << " 1. Batik Air              09:30 -> 11:00        Rp.1.250.000 "<<endl;
    cout << " 2. Garuda Indonesia       02:30 -> 04:30        Rp.1.590.000 "<<endl;
    cout << " 3. Lion Air               04:45 -> 05:25        Rp.1.240.000 "<<endl;
    cout << endl;
    cout << " pilih : "; cin >> krt.pil_pen;
    maskapai(krt.pil_pen);
    cout <<endl;
    pemesanan(lanjut);
    cout << " ------------------------------"<<endl;
    cout << " >>    Rincian Pemesanan     <<"<<endl;
    cout << " ------------------------------"<<endl;
    rin_harga(krt.jml_pnp);
    cout <<endl;
    cout << " ---------------------------------"<<endl;
    cout << " >>    Lanjut Ke pembayaran     <<"<<endl;
    cout << " ---------------------------------"<<endl;
    cout <<endl;
    cout << " 1. IYA "<<endl;
    cout << " 2. TIDAK "<<endl;
    cout << endl;
    cout << " pilih : "; cin >> lanjut;
    cout << endl;
    switch(lanjut){
     case 1:
        {
            pembayaran(lanjut);
            break;
        }
     case 2:
     domestik();
     }
     cout << " ----------------------------------"<<endl;
     cout << " >>     Konfirmasi Pembayaran    <<"<<endl;
     cout << " ----------------------------------"<<endl;
     cout << endl;
     cout << " 1. Sudah Bayar "<<endl;
     cout << " 2. Saya Ingin Membatalkan Pesanan "<<endl;
     cout << endl;
     cout << " -----------------------------------------"<<endl;
     cout << endl;
     cout << " Pilihan Anda : "; cin >> inputmenu2;
     cout << endl;
     switch(inputmenu2)
     {
        case 1:
        {
            push(krt.nama_depan, krt.nama_belakang, krt.email, krt.no_telp, krt.kota_asal, krt.kota_tujuan, krt.jml_pnp, krt.jml_anak, krt.tgl, krt.kelas_penerbangan , krt.biaya_perorang, krt.biaya_anak, krt.biaya_total, krt.maskapai_penerbangan, krt.waktu_penerbangan, krt.kode_penerbangan, krt.seat);
            rin_pesanan(inputmenu2);
            break;
        }
        case 2:
        {
           pop();
           cout << " Pesanan Anda akan dibatalkan " <<endl;
           exit(0);
           break;
        }
     }
}

int search02(int edel[], int JmlElemenArray, int Elemen)
{
    int flaq = -1;
    for(int count = 0; count<JmlElemenArray; count++)
    {
        if(Elemen==edel[count])
        {
            flaq=count;
            break;
        }
    }
    return flaq;
}

int hargatiket()
{
    const int JmlElemenArray = 3;
    int edel[JmlElemenArray] = {1300000,1426000,1500000};
    cout << " ==================================================="<<endl;
    cout << " ||  DAFTAR MASKAPAI PENERBANGAN DAN HARGA TIKET  ||"<<endl;
    cout << " ==================================================="<<endl;
    cout << endl;
    for(int count=0; count<JmlElemenArray; count++)
    {
        cout << "\t" << count+1 << " " << " Harga Tiket Pesawat " << "---> "<<edel[count]<<endl;
    }
    int searchElemen=0;
    int flaq=0;
    cout << endl;
    cout << "''''''''''''''''''''''''''''''''''''''''''''''''''''"<<endl;
    cout << endl;
    cout << " Silahkan masukan harga yang akan di cari ? "; cin >>searchElemen;
    flaq=search02(edel, JmlElemenArray, searchElemen);
    if(flaq != -1)
        cout << " Harga yang anda cari di temukan pada : pesawat " << flaq+1 <<endl;
    else
        cout << " Data yang anda cari tidak ditemukan " <<endl;
    cin.get();
    return 0;

}

void menupilihan()
{
    int inputmenu;
    do
    {
        cout << " ===================================================="<<endl;
        cout << "      SELAMAT DATANG DI MASKAPAI PENERBANGAN         "<<endl;
        cout << "                 KELOMPOK 13                         "<<endl;
        cout << " ===================================================="<<endl;
        cout << endl;
        cout << " _________________________________"<<endl;
        cout << endl;
        cout << "   >>>>> SILAHKAN PILIH MENU <<<<<"<<endl;
        cout << " _________________________________"<<endl;
        cout << endl;
        cout << " (1). Beli Tiket Penerbangan      "<<endl;
        cout << " (2). Cek Harga Tiket Penerbangan "<<endl;
        cout << " (3). Keluar                      "<<endl;
        cout << endl;
        cout << " Masukan pilihan anda  : "; cin>> inputmenu;
        cout << endl;
        switch(inputmenu)
        {
            case 1:
            {
                domestik();
                break;
            }
             case 2:
            {
                hargatiket();
                break;
            }
             case 3:
            {
                exit(0);
                break;
            }
        }
    }
    while (inputmenu > 3);
}

void merge(int low, int mid, int high){
    int a,b,c,edel[50],d;
    a = low;
    b = low;
    c = mid+1;
    while((a<=mid)&&(c<=high)){
        if(krt.edell[a]<=krt.edell[c]){
            edel[b]=krt.edell[a]; a++;
        }else{
            edel[b]=krt.edell[c]; c++;
        }b++;
    }
    if (a>mid){
        for (d=c;d<=high;d++){
            edel[b]=krt.edell[d];b++;
        }
    }
    else {
        for (d=a; d<=mid; d++){
            edel[b]=krt.edell[d];b++;
        }
    }
    for (d=low; d<=high; d++)
        krt.edell[d] = edel[d];
}

void merge_sort(int low, int high){
    int mid;
    if(low<high){
        mid = (low+high)/2;
        merge_sort(low,mid);
        merge_sort(mid+1,high);
        merge(low,mid,high);
    cout <<endl;
    }
}

int main()
{
    menupilihan();
    cout << endl;
    merge_sort(0,5);
    for (int b=1;b<6;b++)
        cout << krt.edell[b] << " ";
    cout << " Terimakasih atas pesanan Anda "<<endl;
    cout <<endl;
    cin.get();
}

