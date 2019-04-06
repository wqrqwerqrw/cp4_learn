#ifndef QUEUE_H_
#define QUEUE_H_
#include <iostream>

class queue {
  private:
    /* data */
    enum { Q_SIZE = 10 };
    struct node {
        customer value;
        node *next;
    };
    const int qsize;
    node *front;
    node *rear;
    int customers;
    // 阻止复制
    queue(const queue &q) : qsize(0) {}
    queue &operator=(const queue &q) { return *this; }

  public:
    queue(int qs = Q_SIZE);
    ~queue();
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const customer &in);
    bool dequeue(customer &in);
    customer top() const;
};

queue::queue(int qs) : qsize(qs), front(nullptr), rear(NULL), customers(0) {}

queue::~queue() {
    node * tmp;
    while(front != nullptr){
        tmp = front;
        front = front -> next;
        delete front;
    }
}

bool queue::isempty() const { return customers == 0; }

bool queue::isfull() const { return customers == qsize; }

int queue::queuecount() const { return customers; }

bool queue::enqueue(const customer &in) {
    if (isfull())
        return false;
    node *toadd = new node;
    toadd->value = in;
    toadd->next = nullptr;
    customers++;
    if (front == nullptr)
        front = toadd;
    else
        rear->next = toadd;
    rear = toadd;
    return true;
}

bool queue::dequeue(customer &in) {
    if (isempty())
        return false;
    in = front->value;
    customers--;
    node *tmp = front;
    front = front->next;
    delete tmp;
    if (isempty())
        rear == nullptr;
    return true;
}

customer queue::top() const { return front->value; }

#endif