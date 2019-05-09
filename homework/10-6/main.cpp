#include<iostream>
using namespace std;
class Complex{
  private:
    double a;
    double b;

  public:
    Complex(double a_ = 0, double b_ = 0){
        a = a_;
        b = b_;
    }
    Complex operator+(double &in){
        Complex tmp;
        tmp.a = a + in;
        tmp.b = b;
        return tmp;
    }
    operator double(){
        return a;
    }
    friend ostream &operator<< (ostream &, Complex&);
    friend istream &operator>> (istream &, Complex&);
};
ostream &operator<<(ostream &os, Complex &in) {
    os << in.a << " + " << in.b << 'i';
    return os;
}
istream &operator>>(istream &os, Complex &in) {
    cout << "分别输入实数部分和虚数部分 : ";
    os >> in.a >> in.b;
    return os;
};

int main(){
    Complex a;
    Complex tmp;
    double in;
    cin >> a;
    cout << "请输入一个浮点数 : ";
    cin >> in;
    tmp = a + in;
    double dl = (double)tmp;
    cout << dl << endl;
    cout << tmp << endl;
    return 0;
}