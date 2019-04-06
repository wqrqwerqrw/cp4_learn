#ifndef TIME_H_
#define TIME_H_
#include<iostream>

class Time{
    private:
        int hour;
        int minute;
        int second;
    public:
        Time();
        Time(int a, int b, int c);
        Time(int a);
        int getsec();
        Time add(const Time &a, const Time &b) const;
        Time add(int a, const Time &b);
        Time sub(const Time &a, const Time &b) const;
        Time sub(int a, const Time &b);
        Time operator +(const Time &b) const;
        Time operator -(const Time &b) const;
        operator int();
        friend Time operator + (int a, const Time &b);
        friend Time operator - (int a, const Time &b);
        friend Time operator + (const Time &a, int b);
        friend Time operator - (const Time &a, int b);
        friend std::ostream & operator << (std::ostream & os, const Time & t);
};

#endif
