#ifndef BRASSPLUS_H_
#define BRASSPLUS_H_
#include "Brass.h"
#include "acctabc.h"
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;
using std::string;
using std::ios_base;
class BrassPlus : public AcctABC {
  private:
    double maxLoan;
    double rate;
    double owesBank;

  public:
    BrassPlus(const string &s = "Nullbody", long an = -1, double bal = 0.0,
              double ml = 500, double r = 0.10);
    BrassPlus(const Brass &ba, double ml = 500, double r = 0.10);
    virtual void ViewAcct() const;
    virtual void Withdraw(double amt);
    void ResetMax(double m) { maxLoan = m; }
    void ResetRate(double r) { rate = r; }
    void ResetOwes() { owesBank = 0; }
};

BrassPlus::BrassPlus(const string &s = "Nullbody", long an = -1,
                     double bal = 0.0, double ml = 500, double r = 0.10)
    : AcctABC(s, an, bal) {
        maxLoan = ml;
        owesBank = 0.0;
        rate = r;
}

BrassPlus::BrassPlus(const Brass & ba, double ml, double r) : AcctABC(ba){
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

void BrassPlus::Withdraw(double amt){
    Formatting f = SetFormat();
    double bal = Baleance();
    if(amt <= bal)
        AcctABC::Withdraw(amt);
    else if(amt <= bal + maxLoan - owesBank){
        double advance = amt - bal;
        owesBank += advance * (1.0 + rate);

        cout << "Bank advancd : $" << advance << endl;
        cout << "Finance charge : $" << advance * rate << endl;
        Deposit(advance);
        AcctABC::Withdraw(amt);
    }else{
        cout << "Credit limit exceeded. Transction cancelled." << endl;
    }
    Restore(f);
}

#endif