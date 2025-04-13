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
    int schrage_queue();
    int schrage_queue_podzial();
    int schrage_vector();
    int schrage_vector_podzial();
    void r_minus_q_na_p();
};



#endif //PROBLEM_H
