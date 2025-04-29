//
// Created by amatusia on 4/28/25.
//

#ifndef MASZYNA_H
#define MASZYNA_H

#include "zadanie.h"
#include <vector>

class maszyna {
    int id;
    std::vector<zadanie> zadaniaNaMaszynie;
public:
    explicit maszyna(int id);
    int getId() const;
    void dodajZadanie(zadanie z);
    void wyczyscMaszyne();
    std::vector<zadanie> getListaZadan() const;
    int getCmax() const;
    void wyswietlZawartosc();

};



#endif //MASZYNA_H
