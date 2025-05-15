//
// Created by amatusia on 4/28/25.
//

#include "zadanie.h"

zadanie::zadanie(int id, int pj) : id(id), pj(pj) {}

int zadanie::getId() const {return id; }

double zadanie::getPj() const {return pj; }

void zadanie::setPj(double val) {
    pj = val;
}


