#include <iostream>
#include "Problem.h"

int main() {

    Problem problem("../schrage/SCHRAGE2.DAT");

    problem.heur_sort(1,0);

    std::cout << "Cmax: " << problem.calc_c() << std::endl;

    std::vector<int> out = problem.PrzegladZupelny();

    std::cout << "Najlepsze rozwiazanie: " << out[0] << std::endl;
    std::cout << "czas " << out[1] << std::endl;

    return 0;
}