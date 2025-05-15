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
    void przegladZaupelny_lok(std::vector<zadanie> z);
public:
    problem(const std::string &path);
    int przegladZaupelny();
    int LSA();
    int LPT();
    int PD();
    int PTAS(int k);
    int FPTAS(int k);
};



#endif //PROBLEM_H
