#ifndef TEST_H_
#define TEST_H_
#include <iostream>
using std::string;
using std::endl;
using std::cout;
class test {
  private:
    std::string a, b, c;

  public:
    test(string in1, string in2, string in3);
    void show();
    ~test();
};

test::test(string in1 = "inita", string in2 = "initb", string in3 = "initc") {
    a = in1;
    b = in2;
    c = in3;
}

void test::show(){
    cout << a << " " << b << " " << c << " " << endl;
}

test::~test() {}

#endif