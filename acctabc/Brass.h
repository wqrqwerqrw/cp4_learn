#ifndef BRASS_H_
#define BRASS_H_
#include "acctabc.h"
#include <iostream>;
#include <string>
using std::cout;
using std::endl;
using std::ios_base;
using std::string;
class Brass : public AcctABC {
  public:
    Brass(const string &s = "Nullbody", long an = -1, double bal = 0.0)
        : AcctABC(s, an, bal) {}
    virtual void Withdraw(double amt);
    virtual void ViewAcct() const;
    virtual ~Brass();
};

void Brass::Withdraw(double amt) {
    if (amt < 0)
        cout << "Withdrwal amout must be positive; "
             << "Withdrawaa canceld." << endl;
    else if (amt <= Baleance())
        AcctABC::Withdraw(amt);
    else
        cout << "Withdrawal amout of $" << amt << " exceeds your balance. \n"
             << "Withdrawal canceld. \b";
}

void Brass::ViewAcct() const {
    Formatting f = SetFormat();
    cout << "Brass Client : " << FullName() << endl;
    cout << "Account Number: " << AcctNum() << endl;
    cout << "Balance : $" << Baleance() << endl;
    Restore(f);
}

Brass::~Brass() {}

#endif