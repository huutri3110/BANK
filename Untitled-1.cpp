#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "BANK.h"
#include <conio.h>
#include <io.h>

using namespace std;




int main() {
	layID();
	
//	moTaiKhoan();
//	moTaiKhoan();
//	moTaiKhoan();
	
	client = getListClient();
	
	cout << client[1].taiKhoan; 
	
//	showListClient(client);
	
//	saveListClient(client);
	
	taoID();
}

