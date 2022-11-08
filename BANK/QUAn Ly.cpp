#include <iostream>
#include "BANK.h"
using namespace std;

int main() {
	layID();
	client = getListClient();		
	int select;
	do {
		system("cls");
		cout << "\n\t\t\tMENU" << endl;
		cout << "1 - Xuat DS Tai Khoan" << endl;
		cout << "2 - Quan Ly Tai Khoan" << endl;
		cout << "3 - Giao Dich" << endl;
		cout << "4 - Lich Su Giao Dich" << endl;
		cout << "5 - Thong Ke Tai Chinh" << endl;
		cout << "0 - EXIT!" << endl;
		
		cin >> select;
		
		switch (select)  
		{
		case 1:
			system("cls");
			if (number){
				showListClient(client);
			} else {
				cout << "================================" << endl;
				cout << "|| Danh sach hien dang trong! ||" << endl;
				cout << "================================" << endl;
			}
			
			system("pause");
			break;
		case 2:
			system("cls");
			int subSelect;
			
				
				cout << "\n1 - Tim Tai Khoan" << endl;
				cout << "2 - Mo Tai Khoan" << endl;
				cout << "3 - Xoa Tai Khoan" << endl;
				cout << "4 - Chinh Sua Tai Khoan" << endl;
				cout << "0 - BACK" << endl;
		
				cin >> subSelect;
				
				switch(subSelect)
				{
				case 1:
					cout << "Tim tai khoan" << endl;
					break;
				case 2:
					moTaiKhoan();

					break;
				case 3:
					system("cls");
					showListClient(client);
					int temp;
					int i;
					cout << "Nhap id cua tai khoan can xoa: ";
					cin >> temp;
					
					for(i=1; i<=number; i++){
						if(client[i].idd == temp) {
						
							deleteCLient(i);
							cout << "Xoa thanh cong!" << endl;
							system("pause");
							i = number + 1; //thoat khoi vong lap tren
						}
					}
					if(i == number+1){
					cout << "id khong ton tai!" << endl;
					system("pause");
					}
					
						break;
					
					
				case 4:
					cout << "Chinh Sua Tai Khoan" << endl;
					break;
				default:
					subSelect = 0;
				}
				system("cls");
			
			 
			 		system("cls");
				break;
		default:
			select = 0;
			

	}} while (select);
	
	
}

