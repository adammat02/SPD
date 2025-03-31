//
// Created by amatusia on 3/31/25.
//

#include "Zadanie.h"

Zadanie::Zadanie(int n, int pj, int rj, int qj): n(n), pj(pj), rj(rj), qj(qj) {};

int Zadanie::get_n() const {return n;}

int Zadanie::get_pj() const {return pj;}

int Zadanie::get_rj() const {return rj;}

int Zadanie::get_qj() const {return qj;}

void Zadanie::print() const {
    std::cout << n << " " << pj << " " << rj << " " << qj << std::endl;
}