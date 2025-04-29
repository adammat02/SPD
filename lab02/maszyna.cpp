//
// Created by amatusia on 4/28/25.
//

#include "maszyna.h"

#include <iostream>
#include <ostream>

maszyna::maszyna(int id) : id(id) {}

int maszyna::getId() const {return id; }

void maszyna::dodajZadanie(const zadanie z) {
    zadaniaNaMaszynie.push_back(z);
}

void maszyna::wyczyscMaszyne() {
    zadaniaNaMaszynie.clear();
}

std::vector<zadanie> maszyna::getListaZadan() const { return zadaniaNaMaszynie; }

int maszyna::getCmax() const {
    int c_max = 0;
    for (int i = 0; i < zadaniaNaMaszynie.size(); i++) {
        c_max += zadaniaNaMaszynie[i].getPj();
    }
    return c_max;
}

void maszyna::wyswietlZawartosc() {
    std::cout << "Maszyna: " << id << std::endl;
    for (int i = 0; i < zadaniaNaMaszynie.size(); i++) {
        std::cout << zadaniaNaMaszynie[i].getPj() << std::endl;
    }
    std::cout << "----------------------------" << std::endl;
}

