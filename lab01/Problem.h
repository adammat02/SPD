//
// Created by amatusia on 3/31/25.
//

#ifndef PROBLEM_H
#define PROBLEM_H

#include "Zadanie.h"
#include <algorithm>
#include <vector>
#include <chrono>
#include <string>
#include <fstream>
#include <queue>

class Problem {
    std::vector<Zadanie> zadania;
    struct compareQ;
    struct compareR;

public:
    explicit Problem(const std::string &path);
    int calc_c() const;
    void heur_sort(float r, float q);
    std::vector<int> PrzegladZupelny();
    void print() const;
    int schrage();
    int schrage_podzial();
};



#endif //PROBLEM_H
