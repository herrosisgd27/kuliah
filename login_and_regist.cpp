#include <iostream>
#include <cstdlib>
#include <string>
#include <regex>
#include <fstream>

using namespace std;

class userAuthentication
{
public:
    string username, password, userId, passId, userTampil;
    string email, emailId;
    short int count;

private:
    bool registrasi = false;
    bool loggedIn;
    void registration()
    {
        count = 1;
        cout << "===== Registrasi =====\n";
        while (true)
        {
            while (true)
            {
                cout << "Masukkan email anda: ";
                cin >> email;
                if (isValidEmail(email))
                {
                    break;
                }
                else
                {
                    cout << "Email anda tidak valid, silahkan coba lagi!!!\n";
                }
            }

            cout << "Masukkan username anda: ";
            cin.ignore();
            getline(cin, username);

            if (username == userId && email == emailId)
            {
                cout << "Email dan username anda sudah tersedia, silahkan masukkan email dan username yang berbeda!\n";
            }
            else if (username == userId)
            {
                cout << "Username anda sudah tersedia, silahkan masukkan username yang berbeda!\n";
            }
            else if (email == emailId)
            {
                cout << "Email anda sudah tersedia, silahkan masukkan email yang berbeda!\n";
            }
            else
            {
                break;
            }

            if (count == 3)
            {
                cout << "Anda sudah melebihi batas percobaan yaitu sebanyak " << count << " silahkan ulangi registrasi anda!\n";
                handleUser();
                return;
            }
            count++;
        }

        cout << "Masukkan password anda: ";
        cin >> password;

        string confirmPassword;
        count = 1;
        while (true)
        {
            cout << "Masukkan ulang password anda: ";
            cin >> confirmPassword;

            if (confirmPassword == password)
            {
                cout << "\nRegistrasi berhasil\n";
                registrasi = true;
                passId = password;
                userId = username;
                emailId = email;
                break;
            }
            else
            {
                cout << "Password tidak cocok!!!\n";
                if (count == 3)
                {
                    cout << "Anda telah memasukkan password yang salah sebanyak " << count << " kali.\n";
                    cout << "Silahkan coba lagi\n";
                    break;
                }
                // cin.get(); //system pause
                //                char c;
                //   cout << "Lanjut?";
                //   cin >> c;
                system("pause");
                system("cls");
            }
            count++;
        }
    }
    bool validUsername(string username)
    {
        bool usernameValid = false;
        if (username != userId)
        {
            return usernameValid;
        }
        return usernameValid = true;
    }
    void login()
    {
        int lupa = 1;
        cout << "===== Login =====\n";
        while (true)
        {
            cout << "\nMasukkan username: ";
            cin.ignore();
            getline(cin, username);

            cout << "Masukkan password: ";
            cin >> password;

            if (!registrasi)
            {
                cout << "Username atau password anda belum terdaftar silahkan registrasi terlebih dahulu!\n";
                break;
            }

            if (username == userId && password == passId)
            {
                loggedIn = true;
                cout << "Login berhasil\n\n";
                userTampil = userId;
                break;
            }
            else if (!validUsername(username))
            {
                cout << "Username yang anda masukkan tidak tersedia, silahkan masukkan username yang benar atau registrasi terlebih dahulu!\n";
            }
            else if (username != userId || password != passId)
            {
                cout << "Login gagal! Periksa kembali username dan password Anda.\n";
                if (lupa >= 3)
                {
                    char lanjut;
                    cout << "Apakah anda lupa password?(Y/N)\n";
                    cin >> lanjut;
                    if (lanjut == 'y' || lanjut == 'Y')
                    {
                        forgot();
                    }
                    break;
                }
                lupa++;
            }
        }
    }

    void forgot()
    {
        string checkEmail;
        cout << "Masukkan email anda : ";
        cin >> checkEmail;

        // if (checkEmail == email){
        //     gantiPassword();
        // }

        if (email == checkEmail)
        {
            cout << "Email Valid\n";
            forgotPassword();
        }
        else
        {
            cout << "Email tidak valid" << '\n';
        }
    }

    void forgotPassword()
    {
        string newPass, konfirmPass;
        cout << "Masukkan password baru anda : ";
        cin >> newPass;

        while (true)
        {
            cout << "Masukkan ulang password baru anda : ";
            cin >> konfirmPass;
            if (newPass == konfirmPass)
            {
                cout << "Ubah password berhasil!\n";
                passId = newPass;
                break;
                login();
            }
            else
            {
                cout << "Password tidak sesuai!\n";
            }
        }
    }

    void gantiPassword()
    {

        string newPass;
        string konfirmPass;
        cout << "Masukkan password lama anda : ";
        cin >> password;

        if (password == passId)
        {
            cout << "Masukkan password baru anda : ";
            cin >> newPass;

            while (true)
            {
                cout << "Masukkan ulang password baru anda : ";
                cin >> konfirmPass;
                if (newPass == konfirmPass)
                {
                    cout << "Ubah password berhasil!\n";
                    passId = newPass;
                    login();
                    break;
                }
                else
                {
                    cout << "Password tidak sesuai!\n";
                }
            }
        }
    }

    bool isValidEmail(string email)
    {
        const regex pattern("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");

        return std::regex_match(email, pattern);
    }

    void logout()
    {
        loggedIn = false;
    }

public:
    userAuthentication()
    {
        loggedIn = false; // Saat program dimulai, pengguna belum login.
    }
    void handleUser()
    {
        int choice;
        if (loggedIn)
        {
            cout << "Username saat ini: " << userTampil << "\n";
        }
        else
        {
            cout << "Username saat ini: (belum login)\n";
        }
        cout << endl;
        for (int i = 1; i <= 20; i++)
        {
            cout << "=";
        }
        cout << '\n';

        cout << "1. Registrasi\n";
        cout << "2. Login\n";
        cout << "3. Ganti password\n";
        cout << "4. Logout\n";
        cout << "5. Keluar dari program\n";

        for (int i = 1; i <= 20; i++)
        {
            cout << "=";
        }
        cout << '\n';

        cout << "Masukkan pilihan anda: ";
        cin >> choice;
        system("cls");
        switch (choice)
        {
        case 1:
            registration();
            break;
        case 2:
            if (loggedIn == true)
            {
                cout << "Anda sudah login!\n";
                break;
            }
            login();
            break;
        case 3:
            if (!loggedIn)
            {
                cout << "Anda belum login, silahkan login terlebih dahulu!\n";
                break;
            }
            gantiPassword();
            break;
        case 4:
            if (!loggedIn)
            {
                cout << "Anda belum login, silahkan login terlebih dahulu!\n";
                break;
            }
            logout();
            break;
        case 5:
            cout << "\nTerima kasih! Keluar dari program." << endl;
            exit(0);
        default:
            cout << "Pilihan tidak valid. Silakan pilih 1, 2, atau 3." << endl;
        }
    }
};

int main()
{
    userAuthentication mhs;

    while (true)
    {
        mhs.handleUser();
    }

    return 0;
}