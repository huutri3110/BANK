#ifndef dateTime_H
#define dateTime_H

#include <iostream>
#include <ctime>
class dateTime{
    private:
    int year;
    int mon;
    int day;
    int hour;
    int min;
    public:
        dateTime(){
             time_t now = time(0);
            tm *ltm = localtime(&now);
            year= 1900 + ltm->tm_year;
            mon= 1 + ltm->tm_mon;
            day=  ltm->tm_mday ;
            min=  1 + ltm->tm_min;
            hour= 1 + ltm->tm_hour;
        }
        int getYear(){
            return year;
        }
        int getMon(){
            return mon;
        }
        int getDay(){
            return day;
        }
        int getHour(){
            return hour;
        }
        int getMin(){
            return min;
        }
};

#endif
