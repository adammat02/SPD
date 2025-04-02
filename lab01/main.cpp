#include <iostream>
#include "Problem.h"

int main() {

    Problem problem("../schrage/SCHRAGE1.DAT");

    problem.heur_sort(1,-1);

    std::cout << "Heur cmax: " << problem.calc_c() << std::endl;

    // std::vector<int> out = problem.PrzegladZupelny();
    //
    // std::cout << "Najlepsze rozwiazanie: " << out[0] << std::endl;
    // std::cout << "czas " << out[1] << std::endl;

    std::cout << "Schrage: " << problem.schrage() << std::endl;
    std::cout << "Schrage_pod: " << problem.schrage_podzial() << std::endl;

    return 0;
}