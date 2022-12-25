#ifndef Hash_Table_h
#define Hash_Table_h

#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

template <class T>
class hashTable {
	private:
		int key;
		T* listValue;
		
		int usedSlots;
		unsigned long long keyCount;
		float loadFactor;
		int covertCharToInt (char data);
	public:
		hashTable(int);
		hashTable (){
		};
		void init (int size);
		unsigned long long insert (unsigned long long, T);
		T& operator [] (unsigned long long);
		unsigned long long strToInt (char str[]);
		unsigned long long findPrimeNum (unsigned long long n);
		unsigned long long isPrimeNum(unsigned long long n);
		unsigned long long hashFunc (unsigned long long key);
		unsigned long long find (unsigned long long idx);
		unsigned long long hashFunc2 (unsigned long long key);
		void checkLoadFactor ();
		unsigned long long getKeyCount () {
			return this->keyCount;
		}
};

template <class T>
hashTable<T>::hashTable(int number) {
	this->keyCount = this->findPrimeNum(number*2);
	
	
	this->usedSlots = 0;
	this->loadFactor = 0.6;
	listValue = new T [this->keyCount];
	for (unsigned long long i = 0; i < this->keyCount; i++)	{
		strcpy (listValue[i].taiKhoan, "");
	}
}

template <class T>
void hashTable<T>::init (int number) {
	this->keyCount = this->findPrimeNum(number*2);
	this->usedSlots = 0;
	this->loadFactor = 0.6;
	listValue = new T [this->keyCount];
}
template <class T>
unsigned long long hashTable<T>::insert (unsigned long long key, T value) {
	this->usedSlots ++;
	this->checkLoadFactor();                     //Kiem tra dung luong cua hash table
	unsigned long long i = 0;
	unsigned long long j = this->hashFunc2(key);
	unsigned long long idx = key;
	do {
		if (idx >= this->keyCount) {
			idx = idx % this->keyCount;
		}
		i++;
	} while (listValue[idx].dta != 0);
	listValue[idx] = value;
	return idx;
}
template <class T>
T& hashTable<T>::operator [] (unsigned long long key) {
	return listValue[key];
}

template <class T>
unsigned long long hashTable<T>::strToInt (char* str) {
	unsigned long long result = 0;
	for (int i = 0; i < strlen(str); i++) {
		result += covertCharToInt(str[i])*pow(37, i);
	}
	return result;
} 

template <class T>
int hashTable<T>::covertCharToInt (char data) {
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

template <class T>
unsigned long long hashTable<T>::isPrimeNum(unsigned long long n) {
    if (n < 2) {
        return 0;
    }
    unsigned long long squareRoot = (unsigned long long) sqrt(n);
    int i;
    for (i = 2; i <= squareRoot; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}
template <class T>
unsigned long long hashTable<T>::findPrimeNum (unsigned long long n) {
	unsigned long long i = n;
	while (!isPrimeNum (i) || i < 21) {
		i++;
	}
	return i;
}

template <class T>
unsigned long long hashTable<T>::hashFunc (unsigned long long key) {
	return key % this->keyCount;
}

template <class T>
unsigned long long hashTable<T>::find (unsigned long long key) {
	unsigned long long i = 0;
	unsigned long long j = this->hashFunc2(key);
	unsigned long long idx = key;
	
	do {
		idx = this->hashFunc(key) + i*j; 
		if (idx >= this->keyCount) {
			idx = idx % this->keyCount;
			
		}
		i++;

		if (listValue[idx].dta == 0) {
			return -1;
		};
	} while (listValue[idx].dta != key);
	return idx;
}

template <class T>
unsigned long long hashTable<T>::hashFunc2 (unsigned long long key) {
	return 8 - (key%8);
} 

template <class T>
void hashTable<T>::checkLoadFactor () {
	if ((float)this->usedSlots / (float)this->keyCount >= this->loadFactor) {
		cout << "  Error! Bo nho cua hash table sap day" << endl;
		exit(0);
	}
}


#endif
