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
	
    
    do
    {
    	system("cls");
    	cout <<"          \n                        Welcome to T.V Bank- Bank of VietNam"<<endl;
        cout<<"\n1.Dang Nhap"<<endl;
        cout<<"2.Dang ki tai khoan"<<endl;
        cout<<"3.Lien he dich vu CSKH"<<endl;
        cout<<"0.Thoat ngan hang"<<endl;
        cout<<"Nhap lua chon cua ban: "; cin>>s;
        switch (s)
        {
        case 1:
            cout<<endl;
            system("cls");
            log_in();
            
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
	


//	moTaiKhoan(); 
	
	 menu_main();
	
 	 

	
// 	showListClient(client);
	
// //	saveListClient(client);
	
	taoID();
}

