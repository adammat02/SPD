#include <iostream>
#include <fstream>
#include <vector>
#include "Zadanie.h"
#include "Problem.h"

int main() {
    std::vector<Zadanie> zadania;
    int n = 0;

    std::ifstream file("../schrage/SCHRAGE2.DAT");
    file >> n;

    for (int j = 0; j < n; j++) {
        int p, r, q;
        file >> r >> p >> q;
        zadania.emplace_back(j, p, r, q);
    }

    Problem problem(zadania);

    problem.heur_sort(1,0);

    std::cout << "Cmax: " << problem.calc_c() << std::endl;

    std::vector<int> out = problem.PrzegladZupelny();

    std::cout << "Najlepsze rozwiazanie: " << out[0] << std::endl;
    std::cout << "czas " << out[1] << std::endl;

    return 0;
}