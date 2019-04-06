#ifndef CUSTOMER_H_
#define CUSTOMER_H_
#include <iostream>

class customer {
  private:
    /* data */
    long arrive;
    int processtime;

  public:
    customer(/* args */);
    void set(long when);
    long when() const { return arrive; }
    int ptime() const { return processtime; }
    ~customer();
};

customer::customer(/* args */) { arrive = processtime = 0; }

customer::~customer() {}

void customer::set(long when) {
    processtime = std::rand() % 3 + 1;
    arrive = when;
}

#endif