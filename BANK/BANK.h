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
bool confirmMessage (); 
int ConfirmPin(int a);
void inSodu(long long a);


class CLIENT {
public:
  int idd;
  int maSoThe;
  char hoTen[256];
  char diaChi[256];
  char soDienThoai[256];
  char cccd[256];
  double soDuTaiKhoan;
  char taiKhoan[256];
  char matKhau[256];
  char email[256];
  char ngaySinh[256];
  int PIN;
public:
  friend istream &operator>>(istream &is, CLIENT &p) {
    fflush(stdin);
    
    cout << "Nhap ten: ";
    cin.getline(p.hoTen, 256);
    
    cout << "Nhap dia chi email: ";
    cin.getline(p.email, 256);
    
    cout << "Nhap so dien thoai: ";
    cin.getline(p.soDienThoai, 256);
    
    cout << "Nhap can cuoc cong dan: ";
    cin.getline(p.cccd, 256);
    
    cout << "Nhap dia chi: ";
    cin.getline(p.diaChi, 256);
    
    cout << "Nhap ngay sinh (dd-mm-yy): ";
    cin.getline(p.ngaySinh, 256);
    
  	cout << "Nhap ten dang nhap: ";
  	cin.getline(p.taiKhoan, 256);
  	
  	cout << "Nhap mat khau: ";
  	cin.getline(p.matKhau, 256);
  	
  	do {
        cout << "Xac nhan mat khau: ";
        char temp[256];
        cin.getline(temp, 256);
        if (strcmp(temp, p.matKhau) == 0) {
            break;
        } else {
            cout << "\n\n!!!Mat khau xac nhan khong chinh xac!!!" << endl;
            cout << "!!!Vui long xac nhan lai mat khau!!!\n" << endl;
        }
    } while(1);
    cout<<"Nhap ma pin moi: "; cin>>p.PIN;
    do {
        cout << "Xac nhan ma pin: ";
        int t;
        cin>>t;
        if (t==p.PIN) {
            break;
        } else {
            cout << "\n\n!!!Ma pin xac nhan khong chinh xac!!!" << endl;
            cout << "!!!Vui long xac nhan lai ma pin!!!\n" << endl;
        }
    } while (1);
    
    p.maSoThe = 10000000 + id;
    p.soDuTaiKhoan = 0;
    p.idd = id;
    return is;
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
void xuatTT(CLIENT& p){
  cout<<"                 THONG TIN TAI KHOAN                  " << endl;
  cout<<"+------------------------------------------------------+" << endl; 
  cout<<"|  So tai khoan: "<< setw(36) << p.maSoThe       << "  |" << endl; 
  cout<<"|  Ten dang nhap: "<< setw(35) << p.taiKhoan     << "  |" << endl;
  cout<<"|  Ho va ten: " << setw(39) <<p.hoTen            << "  |" << endl;
  cout<<"|  So dien thoai: "<< setw(35) << p.soDienThoai  << "  |" << endl;
  cout<<"|  So can cuoc cong dan: "<< setw(28) << p.cccd  << "  |" << endl;
  cout<<"|  Dia chi: " << setw(41) << p.diaChi            << "  |" << endl;
  cout<<"|  Ngay sinh: " << setw(39) << p.ngaySinh        << "  |" << endl; 
  cout<<"|  Email: " << setw(43) << p.email               << "  |" << endl;
  cout<<"+------------------------------------------------------+" << endl; 
  
} 

void xuatSodu(CLIENT& a){
  cout << "+-----------------------------------------------------------------+" << endl;
  cout << "| SO TAI KHOAN   | TEN TAI KHOAN              | SO DU HIEN TAI    |" << endl;
  cout << "|-----------------------------------------------------------------|" << endl;
  cout << "| " << setw(14) << left <<a.maSoThe << " | " << setw(26) << left << a.hoTen <<" | " << setw(17) << left << a.soDuTaiKhoan << " |" << endl;	
  cout << "+-----------------------------------------------------------------+" << endl;
  
  
}

void chuyenkhoan(CLIENT& a){
  char bank[256];
  int stk,s;
  long long tien;
  cout<<"Vui long chon hinh thuc chuyen tien:"<<endl;
  cout<<"1.Chuyen noi bo."<<endl;
  cout<<"2.Chuyen lien ngan hang."<<endl;
  cin >> s;
  switch (s)
  {
  case 1:
    cout<<"  Nhap so tai khoan ma ban muon chuyen toi: "; 
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
    cout<<"  Nhap so tien muon chuyen: "; cin >>tien;
    if(tien>a.soDuTaiKhoan) cout<<"  So du khong du de chuyen, vui long nhap so du nho hon "<<a.soDuTaiKhoan<<endl;
  } while (tien>a.soDuTaiKhoan);
  if(ConfirmPin(a.PIN)==1){
  if (confirmMessage() ) {
    if(a.soDuTaiKhoan<=50000){
      cout<<"So du quy khach nho hon 50K, vui long nap them tien vao tai khoan de thuc hien giao dich!"<<endl;
    }
    else{
  	a.soDuTaiKhoan-=tien;
  	client[x].soDuTaiKhoan += tien;
  	
  	
  	
    cout<<"Giao dich thanh cong! So du hien tai cua quy khach la: "; inSodu(a.soDuTaiKhoan);
  	saveListClient(client);
  	client = getListClient();
  	char x[300];
	  sprintf(x,"TK: %d  Giao Dich: - %d ", a.maSoThe,tien); 
	  cout << x;
    }
  } 
  else {
  	return;
  }
  }
  break;
  
  case 2:
  cout<<"Nhap ngan hang ban muon chuyen toi:"; 
  cin.getline(bank,256);
  cout<<"  Nhap so tai khoan ma ban muon chuyen toi: "; 
  cin >> stk;
  do
  {
    cout<<"  Nhap so tien muon chuyen: "; cin >>tien;
    if(tien>a.soDuTaiKhoan) cout<<"  So du khong du de chuyen, vui long nhap so du nho hon "<<a.soDuTaiKhoan<<endl;
  } while (tien>a.soDuTaiKhoan);
  
  if(ConfirmPin(a.PIN)==1){
  if (confirmMessage() ) {
    if(a.soDuTaiKhoan<=50000){
      cout<<"So du quy khach nho hon 50K, vui long nap them tien vao tai khoan de thuc hien giao dich!"<<endl;
    }
    else{
  	a.soDuTaiKhoan=a.soDuTaiKhoan-tien-0.02*tien;
    cout<<"Giao dich thanh cong! So du hien tai cua quy khach la: "; inSodu(a.soDuTaiKhoan);
    cout<<" (Da tru 2% phi giao dich)";
  	saveListClient(client);
  	client = getListClient();
    }
  } 
  else {
  	return;
  }
  }
    break;
  }
  
}

void napTien(CLIENT& a){
  long long tien;
  cout<<"  Nhap so tien muon nap: "; cin>>tien;
  if (confirmMessage() ) {
  	a.soDuTaiKhoan+=tien;
  	cout<<"\n  Ban da nap thanh cong! So du hien tai la: "; inSodu(a.soDuTaiKhoan);
  	cout << "\n  ";
  	saveListClient(client);
  	client = getListClient();
  }	else {
  	return;
  }
  
}

void rutTien(CLIENT& a){
  long long tien;
  do
  {
  	xuatSodu(a);
  	
    cout<<"  Nhap so tien muon rut: "; cin >>tien;
    if(tien>a.soDuTaiKhoan) cout<<"  So du khong du de rut, vui long nhap so du nho hon "; inSodu(a.soDuTaiKhoan);
  } while (tien>a.soDuTaiKhoan);
  if(ConfirmPin(a.PIN)==1){
  if (confirmMessage() ) {
  	a.soDuTaiKhoan-=tien;
  	cout<<"\n  Ban da rut thanh cong! So du hien tai la: "; inSodu(a.soDuTaiKhoan);
  	cout << "\n  ";
  	saveListClient(client);
  	client = getListClient();
  	
  	
  	
  	
  	
  } else {
  	return;
  }
  }
}

void doiMapin(CLIENT& a){
  char mk[258];
  int pin;
  do
  {
    cout<<"Vui long nhap mat khau: ";
    cin.getline(mk,258);
    if(strcmp(mk, a.matKhau) == 0) break;
  } while (1);
  do
  {
    cout<<"Vui long nhap ma pin cu: ";
    cin >>pin;
    if(pin==a.PIN) break;
  } while (1);
  cout<<"Nhap ma pin moi: ";
  cin>>a.PIN;
  if(confirmMessage()) cout<<"Thay doi ma pin thanh cong!"<<endl;
  else cout<<"Thay doi ma pin khong thanh cong!"<<endl;
}

void dichvuKhac(CLIENT& a){
  cout<<"Comming soon!";
}

int check(char* tendn, char* mk){
  for (int i = 1; i <= number; i++)
  {
    if(strcmp(client[i].taiKhoan,tendn)==0 && strcmp(client[i].matKhau, mk)==0){
    	
    	return i;	
	}	
	
  }
  return 0;
}

int log_in(){
  char tendn[256];
  char mk[256];
  fflush(stdin);
  system("cls");
  cout << "\n  Ten Dang Nhap: "; cin.getline(tendn,256);
  
  	int i = 0;
    char ch;
    cout << "  Mat khau: ";
    ch = _getch();
    while(ch != 13){//character 13 is enter
      mk[i] = ch;
      i ++;
      cout << '*';
      ch = _getch();
    }
  
  return check(tendn,mk);
  
  
  
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



void deleteCLient(int i) {
      saveListClient(client, i);
      client = getListClient();
      number--;
	taoID();
    
	
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
   cout<<endl;
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
   cout<<endl;
  }
}

bool confirmMessage () {
	system("cls");
	cout << "  +------------------------------+" << endl;
	cout << "  | !!!  Xac nhan giao dich  !!! |" << endl;
	cout << "  +------------------------------+" << endl;
	cout << "\n";
	cout << "  1: Xac nhan" << endl;
	cout << "  0: Tu choi" << endl;
	
	bool select;
	cout << "  Nhap lua chon: ";
	cin >> select;
	
	system("cls");
	
	if (select == 1)	return 1;
	else 				return 0;
}
int ConfirmPin(int a){
    int pin;
    cout<<"Vui long nhap ma pin de xac nhan giao dich: ";
    cin >>pin;
    if(a==pin) return 1;
    else return 0;
}
#endif
