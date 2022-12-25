#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h>
#include <iomanip>
#include "dateTime.h"
#include "Hash_Table.h"

using namespace std;

//=============================CLIENT_H ==============================================
class CLIENT
{
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

	unsigned long long getDta()
	{
		return dta;
	}
	void setHoTen();
	char *getHoTen();
	void setDiaChi();
	char *getDiaChi();
	void setSdt();
	char *getSdt();
	void setCccd();
	char *getCccd();
	void setNgaySinh();
	int getNgaySinh()
	{
		return ngaySinh;
	}
	int getThangSinh()
	{
		return thangSinh;
	}
	int getNamSinh()
	{
		return namSinh;
	}

	void setTaiKhoan();
	char *getTaiKhoan();
	void setMatKhau();
	char *getMatKhau();
	void setMaPin();
	char *getMaPin();
	void setSoDuTaiKhoan(unsigned long long);
	unsigned long long getSoDuTaiKhoan();
	void setID(int id);
	int getID();
	void setMaSoThe();
	int getMaSoThe();
	void saveCLIENT();
	const CLIENT operator=(CLIENT &p);
	unsigned long long strToInt(char *str);
	unsigned long long covertCharToInt(char data);
};

CLIENT::CLIENT()
{
	this->dta = 0;
}

unsigned long long CLIENT::strToInt(char *str)
{
	unsigned long long result = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		result += covertCharToInt(str[i]) * pow(37, i);
	}
	return result;
}
unsigned long long CLIENT::covertCharToInt(char data)
{
	switch (data)
	{
	case '0':
		return 0;
	case '1':
		return 1;
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	case '_':
		return 10;
	case 'A':
		return 11;
	case 'a':
		return 11;
	case 'B':
		return 12;
	case 'b':
		return 12;
	case 'C':
		return 13;
	case 'c':
		return 13;
	case 'D':
		return 14;
	case 'd':
		return 14;
	case 'E':
		return 15;
	case 'e':
		return 15;
	case 'F':
		return 16;
	case 'f':
		return 16;
	case 'G':
		return 17;
	case 'g':
		return 17;
	case 'H':
		return 18;
	case 'h':
		return 18;
	case 'I':
		return 19;
	case 'i':
		return 19;
	case 'J':
		return 20;
	case 'j':
		return 20;
	case 'K':
		return 21;
	case 'k':
		return 21;
	case 'L':
		return 22;
	case 'l':
		return 22;
	case 'M':
		return 23;
	case 'm':
		return 23;
	case 'N':
		return 24;
	case 'n':
		return 24;
	case 'O':
		return 25;
	case 'o':
		return 25;
	case 'P':
		return 26;
	case 'p':
		return 26;
	case 'Q':
		return 27;
	case 'q':
		return 27;
	case 'R':
		return 28;
	case 'r':
		return 28;
	case 'S':
		return 29;
	case 's':
		return 29;
	case 'T':
		return 30;
	case 't':
		return 30;
	case 'U':
		return 31;
	case 'u':
		return 31;
	case 'V':
		return 32;
	case 'v':
		return 32;
	case 'W':
		return 33;
	case 'w':
		return 33;
	case 'X':
		return 34;
	case 'x':
		return 34;
	case 'Y':
		return 35;
	case 'y':
		return 35;
	case 'Z':
		return 36;
	case 'z':
		return 36;
	}
}

void CLIENT::setHoTen()
{
	fflush(stdin);
	cout << "  Nhap ten: ";
	cin.getline(this->hoTen, 256);
}
char *CLIENT::getHoTen()
{
	return hoTen;
}
void CLIENT::setDiaChi()
{
	cout << "  Nhap dia chi: ";
	cin.getline(this->diaChi, 256);
}
char *CLIENT::getDiaChi()
{
	return diaChi;
}
void CLIENT::setSdt()
{
	do
	{
		fflush(stdin);
		cout << "  Nhap so dien thoai: ";
		cin.getline(this->soDienThoai, 256);
		if (strlen(this->soDienThoai) == 10)
		{
			break;
		}
		else
		{
			cout << "  So dien thoai vua nhap khong dung!" << endl;
			cout << "  Vui long nhap lai!" << endl;
		}
	} while (1);
}
char *CLIENT::getSdt()
{
	return soDienThoai;
}
void CLIENT::setCccd()
{
	do
	{
		fflush(stdin);
		cout << "  Nhap can cuoc cong dan: ";
		cin.getline(this->cccd, 256);
		if (strlen(this->cccd) == 12)
		{
			break;
		}
		else
		{
			cout << "  So can cuoc cong dan vua nhap khong dung!" << endl;
			cout << "  Vui long nhap lai!" << endl;
		}
	} while (1);
}
char *CLIENT::getCccd()
{
	return cccd;
}
void CLIENT::setNgaySinh()
{
	do
	{
		int day, mon, year;
		cout << "  Nhap ngay sinh (dd mm yy) " << endl;
		cout << "    Nhap ngay: ";
		cin >> day;
		cout << "    Nhap thang: ";
		cin >> mon;
		cout << "    Nhap nam: ";
		cin >> year;
		dateTime dd;
		if (dd.laNgayHopLe(day, mon, year))
		{
			this->ngaySinh = day;
			this->thangSinh = mon;
			this->namSinh = year;
			break;
		}
		else
		{
			cout << "  Ngay thang nam vua nhap khong hop le!" << endl;
			cout << "  Vui long nhap lai!" << endl;
		}
	} while (1);
}

void CLIENT::setTaiKhoan()
{
	fflush(stdin);
	cout << "  Nhap ten dang nhap: ";
	cin.getline(this->taiKhoan, 256);
	fflush(stdin);
	this->dta = strToInt(this->taiKhoan);
}
char *CLIENT::getTaiKhoan()
{
	return taiKhoan;
}
void CLIENT::setMatKhau()
{
	do
	{
		fflush(stdin);
		cout << "  Nhap mat khau: ";
		cin.getline(this->matKhau, 256);
		if (strlen(this->matKhau) >= 6)
		{
			break;
		}
		else
		{
			cout << "  Mat khau vua nhap it hon 6 ki tu!" << endl;
			cout << "  Vui long nhap lai!" << endl;
		}
	} while (1);

	do
	{
		cout << "  Xac nhan mat khau: ";
		char temp[256];
		fflush(stdin);
		cin.getline(temp, 256);
		if (strcmp(temp, this->matKhau) == 0)
		{
			break;
		}
		else
		{
			cout << "  Mat khau xac nhan khong chinh xac!" << endl;
			cout << "  Vui long xac nhan lai mat khau!" << endl;
		}
	} while (1);
}
char *CLIENT::getMatKhau()
{
	return matKhau;
}
void CLIENT::setMaPin()
{
	do
	{
		fflush(stdin);
		cout << "  Nhap ma pin: ";
		cin.getline(this->maPin, 5);
		if (strlen(this->maPin) == 4)
		{
			break;
		}
		else
		{
			cout << "  Ma pin vua nhap khong dung 4 ki tu!" << endl;
			cout << "  Vui long nhap lai!" << endl;
		}
	} while (1);

	do
	{
		cout << "  Xac nhan ma pin: ";
		char temp[256];
		fflush(stdin);
		cin.getline(temp, 5);
		if (strcmp(temp, this->maPin) == 0)
		{
			break;
		}
		else
		{
			cout << "  Ma pin xac nhan khong chinh xac!" << endl;
			cout << "  Vui long xac nhan lai ma pin!" << endl;
		}
	} while (1);
}
char *CLIENT::getMaPin()
{
	return maPin;
}
void CLIENT::setSoDuTaiKhoan(unsigned long long soTien)
{
	this->soDuTaiKhoan = soTien;
}
unsigned long long CLIENT::getSoDuTaiKhoan()
{
	return soDuTaiKhoan;
}
void CLIENT::setID(int id)
{
	this->id = id;
}
int CLIENT::getID()
{
	return id;
}
void CLIENT::setMaSoThe()
{
	this->maSoThe = 1000000000 + this->id;
}
int CLIENT::getMaSoThe()
{
	return maSoThe;
}
void CLIENT::saveCLIENT()
{
	fstream f("text1.txt", ios::binary | ios::out | ios::app);
	if (!f)
		cout << "error occured when open file to write!";
	f.write(reinterpret_cast<char *>(this), sizeof(*this));
	f.close();
}
const CLIENT CLIENT::operator=(CLIENT &p)
{
	strcpy(this->hoTen, p.hoTen);
	strcpy(this->diaChi, p.diaChi);
	strcpy(this->soDienThoai, p.soDienThoai);
	strcpy(this->cccd, p.cccd);
	strcpy(this->taiKhoan, p.taiKhoan);
	strcpy(this->matKhau, p.matKhau);
	strcpy(this->maPin, p.maPin);
	this->dta = p.dta;
	this->soDuTaiKhoan = p.soDuTaiKhoan;
	this->maSoThe = p.maSoThe;
	this->ngaySinh = p.ngaySinh;
	this->thangSinh = p.thangSinh;
	this->namSinh = p.namSinh;
	this->id = p.id;
}

//=====================END_CLIENT_H=========================================================

#endif
