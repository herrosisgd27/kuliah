#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include "validation.h"

using namespace std;

/*******************************
    ~~~ KELOMPOK 2 ~~~

    Kemas Khairunsyah (150)
    Bintang Toar Dondok ()
    Muhamad Fadhli Akbar_197

*******************************/

class userAuthentication {
	public:
		string username, password, userId, passId,userTampil;
		string email, emailId;

	private:
		bool registrasi = false;
		bool loggedIn;
		void registration() {
			short int count = 1;

			system("cls");
			while(true){
				while(true) {
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
	
				system("cls");
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
			
			count = 1;
			do {
				cout << "Masukkan password anda: ";
				cin >> password;

				/* Memeriksa password yang dimasukkan dengan
				    fungsi isValidPassword dalam header check_pass.h
				*/
				if (isPasswordValid(password)) {
					break;
				} else {
					cout << "Password harus berisi minimal 8 kata dengan huruf besar, huruf kecil dan angka.\n\n";
				}
				if (count == 3) {
					cout << "Anda salah memasukkan password yang salah sebanyak " << count << " kali dan program telah berhenti.\n";
					
					handleUser();
				}
				count++;
			}while(true);

			string confirmPassword;

			cout << '\n';
			count = 1;
			while(true) {
				cout << "Masukkan ulang password anda: ";
				cin >> confirmPassword;

				if (confirmPassword == password) {
					cout << "\n~~~ Registrasi berhasil ~~~\n";
					
					registrasi = true;
	                passId = password;
	                userId = username;
	                emailId = email;
					break;
				} else {
					cout << "Password tidak cocok!!!\n";
					if(count == 3) {
						cout << "Anda telah memasukkan password yang salah sebanyak "<< count << " kali.\n";
						cout << "Silahkan coba lagi\n";
						break;
					}
					char choise;
					cout << "Lanjut?";
					cin >> choise;
				}

				count++;
			}

		}
		
		
		

		void login() {
			int lupa = 1;
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
				
				if (username == userId && password == passId) {
	
					loggedIn = true;
	
					cout << "Login berhasil\n\n";
					userTampil = userId;
					break;
				}else if (!validUsername(username, userId)){
	                cout << "Username yang anda masukkan tidak tersedia, silahkan masukkan username yang benar atau registrasi terlebih dahulu!\n";
	            }else {
					cout << "Login gagal! Periksa kembali username dan password Anda.\n";
					if(lupa == 3){
						char answer;
		
						cout << "\nApakah anda lupa password?(Y/N)\n";
						cin >> answer;
		
						if (answer == 'y' || answer == 'Y') {
							forgot();
						}
						break;
					}
					lupa++;
				}
			}
		}

		void forgot() {
//			string checkEmail;

			system("cls");

			cout << "Masukkan email anda : ";
			cin >> email;

			if (isValidEmail(email) && email == emailId) {
				cout << "Email Valid\n";
				system("cls");
				forgotPassword();
			} else {
				cout << "Email tidak valid" << '\n';
			}
		}
		
		void forgotPassword()
	    {
	        string newPass, konfirmPass;
	        while(true){
		        cout << "Masukkan password baru anda : ";
		        cin >> newPass;
				if (isPasswordValid(newPass)) {
					break;
				} else {
					cout << "Password harus berisi minimal 8 kata dengan huruf besar, huruf kecil dan angka.\n\n";
				}
			}
			
	        while (true)
	        {
	            cout << "Masukkan ulang password baru anda : ";
	            cin >> konfirmPass;
	            if (newPass == konfirmPass)
	            {
	                cout << "Ubah password berhasil!, silahkan login kembali!\n";
	                passId = newPass;
//	                break;
	                return;
	            }
	            else
	            {
	                cout << "Password tidak sesuai!\n";
	            }
	        }
	    }
		
		void changePassword() {
			string newPass;
			string confirmPass;
			short int count;

			system("cls");

			cout << "Masukkan password lama anda : ";
			cin >> password;

			if(password == passId) {
				do {
					cout << "Masukkan password baru: ";
					cin >> newPass;

					/* Memeriksa password yang dimasukkan dengan
					    fungsi isValidPassword dalam header check_pass.h
					*/
					if (isPasswordValid(newPass)) {
						break;
					} else {
						cout << "\nPassword harus berisi minimal 8 kata dengan huruf besar, huruf kecil dan angka.\n\n";
					}

					if (count == 3) {
						cout << "Anda salah memasukkan password sebanyak " << count << " kali dan program telah berhenti.\n";
						system("pause");
						handleUser();
					}

					count++;
				} while(true);



				while(true) {
					cout <<"Masukkan ulang password baru anda : ";
					cin >> confirmPass;

					if(newPass == confirmPass) {
						cout << "Ubah password berhasil!\n";

						passId = newPass;

						system("pause");
						return;
					} else {
						cout << "Password tidak sesuai!\n";
					}

					if (count == 3) {
						cout << "Anda salah memasukkan password sebanyak " << count << " kali dan program telah berhenti.\n";
						system("pause");
						handleUser();
					}
					count++;
				}
			}
		}

		void logout(){
			loggedIn = false;
		}
	public:
		userAuthentication() {
			loggedIn = false; // Saat program dimulai, pengguna belum login.
		}
		void handleUser() {
			int choice;
			
			
			system("cls");

			if (loggedIn) {
				cout << "Username saat ini: " << userTampil << "\n";
			} else {
				cout << "Username saat ini: (belum login)\n";
			}
			cout << endl;
			for (int i = 1; i <= 20; i++) {
				cout << "=";
			}
			cout << '\n';

			cout << "1. Registrasi\n";
			cout << "2. Login\n";
			cout << "3. Ganti password\n";
			cout << "4. Logout\n";
			cout << "5. Keluar\n";

			for (int i = 1; i <= 20; i++) {
				cout << "=";
			}
			cout << "\n\n";


			cout << "Masukkan pilihan anda: ";
			cin >> choice;


			switch (choice) {
				case 1:
					registration();
					system("pause");
					break;
				case 2:
					if (loggedIn){
		                cout << "Anda sudah login!\n";
		                system("pause");
		                break;
		            }
					login();
					system("pause");
					break;
				case 3:
					if (!loggedIn){
		                cout << "Anda belum login, silahkan login terlebih dahulu!\n";
		                system("pause");
		                break;
		            }
					changePassword();
					break;
				case 4:
					if (!loggedIn){
		                cout << "Anda belum login, silahkan login terlebih dahulu!\n";
		                system("pause");
		                break;
		            }
					logout();
					cout << "Anda telah logout dari username " << userId << "!\n";
					system("pause");
					break;
				case 5:
					cout << "\nAnda telah keluar dari program." << endl;
					exit(0);
				default:
					cout << "Pilihan tidak valid. Silakan pilih 1, 2, atau 3." << endl;
			}
		}
};




int main() {
	userAuthentication User;


	while (true) {
		User.handleUser();
	}

	return 0;
}