#include <iostream>
using namespace std;
class yuan {
  private:
    static double sum, discount;
    static int n;
    double price;
    int num;
    int quantity;
    double get;

  public:
    yuan(int num_ = 0, int quantity_ = 0, double price_ = 0) {
        num = num_;
        price = price_;
        quantity = quantity_;
        if (quantity > 10) {
            get = price * 0.98 * discount / 10 * quantity;
        } else {
            get = price * discount / 10 * quantity;
        }
        sum += get;
        n += quantity;
    }
    static void setDiscount(double discount_) { discount = discount_; }
    static double average() { return sum / n; }
    static void display() {
        cout << "总销售额为 : " << sum << endl;
        cout << "平均售价为 : " << average() << endl;
    }
};
int yuan::n = 0;
double yuan::sum = 0;
double yuan::discount = 8.8;
int main() {
    double discount;
    int n;
    cout << "请输入本日折扣 : ";
    cin >> discount;
    yuan::setDiscount(discount);
    yuan people[100];
    cout << "请输入售货员数量 : ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        int quantity;
        double price;
        cout << "请分别输入第" << i + 1
             << "名销货员的销货员号, 销货件数, 销货单价 : " << endl;
        cin >> num >> quantity >> price;
        yuan tmp(num, quantity, price);
        people[i] = tmp;
    }
    yuan::display();
    return 0;
}