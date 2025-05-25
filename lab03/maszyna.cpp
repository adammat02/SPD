//
// Created by amatusia on 5/25/25.
//

#include "maszyna.h"
#include <iostream>

maszyna::maszyna(int id) : id(id) {}

int maszyna::getId() const {return id; }

int maszyna::getZadaniePj(int zad_id) {
    return zadaniaNaMaszynie[zad_id].getPj();
}

void maszyna::dodajZadanie(const zadanie z) {
    zadaniaNaMaszynie.push_back(z);
}

void maszyna::wyczyscMaszyne() {
    zadaniaNaMaszynie.clear();
}

std::vector<zadanie> maszyna::getListaZadan() const { return zadaniaNaMaszynie; }


void maszyna::wyswietlZawartosc() {
    std::cout << "Maszyna: " << id << std::endl;
    for (int i = 0; i < zadaniaNaMaszynie.size(); i++) {
        std::cout << zadaniaNaMaszynie[i].getPj() << std::endl;
    }
    std::cout << "----------------------------" << std::endl;
}