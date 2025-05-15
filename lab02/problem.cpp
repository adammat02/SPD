//
// Created by amatusia on 4/28/25.
//

#include "problem.h"
#include <math.h>
#include <algorithm>
#include <limits.h>

problem::problem(const std::string &path) {
    int zadania_n = 0;
    int maszyny_n = 0;
    std::ifstream file(path);
    file >> zadania_n >> maszyny_n;

    for (int i = 0; i < maszyny_n; i++) {
        maszyna m(i);
        maszyny.push_back(m);
    }
    for (int i = 0; i < zadania_n; i++) {
        int pj = 0;
        file >> pj;
        zadanie z(i, pj);
        listaWczytanychZadan.push_back(z);
    }
}

int problem::przegladZaupelny() {

    int n = listaWczytanychZadan.size();
    int limit = 1 << n;
    int cmax1 = 0;
    int cmax2 = 0;
    int cmax = 0;
    int result = INT_MAX;

    for (int mask = 0; mask < limit; ++mask) {
        for (int i = 0; i < maszyny.size(); ++i) {
            maszyny[i].wyczyscMaszyne();
        }

        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                maszyny[0].dodajZadanie(listaWczytanychZadan[i]);
            } else {
                maszyny[1].dodajZadanie(listaWczytanychZadan[i]);
            }
        }
        int wynik = 0;
        for (int i = 0; i < maszyny.size(); ++i) {
            int tempcmax = maszyny[i].getCmax();
            if (tempcmax > wynik) {
                wynik = tempcmax;
            }
        }
        result = std::min(result, wynik);
    }
    return result;
}

void problem::przegladZaupelny_lok(std::vector<zadanie> z) {

    int n = z.size();
    int limit = 1 << n;
    int min = INT_MAX;
    int result = INT_MAX;
    maszyna m0(0);
    maszyna m1(1);


    for (int mask = 0; mask < limit; ++mask) {
        for (int i = 0; i < maszyny.size(); ++i) {
            maszyny[i].wyczyscMaszyne();
        }

        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                maszyny[0].dodajZadanie(z[i]);
            } else {
                maszyny[1].dodajZadanie(z[i]);
            }
        }
        int wynik = 0;
        for (int i = 0; i < maszyny.size(); ++i) {
            int tempcmax = maszyny[i].getCmax();
            if (tempcmax > wynik) {
                wynik = tempcmax;
            }
        }
        result = std::min(result, wynik);
        if (result < min) {
            min = result;
            m0 = maszyny[0];
            m1 = maszyny[1];
        }
    }
    for (int i = 0; i < maszyny.size(); ++i) {
        maszyny[i].wyczyscMaszyne();
    }
    maszyny[0] = m0;
    maszyny[1] = m1;
}





int problem::LSA() {
    for (int i = 0; i < maszyny.size(); ++i) {
        maszyny[i].wyczyscMaszyne();
    }
    for (int j = 0; j < listaWczytanychZadan.size(); ++j) {
        int min_index = 0;
        for (int i = 1; i < maszyny.size(); ++i){
            if (maszyny[i].getCmax() < maszyny[min_index].getCmax()){
                min_index = i;
            }
        }
        maszyny[min_index].dodajZadanie(listaWczytanychZadan[j]);
    }
    int wynik = 0;
    for (int i = 0; i < maszyny.size(); ++i) {
        int tempcmax = maszyny[i].getCmax();
        if (tempcmax > wynik) {
            wynik = tempcmax;
        }
    }
    return wynik;
}


int problem::LPT() {
    std::vector<zadanie> zadania = listaWczytanychZadan;
    std::sort(zadania.begin(), zadania.end(),[](const zadanie &a, const zadanie &b) {
        return a.getPj() > b.getPj();
    });
    for (int i = 0; i < maszyny.size(); ++i) {
        maszyny[i].wyczyscMaszyne();
    }
    for (int j = 0; j < zadania.size(); ++j) {
        int min_index = 0;
        for (int i = 1; i < maszyny.size(); ++i)
            if (maszyny[i].getCmax() < maszyny[min_index].getCmax()){
                min_index = i;
            }
        maszyny[min_index].dodajZadanie(zadania[j]);
    }
    int wynik = 0;
    for (int i = 0; i < maszyny.size(); ++i) {
        int tempcmax = maszyny[i].getCmax();
        if (tempcmax > wynik) {
            wynik = tempcmax;
        }
    }
    return wynik;
}

int problem::PD() {
    int Sum=0;
    for (int i=0;i<listaWczytanychZadan.size();i++){
        Sum=Sum+listaWczytanychZadan[i].getPj();
    }
    int K=Sum/2+1;
    std::vector<std::vector<bool>>dp(listaWczytanychZadan.size()+1,std::vector<bool>(K,0));
    dp[0][0]=1;
    for(int i=1;i<=listaWczytanychZadan.size();++i){
        int p=listaWczytanychZadan[i-1].getPj();
        for(int j=0;j<K;++j){
            dp[i][j]=dp[i-1][j];
            if((j>=p)&&(dp[i-1][j-p]==1)){
                dp[i][j]=1;
            }
        }
    }
    int best=0;
    for(int j=K-1;j>=0;--j){
        if(dp[listaWczytanychZadan.size()][j]==1){
            best=j;
            j=-1;
        }
    }
    int Cmax=std::max(best,Sum-best);
    return Cmax;
}

int problem::PTAS(int k) {
    for (int i = 0; i < maszyny.size(); ++i) {
        maszyny[i].wyczyscMaszyne();
    }

    std::vector<zadanie> zadania = listaWczytanychZadan;
    std::sort(zadania.begin(), zadania.end(),[](const zadanie &a, const zadanie &b) {
        return a.getPj() > b.getPj();
    });

    std::vector<zadanie> duzeZadania;
    std::vector<zadanie> maleZadania;

    for (int i = 0; i < zadania.size(); ++i) {
        if (i < k) {
            duzeZadania.push_back(zadania[i]);
        } else {
            maleZadania.push_back(zadania[i]);
        }
    }

    przegladZaupelny_lok(duzeZadania);

    for (int j = 0; j < maleZadania.size(); ++j) {
        int min_index = 0;
        for (int i = 1; i < maszyny.size(); ++i){
            if (maszyny[i].getCmax() < maszyny[min_index].getCmax()){
                min_index = i;
            }
        }
        maszyny[min_index].dodajZadanie(maleZadania[j]);
    }

    int wynik = 0;
    for (int i = 0; i < maszyny.size(); ++i) {
        int tempcmax = maszyny[i].getCmax();
        if (tempcmax > wynik) {
            wynik = tempcmax;
        }
    }
    return wynik;

}

int problem::FPTAS(int k) {
    std::vector<zadanie> zadania = listaWczytanychZadan;
    for (int j = 0; j < zadania.size(); ++j) {
        zadania[j].setPj(zadania[j].getPj()/k);
    }

    double Sum=0;
    for (int i=0;i<zadania.size();i++){
        Sum=Sum+zadania[i].getPj();
    }
    double K=Sum/2+1;
    std::vector<std::vector<bool>>dp(zadania.size()+1,std::vector<bool>(K,0));
    dp[0][0]=1;
    for(int i=1;i<=zadania.size();++i){
        double p=zadania[i-1].getPj();
        for(int j=0;j<K;++j){
            dp[i][j]=dp[i-1][j];
            if((j>=p)&&(dp[i-1][j-p]==1)){
                dp[i][j]=1;
            }
        }
    }
    double best=0;
    for(int j=K-1;j>=0;--j){
        if(dp[zadania.size()][j]==1){
            best=j;
            j=-1;
        }
    }
    double Cmax=std::max(best,Sum-best);
    return Cmax*k;
}








