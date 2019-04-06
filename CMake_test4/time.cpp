#include "time.h"

Time::Time() {
    hour = 0;
    minute = 0;
    second = 0;
}

Time::Time(int a, int b, int c) {
    hour = a;
    minute = b;
    second = c;
}
Time::Time(int a) {
    hour = 0;
    minute = 0;
    second = 0;
    second = a;
    int sect = second / 60;
    second %= 60;
    minute += sect;
    int mint = minute / 60;
    minute %= 60;
    hour += mint;
}

Time Time::add(const Time &a, const Time &b) const {
    Time tmp;
    tmp.hour = a.hour + b.hour;
    tmp.second = a.second + b.second;
    tmp.minute = a.minute + b.minute;
    if (tmp.second >= 60) {
        tmp.second -= 60;
        tmp.minute++;
    }
    if (tmp.minute >= 60) {
        tmp.minute -= 60;
        tmp.hour++;
    }
    return tmp;
}
Time Time::add(int a, const Time &b) {
    Time tmp;
    Time ta(a);
    tmp = add(ta, b);
    return tmp;
}
Time Time::sub(const Time &a, const Time &b) const {
    Time tmp;
    tmp.hour = a.hour - b.hour;
    tmp.second = a.second - b.second;
    tmp.minute = a.minute - b.minute;
    if (tmp.second < 0) {
        tmp.second += 60;
        tmp.minute--;
    }
    if (tmp.minute < 0) {
        tmp.minute += 60;
        tmp.hour--;
    }
    return tmp;
}
Time Time::sub(int a, const Time &b) {
    Time tmp;
    Time ta(a);
    tmp = sub(ta, b);
    return tmp;
}
Time Time::operator+(const Time &b) const { return Time::add(*this, b); }
Time Time::operator-(const Time &b) const { return Time::sub(*this, b); }
Time operator+(int a, const Time &b);
Time operator-(int a, const Time &b);
Time operator+(const Time &a, int b);
Time operator-(const Time &a, int b);
std::ostream &operator<<(std::ostream &os, const Time &t) {
    os << t.hour << " : " << t.minute << " : " << t.second << std::endl;
    return os;
}