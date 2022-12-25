#include <iostream>
#include "Hash_Table.h"
#include <cstring>
using namespace std;

class bank {
	
	public:
		unsigned long long dta;
		char taiKhoan[256];
		bank (char* p) {
			strcpy (taiKhoan, p);
			
		}
		~bank() {
			
		}
		bank() {
			dta = 0;
		}
		unsigned long long getDta () {
			return dta;
		}
		void setTai (unsigned long long n, char* b) {
			strcpy (this->taiKhoan, b);
			dta = n;
		}
		void operator = (bank& a) {
			strcpy (this->taiKhoan, a.taiKhoan);
			this->dta = a.dta;
		}
		
}; 

class LIST {
	hashTable<bank> list;
	public:
		LIST() {
			list.init(3);
			
		}
		void func (unsigned long long n, char* d) {
			bank* b = new bank;
			b->setTai (n, d);
			cout << list.insert(n, *b) << " ";
			
		}
		void print (unsigned long long n) {
			cout << "\n---------------" << endl;
			int i = list.find(n);
			cout << i << " " << endl;
			
			cout << list[i].taiKhoan << endl;
			
		}
		void test (char a[]) {
			cout << list.strToInt(a);
		}
};


int main() {
	
	LIST a;
	
//	a.test("dinhvan");

	a.func(62401135822, "hee");
	a.print(62401135822);
	
//	cout << 62401135822%23;
	
		
//	try {
//		
//	}
//	catch (string a) {
//		cout << a;
//	}
	
}
