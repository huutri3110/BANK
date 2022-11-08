#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <conio.h>
#include <io.h>
#include <iomanip>
#include <string.h>



using namespace std;

int id;
int number;

class CLIENT;
void taoID(); //bo o dau ham main la duoc
void layID(); //bo o cuoi ham main 
void moTaiKhoan(); //Yeu cau nhap thong tin roi luu thong tin vao file
CLIENT* getListClient();//Lay du lieu trong file va tra ve mang du lieu
void saveListClient(CLIENT* client);//luu du lieu vao file
void showListClient(CLIENT* client);




class CLIENT {
public:
  int idd;
  int maSoThe;
  string hoTen;
  string diaChi;
  string soDienThoai;
  string cccd;
  long long soDuTaiKhoan;
  string taiKhoan;
  string matKhau;
public:
  friend istream &operator>>(istream &is, CLIENT &p) {
    fflush(stdin);
  	cout << "Nhap ten dang nhap: ";
  	cin.getline(p.taiKhoan, 256);
  	cout << "Nhap mat khau: ";
  	cin.getline(p.matKhau, 256);
    cout << "Nhap ten: ";
    cin.getline(p.hoTen, 256);
    cout << "Nhap dia chi: ";
    cin.getline(p.diaChi, 256);
    cout << "Nhap so dien thoai: ";
    cin.getline(p.soDienThoai, 256);
    cout << "Nhap can cuoc cong dan: ";
    cin.getline(p.cccd, 256);
    p.maSoThe = 10000000 + id;
    p.soDuTaiKhoan = 0;
    p.idd = id;
    return is;
  }
  
  friend ostream& operator << (ostream& os, CLIENT &p) {
  	cout << "|" << setw(3)  << left  << p.idd;
  	cout << "|" << setw(14) << left  << p.maSoThe;
  	cout << "|" << setw(22) << left  << p.hoTen;
  	cout << "|" << setw(22) << left  << p.diaChi;
  	cout << "|" << setw(16) << left  << p.soDienThoai;
  	cout << "|" << setw(14) << left  << p.cccd;
  	cout << "|" << setw(16) << left  << p.soDuTaiKhoan << endl;
    return os;
  }
  
};

CLIENT* client;





void moTaiKhoan() {
  id++; 
  number++;
  taoID();
  CLIENT a;
  cin >> a;
  fstream f("text1.txt" , ios::binary|ios::out|ios::app);
  if(!f) cout << "error occured when open file to write!";
  f.write(reinterpret_cast<char *>(&a), sizeof(a));
  f.close();
  client = getListClient();
}
void xuatTT(CLIENT& a){

  cout<<"Ten khach hang: "<<a.hoTen<<endl;
  cout<<"Dia chi: "<<a.diaChi<<endl;
  cout<<"So dien thoai: "<<a.soDienThoai<<endl;
  cout<<"So tai khoan: "<<a.maSoThe<<endl;
  cout<<"So can cuoc cong dan: "<<a.cccd<<endl;
}

void inSodu(long long a ){
  long long n=a;
  int d=0;
  while (n>0)
  {
    n/=10;
    d++;
  }
  int arr[d+1];
  n=a;
  for (int i = 1; i <= d; i++) {
    arr[i]=n%10;
    n/=10;
  }
  if(d%3==0){
    for (int i = 1; i <= d; i++)
   {
     cout<<arr[d-i+1];
     if(i%3==0 && i<d) cout<<".";
   }
  }
  else{
    for (int i = d; i > d-d%3; i--){
      cout<<arr[i];
    }
    cout<<".";
    int t=d-d%3;
     for (int i = 1; i <= t; i++)
   {
     cout<<arr[t-i+1];
     if(i%3==0 && i< t) cout<<".";
   }
  }
  cout<<" VND";
   cout<<endl;
}

void xuatSodu(CLIENT& a){
  cout<<"So du hien tai: "; inSodu(a.soDuTaiKhoan);
}

void chuyenkhoan(CLIENT& a){
  char bank[256];
  int stk;
  long long tien;
  cout<<"Chon ngan hang ban muon chuyen toi: "; 
  fflush(stdin);
  cin.getline(bank,256);
  cout<<"Nhap so tai khoan ma ban muon chuyen toi: "; 
  cin >> stk;
  
  int x;
  for(int i = 1; i<=number; i++) {
  	if (stk == client[i].maSoThe) {
		x = i;
		i = number + 1; //thoat vong lap
	}
  }
  do
  {
    cout<<"Nhap so tien muon chuyen: "; cin >>tien;
    if(tien>a.soDuTaiKhoan) cout<<"So du khong du de chuyen, vui long nhap so du nho hon "; inSodu(a.soDuTaiKhoan); cout<<endl;
  } while (tien>a.soDuTaiKhoan);
  cout<<"Giao dich dang xu li. Giao dich thanh cong!";
  a.soDuTaiKhoan-=tien;
  client[x].soDuTaiKhoan += tien;
  cout<<"So tien con lai la: "; inSodu(a.soDuTaiKhoan);
  saveListClient(client);
  client = getListClient();
}

void napTien(CLIENT& a){
  long long tien;
  cout<<"Nhap so tien muon nap: "; cin>>tien;
  a.soDuTaiKhoan+=tien;
  cout<<"Ban da nap thanh cong! So du hien tai la: "; inSodu(a.soDuTaiKhoan);
  saveListClient(client);
  client = getListClient();
}

void rutTien(CLIENT& a){
  long long tien;
  do
  {
    cout<<"Nhap so tien muon rut: "; cin >>tien;
    if(tien>a.soDuTaiKhoan) cout<<"So du khong du de rut, vui long nhap so du nho hon "<<a.soDuTaiKhoan<<endl;
  } while (tien>a.soDuTaiKhoan);
  a.soDuTaiKhoan-=tien;
  cout<<"Ban da rut thanh cong! So du hien tai la: "; inSodu(a.soDuTaiKhoan);
  saveListClient(client);
  client = getListClient();
}

void dichvuThe(CLIENT& a){
  cout<<"Comming soon!";
}

void dichvuKhac(CLIENT& a){
  cout<<"Comming soon!";
}

int check(char* tendn, char* mk){
  for (int i = 1; i <= number; i++)
  {
    if(strcmp(client[i].taiKhoan,tendn)==0 && strcmp(client[i].matKhau, mk)==0)	return i;
  }
  return 0;
}

void log_in(){
  char tendn[256];
  char mk[256];
  fflush(stdin);
  cout<<"\nTen Dang Nhap: "; cin.getline(tendn,256);
  cout<<"Mat Khau: "; cin.getline(mk,256);
  if(check(tendn,mk)){
        int vt=check(tendn,mk);
        int s=1;
        do
        {
        	system("cls");
            cout<<"\n1.Thong tin tai khoan."<<endl;;
            cout<<"2.So du tai khoan."<<endl;
            cout<<"3.Chuyen khoan"<<endl;
            cout<<"4.Nap tien."<<endl;
            cout<<"5.Rut tien."<<endl;
            cout<<"6.Cac dich vu lien quan den the."<<endl;
            cout<<"7.Cac dich vu khac (Thanh toan hoa don, Tien dien, Tien nuoc,...)"<<endl;
            cout <<"0.Dang Xuat" << endl;
			cin >> s; 
            switch (s)
            {
                case 1: 
                system("cls");
				xuatTT(client[vt]);
				system("pause");
                break;
                case 2:
                system("cls");
				xuatSodu(client[vt]);
				system("pause");
                break;
                case 3:
                system("cls");
				chuyenkhoan(client[vt]);
				system("pause");
                break;
                case 4:
                system("cls");
				napTien(client[vt]);
				system("pause");
                break;
                case 5: 
                system("cls");
				rutTien(client[vt]);
				system("pause");
                break;
                case 6: dichvuThe(client[vt]);
                break;
                case 7: dichvuKhac(client[vt]);
                break;
                default: s = 0;
          }
        } while(s);
        return;
      }
  cout<<"Tai khoan va mat khau chua chinh xac! Vui long nhap lai!"<<endl;
}

CLIENT* getListClient() {
  CLIENT* client = new CLIENT [number+1];
  int i = 1;
  fstream f("text1.txt" , ios::binary|ios::in);
  if(!f) cout << "error occured when open file to read!";
  while(f.good()) {
    f.read(reinterpret_cast<char *>(&client[i]), sizeof(client[i]));
    i++;
    if(f.eof()) break;
  }
  f.close();
  return client;
}

void saveListClient(CLIENT* client) {
	fstream f("text1.txt" , ios::binary|ios::out|ios::trunc);
  	if(!f) cout << "error occured when open file to write!";
	for(int i = 1; i<=number; i++) {
		f.write(reinterpret_cast<char *>(&client[i]), sizeof(client[i]));
	}
	f.close();
}

void saveListClient(CLIENT* client, int ii) {
  fstream f("text1.txt" , ios::binary|ios::out|ios::trunc);
  	if(!f) cout << "error occured when open file to write!";
	for(int i = 1; i<=number; i++) {
    if (i == ii) continue;
		f.write(reinterpret_cast<char *>(&client[i]), sizeof(client[i]));
	}
	f.close();
}


void layID() {
  fstream f("id.txt" , ios::in);
  if(!f) cout << "error occured when open file to read!";
  f >> id;
  f >> number;
  f.close();
}
void taoID() {
  fstream f("id.txt" , ios::out|ios::trunc);
  if(!f) cout << "error occured when open file to write!";
  f << id << ' ';
  f << number;
  f.close();
}

void showListClient(CLIENT* client) {
	cout << "\t\t\t\t\tDanh Sach Tai Khoan\t\t\t\t\t" << endl << endl;
	cout << "|" << setw(3)  << left  << "ID";
  	cout << "|" << setw(14) << left  << "Ma so the";
  	cout << "|" << setw(22) << left  << "Ho ten";
  	cout << "|" << setw(22) << left  << "Dia chi";
  	cout << "|" << setw(16) << left  << "So dien thoai";
  	cout << "|" << setw(14) << left  << "CCCD";
  	cout << "|" << setw(16) << left  << "So du tai khoan" << endl;
	for(int i=1; i<=number; i++){
		cout << client[i];
	}
	cout << endl;
}

void deleteCLient(int i) {
      saveListClient(client, i);
      client = getListClient();
      number--;
	taoID();
    
	
}

#endif
