//
// Created by amatusia on 5/25/25.
//

#ifndef ZADANIE_H
#define ZADANIE_H



class zadanie {
    int id;
    int pj;
public:
    explicit zadanie(int id, int pj);
    int getId() const;
    int getPj() const;
    void setPj(int val);
};



#endif //ZADANIE_H
