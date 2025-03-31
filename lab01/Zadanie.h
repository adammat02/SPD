//
// Created by amatusia on 3/31/25.
//

#ifndef ZADANIE_H
#define ZADANIE_H

#include <iostream>

class Zadanie {
    int n;
    int pj;
    int rj;
    int qj;
public:
    Zadanie(int n, int pj, int rj, int qj);
    int get_n() const;
    int get_pj() const;
    int get_rj() const;
    int get_qj() const;
    void print() const;
};



#endif //ZADANIE_H
