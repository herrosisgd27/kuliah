#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Mobil
{
    string nama;
    double hargaPerhari;
    double totalHarga;
    int jumlahHari;
};

struct ATMTransaction
{
    string bank;
    double amount;
    ATMTransaction* next;

    ATMTransaction(const string& b, double amt) : bank(b), amount(amt), next(nullptr) {}
};

class PenyewaanMobil
{
public:
    PenyewaanMobil()
    {
        daftarMobil = {
            {"Toyota Avanza", 100.0},
            {"Honda Civic", 120.0},
            {"Nissan X-Trail", 150.0},
            {"Ford Mustang", 200.0},
            {"Mitsubishi Pajero", 180.0}};
        atmTransactionsHead = nullptr;
        atmTransactionsTail = nullptr;
    }

    void tampilkanDaftarMobil()
    {
        cout << "Daftar mobil yang tersedia: " << endl;
        for (int i = 0; i < daftarMobil.size(); i++)
        {
            cout << i + 1 << ". " << daftarMobil[i].nama << " - Harga per hari: " << daftarMobil[i].hargaPerhari << "k" << endl;
        }
    }

    void pesanMobil(int indeksMobil)
    {
        if (indeksMobil >= 0 && indeksMobil < daftarMobil.size())
        {
            mobilDipesan.push_back(daftarMobil[indeksMobil]);
            cout << "Anda telah memesan mobil " << daftarMobil[indeksMobil].nama << "." << endl;
        }
        else
        {
            cout << "Pilihan mobil tidak valid." << endl;
        }
    }

    void tampDafMobilDiPesan()
    {
        cout << "Mobil yang dipesan : " << endl;
        for (int i = 0; i < mobilDipesan.size(); i++)
        {
            cout << i + 1 << ". " << mobilDipesan[i].nama<<endl;
        }
    }

    double hitungBiayaTotal()
    {
        double totalBiaya = 0.0;
        for (const auto& mobil : mobilDipesan)
        {
            totalBiaya += mobil.hargaPerhari;
        }

        return totalBiaya;
    }

    void tunai(int totalAmount)
    {
        if (totalAmount >= hitungBiayaTotal())
        {
            cout << "Pembayaran tunai sebesar " << totalAmount << " berhasil." << endl;
            int kembalian = totalAmount - hitungBiayaTotal();
            cout << "Kembalian : " << kembalian << endl;
        }
        else
        {
            cout << "Total pembayaran tidak valid." << endl;
        }
    }

    void bayarDenganATM(const string& bank, double amount)
    {
        ATMTransaction* newTransaction = new ATMTransaction(bank, amount);
        if (atmTransactionsHead == nullptr)
        {
            atmTransactionsHead = newTransaction;
            atmTransactionsTail = newTransaction;
        }
        else
        {
            atmTransactionsTail->next = newTransaction;
            atmTransactionsTail = newTransaction;
        }
        cout << "Transaksi ATM sebesar " << amount << " dengan bank " << bank << " berhasil." << endl;
    }

    void tampilkanDaftarTransaksiATM()
    {
        cout << "Daftar Transaksi ATM:" << endl;
        ATMTransaction* currentTransaction = atmTransactionsHead;
        int index = 1;
        while (currentTransaction != nullptr)
        {
            cout << index << ". Bank: " << currentTransaction->bank << ", Jumlah: " << currentTransaction->amount << endl;
            currentTransaction = currentTransaction->next;
            index++;
        }
    }

private:
    vector<Mobil> daftarMobil;
    vector<Mobil> mobilDipesan;
    ATMTransaction* atmTransactionsHead;
    ATMTransaction* atmTransactionsTail;
};

int main()
{
    PenyewaanMobil rentalCar;
    int pilihan;
    int totalAmount;

    rentalCar.tampilkanDaftarMobil();
    cout << endl << "Pilih mobil yang ingin disewa (masukkan nomor): ";
    cin >> pilihan;

    rentalCar.pesanMobil(pilihan - 1);
    int total = rentalCar.hitungBiayaTotal();
    cout << "Pembayaran yang harus Anda lakukan: " << total << endl;

    cout << "Metode pembayaran: " << endl;
    cout << "1. Pembayaran Tunai" << endl;
    cout << "2. Pembayaran ATM" << endl;
    cout << "Pilihan metode pembayaran (1/2): ";
    short int choose;
    cin >> choose;

    string bank; // Inisialisasi bank di sini

    switch (choose)
    {
    case 1:
        cout << "Daftar mobil yang telah di pesan : " << endl;
        rentalCar.tampDafMobilDiPesan();
        cout << "Total pembayaran anda : " << total << endl;
        cout << "Masukkan total pembayaran tunai: ";
        cin >> totalAmount;
        rentalCar.tunai(totalAmount);
        break;
    case 2:
        cout << "Daftar mobil yang telah di pesan : " << endl;
        rentalCar.tampDafMobilDiPesan();
        cout << "Total pembayaran anda : " << total << endl;
        cout << "Pilih bank ATM (Contoh: BCA, Mandiri, BRI): ";
        cin >> bank; // Gunakan cin di sini
        cout << "Masukkan total pembayaran dengan ATM: ";
        cin >> totalAmount;
        rentalCar.bayarDenganATM(bank, totalAmount);
        rentalCar.tampilkanDaftarTransaksiATM();
        break;
    default:
        cout << "Metode pembayaran tidak valid." << endl;
    }

    return 0;
} 