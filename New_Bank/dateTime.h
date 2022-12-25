#ifndef dateTime_H
#define dateTime_H

#include <ctime>
#include <stdexcept>
using namespace std;
class dateTime{
    private:
    int year;
    int mon;
    int day;
    int hour;
    int min;
    public:
        dateTime();
        bool setDateTime(int, int, int);
        void setCurrentTime();
        int getYear();
        int getMon();
        int getDay();
        int getHour();
        int getMin();
        bool laNamNhuan(int nYear);
        int tinhSoNgayTrongThang(int nMonth, int nYear);
        bool laNgayHopLe(int nDay, int nMonth, int nYear);
        friend ostream& operator << (ostream& os, dateTime p) {
        	os << p.getDay() << "-" << p.getMon() << "-" << p.getYear();
        	return os; 
		}
};

dateTime::dateTime(){
}
bool dateTime::setDateTime(int day,int mon, int year) {
	if (laNgayHopLe(day, mon, year))
	{
		this->day = day;
		this->mon = mon;
		this->year = year;
		return 1;
	}
	else
	{
		return 0;
	}
}
void dateTime::setCurrentTime() {
	time_t now = time(0);
    tm *ltm = localtime(&now);
    year= 1900 + ltm->tm_year;
    mon= 1 + ltm->tm_mon;
    day=  ltm->tm_mday ;
    min=   ltm->tm_min;
    hour=  ltm->tm_hour;
}
int dateTime::getYear(){
	return year;
}
int dateTime::getMon(){
    return mon;
}
int dateTime::getDay(){
    return day;
}
int dateTime::getHour(){
    return hour;
}
int dateTime::getMin(){
    return min;
}

bool dateTime::laNamNhuan(int nYear)
{
	if ((nYear % 4 == 0 && nYear % 100 != 0) || nYear % 400 == 0)
	{
		return true;
	}
	return false;
}
int dateTime::tinhSoNgayTrongThang(int nMonth, int nYear)
{
	int nNumOfDays;

	switch (nMonth)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12: 
		nNumOfDays = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11: 
		nNumOfDays = 30;
		break;
	case 2:
		if (laNamNhuan(nYear))
		{
			nNumOfDays = 29;
		}
		else
		{
			nNumOfDays = 28;
		}
		break;
	}

	return nNumOfDays;
}


bool dateTime::laNgayHopLe(int nDay, int nMonth, int nYear)
{
	if (nYear < 0)
	{
		return false; 
	}
	if (nMonth < 1 || nMonth > 12)
	{
		return false;
	}

	if (nDay < 1 || nDay > tinhSoNgayTrongThang(nMonth, nYear))
	{
		return false; 
	}

	return true;
}

#endif
