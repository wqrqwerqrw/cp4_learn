#include<iostream>
using namespace std;
class Box{
  private:
    int length;
    int width;
    int heigth;

  public:
    Box(int l = 0, int w = 0, int h = 0){
        length = l;
        width = w;
        heigth = h;
    }
    Box operator+(const Box &b) const;
    friend ostream &operator<<(ostream &os, const Box &b);
    friend istream &operator>>(istream &os, Box &b);
};

Box Box::operator+(const Box &b) const {
    Box sum;
    sum.length = length + b.length;
    sum.width = width + b.width;
    sum.heigth = heigth + b.heigth;
    return sum;
}

ostream & operator<<(ostream &os, const Box &b){
    os << "length : " << b.length << endl;
    os << "width : " << b.width << endl;
    os << "heigth : " << b.heigth << endl;
    return os;
}

istream & operator>>(istream &os, Box &b){
    cout << "in : ";
    os >> b.length >> b.width >> b.heigth;
    return os;
}

int main(){
    Box b1, b2(1, 2, 3), b3(4);
    cin >> b1;
    Box b4, b5;
    b4 = b2 + b3;
    b5 = b1 + b3;
    cout << b4 << b5 << endl;
    return 0;
}
