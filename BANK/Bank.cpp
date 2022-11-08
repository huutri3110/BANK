#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <conio.h>
#include <io.h>
#include "BANK.h"



using namespace std;


void menu_main(){
	int s=1;
	int vt;
    
    do
    {
    	system("cls");
    	cout <<"********************************************************************" << endl;
    	cout <<"****                                                            ****" << endl;
    	cout <<"****         Welcome to T.V Bank- Bank of VietNam               ****" << endl;
    	cout <<"****                                                            ****" << endl;
    	cout <<"********************************************************************" << endl;
    	cout << "\n";
        cout<<"  1.Dang Nhap"<<endl;
        cout<<"  2.Dang ki tai khoan"<<endl;
        cout<<"  3.Lien he dich vu CSKH"<<endl;
        cout<<"  0.Thoat ngan hang"<<endl;
        cout<<"  Nhap lua chon cua ban: "; cin>>s;
        
        switch (s)
        {
        case 1:
            cout<<endl;
            
            vt = log_in();
            cout << vt;
            
            if (vt) {
            	int s=1;
        		do
        		{
        	system("cls");
        	
        	cout <<"********************************************************************" << endl;
    		cout <<"****                                                            ****" << endl;
        	cout <<"****                 Welcome" << " " << setw(35) << left << client[vt].hoTen << "****" << endl;
    		cout <<"****                                                            ****" << endl;
    		cout <<"********************************************************************" << endl;
            cout<<"\n  1.Thong tin tai khoan."<<endl;;
            cout<<"  2.So du tai khoan."<<endl;
            cout<<"  3.Chuyen khoan"<<endl;
            cout<<"  4.Nap tien."<<endl;
            cout<<"  5.Rut tien."<<endl;
            cout<<"  6.Cac dich vu lien quan den the."<<endl;
            cout<<"  7.Cac dich vu khac (Thanh toan hoa don, Tien dien, Tien nuoc,...)"<<endl;
            cout<<"  0.Dang Xuat" << endl;
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
			} else {
				cout<<"\n\nTai khoan va mat khau chua chinh xac! Vui long nhap lai!"<<endl;
				system("pause");
			}
            
            break;
        case 2:
        	system("cls");
            moTaiKhoan();
            break;
        case 3:
            // CSKH
            break;
    }
    } while (s);
} 

int main() {
	layID();
	
	client = getListClient();
	



	
	 menu_main();
	
 	 

	
	taoID();
}
