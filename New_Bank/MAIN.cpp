#include "LIST.h" // #include "CLIENT.h"
				  // #include "Hash_Table.h"
				  // #include <iostream>

void menu_main(LIST &list)
{
	int s = 1;

	do
	{
		system("cls");
		cout << "******************************************************************" << endl;
		cout << "*                                                                *" << endl;
		cout << "*           Welcome to T.V Bank- Bank of VietNam                 *" << endl;
		cout << "*                                                                *" << endl;
		cout << "******************************************************************" << endl;
		cout << "\n";
		cout << "  [1] Dang Nhap" << endl;
		cout << "  [2] Dang ki tai khoan" << endl;
		cout << "  [3] Lien he dich vu CSKH" << endl;
		cout << "  [0] Thoat ngan hang" << endl;
		cout << "\n  Nhap lua chon cua ban: ";
		cin >> s;

		switch (s)
		{
		case 1:
		{
		Dangnhap:
			cout << endl;
			int vt = list.log_in();
			int o;
			if (vt != -1)
			{
				do
				{
					system("cls");

					cout << "******************************************************************" << endl;
					cout << "*                                                                *" << endl;
					cout << "*                   Welcome"
							 << " " << setw(35) << left << list[vt].getHoTen() << "  *" << endl;
					cout << "*                                                                *" << endl;
					cout << "******************************************************************" << endl;
					cout << "\n  [1] Thong tin tai khoan." << endl;
					;
					cout << "  [2] So du tai khoan." << endl;
					cout << "  [3] Chuyen khoan" << endl;
					cout << "  [4] Nap tien." << endl;
					cout << "  [5] Rut tien." << endl;
					cout << "  [6] Doi ma pin." << endl;
					cout << "  [7] Thanh toan tien dien,nuoc, dien thoai,..." << endl;
					cout << "  [8] Lich su giao dich." << endl;
					cout << "  [0] Dang Xuat" << endl;
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
					case 6:
						list.doiMapin(list[vt]);
						break;
					case 7:
						list.thanhToan(list[vt]);
						break;
					case 8:
						list.exportTransaction(list[vt]);
						system("pause");
						break;
					default:
						o = 0;
					}
				} while (o);
			}
			else
			{
				int sl = 0;
				cout << "\n\n  Tai khoan va mat khau chua chinh xac! Vui long nhap lai!" << endl;
				do
				{
					cout << "  [1] Quen mat khau" << endl
							 << "  [2] Dang nhap lai" << endl
							 << "  [0] Thoat" << endl;
					cout << "  Nhap lua chon cua ban: ";
					cin >> sl;
					if (sl == 1)
					{
						list.quenMatKhau();
						break;
					}
					if (sl == 2)
					{
						goto Dangnhap;
						break;
					}
				} while (sl != 0);
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

int main()
{
	LIST ds;

	//	ds.signUp();
	//	ds.log_in();

	menu_main(ds);
	return 0;
}
