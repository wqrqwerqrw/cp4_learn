#ifndef ACCTABC_H_
#define ACCTABC_H_
#include<string>
#include<iostream>
using std::string;
using std::cout;
using std::endl;
using std::string;
using std::ios_base;

class AcctABC{
  private:
    string fullName;
    long acctNum;
    double balance;

  protected:
    struct Formatting {
        std::ios_base::fmtflags flag;
        std::streamsize pr;
    };
    const std::string &FullName() const { return fullName; }
    long AcctNum() const { return acctNum; }
    Formatting SetFormat() const;
    void Restore(Formatting &f) const;

  public:
    AcctABC(const string & s, long an, double bal);
    void Deposit(double amt);
    virtual void Withdraw(double amt) = 0;
    double Baleance() const {return balance;};
    virtual void ViewAcct() const = 0;   //定义抽象函数
    virtual ~AcctABC(){}
};

AcctABC::AcctABC(const string & s = "Nullbody", long an = -1, double bal = 0.0){
    fullName = s;
    acctNum = an;
    balance = bal;
}

void AcctABC::Deposit(double amt){
    if (amt < 0)
        cout << "Negative deposit not allowed; "
             << "deposit is cancelled. " << endl;
    else
        balance += amt;
}

void AcctABC::Withdraw(double amt){
    balance -= amt;
}

void AcctABC::Restore(Formatting &f) const{
    cout.setf(f.flag, ios_base::floatfield);
    cout.precision(f.pr);
}



#endif