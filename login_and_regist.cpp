#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

class userAuthentication {
public:
    
    string username, password, userId, passId;

private:
    void registration() {
    	short int count = 1;    	
        cout << "Masukkan username anda: ";
        cin.ignore();
        getline(cin, username);

        cout << "Masukkan password anda: ";
        cin >> password;

        string confirmPassword;


        while(true){
            cout << "Masukkan ulang password anda: ";
            cin >> confirmPassword;

            if (confirmPassword == password) {
                cout << "\nRegistrasi berhasil\n";
                passId = password;
        		userId = username;
                login();
                break;
            } else {
                cout << "Password tidak cocok!!!\n";
                if(count == 3){
                	cout << "Anda telah memasukkan password yang salah sebanyak "<< count << " kali.\n";
        			cout << "Silahkan coba lagi\n";
                	break;
				}
                system("pause");
                system("cls");
            }
            
            count++;
        }
        
//        if (confirmPassword != passId) {
//        	
//		}
        
    }

    void login() {
        cout << "\nMasukkan username: ";
        cin.ignore();
        getline(cin, username);

        cout << "Masukkan password: ";
        cin >> password;

        if (username == userId && password == passId) {
            cout << "Login berhasil\n\n";
        } else {
            cout << "Login gagal! Periksa kembali username dan password Anda.\n\n";
        }
    }

    void forgot() {
        cout << "Apakah anda mau";
    }

    void gantiPassword(){
        string newPass;
        string konfirmPass;
        cout << "Masukkan password lama anda : ";
        cin >> password;

        if(password == passId){
	        cout << "Masukkan password baru anda : ";
	        cin >> newPass;
	        
	        while(true){
	            cout <<"Masukkan ulang password baru anda : ";
	            cin >> konfirmPass;
	            if(newPass == konfirmPass){
	                cout << "Ubah password berhasil!\n";
	                passId = newPass;
	                break;
					login();
	            }else{
	                cout << "Password tidak sesuai!\n";
	            }	
			}
        }
    }

public:
    void handleUser() {
        int choice;
        
        for (int i = 1; i <= 20; i++) {
            cout << "=";    
        }
        cout << '\n';

        cout << "1. Registrasi\n";
        cout << "2. Login\n";
        cout << "3. Ganti password\n";
        cout << "4. Keluar\n";
        
        for (int i = 1; i <= 20; i++) {
            cout << "=";
        }
        cout << '\n';
        

        cout << "Masukkan pilihan anda: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registration();
                break;
            case 2:
                login();
                break;
            case 3:
                gantiPassword();
                break;
            case 4:
                cout << "Terima kasih! Keluar dari program." << endl;
                exit(0);
            default:
                cout << "Pilihan tidak valid. Silakan pilih 1, 2, atau 3." << endl;
        }
    }
};

int main() {
    userAuthentication mhs;

    while (true) {
        mhs.handleUser();
    }

    return 0;
}
