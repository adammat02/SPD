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
    int limit = 1 << n; 
    int cmax1 = 0;
    int cmax2 = 0;
    int cmax = 0;
    int result = INT_MAX;

    for (int mask = 0; mask < limit; ++mask) {
        for (int i = 0; i < maszyny.size(); ++i) {
            maszyny[i].wyczyscMaszyne();
        }

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




int problem::LSA() {
    for (int i = 0; i < maszyny.size(); ++i) {
        maszyny[i].wyczyscMaszyne();
    }
    for (int j = 0; j < listaWczytanychZadan.size(); ++j) {
        int min_index = 0;
        for (int i = 1; i < maszyny.size(); ++i){
            if (maszyny[i].getCmax() < maszyny[min_index].getCmax()){
                min_index = i;
            }
        }
        maszyny[min_index].dodajZadanie(listaWczytanychZadan[j]);
    }
    int wynik = 0;
    for (int i = 0; i < maszyny.size(); ++i) {
        int tempcmax = maszyny[i].getCmax();
        if (tempcmax > wynik) {
            wynik = tempcmax;
        }
    }
    return wynik;
}


int problem::LPT() {
    std::vector<zadanie> zadania = listaWczytanychZadan;
    std::sort(zadania.begin(), zadania.end(),[](const zadanie &a, const zadanie &b) {
        return a.getPj() > b.getPj();
    });
    for (int i = 0; i < maszyny.size(); ++i) {
        maszyny[i].wyczyscMaszyne();
    }
    for (int j = 0; j < zadania.size(); ++j) {
        int min_index = 0;
        for (int i = 1; i < maszyny.size(); ++i)
            if (maszyny[i].getCmax() < maszyny[min_index].getCmax()){
                min_index = i;
            }
        maszyny[min_index].dodajZadanie(zadania[j]);
    }
    int wynik = 0;
    for (const auto &m : maszyny){
        if (m.getCmax() > wynik){
            wynik = m.getCmax();
        }
    }
    return wynik;
}




