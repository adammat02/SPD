//
// Created by amatusia on 4/28/25.
//

#ifndef PROBLEM_H
#define PROBLEM_H

#include "maszyna.h"
#include "zadanie.h"
#include <vector>
#include <string>
#include <fstream>

class problem {
    std::vector<maszyna> maszyny;
    std::vector<zadanie> listaWczytanychZadan;
public:
    problem(const std::string &path);
    int przegladZaupelny();
    int LSA();
    int LPT();
};



#endif //PROBLEM_H
