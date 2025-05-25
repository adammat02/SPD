//
// Created by amatusia on 5/25/25.
//

#ifndef MASZYNA_H
#define MASZYNA_H

#include <vector>
#include "zadanie.h"

class maszyna {
    int id;
    std::vector<zadanie> zadaniaNaMaszynie;
public:
    explicit maszyna(int id);
    int getId() const;
    int getZadaniePj(int zad_id);
    void dodajZadanie(zadanie z);
    void wyczyscMaszyne();
    std::vector<zadanie> getListaZadan() const;
    void wyswietlZawartosc();

};



#endif //MASZYNA_H
