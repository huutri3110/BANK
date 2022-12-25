#ifndef LIST_H
#define LIST_H

#include "CLIENT.h"		//#include <iostream>
						//#include <fstream>
						//#include <cstring>
						//#include <conio.h>
						//#include <iomanip>
						//#include "dateTime.h"				
						//#include "Hash_Table.h"


using namespace std;
//===========================LIST_H==============================================================

class LIST
{
private:
	hashTable<CLIENT> list;
	int number;
	int id;
	int maGD;

public:
	LIST(); // Lay du lieu tu file
	~LIST()
	{
		//			delete[] list;
	}

	void signUp();						 // DangKi
	int log_in();							 // Dang Nhap
	int check(char *, char *); // Check gi day
	void xuatTT(CLIENT &p);		 // Xuat Thong Tin
	void xuatSodu(CLIENT &a);	 // Xuat so du
	void napTien(CLIENT &a);	 // Naptien
	void rutTien(CLIENT &a);
	int taoMaGD();														 //
	void saveTransaction(char *x, char *path); // Luu LSGD
	void exportTransaction(CLIENT &a);				 // Xuat thong tin LSGD
	void saveLIST();
	static bool confirmMessage(); //
	char *intToStr(char target[], unsigned long long num);
	int ConfirmPin(char a[]);
	void doiMapin(CLIENT &a);
	void thanhToan(CLIENT &a);
	void chuyenkhoan(CLIENT &a);
	void quenMatKhau();

	void setID();									 // Luu ID vao file
	void getID();									 // Lay ID tu file
	CLIENT &operator[](int index); // Dinh nghia lai toan tu []
};

LIST::LIST()
{
	getID();

	list.init(number);

	int i = 0;
	fstream f("text1.txt", ios::binary | ios::in);
	if (!f)
		cout << "error occured when open file to read!";
	while (i < number)
	{
		CLIENT *client = new CLIENT;
		f.read(reinterpret_cast<char *>(client), sizeof(*client));
		i++;
		list.insert(client->getDta(), *client);

		if (f.eof())
			break;
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

void LIST::saveLIST()
{
	fstream ofs("text1.txt", ios::out | ios::trunc);
	ofs.close();
	for (int i = 0; i < this->list.getKeyCount(); i++)
	{
		if (list[i].getDta() != 0)
		{
			list[i].saveCLIENT();
		}
	}
}

CLIENT &LIST::operator[](int index)
{
	return list[index];
	//	return list.find(index);
}

void LIST::signUp()
{

	number++;
	id++;
	this->setID();

	CLIENT *p = new CLIENT;
	p->setHoTen();
	p->setDiaChi();
	p->setSdt();
	p->setCccd();
	p->setNgaySinh();
	int check;
	do
	{
		check = 0;
		p->setTaiKhoan();
		for (int i = 0; i < list.getKeyCount(); i++)
		{
			if (list[i].getDta() != 0)
			{
				if (strcmp(p->getTaiKhoan(), list[i].getTaiKhoan()) == 0)
				{
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

void LIST::saveTransaction(char *x, char *path)
{
	fstream f;
	f.open(path, ios::out | ios::app);
	f << x;
	f.close();
}

void LIST::getID()
{
	fstream f("id.txt", ios::in);
	if (!f)
		cout << "error occured when open file to read!";
	f >> id;
	f >> number;
	f >> maGD;
	f.close();
}
void LIST::setID()
{
	fstream f("id.txt", ios::out | ios::trunc);
	if (!f)
		cout << "error occured when open file to write!";
	f << id << ' ';
	f << number << ' ';
	f << maGD;
	f.close();
}

int LIST::log_in()
{
	char tendn[256];
	char mk[256];
	fflush(stdin);
	system("cls");
	cout << "\n  Ten Dang Nhap: ";
	cin.getline(tendn, 256);

	int i = 0;
	char ch;
	cout << "  Mat khau: ";
	ch = _getch();
	while (ch != 13)
	{
		mk[i] = ch;
		i++;
		cout << '*';
		ch = _getch();
	}
	int temp = check(tendn, mk);
	if (temp == -1)
	{
		cout << "  \nTen dang nhap hoac mat khau khong dung!" << endl;
		return temp;
	}
	else
	{
		return temp;
	}
}

int LIST::check(char *tendn, char *mk)
{
	CLIENT *p = new CLIENT;

	int i = this->list.find(p->strToInt(tendn));
	//	cout << "-------------" << endl;
	//	cout << p->strToInt(tendn) << endl;
	//	cout << i << endl;
	//	system("pause");
	if (i == -1)
		return -1;

	//	cout << list[i].getTaiKhoan() << " " <<  list[i].getMatKhau()  << endl;
	//	system("pause");

	if (strcmp(list[i].getTaiKhoan(), tendn) == 0 && strcmp(list[i].getMatKhau(), mk) == 0)
	{
		return i;
	}
	else
	{
		return -1;
	}
}

void LIST::xuatTT(CLIENT &p)
{
	cout << endl;
	cout << "                   THONG TIN TAI KHOAN                  " << endl;
	cout << "  +------------------------------------------------------+" << endl;
	cout << "  |  So tai khoan: " << setw(36) << right << p.getMaSoThe() << "  |" << endl;
	cout << "  |  Ten dang nhap: " << setw(35) << right << p.getTaiKhoan() << "  |" << endl;
	cout << "  |  Ho va ten: " << setw(39) << right << p.getHoTen() << "  |" << endl;
	cout << "  |  So dien thoai: " << setw(35) << right << p.getSdt() << "  |" << endl;
	cout << "  |  So can cuoc cong dan: " << setw(28) << right << p.getCccd() << "  |" << endl;
	cout << "  |  Dia chi: " << setw(41) << right << p.getDiaChi() << "  |" << endl;
	cout << "  |  Ngay sinh: " << setw(31) << right << p.getNgaySinh() << "-" << setw(2) << right << p.getThangSinh() << "-" << setw(2) << right << p.getNamSinh() << "  |" << endl;
	cout << "  +------------------------------------------------------+" << endl
			 << endl;
}

void LIST::xuatSodu(CLIENT &a)
{
	cout << endl;
	cout << "  \t\t\tSO DU TAI KHOAN" << endl;
	char target[256] = "";
	cout << "  +-------------------------------------------------------------------------+" << endl;
	cout << "  | SO TAI KHOAN   | TEN TAI KHOAN              | SO DU HIEN TAI            |" << endl;
	cout << "  |-------------------------------------------------------------------------|" << endl;
	cout << "  | " << setw(14) << left << a.getMaSoThe() << " | " << setw(26) << left << a.getHoTen() << " | " << setw(24) << this->intToStr(target, a.getSoDuTaiKhoan()) << "  |" << endl;
	cout << "  +-------------------------------------------------------------------------+" << endl
			 << endl;
}

void LIST::napTien(CLIENT &a)
{
	xuatSodu(a);
	unsigned long long soTien;
	cout << "  Nhap so tien muon nap: ";
	cin >> soTien;
	if (LIST::confirmMessage())
	{
		a.setSoDuTaiKhoan(a.getSoDuTaiKhoan() + soTien);
		char target1[256] = "";
		cout << "\n  Ban da nap thanh cong! So du hien tai la: " << this->intToStr(target1, a.getSoDuTaiKhoan()) << endl;

		char x[256];
		dateTime d;
		d.setCurrentTime();
		char target[256] = "";
		sprintf(x, " TK:%d\n+%s\n%d/%d/%d %d:%d\nNap Tien\nNap tien vao tai khoan\nMa GD: %d%d\n", a.getMaSoThe(), this->intToStr(target, soTien), d.getDay(), d.getMon(), d.getYear(), d.getHour(), d.getMin(), 2, LIST::taoMaGD());
		char path[256];
		sprintf(path, "./LSGD/%d-%s.txt", a.getID(), a.getHoTen());

		this->saveTransaction(x, path);

		this->saveLIST();

		cout << endl;
		char target3[256] = "";
		cout << "  +--------- Thong bao bien dong so du: ----------+" << endl;
		cout << "  | Tai khoan: " << setw(34) << right << a.getMaSoThe() << " |" << endl;
		cout << "  | So tien giao dich: " << setw(26) << right << this->intToStr(target3, soTien) << " |" << endl;
		cout << "  | Thoi gian: " << setw(20) << right << d.getDay() << "/" << d.getMon() << "/" << d.getYear() << " " << setw(2) << right << d.getHour() << ":" << setw(2) << right << d.getMin() << " |" << endl;
		cout << "  | Noi dung:              Nap tien vao tai khoan |" << endl;
		cout << "  +-----------------------------------------------+" << endl;
	}
	else
	{
		return;
	}
}

int LIST::taoMaGD()
{
	maGD++;
	this->setID();
	return 100000000 + maGD;
}

bool LIST::confirmMessage()
{

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

	if (select == 1)
		return 1;
	else
		return 0;
}

void LIST::exportTransaction(CLIENT &a)
{

	fstream f;
	char path[256];
	sprintf(path, "./LSGD/%d-%s.txt", a.getID(), a.getHoTen());
	f.open(path, ios::in);

	if (!(f.peek() == std::ifstream::traits_type::eof()))
	{
		string temp;
		system("cls");
		cout << "\n\t\t\t\t\t\t\t\t\t\t\tLICH SU GIAO DICH" << endl
				 << endl;
		cout << "  +----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "  | So Tai Khoan     | Bien Dong So Du     | Thoi Gian Giao Dich       | Hinh Thuc        | Noi Dung                                                                       | Ma Giao Dich              |" << endl;
		cout << "  +----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << endl;

		int i = 0;
		while (!f.eof())
		{
			cout << "  +------------------+---------------------+---------------------------+------------------+--------------------------------------------------------------------------------+---------------------------+" << endl;
			getline(f, temp, '\n');
			if (temp.length() != 0)
			{
				cout << "  |" << setw(18) << left << temp << "| ";
			}

			getline(f, temp, '\n');
			if (temp.length() != 0)
			{
				cout << setw(20) << temp << "| ";
			}

			getline(f, temp, '\n');
			if (temp.length() != 0)
			{
				cout << setw(26) << left << temp << "| ";
			}

			getline(f, temp, '\n');
			if (temp.length() != 0)
			{
				cout << setw(17) << left << temp << "| ";
			}

			getline(f, temp, '\n');
			if (temp.length() != 0)
			{
				cout << setw(79) << left << temp << "| ";
			}

			getline(f, temp, '\n');
			if (temp.length() != 0)
			{
				cout << setw(26) << left << temp << "| ";
			}

			cout << endl;
		}
	}
	else
	{
		cout << "  Chua co lich su giao dich!" << endl;
	}
	f.close();
}

void LIST::rutTien(CLIENT &a)
{

	this->xuatSodu(a);
	int sl = 3;
	unsigned long long tien;
	do
	{
		cout << "  Nhap so tien muon rut: ";
		cin >> tien;
		if (tien > a.getSoDuTaiKhoan())
		{
			char target[256] = "";
			cout << "  So du khong du de rut, vui long nhap so du nho hon " << this->intToStr(target, a.getSoDuTaiKhoan());
		}
	} while (tien > a.getSoDuTaiKhoan());
NhapPin:
	fflush(stdin);
	if (ConfirmPin(a.getMaPin()) == 1)
	{
		if (confirmMessage())
		{
			a.setSoDuTaiKhoan(a.getSoDuTaiKhoan() - tien);
			char target[256] = "";
			cout << "\n  Ban da rut thanh cong! So du hien tai la: " << this->intToStr(target, a.getSoDuTaiKhoan());
			cout << "\n  ";

			char x[256];
			dateTime d;
			d.setCurrentTime();
			char target1[256] = "";
			sprintf(x, " TK:%d\n-%s\n%d/%d/%d %d:%d\nRut Tien\nRut tien tu tai khoan %d\nMa GD: %d%d\n", a.getMaSoThe(), this->intToStr(target1, tien), d.getDay(), d.getMon(), d.getYear(), d.getHour(), d.getMin(), a.getMaSoThe(), 3, taoMaGD());
			char path[256];
			sprintf(path, "./LSGD/%d-%s.txt", a.getID(), a.getHoTen());

			this->saveTransaction(x, path);
			this->saveLIST();

			cout << endl;
			char target3[256] = "";
			cout << "  +--------- Thong bao bien dong so du: ----------+" << endl;
			cout << "  | Tai khoan: " << setw(34) << right << a.getMaSoThe() << " |" << endl;
			cout << "  | So tien giao dich: " << setw(26) << right << this->intToStr(target3, tien) << " |" << endl;
			cout << "  | Thoi gian: " << setw(20) << right << d.getDay() << "/" << d.getMon() << "/" << d.getYear() << " " << setw(2) << right << d.getHour() << ":" << setw(2) << right << d.getMin() << " |" << endl;
			cout << "  | Noi dung:                            Rut tien |" << endl;
			cout << "  +-----------------------------------------------+" << endl;
		}
		else
		{
			return;
		}
	}
	else
	{
		cout << "  Ma pin sai! Con " << sl << " lan nhap ma!" << endl;
		sl--;
		if (sl >= 0)
			goto NhapPin;
		else
		{
			cout << "  Da nhap sai qua 3 lan! Vui long thuc hien lai giao dich!" << endl;
		}
	}
}

char *LIST::intToStr(char target[], unsigned long long num)
{
	if (num < 100)
	{
		char source[256];
		sprintf(source, "%llu", num);
		strcat(target, source);
		strcat(target, " VND");
		return target;
	}
	char source[256];
	sprintf(source, "%llu", num);
	int sizeLen = strlen(source);
	int idx = strlen(source) % 3;
	if (idx == 0)
	{
		int i = 0;
		int j = 0;
		for (; idx <= sizeLen; idx++)
		{
			target[idx + j] = source[idx];
			i++;
			if (i % 3 == 0 && i < sizeLen - strlen(source) % 3)
			{
				strcat(target, ".");
				j++;
			}
		}
	}
	else
	{
		strncat(target, source, idx);
		strcat(target, ".");
		int i = 0;
		int j = 1;
		for (; idx <= sizeLen; idx++)
		{
			target[idx + j] = source[idx];
			i++;
			if (i % 3 == 0 && i < sizeLen - strlen(source) % 3)
			{
				strcat(target, ".");
				j++;
			}
		}
	}

	strcat(target, " VND");
	return target;
}

int LIST::ConfirmPin(char a[])
{
	char pin[256];
	fflush(stdin);
	cout << "  Vui long nhap ma pin de xac nhan giao dich: ";
	cin.getline(pin, 256);
	if (strcmp(pin, a) == 0)
		return 1;
	else
		return 0;
}

void LIST::doiMapin(CLIENT &a)
{
	system("cls");
	char mk[256];
	char pin[256];
	do
	{
		cout << endl;
		cout << "  Vui long nhap mat khau: ";
		fflush(stdin);
		cin.getline(mk, 256);
		if (strcmp(mk, a.getMatKhau()) == 0)
			break;
		else
		{
			cout << "  Mat khau khong chinh xac! Vui long nhap lai! " << endl;
		}
	} while (1);

	do
	{
		cout << "  Vui long nhap ma pin cu: ";
		fflush(stdin);
		cin.getline(pin, 256);
		if (strcmp(pin, a.getMaPin()) == 0)
			break;
		else
		{
			cout << "  Ma pin khong chinh xac! Vui long nhap lai!" << endl;
		}
	} while (1);
	fflush(stdin);
	cout << "  Tao ma pin moi: " << endl;
	a.setMaPin();
	if (confirmMessage())
	{
		cout << "  Thay doi ma pin thanh cong!" << endl;
		system("pause");
		this->saveLIST();
	}
	else
	{
		cout << "  Thay doi ma pin khong thanh cong!" << endl;
		system("pause");
	}
}

void LIST::thanhToan(CLIENT &a)
{
	int sl;
	while (1)
	{
		system("cls");
		this->xuatSodu(a);
		cout << "  [1] Nap tien dien thoai." << endl;
		cout << "  [2] Thanh toan tien dien." << endl;
		cout << "  [3] Thanh toan tien nuoc" << endl;
		cout << "  [4] Thoat dich vu." << endl;
		cout << "  Nhap lua chon: ";
		cin >> sl;
		switch (sl)
		{
		case 1:
		{
			long long s;
			char sdt[20];
			cout << "  Nhap so dien thoai nap: ";
			cin >> sdt;
			cout << "  Chon nha mang: " << endl;
			cout << "  [1] Viettel\n  [2] MobiPhone\n  [3] Vinaphone" << endl;
			cout << "  Nhap lua chon:";
			cin >> s;
			cout << "  Nhap menh gia muon nap(10.000d, 20.000d, 50.000d): ";
			cin >> s;
			int q = 3;
			do
			{
				int check = ConfirmPin(a.getMaPin());
				if (!check)
				{
					q--;
					cout << "  Ma pin sai! Vui long nhap lai! Con " << q << " lan nhap!" << endl;
					if (q == 0)
					{
						cout << "  Da nhap sai qua 3 lan! Vui long thuc hien lai giao dich moi!" << endl;
						return;
					}
				}
				else
					break;
			} while (1);
			if (confirmMessage())
			{
				if (a.getSoDuTaiKhoan() >= s)
				{
					cout << "  Da nap thanh cong " << s << "d vao SDT: " << sdt << endl;
					a.setSoDuTaiKhoan(a.getSoDuTaiKhoan() - s);
					char x[256];
					dateTime d;
					d.setCurrentTime();

					char target[256] = "";
					sprintf(x, " TK:%d\n-%s\n%d/%d/%d %d:%d\nThanh toan DV\nNap tien dien thoai\nMa GD: %d%d\n", a.getMaSoThe(), this->intToStr(target, s), d.getDay(), d.getMon(), d.getYear(), d.getHour(), d.getMin(), 4, taoMaGD());
					char path[256];
					sprintf(path, "./LSGD/%d-%s.txt", a.getID(), a.getHoTen());

					this->saveTransaction(x, path);
					this->saveLIST();

					cout << endl;
					char target4[256] = "";

					cout << "  +--------- Thong bao bien dong so du: ----------+" << endl;
					cout << "  | Tai khoan: " << setw(34) << right << a.getMaSoThe() << " |" << endl;
					cout << "  | So tien giao dich: " << setw(26) << right << this->intToStr(target4, s) << " |" << endl;
					cout << "  | Thoi gian: " << setw(20) << right << d.getDay() << "/" << d.getMon() << "/" << d.getYear() << " " << setw(2) << right << d.getHour() << ":" << setw(2) << right << d.getMin() << " |" << endl;
					cout << "  | Noi dung:                 Nap tien dien thoai |" << endl;
					cout << "  +-----------------------------------------------+" << endl;

					system("pause");
				}
				else
				{
					cout << "  So du khong du! Vui long nap them tien de thuc hien giao dich!" << endl;
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
			cout << "  Chon khu vuc: " << endl;
			cout << "  [1] Ha Noi\n  [2] Da Nang\n  [3] Quang Nam\n  [4] Thua Thien Hue\n  [5] Quang Nam\n [6] TP Ho Chi Minh\n";
			cout << "  Nhap lua chon: ";
			cin >> sl;
			cout << "  Nhap ma khach hang (Vd: PC0234234323,..): " << endl;
			cin >> makh;
			srand(time(NULL));
			int res = rand() % (1000000 - 300000 + 1) + 300000;
			char target[256] = "";
			cout << "  So tien dien cua khach hang " << makh << " trong thang 12: " << this->intToStr(target, res) << endl;
			cout << "  Quy khach co muon thanh toan khong?:" << endl;
			cout << "  [1] Co." << endl;
			cout << "  [2] Khong." << endl;
			cout << "  Nhap lua chon:";
			cin >> tien;
			if (tien == 1)
			{
				int q = 3;
				do
				{
					int check = ConfirmPin(a.getMaPin());
					if (!check)
					{
						q--;
						cout << "  Ma pin sai! Vui long nhap lai! Con " << q << " lan nhap!" << endl;
						if (q == 0)
						{
							cout << "  Da nhap sai qua 3 lan! Vui long thuc hien lai giao dich moi!" << endl;
							return;
						}
					}
					else
						break;
				} while (1);
				if (confirmMessage())
				{
					if (a.getSoDuTaiKhoan() >= res)
					{
						char target[256] = "";
						cout << "  Da thanh toan tien dien thanh cong so tien " << this->intToStr(target, res) << " VND cho khach hang: " << makh << endl;
						a.setSoDuTaiKhoan(a.getSoDuTaiKhoan() - res);

						char x[256];
						dateTime d;
						d.setCurrentTime();
						char target1[256] = "";
						sprintf(x, " TK:%d\n-%s\n%d/%d/%d %d:%d\nThanh toan DV\nThanh toan tien dien\nMa GD: %d%d\n", a.getMaSoThe(), this->intToStr(target1, res), d.getDay(), d.getMon(), d.getYear(), d.getHour(), d.getMin(), 5, taoMaGD());
						char path[256];
						sprintf(path, "./LSGD/%d-%s.txt", a.getID(), a.getHoTen());

						this->saveTransaction(x, path);
						this->saveLIST();

						cout << endl;
						char target3[256] = "";
						cout << "  +--------- Thong bao bien dong so du: ----------+" << endl;
						cout << "  | Tai khoan: " << setw(34) << right << a.getMaSoThe() << " |" << endl;
						cout << "  | So tien giao dich: " << setw(26) << right << this->intToStr(target3, res) << " |" << endl;
						cout << "  | Thoi gian: " << setw(20) << right << d.getDay() << "/" << d.getMon() << "/" << d.getYear() << " " << setw(2) << right << d.getHour() << ":" << setw(2) << right << d.getMin() << " |" << endl;
						cout << "  | Noi dung:                Thanh toan tien dien |" << endl;
						cout << "  +-----------------------------------------------+" << endl;

						system("pause");
					}
					else
					{
						cout << "  So du khong du! Vui long nap them tien de thuc hien giao dich!" << endl;
						return;
					}
				}
			}
		}
		break;
		case 3:
		{
			int sl;
			long long tien;
			char makh[30];
			cout << "  Chon khu vuc: " << endl;
			cout << "  [1] Ha Noi\n  [2] Da Nang\n  [3] Quang Nam\n  [4] Thua Thien Hue\n  [5] Quang Nam\n  [6] TP Ho Chi Minh\n";
			cout << "  Nhap lua chon: ";
			cin >> sl;
			cout << "  Nhap ma khach hang (Vd: PC0234234323,..): " << endl;
			cin >> makh;
			srand(time(NULL));
			long long res = rand() % (500000 - 100000 + 1) + 100000;
			char target[256] = "";
			cout << "  So tien nuoc cua khach hang " << makh << " trong thang 12: " << this->intToStr(target, res) << endl;
			cout << "  Quy khach co muon thanh toan khong?:" << endl;
			cout << "  [1] Co" << endl;
			cout << "  [2] Khong" << endl;
			cout << "  Nhap lua chon:";
			cin >> tien;
			if (tien)
			{
				int q = 3;
				do
				{
					int check = ConfirmPin(a.getMaPin());
					if (!check)
					{
						q--;
						cout << "  Ma pin sai! Vui long nhap lai! Con " << q << " lan nhap!" << endl;
						if (q == 0)
						{
							cout << "  Da nhap sai qua 3 lan! Vui long thuc hien lai giao dich moi!" << endl;
							return;
						}
					}
					else
						break;
				} while (1);
				if (confirmMessage())
				{
					if (a.getSoDuTaiKhoan() >= res)
					{
						char target[256] = "";
						cout << "  Da thanh toan tien nuoc thanh cong so tien " << this->intToStr(target, res) << " cho khach hang: " << makh << endl;
						a.setSoDuTaiKhoan(a.getSoDuTaiKhoan() - res);

						char x[256];
						dateTime d;
						d.setCurrentTime();
						char target1[256] = "";
						sprintf(x, " TK:%d\n-%s\n%d/%d/%d %d:%d\nThanh toan DV\nThanh toan tien nuoc\nMa GD: %d%d\n", a.getMaSoThe(), this->intToStr(target1, res), d.getDay(), d.getMon(), d.getYear(), d.getHour(), d.getMin(), 6, taoMaGD());
						char path[256];
						sprintf(path, "./LSGD/%d-%s.txt", a.getID(), a.getHoTen());

						this->saveTransaction(x, path);
						this->saveLIST();

						cout << endl;
						char target4[256] = "";

						cout << "  +--------- Thong bao bien dong so du: ----------+" << endl;
						cout << "  | Tai khoan: " << setw(34) << right << a.getMaSoThe() << " |" << endl;
						cout << "  | So tien giao dich: " << setw(26) << right << this->intToStr(target4, res) << " |" << endl;
						cout << "  | Thoi gian: " << setw(20) << right << d.getDay() << "/" << d.getMon() << "/" << d.getYear() << " " << setw(2) << right << d.getHour() << ":" << setw(2) << right << d.getMin() << " |" << endl;
						cout << "  | Noi dung:                Thanh toan tien nuoc |" << endl;
						cout << "  +-----------------------------------------------+" << endl;

						system("pause");
					}
					else
					{
						cout << "  So du khong du! Vui long nap them tien de thuc hien giao dich!" << endl;
						return;
					}
				}
			}
		}
		break;
		case 4:
			return;
		}
	}
}

void LIST::chuyenkhoan(CLIENT &a)
{
	this->xuatSodu(a);
	char bank[256], nd[256];
	int stk = 0, s;

	long long tien;
	cout << "  Vui long chon hinh thuc chuyen tien:" << endl;
	cout << "  [1] Chuyen noi bo." << endl;
	cout << "  [2] Chuyen lien ngan hang." << endl;
	cout << "  [0] Thoat giao dich." << endl;
	cout << "  Nhap lua chon: ";
	cin >> s;
	switch (s)
	{
	case 1:
	{
		
		int kh = 0;
		int i;
		do
		{
			system("cls");
			cout << "  Nhap so tai khoan ma ban muon chuyen toi: ";
			cin >> stk;

			for (i = 0; i < list.getKeyCount(); i++)
			{

				if (list[i].getDta() == 0)
					continue;
				if (stk == list[i].getMaSoThe())
				{
					if (stk != a.getMaSoThe())
					{
						kh = i;
						cout << "  Ten nguoi thu huong: " << list[i].getHoTen() << endl;
						do
						{
							cout << "  Nhap so tien muon chuyen: ";
							cin >> tien;
							if (tien > a.getSoDuTaiKhoan())
							{
								char target[256] = "";
								cout << "  So du khong du de chuyen, vui long nhap so du nho hon " << this->intToStr(target, a.getSoDuTaiKhoan());
							}
						} while (tien > a.getSoDuTaiKhoan());

						fflush(stdin);
						sprintf(nd, "%s chuyen tien", a.getHoTen());
						int q = 3;
						do
						{
							int check = ConfirmPin(a.getMaPin());
							if (!check)
							{
								q--;
								cout << "  Ma pin sai! Vui long nhap lai! Con " << q << " lan nhap!" << endl;
								if (q == 0)
								{
									cout << "  Da nhap sai qua 3 lan! Vui long thuc hien lai giao dich moi!" << endl;
									return;
								}
							}
							else
								break;
						} while (1);

						if (confirmMessage())
						{
							if (a.getSoDuTaiKhoan() - tien <= 50000)
							{
								
								cout << "  Yeu cau so du duy tri tai khoan toi thieu 50.000 VND, quy khach vui long nap them tien vao tai khoan de thuc hien giao dich!" << endl;
								break;
							}
							else
							{
								long long cu = a.getSoDuTaiKhoan();
								a.setSoDuTaiKhoan(a.getSoDuTaiKhoan() - tien);

								list[kh].setSoDuTaiKhoan(list[kh].getSoDuTaiKhoan() + tien);

								char target1[256] = "";
								cout << endl;
								cout << "  Giao dich thanh cong! So du hien tai cua quy khach la: " << this->intToStr(target1, a.getSoDuTaiKhoan()) << endl;
								char x[256], y[256];
								dateTime d;
								d.setCurrentTime();

								char target2[256] = "";
								sprintf(x, " TK:%d\n-%s\n%d/%d/%d %d:%d\nChuyen Khoan\n%s\nMa GD: %d%d\n", a.getMaSoThe(), this->intToStr(target2, tien), d.getDay(), d.getMon(), d.getYear(), d.getHour(), d.getMin(), nd, 1, taoMaGD());
								char path1[256], path2[256];
								sprintf(path1, "./LSGD/%d-%s.txt", a.getID(), a.getHoTen());

								this->saveTransaction(x, path1);

								char target3[256] = "";
								sprintf(y, " TK:%d\n+%s\n%d/%d/%d %d:%d\nChuyen Khoan\n%s\nMa GD: %d\n", list[kh].getMaSoThe(), this->intToStr(target3, tien), d.getDay(), d.getMon(), d.getYear(), d.getHour(), d.getMin(), nd, taoMaGD());
								sprintf(path2, "./LSGD/%d-%s.txt", list[kh].getID(), list[kh].getHoTen());

								this->saveTransaction(y, path2);

								this->saveLIST();

								cout << endl;
								char target4[256] = "";

								cout << "  +--------- Thong bao bien dong so du: ----------+" << endl;
								cout << "  | Tai khoan: " << setw(34) << right << a.getMaSoThe() << " |" << endl;
								cout << "  | So tien giao dich: " << setw(26) << right << this->intToStr(target4, tien) << " |" << endl;
								cout << "  | Thoi gian: " << setw(20) << right << d.getDay() << "/" << d.getMon() << "/" << d.getYear() << " " << setw(2) << right << d.getHour() << ":" << setw(2) << right << d.getMin() << " |" << endl;
								cout << "  | Noi dung:                        Chuyen khoan |" << endl;
								cout << "  +-----------------------------------------------+" << endl
										 << endl;
								break; 
							}
						}
					}
					else
					{
						cout << "  Khong the chuyen cho chinh ban! Vui long nhap STK khac!" << endl;
						return;
					}
				}
			}
			
			if (i == list.getKeyCount()) {
					cout << "  Khong tim thay khach hang co so tai khoan: " << stk << endl;
					cout << "  [1] Nhap lai!" << endl;
					cout << "  [0] Thoat" << endl; 
					int sl;
					cout << "  Nhap lua chon: ";
					cin >> sl;
					if (sl < 0 || sl > 1) {
						cout << "  Lua chon vua nhap khong dung!" << endl;
						cout << "  Nhap lua chon: ";
						cin >> sl;
					}
					switch (sl) {
						case 1:
							stk = 0;
							break;
						case 0:
							return;
							break;
					}
			}
				
		} while (stk == 0);
	}
	break;

	case 2:
	{
		fflush(stdin);
		system("cls");
		cout << "  Chon ngan hang ban muon chuyen den:" << endl;
		int choose = 0;
		struct bank
		{
			char name[256];
		};
		bank listbank[8] = {"", "Agribank", "Mb Bank", "Tien Phong", "VP Bank", "ACB", "Nam A Bank", "Sacombank"};
		cout << "  [1] Ngan hang AgriBank" << endl;
		cout << "  [2] Ngan hang Mb bank" << endl;
		cout << "  [3] Ngan hang Tien Phong" << endl;
		cout << "  [4] Ngan hang VP Bank" << endl;
		cout << "  [5] Ngan hang ACB" << endl;
		cout << "  [6] Ngan hang Nam A Bank" << endl;
		cout << "  [7] Ngan hang SacomBank" << endl;
		cout << "  [0] Khong co ngan hang ban ban tim" << endl;
		cout << "  Nhap lua chon cua ban: ";
		cin >> choose;

		if (choose == 0)
		{
			cout << "  Nhap ngan hang chuyen den: " << endl;
			cin.getline(listbank[0].name, 256);
		}
		fflush(stdin);
		cout << "  Nhap so tai khoan ma ban muon chuyen toi: ";
		cin >> stk;
		do
		{
			cout << "  Nhap so tien muon chuyen: ";
			cin >> tien;
			if (tien > a.getSoDuTaiKhoan())
				cout << "  So du khong du de chuyen, vui long nhap so du nho hon " << a.getSoDuTaiKhoan() << endl;
		} while (tien > a.getSoDuTaiKhoan());
		fflush(stdin);
		//    cout<<"  Nhap noi dung chuyen khoan: "; cin.getline(nd,256);
		//    if(strcmp(nd,"")==0)sprintf(nd," %s chuyen tien",a.hoTen );
		int q = 3;
		do
		{
			int check = ConfirmPin(a.getMaPin());
			if (!check)
			{
				q--;
				cout << "  Ma pin sai! Vui long nhap lai! Con " << q << " lan nhap!" << endl;
				if (q == 0)
				{
					cout << "  Da nhap sai qua 3 lan! Vui long thuc hien lai giao dich moi!" << endl;
					return;
				}
			}
			else
				break;
		} while (1);
		if (confirmMessage())
		{
			if (a.getSoDuTaiKhoan() <= 50000)
			{
				cout << "  So du quy khach nho hon 50K, vui long nap them tien vao tai khoan de thuc hien giao dich!" << endl;
			}
			else
			{
				a.setSoDuTaiKhoan(a.getSoDuTaiKhoan() - tien - 0.02 * tien);

				system("cls");
				char target[256] = "";
				cout << "  Giao dich thanh cong!" << endl;
				cout << "  (Da tru 2% phi giao dich)" << endl;
				char x[256];
				dateTime d;
				d.setCurrentTime();
				char target1[256] = "";
				sprintf(x, " TK:%d\n-%s\n%d/%d/%d %d:%d\nChuyen khoan\nChuyen khoan den STK: %d thuoc ngan hang %s\nMa GD: %d%d\n", a.getMaSoThe(), this->intToStr(target1, tien), d.getDay(), d.getMon(), d.getYear(), d.getHour(), d.getMin(), stk, listbank[choose].name, 1, taoMaGD());
				char path[256];
				sprintf(path, "./LSGD/%d-%s.txt", a.getID(), a.getHoTen());

				this->saveTransaction(x, path);
				this->saveLIST();

				cout << endl;
				char target3[256] = "";
				cout << "  +--------- Thong bao bien dong so du: ----------+" << endl;
				cout << "  | Tai khoan: " << setw(34) << right << a.getMaSoThe() << " |" << endl;
				cout << "  | So tien giao dich: " << setw(26) << right << this->intToStr(target3, tien + 0.02 * tien) << " |" << endl;
				cout << "  | Thoi gian: " << setw(20) << right << d.getDay() << "/" << d.getMon() << "/" << d.getYear() << " " << setw(2) << right << d.getHour() << ":" << setw(2) << right << d.getMin() << " |" << endl;
				cout << "  | Noi dung:                        Chuyen khoan |" << endl;
				cout << "  +-----------------------------------------------+" << endl
						 << endl;
			}
		}
		break;
	}
	case 0:
		return;
	}
}

void LIST::quenMatKhau()
{
	fflush(stdin);
	cout << "  Nhap ten dang nhap: ";
	char _tenDangNhap[256];
	cin.getline(_tenDangNhap, 256);

	CLIENT *p = new CLIENT;

	int i = this->list.find(p->strToInt(_tenDangNhap));
	if (i == -1)
	{
		cout << "  Ten dang nhap khong ton tai!" << endl
				 << endl;
		system("pause");
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

	if (strcmp(_sdt, list[i].getSdt()) == 0 && strcmp(_hoTen, list[i].getHoTen()) == 0 && strcmp(_cccd, list[i].getCccd()) == 0)
	{

		char _matKhau[256];
		cout << "\n  Nhap mat khau moi: " << endl;
		list[i].setMatKhau();

		this->saveLIST();
		cout << "  Thay doi mat khau thanh cong!" << endl;
		system("pause");
	}
	else
	{
		cout << "  Thong tin quy khach vua nhap khong khop voi thong tin da dang ky tren TV Bank! Vui long thuc hien lai!" << endl;
		system("pause");
	}
}

//===================END_LIST_H============================================================



#endif

