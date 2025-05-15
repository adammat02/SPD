//
// Created by amatusia on 4/28/25.
//

#ifndef ZADANIE_H
#define ZADANIE_H


class zadanie {
    int id;
    double pj;
public:
    explicit zadanie(int id, int pj);
    int getId() const;
    double getPj() const;
    void setPj(double val);
};



#endif //ZADANIE_H
