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
    Complex operator+(Complex &in){
        Complex tmp;
        tmp.a = a + in.a;
        tmp.b = b + in.b;
        return tmp;
    }
    Complex operator-(Complex &in){
        Complex tmp;
        tmp.a = a - in.a;
        tmp.b = b - in.b;
        return tmp;
    }
    Complex operator*(Complex &in){
        double c = in.a;
        double d = in.b;
        Complex tmp;
        tmp.a = a * c - b * d;
        tmp.b = b * c + a * d;
        return tmp;
    }
    Complex operator/(Complex &in){
        double c = in.a;
        double d = in.b;
        Complex tmp;
        tmp.a = (a * c + b * d) / c * c + d * d;
        tmp.a = (b * c - a * d) / c * c + d * d;
        return tmp;
    }
    friend ostream &operator<< (ostream &, Complex&);
    friend istream &operator>> (istream &, Complex&);
};
ostream &operator<<(ostream &os, Complex &in) {
    os << "复数实数部分为 : " << in.a << " 虚数部分为 : " << in.b << endl; 
    return os;
}
istream &operator>>(istream &os, Complex &in) {
    cout << "分别输入实数部分和叙述部分 : ";
    os >> in.a >> in.b;
    return os;
};

int main(){
    Complex a(1, 2);
    Complex b;
    cin >> b;
    Complex c;
    c = a + b;
    cout << c << endl;
    c = a - b;
    cout << c << endl;
    c = a * b;
    cout << c << endl;
    c = a / b;
    cout << c << endl;
    return 0;
}