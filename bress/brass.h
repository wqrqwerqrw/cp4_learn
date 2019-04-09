#ifndef BRESS_H_
#define BRESS_H_
#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::cin;
using std::endl;
typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f, precis p);

class Brass {
  private:
    /* data */
    string name;
    long acctNum;
    double balance;
  public:
    Brass(const string & s = "Nullbody", long an = -1, double bal = 0.0);
    virtual ~Brass();
    void Deposit(double amt);
    virtual void Withdraw(double amt);
    double Balance() const;
    virtual void ViewAcct() const;
};

Brass::Brass(const string & s = "Nullbody", long an = -1, double bal = 0.0){
    name = s;
    acctNum = an;
    balance = bal;
}

void Brass::Deposit(double amt){
    if (amt < 0)
        cout << "Negative deposit not allowed; "
             << "deposit is canaelled." << endl;
    else
        balance += amt;
}

void Brass::ViewAcct() const {
    format initialState = setFormat();
    precis prec = cout.precision(2);

    cout << "Client: " << name << endl;
    cout << "Account Number: " << acctNum << endl;
    cout << "Balance: $" << balance << endl;
    restore(initialState, prec);
}

Brass::~Brass() {}

#endif