/*

Kemas Khairunsyah
2200018155
NIM GANJIL

*/

#include <iostream>
#include <string>
using namespace std;

struct KTPData
{
    string nama;
    int tanggalLahir;
    string jenisKelamin;
    string alamat;
    string agama;
    string status;
    string pekerjaan;
};

class node
{
public:
    KTPData data;
    node *next;

    node(const KTPData &ktp) : data(ktp) {}
};

class KTPManager
{
public:
    node *head;
    node *tail;

    void inputData(KTPData &ktp)
    {
        cout << "Nama: ";
        cin >> ktp.nama;

        cout << "Tanggal Lahir: ";
        cin >> ktp.tanggalLahir;
        cin.ignore();

        cout << "Jenis Kelamin: ";
        getline(cin, ktp.jenisKelamin);

        cout << "Alamat: ";
        getline(cin, ktp.alamat);

        cout << "Agama: ";
        getline(cin, ktp.agama);

        cout << "Status: ";
        getline(cin, ktp.status);

        cout << "Pekerjaan: ";
        getline(cin, ktp.pekerjaan);
    }

    void displayData(const KTPData &ktp)
    {
        cout << "Nama: " << ktp.nama << "\n";
        cout << "Tanggal Lahir: " << ktp.tanggalLahir << "\n";
        cout << "Jenis Kelamin: " << ktp.jenisKelamin << "\n";
        cout << "Alamat: " << ktp.alamat << "\n";
        cout << "Agama: " << ktp.agama << "\n";
        cout << "Status: " << ktp.status << "\n";
        cout << "Pekerjaan: " << ktp.pekerjaan << "\n";
        cout << "==========================\n\n";
    }

    void tambahDataBelakang(const KTPData &ktp)
    {
        node *newNode = new node(ktp);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void hapusDataBelakang()
    {
        if (head == nullptr)
        {
            cout << "Linked List kosong. Tidak ada yang bisa dihapus." << endl;
            return;
        }
        if (head == tail)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            node *current = head;
            while (current->next != tail)
            {
                current = current->next;
            }
            delete current->next;
            tail = current;
            tail->next = nullptr;
        }
    }
};

int main()
{
    KTPManager ktpManager;

    int maxData = 0;

    cout << "Masukkan jumlah maksimal data KTP yang ingin Anda tampung: ";
    cin >> maxData;

    for (int i = 0; i < maxData; i++)
    {
        KTPData ktp;
        cout << "\n\n";
        cout << "Data KTP ke-" << i + 1 << ":" << endl;
        ktpManager.inputData(ktp);
        ktpManager.tambahDataBelakang(ktp);
    }

    cout << endl
         << endl;

    cout << "Data sebelum menghapus node terakhir:\n\n";

    node *current = ktpManager.head;
    int i = 0;
    while (current != nullptr)
    {
        cout << "\tDara KTP ke- " << i + 1 << ":" << endl;
        ktpManager.displayData(current->data);
        current = current->next;
        i++;
    }

    ktpManager.hapusDataBelakang();

    cout << "\n\n";
    cout << "Data setelah menghapus node terakhir:\n\n";

    current = ktpManager.head;
    i = 0;
    while (current != nullptr)
    {
        cout << "\tDara KTP ke- " << i + 1 << ":" << endl;
        ktpManager.displayData(current->data);
        current = current->next;
        i++;
    }

    while (ktpManager.head != nullptr)
    {
        node *temp = ktpManager.head;
        ktpManager.head = ktpManager.head->next;
        delete temp;
    }

    return 0;
}
