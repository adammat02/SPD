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
    explicit Zadanie(int n=-1, int pj=0, int rj=0, int qj=0);
    int get_n() const;
    int get_pj() const;
    void set_pj(int val);
    int get_rj() const;
    int get_qj() const;
    void print() const;
};



#endif //ZADANIE_H
