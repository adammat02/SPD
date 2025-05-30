//
// Created by amatusia on 5/25/25.
//

#ifndef PROBLEM_H
#define PROBLEM_H

#include "maszyna.h"
#include "zadanie.h"
#include <vector>
#include <string>

class problem {
    std::vector<maszyna> maszyny;
    std::vector<int> kolejnosc;
    int zadania_n;
    int maszyny_n;
public:
    problem(const std::string &path);
    void print_maszyny();
    int get_cmax(const std::vector<int>& lokalna_kolejnosc);
    int przegladZupelny();
    int NEH();
    int NEH_2();
    int Johnson();
    int lowerr(const std::vector<int>& kolejnosc); 
};


#endif //PROBLEM_H
