#include "customer.h"
#include "queue.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

const int MIN_PER_HR = 60;

bool newcustomer(double x) { return (std::rand() * x / RAND_MAX < 1); }

int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;
    std::srand(std::time(0));
    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;
    queue line(qs);

    cout << "Enter the number of simulation hours: ";
    int hours;
    cin >> hours;
    long cyclelimit = MIN_PER_HR * hours;
    cout << "Enter the average number of customer per hour: ";
    double perhour;
    cin >> perhour;
    double min_per_cust;
    min_per_cust = MIN_PER_HR;

    customer tmp;
    long turraways = 0;
    long customers = 0;
    long served = 0;
    long sum_line = 0;
    int wait_time = 0;
    long line_wait = 0;

    for (int cycle = 0; cycle < cyclelimit; cycle++) {
        if (newcustomer(min_per_cust)) {
            if (line.isfull())
                turraways++;
            else {
                customers++;
                tmp.set(cycle);
                line.enqueue(tmp);
            }
        }

        if (wait_time <= 0 && !line.isempty()) {
            line.dequeue(tmp);
            wait_time = tmp.ptime();
            line_wait += cycle - tmp.when();
            served++;
        }

        if (wait_time > 0) {
            wait_time--;
        }

        sum_line += line.queuecount();
    }
    if (customers > 0) {
        cout << "customers accepted: " << customers << endl;
        cout << "   customers seved: " << served << endl;
        cout << "         turnaways: " << turraways << endl;
        cout << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double)sum_line / cyclelimit << endl;
        cout << " average wait time: ";
        cout << (double)line_wait / served << " minutesl" << endl;
    } else
        cout << "No customers!" << endl;
    cout << "Done!" << endl;
    return 0;
}