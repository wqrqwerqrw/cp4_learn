#ifndef BRESSPLUS_H_
#define BRESSPLUS_H_
#include"brass.h"
#include<iostream>
#include<string>
using std::string;

class BrassPlus {
  private:
    /* data */
    double maxLoan;
    double rate;
    double owesBank;
  public:
    BrassPlus(const string &s = "Nullbody", long an = -1, double bal = 0.0,
              double ml = 500, double r = 0.11125);
    BrassPlus(const Brass &ba, double ml = 500, double r = 0.11125);
    virtual void ViewAcct() const;
    virtual void Withdraw(double amt);
    void ResetMax(double m) { maxLoan = m; }
    void ResetRate(double r) { rate = r; }
    void ResetOwes() { owesBank = 0; }
    ~BrassPlus();
};


BrassPlus::~BrassPlus() {}

#endif