#include"String1.h"
#include<cstring>
using std::strlen;
using std::strcpy;

int String::num_strings = 0;

int String::howMany(){
    return num_strings;
}

String::String(const char *s) {
    len = strlen(s);
    str = new char[len + 1];
    strcpy(str, s);
    num_strings++;
}

String::String() {
    len = 0;
    str = new char[len + 1];
    str[0] = '\0';
    num_strings++;
}

String::String(const String &st) {
    num_strings++;
    len = st.len;
    str = new char[len + 1];
    strcpy(str, st.str);
}

String::~String() {
    --num_strings;
    delete[] str;
}

String &String::operator=(const String &st) {
    if (this == &st) {
        return *this;
    }

    delete[] str;
    len = st.len;
    str = new char[len + 1];
    strcpy(str, st.str);
    return *this;
}

String &String::operator=(const char *st) {
    delete[] str;
    len = strlen(st);
    str = new char[len + 1];
    strcpy(str, st);
    return *this;
}

char &String::operator[](int i) { return str[i]; }

const char &String::operator[](int i) const { return str[i]; }

bool operator<(const String &st1, const String &st2) {
    return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String &st1, const String &st2) { return st2 < st1; }

bool operator==(const String &st1, const String &st2) {
    return (std::strcmp(st1.str, st2.str) == 0);
}

std::ostream &operator<<(std::ostream &os, const String &st) {
    os << st.str;
    return os;
}

std::istream &operator>>(std::istream &is, String &st) {
    char tmp[String::CINLIM];
    is.get(tmp, String::CINLIM);
    if (is)
        st = tmp;
    while (is && is.get() != '\n')
        continue;
    return is;
}
