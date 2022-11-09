

#include <iostream>
#include <ctime>

using namespace std;

int main() {
   // th?i gian hi?n t?i tính theo h? th?ng
   time_t now = time(0);

   cout << "Number of sec since 1/1/1970:" << now << endl;

   tm *ltm = localtime(&now);

   // in ra các thành ph?n c?a c?u trúc tm struct
   cout << "Year: " << 1900 + ltm->tm_year << endl;
   cout << "Month: "<< 1 + ltm->tm_mon<< endl;
   cout << "Day: "<<  ltm->tm_mday << endl;
   cout << "Time: "<< 1 + ltm->tm_hour << ":";
   cout << 1 + ltm->tm_min << ":";
   cout << 1 + ltm->tm_sec << endl;
}
