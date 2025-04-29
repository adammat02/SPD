#include <iostream>
#include "problem.h"

/*
 *      Format danych w .DAT
 *
 *      liczba_zadan liczba_maszyn
 *      zad_1
 *      zad_2
 *      ...
 *      zad_n
 *
 *      Narazie przeglad zupelny dziala tylko dla dwoch maszyn
 */

int main() {

    problem p("../TEST.DAT");

    std::cout << "cmax: " << p.przegladZaupelny() << std::endl;

    return 0;
}