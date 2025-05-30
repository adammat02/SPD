#include <iostream>
#include "problem.h"

int main() {
    problem p("../test2j.dat");
    //p.print_maszyny();
    //std::cout << p.przegladZupelny() << std::endl;
    std::cout << "Neh: " << p.NEH() << std::endl;

    problem p3("../test2j.dat");
    //p.print_maszyny();
    //std::cout << p.przegladZupelny() << std::endl;
    std::cout << "Neh_2: " << p3.NEH() << std::endl;


    problem p2("../test2j.dat"); // zakładamy że masz 2 maszyny
    std::cout << "Johnson: " << p2.Johnson() << std::endl;
    return 0;
}