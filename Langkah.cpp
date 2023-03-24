#include<iostream>
#include<conio.h>
using namespace std;
int main(){
	//
	int i,j,a[20],b[20],banyakA,banyakB;
	cout<<"IRISAN & GABUNGAN 2 HIMPUNAN\n";
	cout<<"============================\n\n";
	
	cout<<"Masukkan banyaknya anggota himpunan A : ";
	cin>>banyakA;
	
	//isi anggota A ditanpung dalam array a
	for(i=0;i<banyakA;i++){
	
	cout<<"Masukkan anggota " << i+1 <<" : ";
	cin>>a[i];
	}
	
	cout<<"Masukkan banyaknya anggota himpunan B : ";
	cin>>banyakB;
	
	//isi anggota B di tampung dalam array b
	for(i=0;i<banyakB;i++){
		cout<<"Masukkan anggota "<< i+1 <<" : ";
		cin>>b[i];
	}
	
	//memanampilkan isi dai array a
	cout<<"\nHimpunan A={ ";
	for(i=0;i<banyakA;i++){
		cout<<a[i]<<" ";
	}
	cout<<"}";
	
	//menampilkan isi dari array b
	cout<<"\nHimpunan B={ ";
	for(i=0;i<banyakB;i++){
		cout<<b[i]<<" ";
	}
	cout<<"}";
	
	//Membuat kode untuk mencari irisan nya
	cout<<"\n\n-------------------------------\n";
	cout<<"A irisan B = { ";
	for(i=0;i<banyakA;i++){
		for(j=0;j<banyakB;j++){
			//a irisan b berisi anggota dari himpunan a dan b yang sama
			//jika isi dari array a = isi array b, maka tampilkan isi array a
			if(a[i]==b[j]){
				cout<<a[i]<<" ";
			}
		}
	}
	
	cout<<"}\n";
	cout<<"A Gabungan B ={ ";
	for(i=0;i<banyakA;i++){
		cout<<a[i]<<" ";
	}
	for(j=0;j<banyakB;j++){
		cout<<b[j]<<" ";
	}
	
	cout<<"}\n";
	cout<<"\n\nTekan sembarang untuk keluar . . .";
	getch();
	return 0;
}
