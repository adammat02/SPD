//
// Created by amatusia on 4/28/25.
//

#include "problem.h"
#include <math.h>
#include <algorithm>
#include <limits.h>

problem::problem(const std::string &path) {
    int zadania_n = 0;
    int maszyny_n = 0;
    std::ifstream file(path);
    file >> zadania_n >> maszyny_n;

    for (int i = 0; i < maszyny_n; i++) {
        maszyna m(i);
        maszyny.push_back(m);
    }
    for (int i = 0; i < zadania_n; i++) {
        int pj = 0;
        file >> pj;
        zadanie z(i, pj);
        listaWczytanychZadan.push_back(z);
    }
}

int problem::przegladZaupelny() {

    int n = listaWczytanychZadan.size();
    int limit = 1 << (n - 1);  // 2^(n-1) kombinacji
    int cmax1 = 0;
    int cmax2 = 0;
    int cmax = 0;
    int result = INT_MAX;

    for (int mask = 0; mask < limit; ++mask) {
        maszyny[0].wyczyscMaszyne();
        maszyny[1].wyczyscMaszyne();

        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                maszyny[0].dodajZadanie(listaWczytanychZadan[i]);
            } else {
                maszyny[1].dodajZadanie(listaWczytanychZadan[i]);
            }
        }
        cmax1 = maszyny[0].getCmax();
        cmax2 = maszyny[1].getCmax();
        cmax = std::max(cmax1, cmax2);
        result = std::min(result, cmax);
    }
    return result;
}



