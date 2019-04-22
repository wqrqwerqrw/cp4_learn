#include<iostream>
#include"test.h"

int main(){
    test a("1");
    a.show();
    test b;
    b.show();
    test c("1", "2", "3");
    c.show();
    test d("1", "2");
    d.show();
    return 0;
}