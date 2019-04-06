/*************************************************************************
    > File Name: main.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月02日 星期二 17时43分52秒
 ************************************************************************/

#include<iostream>
#include"time.h"
int main() {
    Time a(2, 4, 6);
    Time b(1, 2, 3);
    Time c = 1000;
    std::cout << a - b << std::endl;
    std::cout << a - b + 1000 << std::endl;
    std::cout << int(c) << std::endl;
    std::cout << int(1000 + c) << std::endl;
    std::cout << int(c + 1000) << std::endl;
    return 0;
}
