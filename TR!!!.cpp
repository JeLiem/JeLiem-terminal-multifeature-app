#include <iostream>
#include <windows.h>
#include <vector>
#include <ctime>
#include <cstring>

using namespace std;

void setWarna(int warna) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, warna);
}

void loading1(){
    system("cls");
    int bar1 = 177, bar2 = 219;

    cout << "\n\n\t\t\t\t\tKELOMPOK 3";
    cout << "\n\n\t\t\t      SELAMAT DATANG DI TUGAS RANCANG";
    cout << "\n\n\t\t\t\t\t Loading...";
    cout << "\n\n\t\t\t\t ";

    for(int i=0; i<25; i++)
    cout << (char)bar1;
    cout << "\r";
    cout << "\t\t\t\t ";  

    for(int i=0; i<25; i++){
        cout << (char)bar2;
        Sleep(150);
    }

    cout << "\n\t\t\t\t" << (char)1 << "!";
    system("Pause");
}

void loading2(){
    system ("cls");
    cout << "Loading";
    Sleep(1000);
    cout << "\rLoading.";
    Sleep(1000);
    cout << "\rLoading..";
    Sleep(1000);
    cout << "\rLoading...";
}

bool login() {
    string username, password;
    const string USERNAME = "DDP F", PASSWORD = "gacor";

    while (true) {
        system("cls");
        cout << "***************************************" << endl;
        cout << "*               TR DDP-F              *" << endl;
        cout << "***************************************" << endl;
        cout << "      USERNAME: ";
        getline(cin, username);
        cout << "      PASSWORD: ";
        getline(cin, password);


        if (username == USERNAME && password == PASSWORD) {
            cout << "\nLogin Berhasil!" << endl;
            cout << "Tekan Enter untuk memulai program...";
            cin.get();
            return true;
        } else {
            cout << "Username atau password salah, coba lagi!" << endl;
            cout << "Tekan Enter untuk mengulang...";
            cin.ignore();
            cin.get();
        }
    }
}

void menuUtama(){
    system("cls");
    cout << "***************************************" << endl;
    cout << "*              KELOMPOK 3             *" << endl;
    cout << "***************************************" << endl;
    cout << "*                Menu :               *" << endl;
    cout << "*                                     *" << endl;
    cout << "* 1. Rumah Pola                       *" << endl;
    cout << "* 2. Bioskop                          *" << endl;
    cout << "* 3. Batu Gunting Kertas              *" << endl;
    cout << "* 4. Bendera                          *" << endl;
    cout << "* 5. Kamus Sederhana                  *" << endl;
    cout << "* 6. Author                           *" << endl; 
    cout << "* 7. Exit                             *" << endl;
    cout << "***************************************" << endl;
    cout << "Pilihan: ";
    }

void rumahPola() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    auto setWarna = [&](int warna) {
        SetConsoleTextAttribute(hConsole, warna);
    };

    int tinggi;
    char bahan;
    char pilihan;

    do {
        system("cls");
        cout << "================================\n";
        cout << "|      Program Rumah Pola      |\n";
        cout << "================================\n";
        cout << "Tentukan Tinggi: ";
        cin >> tinggi;
        cout << "Masukkan Bahan Rumah: ";
        cin >> bahan;

        int lebar = tinggi;

        for (int i = 0; i < tinggi; i++) {
            for (int j = 0; j < tinggi - 1; j++) {
                cout << " ";
            }
            for (int j = 0; j < tinggi - 1; j++) {
                cout << bahan;
            }
            cout << endl;
            Sleep(10);
        }

        for (int i = 0; i < tinggi; i++) {
            for (int j = 0; j < tinggi - i - 1; j++) {
                cout << " "; 
            }
            setWarna(1);
            for (int j = 0; j < (2 * i + 1); j++) {
                cout << bahan;
                Sleep(5);
            }

            for (int j = 0; j < tinggi; j++) {
                cout << "";
            }
            setWarna(4);
            for (int j = 0; j < tinggi * 2; j++) {
                cout << bahan;
                Sleep(5);
            }

            cout << endl;
        }

        for (int i = 0; i < lebar; i++) {
            setWarna(2);
            for (int j = 0; j < tinggi * 2; j++) {
                cout << bahan;
                Sleep(5);
            }

            for (int j = 0; j < tinggi; j++) {
                cout << "";
            }
            setWarna(5);
            for (int j = 0; j < tinggi * 2; j++) {
                cout << bahan;
                Sleep(5);
            }

            cout << endl;
        }

        do {
            cout << "\nU: Ulang\nX: Exit\nPilihan: ";
            cin >> pilihan;

            if (pilihan != 'U' && pilihan != 'u' && pilihan != 'X' && pilihan != 'x') {
                cout << "Input Tidak Valid! Harap masukkan 'U' untuk Ulang atau 'X' untuk Keluar.\n";
            }

        } while (pilihan != 'U' && pilihan != 'u' && pilihan != 'X' && pilihan != 'x');
    } while (pilihan == 'U' || pilihan == 'u');
    setWarna(15);
}

void bioskop() {
    struct Item {
        string nama;
        int harga;
    };

    struct Keranjang {
        string nama;
        int jumlah;
        int totalHarga;
    };

    vector<Item> fnb = {
        {"Popcorn", 35000},
        {"French Fries", 50000},
        {"Sistagor", 65000},
        {"Hot Chocolate", 40000},
        {"Java Tea", 25000}
    };

    vector<Item> film = {
        {"Avengers: Endgame", 50000},
        {"Frozen III", 50000},
        {"Inside Out 2", 50000},
        {"Moana 2", 50000},
        {"Wish", 50000}
    };

    vector<Keranjang> keranjang;
    int pilihan;

    while (true) {
        system("cls");
        cout << "=================================================================================================\n";
        cout << "|                                Selamat datang di FTI Cinema                                   |\n";
        cout << "|                          Silakan pilih film atau makanan favorit Anda                         |\n";
        cout << "=================================================================================================\n";
        cout << "| No. | Food & Beverage         | Harga         | No. | Movies              | Harga             |\n";
        cout << "=================================================================================================\n";
        for (size_t i = 0; i < max(fnb.size(), film.size()); ++i) {
            if (i < fnb.size()) {
                cout << "| " << (i + 1 < 10? " " : "") << i + 1 << "  | " << fnb[i].nama;
                int spasiFNB = 24 - fnb[i].nama.length();
                for (int s = 0; s < spasiFNB; ++s) cout << " ";
                cout << "| Rp" << fnb[i].harga;
                int spasiHargaFNB = 12 - to_string(fnb[i].harga).length();
                for (int s = 0; s < spasiHargaFNB; ++s) cout << " ";
                cout << "| ";
            } else {
                cout << "|     |                         |               | ";
            }

            if (i < film.size()) {
                cout << (i + 1 + fnb.size() < 10 ? " " : "") << i + 1 + fnb.size() << "  | " << film[i].nama;
                int spasiFilm = 20 - film[i].nama.length();
                for (int s = 0; s < spasiFilm; ++s) cout << " ";
                cout << "| Rp" << film[i].harga;
                int spasiHargaFilm = 16 - to_string(film[i].harga).length();
                for (int s = 0; s < spasiHargaFilm; ++s) cout << " ";
                cout << "|\n";
            } else {
                cout << "    |                     |                   |\n"; 
            }
        }

        cout << "=================================================================================================\n";
        cout << "| 111.Reset Pilihan | 222.Tambah Item | 333.Struk Pembayaran | 444.Hapus Item | 555.Lihat Promo |\n";
        cout << "=================================================================================================\n";

        cout << "\nInput pilihan yang Anda inginkan: ";
        cin >> pilihan;

        if (pilihan >= 1 && pilihan <= (int)fnb.size()) {
            int jumlah;
            cout << "[ " << pilihan << " ] " << fnb[pilihan - 1].nama << "\nJumlah: ";
            cin >> jumlah;
            cout << "===============================================\n";

            bool found = false;
            for (auto& item : keranjang) {
                    if (item.nama == fnb[pilihan - 1].nama) {
                    item.jumlah += jumlah;
                    item.totalHarga += jumlah * fnb[pilihan - 1].harga;
                    found = true;
                    break;
                }
            }
            if (!found) {
                keranjang.push_back({fnb[pilihan - 1].nama, jumlah, jumlah * fnb[pilihan - 1].harga});
            }
        }else if (pilihan > fnb.size() && pilihan <= fnb.size() + film.size()) {
            int indexFilm = pilihan - fnb.size() - 1;
            int jumlah;

            cout << "[ " << pilihan << " ] " << film[indexFilm].nama << "\nJumlah: ";
            cin >> jumlah;
            cout << "===============================================\n";

            bool found = false;
            for (auto& item : keranjang) {
                if (item.nama == film[indexFilm].nama) {
                    item.jumlah += jumlah;
                    item.totalHarga += jumlah * film[indexFilm].harga;
                    found = true;
                    break;
                }
            }
            if (!found) {
                keranjang.push_back({film[indexFilm].nama, jumlah, jumlah * film[indexFilm].harga});
            }
        } else if (pilihan == 111) {
            keranjang.clear();
            cout << "\nPilihan telah di-reset.\n";
        } else if (pilihan == 222) {
            int jenis;
            string namaBaru;
            int hargaBaru;

            cout << "\nPilih jenis item yang ingin ditambahkan (1 untuk FNB, 2 untuk Film): ";
            cin >> jenis;
            cout << "Masukkan nama item baru: ";
            cin.ignore();
            getline(cin, namaBaru);
            cout << "Masukkan harga item baru: Rp";
            cin >> hargaBaru;

            if (jenis == 1) {
                fnb.push_back({namaBaru, hargaBaru});
                cout << "\nItem " << namaBaru << " berhasil ditambahkan ke daftar FNB.\n";
            } else if (jenis == 2) {
                film.push_back({namaBaru, hargaBaru});
                cout << "\nItem " << namaBaru << " berhasil ditambahkan ke daftar Film.\n";
            } else {
                cout << "\nJenis item tidak valid.\n";
            }
            
        } else if (pilihan == 333) {
            system("cls");
            cout << "\n=========================== Rincian Pembelian ============================\n\n";
            cout << "Pesanan Makanan dan Minuman\n";
            cout << "==========================================================================\n";
            cout << "Jumlah | Nama Makanan/Minuman       | Total Harga\n";
            cout << "==========================================================================\n";

            int totalKeseluruhan = 0;
            int totalFNB = 0;
            int totalFilm = 0;
            int jumlahFilm = 0;

            for (size_t i = 0; i < fnb.size(); ++i) {
                int jumlah = 0, totalHarga = 0;
                for (const auto& item : keranjang) {
                    if (item.nama == fnb[i].nama) {
                        jumlah = item.jumlah;
                        totalHarga = item.totalHarga;
                    }
                }
                cout << jumlah << "      | " << fnb[i].nama;
                int spasiNama = 27 - fnb[i].nama.length();
                for (int s = 0; s < spasiNama; ++s) cout << " ";
                cout << "| Rp" << totalHarga << "\n";

                totalKeseluruhan += totalHarga;
                totalFNB += totalHarga;
            }

            cout << "==========================================================================\n\n";

            cout << "Pesanan Tiket Film\n";
            cout << "==========================================================================\n";
            cout << "Jumlah | Nama Film                  | Total Harga\n";
            cout << "==========================================================================\n";

            for (size_t i = 0; i < film.size(); ++i) {
                int jumlah = 0, totalHarga = 0;
                for (const auto& item : keranjang) {
                    if (item.nama == film[i].nama) {
                        jumlah = item.jumlah;
                        totalHarga = item.totalHarga;
                        jumlahFilm += jumlah;
                    }
                }
                cout << jumlah << "      | " << film[i].nama;
                int spasiNama = 27 - film[i].nama.length();
                for (int s = 0; s < spasiNama; ++s) cout << " ";
                cout << "| Rp" << totalHarga << "\n";

                totalKeseluruhan += totalHarga;
                totalFilm += totalHarga;
            }

            cout << "==========================================================================\n";

            int diskonFNB = (totalFNB >= 200000) ? (totalFNB * 20/100) : 0;
            int diskonFilm = (jumlahFilm >= 3) ? (totalFilm * 10 / 100) : 0;
            int totalDiskon = diskonFNB + diskonFilm;
            totalKeseluruhan -= totalDiskon;

            if (diskonFNB > 0 || diskonFilm > 0) {
                            cout << "\nPromo yang Diterapkan:\n";
                            if (diskonFNB > 0) {
                                cout << "- Diskon FNB (20%): -Rp" << diskonFNB << "\n";
                            }
                            if (diskonFilm > 0) {
                                cout << "- Diskon Film (10%): -Rp" << diskonFilm << "\n";
                            }
                        }

            cout << "--------------------------------------------------------------------------\n";
            cout << "Total Harga: Rp" << totalKeseluruhan << ",-\n";
            cout << "--------------------------------------------------------------------------";

            char pembayaran;
            int bayar;
            do {
                cout << "\nPilih metode pembayaran (D untuk Debit, T untuk Tunai): ";
                cin >> pembayaran;

                if (pembayaran == 'D' || pembayaran == 'd') {
                    do {
                        cout << "Masukkan jumlah pembayaran (Rp" << totalKeseluruhan << "): ";
                        cin >> bayar;
                        if (bayar == totalKeseluruhan) {
                            cout << "Pembayaran berhasil dengan Debit.\n";
                            break;
                        } else {
                            cout << "Jumlah pembayaran tidak sesuai, silakan coba lagi.\n";
                        }
                    } while (bayar != totalKeseluruhan);
                } else if (pembayaran == 'T' || pembayaran == 't') {
                    do {
                        cout << "Masukkan jumlah uang tunai yang dibayar: ";
                        cin >> bayar;
                        if (bayar >= totalKeseluruhan) {
                            cout << "Pembayaran berhasil dengan uang tunai.\n";
                            cout << "Kembalian: Rp" << bayar - totalKeseluruhan << ",-\n";
                            break;
                        } else {
                            cout << "Jumlah uang tunai tidak cukup, silakan coba lagi.\n";
                        }
                    } while (bayar < totalKeseluruhan);
                } else {
                    cout << "Pilihan pembayaran tidak valid.\n";
                }
            } while (pembayaran != 'D' && pembayaran != 'd' && pembayaran != 'T' && pembayaran != 't');

            system("cls");
            cout << "=========================================================================\n";
            cout << "|                              FTI CINEMA                               |\n";
            cout << "|              Jl. Dr. O. Notohamidjojo No.1 - 10, Salatiga             |\n";
            cout << "|                              Jawa Tengah                              |\n";
            cout << "|                          Telp : 08123456789                           |\n";
            cout << "|-----------------------------------------------------------------------|\n";
            cout << "| Nama Pesanan          | Harga Satuan     | Jumlah     | Total Harga   |\n";
            cout << "|=======================|==================|============|===============|\n";
            for (const auto& item : keranjang) {
                cout << "| " << item.nama;
                int spasiNama = 22 - item.nama.length();
                for (int s = 0; s < spasiNama; ++s) cout << " ";
                cout << "| Rp" << item.totalHarga / item.jumlah;
                int spasiHarga = 15 - to_string(item.totalHarga / item.jumlah).length();
                for (int s = 0; s < spasiHarga; ++s) cout << " ";
                cout << "| " << item.jumlah;
                int spasiJumlah = 11 - to_string(item.jumlah).length();
                for (int s = 0; s < spasiJumlah; ++s) cout << " ";
                cout << "| Rp" << item.totalHarga;
                int spasiTotal = 12 - to_string(item.totalHarga).length();
                for (int s = 0; s < spasiTotal; ++s) cout << " ";
                cout << "|\n";
            }
            cout << "|-----------------------------------------------------------------------|\n";
            cout << "| Total Keseluruhan: Rp" << totalKeseluruhan;
            int spasiTotal = 49 - to_string(totalKeseluruhan).length();
            for (int s = 0; s < spasiTotal; ++s) cout << " ";
            cout << "|\n";

        if (diskonFNB > 0 || diskonFilm > 0) {
            cout << "| Promo yang Digunakan:                                                 |\n";
            cout << "| ";
            string promoText;
            if (diskonFNB > 0) {
                promoText += "Diskon FNB (20%): Rp" + to_string(diskonFNB);
            }
            if (diskonFilm > 0) {
                if (!promoText.empty()) promoText += ", ";
                promoText += "Diskon Film (10%): Rp" + to_string(diskonFilm);
            }

            int lebarKolomPromo = 70; 
            int spasiTambahan = lebarKolomPromo - promoText.length();
            cout << promoText;
            for (int i = 0; i < spasiTambahan; ++i) cout << " ";
            cout << "|\n";
        }

            cout << "| Metode Pembayaran: " << (pembayaran == 'D' || pembayaran == 'd' ? "Debit" : "Tunai");
            int spasiPembayaran = 51 - (pembayaran == 'D' || pembayaran == 'd' ? 5 : 5); 
            for (int s = 0; s < spasiPembayaran; ++s) cout << " ";
            cout << "|\n";

            cout << "| Jumlah Dibayar: Rp" << bayar;
            int spasiBayar = 52 - to_string(bayar).length();
            for (int s = 0; s < spasiBayar; ++s) cout << " ";
            cout << "|\n";

            if (bayar > totalKeseluruhan) {
                cout << "| Kembalian: Rp" << bayar - totalKeseluruhan;
                int spasiKembalian = 57 - to_string(bayar - totalKeseluruhan).length();
                for (int s = 0; s < spasiKembalian; ++s) cout << " ";
                cout << "|\n";
            }
            cout << "|                                                                       |\n";
            cout << "|-----------------------------------------------------------------------|\n";
            time_t now = time(0);
            char* dt = ctime(&now);
            dt[strlen(dt) - 1] = '\0';
            cout << "| Tanggal/Waktu Transaksi: " << dt;
            int spasiTanggal = 45 - strlen(dt);
            for (int s = 0; s < spasiTanggal; ++s)
            cout << " ";
            cout << "|\n";
            cout << "| Perhatian : Barang yang dibeli tidak bisa dikembalikan!               |\n";
            cout << "|                                                                       |\n";
            cout << "=========================================================================\n";
                    char pilihan;
                    do {
                        cout << "\nIngin mengulangi program bioskop atau kembali ke menu utama?" << endl;
                        cout << "Tekan [U] untuk ulang, [X] untuk kembali ke menu utama: ";
                        cin >> pilihan;

                        if (pilihan == 'U' || pilihan == 'u') {
                            bioskop();
                            return;
                        } else if (pilihan == 'X' || pilihan == 'x') {
                            menuUtama();
                            return; 
                        } else {
                            cout << "Input tidak valid. Silakan coba lagi.\n";
                        }
                    } while (true);                    

        } else if (pilihan == 444) {
            int hapus;
            cout << "Pilih item yang ingin dihapus (1 untuk FNB, 2 untuk Film): ";
            cin >> hapus;

            if (hapus == 1) {
                cout << "Masukkan nomor item yang ingin dihapus (1-" << fnb.size() << "): ";
                int nomorFNB;
                cin >> nomorFNB;
                if (nomorFNB > 0 && nomorFNB <= fnb.size()) {
                    fnb.erase(fnb.begin() + nomorFNB - 1);
                    cout << "Item FNB berhasil dihapus.\n";
                } else {
                    cout << "Nomor item tidak valid.\n";
                }
            } else if (hapus == 2) {
                cout << "Masukkan nomor item yang ingin dihapus (1-" << film.size() << "): ";
                int nomorFilm;
                cin >> nomorFilm;
                if (nomorFilm > 0 && nomorFilm <= film.size()) {
                    film.erase(film.begin() + nomorFilm - 1);
                    cout << "Item Film berhasil dihapus.\n";
                } else {
                    cout << "Nomor item tidak valid.\n";
                }
            } else {
                cout << "Pilihan tidak valid.\n";
            }
        } else if (pilihan == 555) {
            system ("cls");
            cout << "\n================================== PROMO ====================================\n";
            cout << "| 1. Diskon 20% untuk pembelian FnB diatas Rp. 200.000,- !                  |\n";
            cout << "| 2. Diskon 10% untuk pembelian minimal 3 tiket film.                       |\n";
            cout << "=============================================================================\n";
        } else {
            cout << "\nPilihan tidak valid.\n";
        }

        system("pause");
    }
}

void batuGuntingKertas(){
    char ulang; 
    do {
        system("cls"); 
        
        int pilihanUser;
        int pilihanKomputer;
        
        srand(time(0));

        cout << "===================================\n";
        cout << "| Permainan Batu, Gunting, Kertas |\n";
        cout << "===================================\n";
        cout << "| 1. Batu                         |\n";
        cout << "| 2. Gunting                      |\n";
        cout << "| 3. Kertas                       |\n";
        cout << "===================================\n";

        do {
            cout << "\nMasukkan pilihan Anda (1-3): ";
            cin >> pilihanUser;

            if (pilihanUser < 1 || pilihanUser > 3) {
                cout << "Pilihan Tidak Valid! Pilih 1-3.\n";
            }
        } while (pilihanUser < 1 || pilihanUser > 3);

        pilihanKomputer = rand() % 3 + 1;

        if (pilihanUser == 1) {
            cout << "Anda memilih: Batu\n";
        } else if (pilihanUser == 2) {
            cout << "Anda memilih: Gunting\n";
        } else {
            cout << "Anda memilih: Kertas\n";
        }

        if (pilihanKomputer == 1) {
            cout << "Komputer memilih: Batu\n";
        } else if (pilihanKomputer == 2) {
            cout << "Komputer memilih: Gunting\n";
        } else {
            cout << "Komputer memilih: Kertas\n";
        }

        if (pilihanUser == pilihanKomputer) {
            cout << "Hasil: Seri!\n";
        } else if ((pilihanUser == 1 && pilihanKomputer == 2) ||
                   (pilihanUser == 2 && pilihanKomputer == 3) ||
                   (pilihanUser == 3 && pilihanKomputer == 1)) {
            cout << "\nHasil: Anda Menang!\n";
        } else {
            cout << "\nHasil: Anda Kalah!\n";
        }

        do {
            cout << "\nApakah Anda ingin bermain lagi? (U: Ulang / X: Keluar): ";
            cin >> ulang;

            if (ulang != 'U' && ulang != 'u' && ulang != 'X' && ulang != 'x') {
                cout << "Input Tidak Valid! Harap masukkan 'U' untuk Ulang atau 'X' untuk Keluar.\n";
            }
        } while (ulang != 'U' && ulang != 'u' && ulang != 'X' && ulang != 'x'); 

    } while (ulang == 'U' || ulang == 'u');
}

void bendera() {
    char pilihan;
    do {
        system("cls");
        cout << "================================\n";
        cout << "|        Program Bendera       |\n";
        cout << "================================\n";
        int tinggi;
        cout << "Masukkan tinggi bendera: ";
        cin >> tinggi;

        int lebar = tinggi; 
        int bar = 219;  

        setWarna(4);  
        for (int i = 0; i < tinggi; i++) {
            for (int j = 0; j < lebar * 6; j++) {
                cout << (char)bar;
            }
            cout << endl;
            Sleep(100); 
        }

        setWarna(15);  
        for (int i = 0; i < tinggi; i++) {
            for (int j = 0; j < lebar * 6; j++) {
                cout << (char)bar;
            }
            cout << endl;
            Sleep(100);
        }

        do {
            cout << "\nU: Ulang\nX: Exit\nPilihan: ";
            cin >> pilihan;

            if (pilihan != 'U' && pilihan != 'u' && pilihan != 'X' && pilihan != 'x') {
                cout << "Input Tidak Valid! Harap masukkan 'U' untuk Ulang atau 'X' untuk Keluar.\n";
            }

        } while (pilihan != 'U' && pilihan != 'u' && pilihan != 'X' && pilihan != 'x');

    } while (pilihan == 'U' || pilihan == 'u');

    cout << "Terima kasih!" << endl;
}

void kamus(){
    system ("cls");
    int jumlahKata;
    cout << "====================================\n";
    cout << "|          Kamus Sederhana         |\n";
    cout << "====================================\n";
    cout << "Masukkan jumlah kata dalam kamus: ";
    cin >> jumlahKata;
    cin.ignore(); 

    vector<string> kata(jumlahKata);
    vector<string> definisi(jumlahKata);

    for (int i = 0; i < jumlahKata; ++i) {
        cout << "\nMasukkan kata ke-" << i + 1 << ": ";
        getline(cin, kata[i]);

        cout << "Masukkan definisi kata '" << kata[i] << "': ";
        getline(cin, definisi[i]);
    }


    while (true) {
        system("cls"); 
        cout << "===============================\n";
        cout << "|         Menu Kamus:         |\n";
        cout << "===============================\n";
        cout << "| 1. Cari Definisi Kata       |\n";
        cout << "| 2. Keluar dari Program      |\n";
        cout << "|                             |\n";
        cout << "===============================\n";
        cout << "\nPilih Menu: ";
        int pilihan;
        cin >> pilihan;
        cin.ignore(); 

        if (pilihan == 1) {
            string cariKata;
            cout << "Masukkan kata yang ingin anda cari: ";
            getline(cin, cariKata);

            bool found = false;
            for (int i = 0; i < jumlahKata; ++i) {
                if (kata[i] == cariKata) {
                    cout << "Definisi dari '" << cariKata << "' adalah: " << definisi[i] << endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Kata '" << cariKata << "' tidak ditemukan dalam kamus." << endl;
            }
            cout << "Tekan Enter Untuk Kembali";
            cin.ignore();
        } else if (pilihan == 2) {
            break;
        } else {
            cout << "Pilihan tidak valid. Tekan Enter Untuk Kembali.";
            cin.ignore();
        }
    }
}

void creator(){
    string text;

    system ("cls");
    cout << "-------------------------------------------------" << endl;
    text = "                     CREATOR\n";
    for (char c : text) {
        cout << c << flush;  
        Sleep(50);     
    }     
    cout << "-------------------------------------------------" << endl;

    text = "NAMA    : DEWA SAPUTRA RIAWAN\n";
    for (char c : text) {
        cout << c << flush;  
        Sleep(50);       
    }

    text = "NIM     : 672024084\n";
    for (char c : text) {
        cout << c << flush;  
        Sleep(50);          
    }

    cout << endl;

    text = "NAMA    : ARNOLD PASKAH PRATAMA\n";
    for (char c : text) {
        cout << c << flush; 
        Sleep(50);          
    }

    text = "NIM     : 672024087\n";
    for (char c : text) {
        cout << c << flush; 
        Sleep(50);          
    }

    cout << endl;

    text = "NAMA    : BERNARDINO JEREMY TRYSTAN LIEM\n";
    for (char c : text) {
        cout << c << flush;  
        Sleep(50);         
    }

    text = "NIM     : 672024090\n";
    for (char c : text) {
        cout << c << flush;  
        Sleep(50);          
    }

    cout << endl;

    system("pause");
}

void keluar() {
    system("cls"); 
    const string RED = "\033[31m";
    const string GREEN = "\033[32m";
    const string YELLOW = "\033[33m";
    const string RESET = "\033[0m";

    cout << RED << "*************************************************************\n";
    cout << "* *                                                       * *\n";
    cout << "*   *                                                   *   *\n";
    cout << "*      *                                             *      *\n";
    cout << "*         *                                        *        *\n";
    cout << "*            *                                  *           *\n";
    cout << "*              *                              *             *\n";
    cout << "*                 *                        *                *\n";
    cout << "*                    *                  *                   *\n";
    cout << "*                       *            *                      *\n";
    cout << "*                          *      *                         *\n";
    cout << "*                            *  *                           *\n";
    cout << "*                                                           *\n";
    cout << "*                                                           *\n";
    cout << "*                                                           *\n";
    cout << "*************************************************************\n";
    system ("pause");
    system ("cls");
    cout << "*************************************************************\n";
    cout << "*             TERIMA KASIH KEPADA ASISTEN DOSEN             *\n";
    cout << "*            Asistensi Dasar Dasar Pemrograman F            *\n";
    cout << "*                  Kak Joe dan Kak Enrico                   *\n";
    cout << "*    Atas bimbingan yang diberikan selama satu semester!    *\n";
    cout << "*          Semoga ilmu yang diberikan bermanfaat.           *\n";
    cout << "*      Semangat terus dalam mengajar dan berbagi ilmu!      *\n";
    cout << "*************************************************************\n";
    cout << RESET << endl;

    cout << GREEN << "Program akan keluar dalam:\n";
    for (int i = 10; i >= 0; i--) {
        cout << YELLOW << i << " detik...\r"; 
        Sleep(1000); 
    }
    cout << endl;
    
    cout << RESET << "\nTerima kasih telah menggunakan program ini!\n";
    Sleep(2000); 

    exit(0); 
}

int main(){
    loading1();
    if (!login()) return 0;

    while (true) {
        char pilihan;
        menuUtama();
        cin >> pilihan;

        switch (pilihan) {
            case '1': 
            loading2();
            rumahPola(); 
            break;
            case '2': 
            loading2();
            bioskop(); 
            break;
            case '3': 
            loading2();
            batuGuntingKertas(); 
            break;
            case '4': 
            loading2();
            bendera(); 
            break;
            case '5': 
            loading2();
            kamus(); 
            break;
            case '6': 
            loading2();
            creator(); 
            break;
            case '7': 
            keluar(); 
            return 0;
            default: 
            cout << "Pilihan Tidak Valid! Masukkan Pilihan Yang Tersedia!\n";
            cout << "Tekan Enter Untuk Mengulangi!";
            cin.get();
            cin.ignore();
            break;
        }
    }
}