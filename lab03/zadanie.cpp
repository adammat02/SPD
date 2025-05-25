//
// Created by amatusia on 5/25/25.
//

#include "zadanie.h"

zadanie::zadanie(int id, int pj) : id(id), pj(pj) {}

int zadanie::getId() const {return id; }

int zadanie::getPj() const {return pj; }

void zadanie::setPj(int val) {
    pj = val;
}