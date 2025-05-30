//
// Created by amatusia on 5/25/25.
//

#include "problem.h"
#include <math.h>
#include <algorithm>
#include <limits.h>
#include <fstream>
#include <iostream>


problem::problem(const std::string &path) {

    std::ifstream file(path);
    file >> zadania_n >> maszyny_n;
    for (int i = 0; i < maszyny_n; i++) {
        maszyna m(i);
        maszyny.push_back(m);
    }
    for (int i = 0; i < zadania_n; i++) {
        int pj;
        int maszyna_id;
        kolejnosc.push_back(i);
        for (int j = 0; j < maszyny_n; j++) {
            file >> maszyna_id >> pj;
            zadanie z(i, pj);
            maszyny[maszyna_id].dodajZadanie(z);
        }
    }
}

void problem::print_maszyny() {
    for (int i = 0; i < maszyny.size(); i++) {
        maszyny[i].wyswietlZawartosc();
    }
    std::cout << "Kolejnosc: ";
    for (int i = 0; i < kolejnosc.size(); i++) {
        std::cout << kolejnosc[i] << ", ";
    }
    std::cout << std::endl;
}

int problem::get_cmax(const std::vector<int>& lokalna_kolejnosc) {
    std::vector<int> cmaxes(maszyny_n, 0);

    for (int i = 0; i < lokalna_kolejnosc.size(); i++) {
        for (int j = 0; j < maszyny_n; j++) {
            if (j == 0) {
                cmaxes[j] += maszyny[j].getZadaniePj(lokalna_kolejnosc[i]);
            } else {
                cmaxes[j] = std::max(cmaxes[j - 1], cmaxes[j]) + maszyny[j].getZadaniePj(lokalna_kolejnosc[i]);
            }
        }
    }

    return cmaxes[maszyny_n - 1];
}

int problem::przegladZupelny() {
    std::vector<int> kopia_kolejnosc = kolejnosc;

    int cmax_min = get_cmax(kopia_kolejnosc);

    while (std::next_permutation(kopia_kolejnosc.begin(), kopia_kolejnosc.end())) {
        cmax_min = std::min(cmax_min, get_cmax(kopia_kolejnosc));
    }

    return cmax_min;
}

int problem::NEH() {

    std::vector<std::pair<int, int>> suma_zadan;
    for (int i = 0; i < zadania_n; ++i) {
        int suma = 0;
        for (int j = 0; j < maszyny_n; ++j) {
            suma += maszyny[j].getZadaniePj(i);
        }
        suma_zadan.push_back({i, suma});
    }

    //Sortowanie malejąco po sumie
    std::sort(suma_zadan.begin(), suma_zadan.end(),
              [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
                  return a.second > b.second;
              });

    std::vector<int> najlepsza_kolejnosc;
    for (int i = 0; i < suma_zadan.size(); ++i) {
        int zad = suma_zadan[i].first;
        int najlepszy_cmax = INT_MAX;
        std::vector<int> najlepsza_tmp;

        // Wstawianie zadania na każdą możliwą pozycję
        for (int pos = 0; pos <= najlepsza_kolejnosc.size(); ++pos) {
            std::vector<int> tmp = najlepsza_kolejnosc;
            tmp.insert(tmp.begin() + pos, zad);
            int cmax = get_cmax(tmp);
            if (cmax < najlepszy_cmax) {
                najlepszy_cmax = cmax;
                najlepsza_tmp = tmp;
            }
        }
        najlepsza_kolejnosc = najlepsza_tmp;
    }

    return get_cmax(najlepsza_kolejnosc);
}

int problem::Johnson(){

    std::vector<int>L,R;
    for(int i=0;i<zadania_n;++i){
        int p1=maszyny[0].getZadaniePj(i);
        int p2=maszyny[1].getZadaniePj(i);

        if(p1<=p2){
            L.push_back(i);
        }
        else{
            R.push_back(i);
        }
    }

    std::sort(L.begin(),L.end(),[&](int a,int b){
        return maszyny[0].getZadaniePj(a)<maszyny[0].getZadaniePj(b);
    });

    std::sort(R.begin(),R.end(),[&](int a,int b){
        return maszyny[1].getZadaniePj(a)>maszyny[1].getZadaniePj(b);
    });

    std::vector<int> pi;
    pi.insert(pi.end(),L.begin(),L.end());
    pi.insert(pi.end(),R.begin(),R.end());

    return get_cmax(pi);
}


int problem::lowerr(const std::vector<int>& kolejnosc) {
    std::vector<int> suma_maszyn(maszyny_n,0);
    for(int i=0;i<kolejnosc.size();i++){
        int id_zad=kolejnosc[i];
        for(int j=0;j<maszyny_n;j++){
            suma_maszyn[j]+=maszyny[j].getZadaniePj(id_zad);
        }
    }
    int max_suma=0;
    for(int i=0;i<suma_maszyn.size();i++){
        if(suma_maszyn[i]>max_suma){
            max_suma=suma_maszyn[i];
        }
    }
    return max_suma;
}



int problem::NEH_2() {
    std::vector<std::pair<int, int>> suma_zadan;
    for (int i = 0; i < zadania_n; ++i) {
        int suma = 0;
        for (int j = 0; j < maszyny_n; ++j) {
            suma += maszyny[j].getZadaniePj(i);
        }
        suma_zadan.push_back({i, suma});
    }

    //Sortowanie malejąco po sumie
    std::sort(suma_zadan.begin(), suma_zadan.end(),
              [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
                  return a.second > b.second;
              });

    std::vector<int> najlepsza_kolejnosc;
    for (int i = 0; i < suma_zadan.size(); ++i) {
        int zad = suma_zadan[i].first;
        int najlepszy_cmax = INT_MAX;
        std::vector<int> najlepsza_tmp;

        // Wstawianie zadania na każdą możliwą pozycję
        for (int pos = 0; pos <= najlepsza_kolejnosc.size(); ++pos) {
            std::vector<int> tmp = najlepsza_kolejnosc;
            tmp.insert(tmp.begin() + pos, zad);

            int lb=lowerr(tmp);
            if(lb<=najlepszy_cmax){
                int cmax=get_cmax(tmp);
                if(cmax<najlepszy_cmax){
                    najlepszy_cmax=cmax;
                    najlepsza_tmp=tmp;
                }
            }


            int cmax = get_cmax(tmp);
            if (cmax < najlepszy_cmax) {
                najlepszy_cmax = cmax;
                najlepsza_tmp = tmp;
            }
        }
        najlepsza_kolejnosc = najlepsza_tmp;
    }

    return get_cmax(najlepsza_kolejnosc);
}




























