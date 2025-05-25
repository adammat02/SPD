#include <iostream>
#include "problem.h"

int main() {
    problem p("../test2.dat");
    //p.print_maszyny();
    //std::cout << p.przegladZupelny() << std::endl;
    std::cout << p.NEH() << std::endl;
    return 0;
}