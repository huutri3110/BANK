//#ifndef BANK_H
//#define BANK_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <conio.h>
#include <io.h>
#include <iomanip>
#include <string.h>
#include <cstdlib>
#include "dateTime.h"
#include "Hash_Table.h"


using namespace std;

//=============================CLIENT_H ==============================================
class CLIENT {
private:
  int id;
  int maSoThe;
  
  
  
  
  
  int ngaySinh;
  int thangSinh;
  int namSinh;
  
  
  unsigned long long soDuTaiKhoan;
  unsigned long long dta;
  char hoTen[256];
  char diaChi[256];
  char soDienThoai[256];
  char cccd[256];
  char taiKhoan[256];
  char matKhau[256];
  char maPin[4];

public:
	friend class hashTable<CLIENT>;
	CLIENT();
	
	unsigned long long getDta() {
		return dta;
	}
	void setHoTen ();
	char* getHoTen ();
	void setDiaChi();
	char* getDiaChi();
	void setSdt();
	char* getSdt();
	void setCccd();
	char* getCccd();
	void setNgaySinh();
	int getNgaySinh () {
		return ngaySinh;
	}
	int getThangSinh () {
		return thangSinh;
	}
	int getNamSinh () {
		return namSinh;
	}
	
	void setTaiKhoan();
	char* getTaiKhoan();
	void setMatKhau();
	char* getMatKhau();
	void setMaPin ();
	char* getMaPin();	
	void setSoDuTaiKhoan(unsigned long long);
	unsigned long long getSoDuTaiKhoan();
	void setID (int id);
	int getID();
	void setMaSoThe();
	int getMaSoThe();
	void saveCLIENT();
	const CLIENT operator = (CLIENT& p);
	unsigned long long strToInt (char* str);
	unsigned long long covertCharToInt (char data);
};

CLIENT::CLIENT(){
	this->dta = 0;
}


unsigned long long CLIENT::strToInt (char* str) {
			unsigned long long result = 0;
			for (int i = 0; i < strlen(str); i++) {
				result += covertCharToInt(str[i])*pow(37, i);
			}
			return result;
		} 
unsigned long long CLIENT::covertCharToInt (char data) {
	switch (data) {
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		case '_': return 10; 
		case 'A': return 11;
		case 'a': return 11;
		case 'B': return 12;
		case 'b': return 12;
		case 'C': return 13;
		case 'c': return 13;
		case 'D': return 14;
		case 'd': return 14;
		case 'E': return 15;
		case 'e': return 15;
		case 'F': return 16;
		case 'f': return 16;
		case 'G': return 17;
		case 'g': return 17;
		case 'H': return 18;
		case 'h': return 18;
		case 'I': return 19;
		case 'i': return 19;
		case 'J': return 20;
		case 'j': return 20;
		case 'K': return 21;
		case 'k': return 21;
		case 'L': return 22;
		case 'l': return 22;
		case 'M': return 23;
		case 'm': return 23;
		case 'N': return 24;
		case 'n': return 24;
		case 'O': return 25;
		case 'o': return 25;
		case 'P': return 26;
		case 'p': return 26;
		case 'Q': return 27;
		case 'q': return 27;
		case 'R': return 28;
		case 'r': return 28;
		case 'S': return 29;
		case 's': return 29;
		case 'T': return 30;
		case 't': return 30;
		case 'U': return 31;
		case 'u': return 31;
		case 'V': return 32;
		case 'v': return 32;
		case 'W': return 33;
		case 'w': return 33;
		case 'X': return 34;
		case 'x': return 34;
		case 'Y': return 35;
		case 'y': return 35;
		case 'Z': return 36;
		case 'z': return 36;
		
	}
}

void CLIENT::setHoTen () {
		fflush(stdin);
    	cout << "  Nhap ten: ";
    	cin.getline(this->hoTen, 256);
}
char* CLIENT::getHoTen() {
	return hoTen;
}
void CLIENT::setDiaChi() {
	cout << "  Nhap dia chi: ";
    cin.getline(this->diaChi, 256);
}
char* CLIENT::getDiaChi() {
	return diaChi;
}
void CLIENT::setSdt() {
    do {
   		fflush(stdin);
   		cout << "  Nhap so dien thoai: ";
   		cin.getline(this->soDienThoai, 256);
   		if (strlen(this->soDienThoai) == 10) {
   			break;
		} else {
		cout << "  So dien thoai vua nhap khong dung!" << endl;
		cout << "  Vui long nhap lai!" << endl;
		}
	} while (1);
}
char* CLIENT::getSdt() {
	return soDienThoai;
}
void CLIENT::setCccd() {
	do {
    	fflush(stdin);
    	cout << "  Nhap can cuoc cong dan: ";
    	cin.getline(this->cccd, 256);
    	if (strlen(this->cccd) == 12) {
    		break;
		} else {
			cout << "  So can cuoc cong dan vua nhap khong dung!" << endl;
			cout << "  Vui long nhap lai!" << endl;
		}
	} while (1);
}
char* CLIENT::getCccd() {
	return cccd;
}
void CLIENT::setNgaySinh() {
	do {
    	int day, mon, year;
	    cout << "  Nhap ngay sinh (dd mm yy) " << endl;
	    cout << "    Nhap ngay: "; cin >> day;
	    cout << "    Nhap thang: "; cin >> mon;
	    cout << "    Nhap nam: "; cin >> year;
    	dateTime dd;
	    if (dd.laNgayHopLe(day, mon, year)) {
	    	this->ngaySinh = day;
	    	this->thangSinh = mon;
	    	this->namSinh = year;
	    	break;
		} else {
			cout << "  Ngay thang nam vua nhap khong hop le!" << endl;
			cout << "  Vui long nhap lai!" << endl;
		}
	} while (1);
}

void CLIENT::setTaiKhoan() {
		fflush(stdin);
		cout << "  Nhap ten dang nhap: ";
		cin.getline(this->taiKhoan, 256);
		fflush(stdin);
		this->dta = strToInt (this->taiKhoan);

}
char* CLIENT::getTaiKhoan() {
	return taiKhoan;
}
void CLIENT::setMatKhau() {
	do {
    	fflush(stdin);
    	cout << "  Nhap mat khau: ";
	 	cin.getline(this->matKhau, 256);
    	if (strlen(this->matKhau) >= 6 ) {
    		break;
		} else {
			cout << "  Mat khau vua nhap it hon 6 ki tu!" << endl;
			cout << "  Vui long nhap lai!" << endl;
		}
	} while (1); 	
	
	do {
        cout << "  Xac nhan mat khau: ";
        char temp[256];
        fflush(stdin);
        cin.getline(temp, 256);
        if (strcmp(temp, this->matKhau) == 0) {
            break;
        } else {
            cout << "  Mat khau xac nhan khong chinh xac!" << endl;
            cout << "  Vui long xac nhan lai mat khau!" << endl;
        }
    } while(1);
	
}
char* CLIENT::getMatKhau() {
	return matKhau;
}
void CLIENT::setMaPin () {
	do {
		fflush(stdin);
		cout << "  Nhap ma pin: ";
		cin.getline(this->maPin, 5);
		if (strlen(this->maPin) == 4) {
			break;
		} else {
			cout << "  Ma pin vua nhap khong dung 4 ki tu!" << endl;
			cout << "  Vui long nhap lai!" << endl;
		}
	} while (1);
	
	do {
        cout << "  Xac nhan ma pin: ";
        char temp[256];
        fflush(stdin);
        cin.getline(temp, 5);
        if (strcmp(temp, this->maPin) == 0) {
            break;
        } else {
            cout << "  Ma pin xac nhan khong chinh xac!" << endl;
            cout << "  Vui long xac nhan lai ma pin!" << endl;
        }
    } while(1);
}
char* CLIENT::getMaPin() {
	return maPin;
}
void CLIENT::setSoDuTaiKhoan(unsigned long long soTien) {
		this->soDuTaiKhoan = soTien;
}
unsigned long long CLIENT::getSoDuTaiKhoan() {
	return soDuTaiKhoan;
}
void CLIENT::setID (int id) {
		this->id = id;
}
int CLIENT::getID() {
	return id;
}
void CLIENT::setMaSoThe() {
		this->maSoThe = 1000000000 + this->id;
}
int CLIENT::getMaSoThe() {
	return maSoThe;
}
void CLIENT::saveCLIENT() {
		fstream f("text1.txt" , ios::binary|ios::out|ios::app);
	  	if(!f) cout << "error occured when open file to write!";
		f.write(reinterpret_cast<char *>(this), sizeof(*this));
		f.close();
}
const CLIENT CLIENT::operator = (CLIENT& p) {
		strcpy (this->hoTen, p.hoTen);
		strcpy (this->diaChi, p.diaChi);
		strcpy (this->soDienThoai, p.soDienThoai);
		strcpy (this->cccd, p.cccd);
		strcpy (this->taiKhoan, p.taiKhoan);
		strcpy (this->matKhau, p.matKhau);
		strcpy (this->maPin, p.maPin);
		this->dta = p.dta;
		this->soDuTaiKhoan = p.soDuTaiKhoan;
		this->maSoThe = p.maSoThe;
		this->ngaySinh = p.ngaySinh;
		this->thangSinh = p.thangSinh;
		this->namSinh = p.namSinh;
		this->id = p.id;
		
}
  	


//=====================END_CLIENT_H=========================================================


//===========================LIST_H==============================================================

class LIST {
	private:
		hashTable<CLIENT> list;
		int number;
		int id;
		int maGD; 
	public:
		LIST();                         //Lay du lieu tu file
		~LIST() {
//			delete[] list;
		}
		
		
		
		
		
		void signUp(); 					//DangKi
		int log_in();					//Dang Nhap
		int check(char*, char*);        //Check gi day
		void xuatTT(CLIENT& p);         //Xuat Thong Tin
		void xuatSodu(CLIENT& a);		//Xuat so du
		void napTien(CLIENT& a);		//Naptien
		void rutTien(CLIENT& a);
		int taoMaGD ();                 //
		void saveTransaction (char* x, char* path); //Luu LSGD
		void exportTransaction (CLIENT& a);         //Xuat thong tin LSGD
		void saveLIST ();
		static bool confirmMessage ();                    //
		char* intToStr (char target[], unsigned long long num);
		int ConfirmPin(char a[]);
		void doiMapin(CLIENT& a);
		void thanhToan(CLIENT &a);
		void chuyenkhoan(CLIENT& a);
		void quenMatKhau ();
		
		void setID();                   //Luu ID vao file
		void getID();                   //Lay ID tu file
		CLIENT& operator [] (int index);//Dinh nghia lai toan tu []
};

LIST::LIST() {
	getID();
	
	list.init(number);

  	int i = 0;
  	fstream f("text1.txt" , ios::binary|ios::in);
  	if(!f) cout << "error occured when open file to read!";
  	while(i<number) {
  		CLIENT* client = new CLIENT;
    	f.read(reinterpret_cast<char *>(client), sizeof(*client));
    	i++;
		list.insert (client->getDta(), *client);
		
    	if(f.eof()) break;
    	delete client;
  	}		
  	

  	
//  	------------------------------------------------------------------------------
//  	for (int i = 0; i<list.getKeyCount(); i++) {
//  		cout << "list[" << i << "]: " << list[i].getDta() << endl;
//	}
//	system("pause");
//	  ----------------------------------------------------------------------------
  	f.close();

	
	
//	getID();
//	list = new CLIENT [number];
//  	int i = 0;
//  	fstream f("text1.txt" , ios::binary|ios::in);
//  	if(!f) cout << "error occured when open file to read!";
//  	while(f.good() && i<number) {
//  		
//    	f.read(reinterpret_cast<char *>(&list[i]), sizeof(list[i]));
//    	i++;
//    	if(f.eof()) break;
//  	}		
//  	f.close();

}

void LIST::saveLIST () {
			fstream ofs ("text1.txt", ios::out|ios::trunc);
			ofs.close();
			for (int i = 0; i < this->list.getKeyCount(); i++) {
				if (list[i].getDta() != 0) {
					list[i].saveCLIENT();
				}
				
			}
}

CLIENT& LIST::operator [] (int index) {
	return list[index];
//	return list.find(index);
}

void LIST::signUp() {
	
	number++;
    id++;
    this->setID();
	
	CLIENT* p = new CLIENT;
	p->setHoTen();
	p->setDiaChi();
	p->setSdt();
	p->setCccd();
	p->setNgaySinh();
	int check;
	do {
		check = 0;
		p->setTaiKhoan();
		for (int i=0; i<list.getKeyCount(); i++) {
			if (list[i].getDta() != 0) {
				if (strcmp(p->getTaiKhoan(), list[i].getTaiKhoan()) == 0) {
				check = 1;
				cout << "  Ten dang nhap da duoc su dung!" << endl;
				cout << "  Vui long nhap lai!" << endl;
				}
			}
			
		}
	} while (check);
//	
//	cout << p->getDta() << endl;
	
	p->setMatKhau();
	p->setMaPin();
	p->setSoDuTaiKhoan(0);
    p->setID(id);
    p->setMaSoThe();
    
    p->saveCLIENT();
//    
//    cout << "new: " << p->getDta() << endl;
    
    this->list.insert(p->getDta(), *p);
//    cout << list.find(p->getDta()) << " " << p->getDta();
    
    system("pause");
} 

void LIST::saveTransaction (char* x, char* path) {
	fstream f;
	f.open(path, ios::out | ios::app);
	f << x;
	f.close();
} 

void LIST::getID() {
  fstream f("id.txt" , ios::in);
  if(!f) cout << "error occured when open file to read!";
  f >> id;
  f >> number;
  f >> maGD;
  f.close();
}
void LIST::setID() {
  fstream f("id.txt" , ios::out|ios::trunc);
  if(!f) cout << "error occured when open file to write!";
  f << id << ' ';
  f << number << ' ';
  f << maGD;
  f.close();
}

int LIST::log_in(){
  char tendn[256];
  char mk[256];
  fflush(stdin);
  system("cls");
  cout << "\n  Ten Dang Nhap: "; cin.getline(tendn,256);
  
  	int i = 0;
    char ch;
    cout << "  Mat khau: ";
    ch = _getch();
    while(ch != 13){
      mk[i] = ch;
      i ++;
      cout << '*';
      ch = _getch();
    }
    int temp = check(tendn,mk);
  	if (temp == -1) {
  		cout << "  \nTen dang nhap hoac mat khau khong dung!" << endl;
  		return temp;
	} else {
		return temp;
	}
  
}

int LIST::check(char* tendn, char* mk){
	CLIENT* p = new CLIENT;
	
	int i = this->list.find(p->strToInt(tendn));
//	cout << "-------------" << endl;
//	cout << p->strToInt(tendn) << endl;
//	cout << i << endl;
//	system("pause");
	if (i == -1) return -1;
	
//	cout << list[i].getTaiKhoan() << " " <<  list[i].getMatKhau()  << endl;
//	system("pause");

	if(strcmp(list[i].getTaiKhoan(),tendn)==0 && strcmp(list[i].getMatKhau(), mk)==0) {
		return i;
	} else {
		return -1;
	}
	
}

void LIST::xuatTT(CLIENT& p){
  cout << endl;
  cout<<"                   THONG TIN TAI KHOAN                  " << endl;
  cout<<"  +------------------------------------------------------+" << endl; 
  cout<<"  |  So tai khoan: "<< setw(36) << right << p.getMaSoThe()       << "  |" << endl; 
  cout<<"  |  Ten dang nhap: "<< setw(35) << right << p.getTaiKhoan()     << "  |" << endl;
  cout<<"  |  Ho va ten: " << setw(39) << right <<p.getHoTen()            << "  |" << endl;
  cout<<"  |  So dien thoai: "<< setw(35) << right << p.getSdt()  << "  |" << endl;
  cout<<"  |  So can cuoc cong dan: "<< setw(28) << right << p.getCccd()  << "  |" << endl;
  cout<<"  |  Dia chi: " << setw(41) << right << p.getDiaChi()            << "  |" << endl;
  cout<<"  |  Ngay sinh: " << setw(31) << right<< p.getNgaySinh() << "-" << setw(2) << right << p.getThangSinh() << "-" << setw(2) << right << p.getNamSinh() << "  |" << endl; 
  cout<<"  +------------------------------------------------------+" << endl << endl; 
  
} 

void LIST::xuatSodu(CLIENT& a){
  cout << endl;
  cout << "  \t\t\tSO DU TAI KHOAN" << endl;
  char target[256] = "";
  cout << "  +-------------------------------------------------------------------------+" << endl;
  cout << "  | SO TAI KHOAN   | TEN TAI KHOAN              | SO DU HIEN TAI            |" << endl;
  cout << "  |-------------------------------------------------------------------------|" << endl;
  cout << "  | " << setw(14) << left <<a.getMaSoThe() << " | " << setw(26) << left << a.getHoTen() <<" | " << setw(24) << this->intToStr(target, a.getSoDuTaiKhoan()) << "  |" << endl;
  cout << "  +-------------------------------------------------------------------------+" << endl << endl;
}

void LIST::napTien(CLIENT& a){
  xuatSodu(a);
  unsigned long long soTien;
  cout<<"  Nhap so tien muon nap: "; cin >> soTien;
  if (LIST::confirmMessage() ) {
  	a.setSoDuTaiKhoan(a.getSoDuTaiKhoan() + soTien);
  	char target1[256]= "";
  	cout<<"\n  Ban da nap thanh cong! So du hien tai la: " << this->intToStr(target1, a.getSoDuTaiKhoan()) << endl;

    char x[256];
    dateTime d;
    d.setCurrentTime();
    char target[256] = "";
    sprintf(x," TK:%d\n+%s\n%d/%d/%d %d:%d\nNap Tien\nNap tien vao tai khoan\nMa GD: %d%d\n",a.getMaSoThe(),this->intToStr(target, soTien),d.getDay(),d.getMon(),d.getYear(),d.getHour(),d.getMin(),2,LIST::taoMaGD());
    char path[256];
    sprintf(path,"./LSGD/%d-%s.txt",a.getID(),a.getHoTen());
    
    
    
    this->saveTransaction(x,path);
    
    this->saveLIST();
    
	cout << endl;
	char target3[256] = "";
    cout << "  +--------- Thong bao bien dong so du: ----------+" << endl;
    cout << "  | Tai khoan: " << setw(34) << right << a.getMaSoThe() << " |" << endl;
    cout << "  | So tien giao dich: " << setw(26) << right << this->intToStr(target3, soTien) << " |" << endl;
    cout << "  | Thoi gian: " << setw(20) << right << d.getDay() << "/" << d.getMon() << "/" << d.getYear() << " " << setw(2) << right << d.getHour() << ":" << setw(2) << right  << d.getMin() << " |" << endl;
    cout << "  | Noi dung:              Nap tien vao tai khoan |" << endl;
    cout << "  +-----------------------------------------------+" << endl;
  }else {
  	return;
  }
}

int LIST::taoMaGD() {
	maGD++;
	this->setID();
	return 100000000 + maGD;
}
  


bool LIST::confirmMessage () {

	cout << endl;
	cout << "  +------------------------------+" << endl;
	cout << "  | !!!  Xac nhan giao dich  !!! |" << endl;
	cout << "  +------------------------------+" << endl;
	cout << "\n";
	cout << "  1: Xac nhan" << endl;
	cout << "  0: Tu choi" << endl;
	
	bool select;
	cout << "  Nhap lua chon: ";
	cin >> select;
	

	
	if (select == 1)	return 1;
	else 				return 0;
}


void LIST::exportTransaction (CLIENT& a) {
	
	fstream f;
	char path[256];
	sprintf(path,"./LSGD/%d-%s.txt",a.getID(),a.getHoTen());
	f.open(path, ios::in);

  if(!(f.peek()==std::ifstream::traits_type::eof())){
	string temp;
	system ("cls");
	cout << "\n\t\t\t\t\t\t\t\t\t\t\tLICH SU GIAO DICH" << endl << endl;
	cout << "  +----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
	cout << "  | So Tai Khoan     | Bien Dong So Du     | Thoi Gian Giao Dich       | Hinh Thuc        | Noi Dung                                                                       | Ma Giao Dich              |" << endl; 
	cout << "  +----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
	cout << endl;
	
	int i = 0; 
	while (!f.eof()) {
		cout << "  +------------------+---------------------+---------------------------+------------------+--------------------------------------------------------------------------------+---------------------------+" << endl;
		getline(f, temp, '\n');
		if (temp.length() != 0) {
			cout << "  |" << setw(18) << left << temp << "| ";
		}
		
		
		getline(f, temp, '\n');
		if (temp.length() != 0) {
			cout << setw(20) << temp << "| ";
		}
		
		
		getline(f, temp, '\n');
		if (temp.length() != 0) {
			cout << setw(26) << left << temp << "| ";
		}
		
		
		getline(f, temp, '\n');
		if (temp.length() != 0) {
			cout << setw(17) << left << temp << "| ";
		}
		
		
		getline(f, temp, '\n');
		if (temp.length() != 0) {
			cout << setw(79) << left << temp << "| ";
		}
		
		
		getline(f, temp, '\n');
		if (temp.length() != 0) {
			cout << setw(26) << left << temp << "| ";
		}
		
		cout << endl;
	}
  }
  else{
    cout<<"  Chua co lich su giao dich!"<<endl;
  }
	f.close();

}


void LIST::rutTien(CLIENT& a) {
	

  this->xuatSodu(a);
  int sl=3;
  unsigned long long tien;
  do
  {
    cout<<"  Nhap so tien muon rut: "; cin >>tien;
    if(tien>a.getSoDuTaiKhoan()){
       char target[256] = "";
       cout<<"  So du khong du de rut, vui long nhap so du nho hon " << this->intToStr(target, a.getSoDuTaiKhoan());
    }
  } while (tien>a.getSoDuTaiKhoan());
NhapPin:  
	fflush(stdin);
  if(ConfirmPin(a.getMaPin())==1){
  if (confirmMessage() ) {
  	a.setSoDuTaiKhoan(a.getSoDuTaiKhoan() - tien);
  	char target[256] = "";
  	cout<<"\n  Ban da rut thanh cong! So du hien tai la: " << this->intToStr(target, a.getSoDuTaiKhoan());
  	cout << "\n  ";
  	
  	
    char x[256];
    dateTime d;
    d.setCurrentTime();
    char target1[256] = "";
    sprintf(x," TK:%d\n-%s\n%d/%d/%d %d:%d\nRut Tien\nRut tien tu tai khoan %d\nMa GD: %d%d\n",a.getMaSoThe(),this->intToStr(target1, tien),d.getDay(),d.getMon(),d.getYear(),d.getHour(),d.getMin(),a.getMaSoThe(),3,taoMaGD());
    char path[256];
    sprintf(path,"./LSGD/%d-%s.txt",a.getID(),a.getHoTen());
    
        
    this->saveTransaction(x,path);
    this->saveLIST();
    
    cout << endl;
	char target3[256] = "";
    cout << "  +--------- Thong bao bien dong so du: ----------+" << endl;
    cout << "  | Tai khoan: " << setw(34) << right << a.getMaSoThe() << " |" << endl;
    cout << "  | So tien giao dich: " << setw(26) << right << this->intToStr(target3, tien) << " |" << endl;
    cout << "  | Thoi gian: " << setw(20) << right << d.getDay() << "/" << d.getMon() << "/" << d.getYear() << " " << setw(2) << right << d.getHour() << ":" << setw(2) << right  << d.getMin() << " |" << endl;
    cout << "  | Noi dung:                            Rut tien |" << endl;
    cout << "  +-----------------------------------------------+" << endl;
    
  } else {
  	return;
  }
  }else{
    cout<<"  Ma pin sai! Con "<<sl<<" lan nhap ma!"<<endl;
    sl--;
    if(sl>=0) goto NhapPin;
    else{
      cout<<"  Da nhap sai qua 3 lan! Vui long thuc hien lai giao dich!"<<endl;
    }
  }
}

char* LIST::intToStr (char target[],unsigned long long num) {
	if (num < 100) {
		char source[256];
    	sprintf(source, "%llu", num);
		strcat (target, source);
		strcat (target, " VND");
		return target;
	}
    char source[256];
    sprintf(source, "%llu", num);
    int sizeLen = strlen(source);
    int idx = strlen(source)%3;
	if (idx == 0) {
		int i = 0;
    	int j = 0;
		for (; idx <= sizeLen; idx++) {
    		target[idx + j] = source[idx]; 
    		i++;
    		if (i%3 == 0 && i < sizeLen - strlen(source)%3) {
    			strcat (target, ".");
    			j++; 
			} 
    	
		}
	} else {
		strncat (target, source, idx);
		strcat (target, ".");
		int i = 0;
    	int j = 1;
    	for (; idx <= sizeLen; idx++) {
    		target[idx + j] = source[idx]; 
    		i++;
    		if (i%3 == 0 && i < sizeLen - strlen(source)%3) {
    			strcat (target, ".");
    			j++;
			} 
    	
		}
	}
    
	strcat (target, " VND");
    return target;
}

int LIST::ConfirmPin(char a[]){
    char pin[256];
    fflush(stdin);
    cout<<"  Vui long nhap ma pin de xac nhan giao dich: ";
    cin.getline(pin,256);
    if(strcmp(pin,a)==0) return 1;
    else return 0;
}

void LIST::doiMapin(CLIENT& a){
	system("cls");
  char mk[256];
  char pin[256];
  do
  {
  	cout << endl;
    cout<<"  Vui long nhap mat khau: ";
    fflush(stdin);
    cin.getline(mk,256);
    if(strcmp(mk, a.getMatKhau()) == 0) break;
    else{
      cout<<"  Mat khau khong chinh xac! Vui long nhap lai! "<<endl;
    }
  } while (1);

  do
  {
    cout<<"  Vui long nhap ma pin cu: ";
    fflush(stdin);
    cin.getline(pin,256);
    if(strcmp(pin,a.getMaPin())==0) break;
    else{
      cout<<"  Ma pin khong chinh xac! Vui long nhap lai!"<<endl;
    }
  } while (1);
  fflush(stdin);
  cout<<"  Tao ma pin moi: " << endl;
  a.setMaPin();
  if(confirmMessage()){ 
    cout<<"  Thay doi ma pin thanh cong!"<<endl;
    system("pause");
    this->saveLIST();
  }
  else{ 
    cout<<"  Thay doi ma pin khong thanh cong!"<<endl;
    system("pause");
  }
}


void LIST::thanhToan(CLIENT &a){
  int sl;
  while (1)
  {
     system("cls");
     this->xuatSodu(a);
    cout<<"  [1] Nap tien dien thoai."<<endl;
    cout<<"  [2] Thanh toan tien dien."<<endl;
    cout<<"  [3] Thanh toan tien nuoc"<<endl;
    cout<<"  [4] Thoat dich vu."<<endl;
    cout<<"  Nhap lua chon: "; cin>>sl;
    switch (sl)
    {
    case 1:{
      long long s;
      char sdt[20];
      cout<<"  Nhap so dien thoai nap: ";
      cin>>sdt;
      cout<<"  Chon nha mang: "<<endl;
      cout<<"  [1] Viettel\n  [2] MobiPhone\n  [3] Vinaphone"<<endl;
      cout<<"  Nhap lua chon:";
      cin>>s;
      cout<<"  Nhap menh gia muon nap(10.000d, 20.000d, 50.000d): ";
      cin>>s;
      int q=3;
      do{
          int check=ConfirmPin(a.getMaPin());
          if(!check){
            q--;
            cout<<"  Ma pin sai! Vui long nhap lai! Con "<<q<<" lan nhap!"<<endl;
            if(q==0){
              cout<<"  Da nhap sai qua 3 lan! Vui long thuc hien lai giao dich moi!"<<endl;
               return;
            }
          }
          else break;
      }while(1);
      if(confirmMessage()){
        if(a.getSoDuTaiKhoan()>=s) {
          cout<<"  Da nap thanh cong "<<s<<"d vao SDT: "<<sdt<<endl;
          a.setSoDuTaiKhoan(a.getSoDuTaiKhoan() - s);
          char x[256];
          dateTime d;
          d.setCurrentTime();
          
          char target[256]="";
          sprintf(x," TK:%d\n-%s\n%d/%d/%d %d:%d\nThanh toan DV\nNap tien dien thoai\nMa GD: %d%d\n",a.getMaSoThe(),this->intToStr(target, s),d.getDay(),d.getMon(),d.getYear(),d.getHour(),d.getMin(),4,taoMaGD());
          char path[256];
          sprintf(path,"./LSGD/%d-%s.txt",a.getID(),a.getHoTen());
          
          
          this->saveTransaction(x,path);
    	  this->saveLIST();
          
          cout << endl;
		char target4[256] = "";
		
	    cout << "  +--------- Thong bao bien dong so du: ----------+" << endl;
	    cout << "  | Tai khoan: " << setw(34) << right << a.getMaSoThe() << " |" << endl;
	    cout << "  | So tien giao dich: " << setw(26) << right << this->intToStr(target4, s) << " |" << endl;
	    cout << "  | Thoi gian: " << setw(20) << right << d.getDay() << "/" << d.getMon() << "/" << d.getYear() << " " << setw(2) << right << d.getHour() << ":" << setw(2) << right  << d.getMin() << " |" << endl;
	    cout << "  | Noi dung:                 Nap tien dien thoai |" << endl;
	    cout << "  +-----------------------------------------------+" << endl;
          
          system("pause");
        }
        else{
          cout<<"  So du khong du! Vui long nap them tien de thuc hien giao dich!"<<endl;
          return;
        }
      }
    }
    break;
    case 2:
    {
      int sl;
      long long tien;
      char makh[30];
      cout<<"  Chon khu vuc: "<<endl;
      cout<<"  [1] Ha Noi\n  [2] Da Nang\n  [3] Quang Nam\n  [4] Thua Thien Hue\n  [5] Quang Nam\n [6] TP Ho Chi Minh\n";
      cout <<"  Nhap lua chon: ";
      cin>>sl;
      cout<<"  Nhap ma khach hang (Vd: PC0234234323,..): "<<endl;
      cin>>makh;
      srand(time(NULL)); 
	    int res = rand() % ( 1000000 - 300000 + 1) + 300000;
	  char target[256]="";
      cout<<"  So tien dien cua khach hang "<<makh<<" trong thang 12: " << this->intToStr(target, res) << endl;
      cout<<"  Quy khach co muon thanh toan khong?:" << endl;
      cout<<"  [1] Co."<<endl;
      cout<<"  [2] Khong."<<endl;
      cout<<"  Nhap lua chon:";
      cin>>tien;
      if(tien==1){
      int q=3;
      do{
          int check=ConfirmPin(a.getMaPin());
          if(!check){
            q--;
            cout<<"  Ma pin sai! Vui long nhap lai! Con "<<q<<" lan nhap!"<<endl;
            if(q==0){
              cout<<"  Da nhap sai qua 3 lan! Vui long thuc hien lai giao dich moi!"<<endl;
               return;
            }
          }
          else break;
      }while(1);
      if(confirmMessage()){
        if(a.getSoDuTaiKhoan()>=res) {
        	char target[256] = "";
          cout<<"  Da thanh toan tien dien thanh cong so tien "<< this->intToStr(target, res) <<" VND cho khach hang: "<<makh<<endl;
          a.setSoDuTaiKhoan(a.getSoDuTaiKhoan() - res);
 
          char x[256];
          dateTime d;
          d.setCurrentTime();
          char target1[256] = "";
          sprintf(x," TK:%d\n-%s\n%d/%d/%d %d:%d\nThanh toan DV\nThanh toan tien dien\nMa GD: %d%d\n",a.getMaSoThe(),this->intToStr(target1, res),d.getDay(),d.getMon(),d.getYear(),d.getHour(),d.getMin(),5,taoMaGD());
          char path[256];
          sprintf(path,"./LSGD/%d-%s.txt",a.getID(),a.getHoTen());
          
          this->saveTransaction(x,path);
    	  this->saveLIST();
          
          cout << endl;
		char target3[256] = "";
	    cout << "  +--------- Thong bao bien dong so du: ----------+" << endl;
	    cout << "  | Tai khoan: " << setw(34) << right << a.getMaSoThe() << " |" << endl;
	    cout << "  | So tien giao dich: " << setw(26) << right << this->intToStr(target3, res) << " |" << endl;
	    cout << "  | Thoi gian: " << setw(20) << right << d.getDay() << "/" << d.getMon() << "/" << d.getYear() << " " << setw(2) << right << d.getHour() << ":" << setw(2) << right  << d.getMin() << " |" << endl;
	    cout << "  | Noi dung:                Thanh toan tien dien |" << endl;
	    cout << "  +-----------------------------------------------+" << endl;
          
          system("pause");
        }
        else{
          cout<<"  So du khong du! Vui long nap them tien de thuc hien giao dich!"<<endl;
          return;
        }
      }
    }
    }
    break;
    case 3:{
      int sl;
      long long tien;
      char makh[30];
      cout<<"  Chon khu vuc: "<<endl;
      cout<<"  [1] Ha Noi\n  [2] Da Nang\n  [3] Quang Nam\n  [4] Thua Thien Hue\n  [5] Quang Nam\n  [6] TP Ho Chi Minh\n";
      cout << "  Nhap lua chon: ";
      cin>>sl;
      cout<<"  Nhap ma khach hang (Vd: PC0234234323,..): "<<endl;
      cin>>makh;
      srand(time(NULL)); 
	    long long res = rand() % ( 500000 - 100000 + 1) + 100000;
	    char target[256] = "";
      cout<<"  So tien nuoc cua khach hang "<<makh<<" trong thang 12: " << this->intToStr(target, res) << endl;
      cout<<"  Quy khach co muon thanh toan khong?:" << endl;
      cout<<"  [1] Co"<<endl;
      cout<<"  [2] Khong"<<endl;
      cout<<"  Nhap lua chon:";
      cin>>tien;
      if(tien){
      int q=3;
      do{
          int check=ConfirmPin(a.getMaPin());
          if(!check){
            q--;
            cout<<"  Ma pin sai! Vui long nhap lai! Con "<<q<<" lan nhap!"<<endl;
            if(q==0){
              cout<<"  Da nhap sai qua 3 lan! Vui long thuc hien lai giao dich moi!"<<endl;
               return;
            }
          }
          else break;
      }while(1);
      if(confirmMessage()){
        if(a.getSoDuTaiKhoan()>=res) {
        	char target[256]= "";
          cout<<"  Da thanh toan tien nuoc thanh cong so tien "<< this->intToStr(target, res) <<" cho khach hang: "<<makh<<endl;
          a.setSoDuTaiKhoan(a.getSoDuTaiKhoan() - res);
          
          char x[256];
          dateTime d;
          d.setCurrentTime();
          char target1[256] = "";
          sprintf(x," TK:%d\n-%s\n%d/%d/%d %d:%d\nThanh toan DV\nThanh toan tien nuoc\nMa GD: %d%d\n",a.getMaSoThe(),this->intToStr(target1, res),d.getDay(),d.getMon(),d.getYear(),d.getHour(),d.getMin(),6,taoMaGD());
          char path[256];
          sprintf(path,"./LSGD/%d-%s.txt",a.getID(),a.getHoTen());
          
          this->saveTransaction(x,path);
          this->saveLIST();
          
          cout << endl;
		char target4[256] = "";
		
	    cout << "  +--------- Thong bao bien dong so du: ----------+" << endl;
	    cout << "  | Tai khoan: " << setw(34) << right << a.getMaSoThe() << " |" << endl;
	    cout << "  | So tien giao dich: " << setw(26) << right << this->intToStr(target4, res) << " |" << endl;
	    cout << "  | Thoi gian: " << setw(20) << right << d.getDay() << "/" << d.getMon() << "/" << d.getYear() << " " << setw(2) << right << d.getHour() << ":" << setw(2) << right  << d.getMin() << " |" << endl;
	    cout << "  | Noi dung:                Thanh toan tien nuoc |" << endl;
	    cout << "  +-----------------------------------------------+" << endl;
          
           system("pause");
        }
        else{
          cout<<"  So du khong du! Vui long nap them tien de thuc hien giao dich!"<<endl;
          return;
        }
      }
    }
    }
    break;
    case 4: return;
}}}

void LIST::chuyenkhoan(CLIENT& a){
  this->xuatSodu(a);
  char bank[256],nd[256];
  int stk = 0, s;
  
  long long tien;
  cout << "  Vui long chon hinh thuc chuyen tien:"<<endl;
  cout << "  [1] Chuyen noi bo."<<endl;
  cout << "  [2] Chuyen lien ngan hang."<<endl;
  cout << "  [0] Thoat giao dich."<<endl;
  cout << "  Nhap lua chon: ";
  cin >> s;
  switch (s)
  {
  case 1:
  {
    system("cls");
    int kh=0;
    do
    {
      CK:
      cout<<"  Nhap so tai khoan ma ban muon chuyen toi: "; 
      cin >> stk;
      
      for (int i = 0; i< list.getKeyCount(); i++)   {
      	
	  if (list[i].getDta() == 0)	continue;
        if (stk == list[i].getMaSoThe()){
          if(stk != a.getMaSoThe()){
          kh = i;
          cout<<"  Ten nguoi thu huong: "<<list[i].getHoTen()<<endl;
          do
        {
          cout<<"  Nhap so tien muon chuyen: "; cin >>tien;
          if(tien>a.getSoDuTaiKhoan()) {
          	char target[256]= "";
          	cout<<"  So du khong du de chuyen, vui long nhap so du nho hon " << this->intToStr(target, a.getSoDuTaiKhoan()); 
		    } 
        } while (tien>a.getSoDuTaiKhoan());

		    fflush (stdin);
        sprintf(nd,"%s chuyen tien",a.getHoTen() );
        int q=3;
        do{
          int check=ConfirmPin(a.getMaPin());
          if(!check){
            q--;
            cout<<"  Ma pin sai! Vui long nhap lai! Con "<<q<<" lan nhap!"<<endl;
            if(q==0){
              cout<<"  Da nhap sai qua 3 lan! Vui long thuc hien lai giao dich moi!"<<endl;
               return;
            }
          }
          else break;
         }while(1);

        if (confirmMessage()) {
        if(a.getSoDuTaiKhoan()-tien<=50000){
          cout<<"  Yeu cau so du duy tri tai khoan toi thieu 50.000 VND, quy khach vui long nap them tien vao tai khoan de thuc hien giao dich!"<<endl;
        }
        else{
        long long cu= a.getSoDuTaiKhoan();
        a.setSoDuTaiKhoan (a.getSoDuTaiKhoan() - tien);

		list[kh].setSoDuTaiKhoan(list[kh].getSoDuTaiKhoan() + tien);
        
        char target1[256] = "";
        cout << endl;
        cout<<"  Giao dich thanh cong! So du hien tai cua quy khach la: " << this->intToStr(target1, a.getSoDuTaiKhoan()) << endl;
        char x[256],y[256];
        dateTime d;
        d.setCurrentTime();

		char target2[256] = "";
        sprintf(x," TK:%d\n-%s\n%d/%d/%d %d:%d\nChuyen Khoan\n%s\nMa GD: %d%d\n",a.getMaSoThe(),this->intToStr(target2, tien),d.getDay(),d.getMon(),d.getYear(),d.getHour(),d.getMin(),nd,1,taoMaGD());
        char path1[256],path2[256];
        sprintf(path1,"./LSGD/%d-%s.txt",a.getID(),a.getHoTen());
        
        this->saveTransaction(x,path1);
    	

        
        char target3[256] = "";
        sprintf(y," TK:%d\n+%s\n%d/%d/%d %d:%d\nChuyen Khoan\n%s\nMa GD: %d\n",list[kh].getMaSoThe(),this->intToStr(target3, tien),d.getDay(),d.getMon(),d.getYear(),d.getHour(),d.getMin(),nd,taoMaGD());
        sprintf(path2,"./LSGD/%d-%s.txt",list[kh].getID(), list[kh].getHoTen());
        
        
        this->saveTransaction(y,path2);
        
        this->saveLIST();
        
        cout << endl;
		char target4[256] = "";
		
	    cout << "  +--------- Thong bao bien dong so du: ----------+" << endl;
	    cout << "  | Tai khoan: " << setw(34) << right << a.getMaSoThe() << " |" << endl;
	    cout << "  | So tien giao dich: " << setw(26) << right << this->intToStr(target4, tien) << " |" << endl;
	    cout << "  | Thoi gian: " << setw(20) << right << d.getDay() << "/" << d.getMon() << "/" << d.getYear() << " " << setw(2) << right << d.getHour() << ":" << setw(2) << right  << d.getMin() << " |" << endl;
	    cout << "  | Noi dung:                        Chuyen khoan |" << endl;
	    cout << "  +-----------------------------------------------+" << endl << endl;
        }
        }
        
        

    }
    else{ 
      cout<<"  Khong the chuyen cho chinh ban! Vui long nhap STK khac!"<<endl;
      goto CK;
    }
    }
    else 
      if(i == list.getKeyCount()){
      	cout<<"  Khong tim thay khach hang co so tai khoan: "<< stk << "\n" <<"  Vui long nhap lai!"<<endl;
      	stk = 0;
	  } 
}
    }while (stk == 0);
  }
break;
  
  case 2:
  {
    fflush(stdin);
     system("cls");
    cout<<"  Chon ngan hang ban muon chuyen den:"<<endl;
    int choose=0;
    struct bank
    {
      char name[256];
    };
    bank listbank[8]={"","Agribank","Mb Bank","Tien Phong","VP Bank","ACB","Nam A Bank","Sacombank"};
      cout<<"  [1] Ngan hang AgriBank"<<endl;
      cout<<"  [2] Ngan hang Mb bank"<<endl;
      cout<<"  [3] Ngan hang Tien Phong"<<endl;
      cout<<"  [4] Ngan hang VP Bank"<<endl;
      cout<<"  [5] Ngan hang ACB"<<endl;
      cout<<"  [6] Ngan hang Nam A Bank"<<endl;
      cout<<"  [7] Ngan hang SacomBank"<<endl;
      cout<<"  [0] Khong co ngan hang ban ban tim"<<endl;
      cout<<"  Nhap lua chon cua ban: ";
      cin>>choose;
    
    if(choose==0){
      cout<<"  Nhap ngan hang chuyen den: "<<endl;
      cin.getline(listbank[0].name,256);
    } 
    fflush(stdin);
    cout<<"  Nhap so tai khoan ma ban muon chuyen toi: "; 
    cin >> stk;
    do
    {
      cout<<"  Nhap so tien muon chuyen: "; cin >>tien;
      if(tien>a.getSoDuTaiKhoan()) cout<<"  So du khong du de chuyen, vui long nhap so du nho hon "<<a.getSoDuTaiKhoan()<<endl;
    } while (tien>a.getSoDuTaiKhoan());
    fflush(stdin);
//    cout<<"  Nhap noi dung chuyen khoan: "; cin.getline(nd,256);
//    if(strcmp(nd,"")==0)sprintf(nd," %s chuyen tien",a.hoTen );
    int q=3;
        do{
          int check=ConfirmPin(a.getMaPin());
          if(!check){
            q--;
            cout<<"  Ma pin sai! Vui long nhap lai! Con "<<q<<" lan nhap!"<<endl;
            if(q==0){
              cout<<"  Da nhap sai qua 3 lan! Vui long thuc hien lai giao dich moi!"<<endl;
               return;
            }
          }
          else break;
         }while(1);
    if (confirmMessage()) {
      if(a.getSoDuTaiKhoan()<=50000){
        cout<<"  So du quy khach nho hon 50K, vui long nap them tien vao tai khoan de thuc hien giao dich!"<<endl;
      }
      else{
      	a.setSoDuTaiKhoan(a.getSoDuTaiKhoan() - tien - 0.02*tien);
    
      system("cls");
      char target[256]="";
      cout<<"  Giao dich thanh cong!" << endl;
      cout<<"  (Da tru 2% phi giao dich)"<<endl;
      char x[256];
      dateTime d;
      d.setCurrentTime();
      char target1[256]="";
      sprintf(x," TK:%d\n-%s\n%d/%d/%d %d:%d\nChuyen khoan\nChuyen khoan den STK: %d thuoc ngan hang %s\nMa GD: %d%d\n",a.getMaSoThe(),this->intToStr(target1, tien),d.getDay(),d.getMon(),d.getYear(),d.getHour(),d.getMin(),stk,listbank[choose].name,1,taoMaGD());
      char path[256];
      sprintf(path,"./LSGD/%d-%s.txt",a.getID(),a.getHoTen());
      
      this->saveTransaction(x,path);
      this->saveLIST();
      
      cout << endl;
	char target3[256] = "";
    cout << "  +--------- Thong bao bien dong so du: ----------+" << endl;
    cout << "  | Tai khoan: " << setw(34) << right << a.getMaSoThe() << " |" << endl;
    cout << "  | So tien giao dich: " << setw(26) << right << this->intToStr(target3, tien + 0.02*tien) << " |" << endl;
    cout << "  | Thoi gian: " << setw(20) << right << d.getDay() << "/" << d.getMon() << "/" << d.getYear() << " " << setw(2) << right << d.getHour() << ":" << setw(2) << right  << d.getMin() << " |" << endl;
    cout << "  | Noi dung:                        Chuyen khoan |" << endl;
    cout << "  +-----------------------------------------------+" << endl << endl;
      
      }
    } 
    break;
  }
    case 0: return;
  }
}

void LIST:: quenMatKhau () {
	fflush (stdin);
	cout << "  Nhap ten dang nhap: ";
	char _tenDangNhap[256];
	cin.getline(_tenDangNhap, 256);
	
	
	CLIENT* p = new CLIENT;
	
	int i = this->list.find(p->strToInt(_tenDangNhap));
	if (i == -1) {
		cout << "  Ten dang nhap khong ton tai!" << endl << endl;
		system ("pause");
		return;
	} 
	
	cout << "  Quy khach vui long xac nhan mot so thong tin can thiet" << endl;
	cout << "  Nhap so dien thoai dang ky: ";
	char _sdt[256];
	cin.getline(_sdt, 256);
	cout << "  Nhap ho ten: ";
	char _hoTen[256];
	cin.getline(_hoTen, 256);
	cout << "  Nhap so can cuoc cong dan da dang ky: ";
	char _cccd[256];
	cin.getline(_cccd, 256);
		
    if (strcmp (_sdt, list[i].getSdt()) == 0 && strcmp (_hoTen, list[i].getHoTen()) == 0 && strcmp (_cccd, list[i].getCccd())==0) {
		
			char _matKhau[256];
			cout << "\n  Nhap mat khau moi: " << endl;
			list[i].setMatKhau();
			
        	this->saveLIST();
        	cout << "  Thay doi mat khau thanh cong!" << endl;
        	system("pause");
	} else{
    	cout<<"  Thong tin quy khach vua nhap khong khop voi thong tin da dang ky tren TV Bank! Vui long thuc hien lai!"<<endl;
    	system("pause");
    }
}

//===================END_LIST_H============================================================


void menu_main(LIST &list){
	int s=1;
    
    do
    {
    	system("cls");
    	cout <<"******************************************************************" << endl;
    	cout <<"*                                                                *" << endl;
    	cout <<"*           Welcome to T.V Bank- Bank of VietNam                 *" << endl;
    	cout <<"*                                                                *" << endl;
    	cout <<"******************************************************************" << endl;
    	cout << "\n";
        cout<<"  [1] Dang Nhap"<<endl;
        cout<<"  [2] Dang ki tai khoan"<<endl;
        cout<<"  [3] Lien he dich vu CSKH"<<endl;
        cout<<"  [0] Thoat ngan hang"<<endl;
        cout<<"\n  Nhap lua chon cua ban: "; cin>>s;
        
        switch (s)
        {
        case 1:
        	{
        	Dangnhap:
            cout<<endl;
            int vt = list.log_in();
            int o;
            if (vt != -1) {
        		do
        		{
        		system("cls");
        	
	        	cout <<"******************************************************************" << endl;
	    		cout <<"*                                                                *" << endl;
	        	cout <<"*                   Welcome" << " " << setw(35) << left << list[vt].getHoTen() << "  *" << endl;
	    		cout <<"*                                                                *" << endl;
	    		cout <<"******************************************************************" << endl;
	            cout<<"\n  [1] Thong tin tai khoan."<<endl;;
	            cout<<"  [2] So du tai khoan."<<endl;
	            cout<<"  [3] Chuyen khoan"<<endl;
	            cout<<"  [4] Nap tien."<<endl;
	            cout<<"  [5] Rut tien."<<endl;
	            cout<<"  [6] Doi ma pin."<<endl;
				cout<<"  [7] Thanh toan tien dien,nuoc, dien thoai,..."<<endl;
	            cout<<"  [8] Lich su giao dich."<<endl;
	            cout<<"  [0] Dang Xuat" << endl;
	            cout << "\n  Nhap lua chon: ";
				cin >> o; 
	            switch (o)
	            {
	                case 1: 
	                system("cls");
					list.xuatTT(list[vt]);
					system("pause");
	                break;
	                case 2:
	                system("cls");
					list.xuatSodu(list[vt]);
					system("pause");
	                break;
	                case 3:
	                system("cls");
					list.chuyenkhoan(list[vt]);
					system("pause");
	                break;
	                case 4:
	                system("cls");
					list.napTien(list[vt]);
					system("pause");
	                break;
	                case 5: 
	                system("cls");
					list.rutTien(list[vt]);
					system("pause");
	                break;
	                case 6: list.doiMapin(list[vt]);
	                break;
					case 7: list.thanhToan(list[vt]);
					break;
	                case 8: 
						list.exportTransaction(list[vt]);
	                    system("pause");
	                	break;
	                default: o = 0;
	          }
	        } while(o);
			} else {
                int sl=0;
				cout<<"\n\n  Tai khoan va mat khau chua chinh xac! Vui long nhap lai!"<<endl;
                do{
                    cout<<"  [1] Quen mat khau"<<endl<<"  [2] Dang nhap lai"<<endl<<"  [0] Thoat"<<endl;
                    cout<<"  Nhap lua chon cua ban: "; cin>>sl;
                    if(sl==1){
                         list.quenMatKhau();
                         break;
                    }
                    if(sl==2){
                        goto Dangnhap;
                        break;
                    } 
                }while(sl!=0);
			}
            
            break;
			}
        case 2:
        	{
        	system("cls");
            list.signUp();
            break;
			}
        case 3:
            // CSKH
            break;
    }
    } while (s);
} 



int main() {
	LIST ds;

//	ds.signUp();
//	ds.log_in();




	menu_main(ds);
	return 0;
}


//#endif
