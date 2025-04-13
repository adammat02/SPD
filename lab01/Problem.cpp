//
// Created by amatusia on 3/31/25.
//

#include "Problem.h"

Problem::Problem(const std::string &path) {
    int n = 0;
    std::ifstream file(path);
    file >> n;

    for (int j = 0; j < n; j++) {
        int p, r, q;
        file >> r >> p >> q;
        zadania.emplace_back(j, p, r, q);
    }
}

int Problem::calc_c() const {
    int cq_max = 0;
    int cpi = 0;
    for (int i = 0; i < zadania.size(); i++) {
        if (i == 0) {
            cpi = zadania[i].get_rj() + zadania[i].get_pj();
        } else {
            cpi = std::max(zadania[i].get_rj(), cpi) + zadania[i].get_pj();
        }
        cq_max = std::max(cq_max, cpi + zadania[i].get_qj());
    }
    return cq_max;
}

void Problem::heur_sort(float r, float q) {
    std::sort(zadania.begin(), zadania.end(),
        [r, q](const Zadanie &z1, const Zadanie &z2) {
            return (r * z1.get_rj() + q * z1.get_qj()) < (r * z2.get_rj() + q * z2.get_qj());
        });
}

std::vector<int> Problem::PrzegladZupelny() {

    std::vector<int> output;

    std::sort(zadania.begin(), zadania.end(),
        [](const Zadanie &z1, const Zadanie &z2) {return (z1.get_n() < z2.get_n()); });

    auto start = std::chrono::high_resolution_clock::now();

    int cq_min = calc_c();

    while (std::next_permutation(zadania.begin(), zadania.end(),
        [](const Zadanie &z1, const Zadanie &z2) {return (z1.get_n() < z2.get_n()); })) {
        cq_min = std::min(cq_min, calc_c());
        }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    int time = (int)duration.count();
    output.push_back(cq_min);
    output.push_back(time);
    return output;
}

void Problem::print() const {
    for (auto i : zadania) {
        i.print();
    }
}

struct Problem::compareQ {
    bool operator()(const Zadanie &z1, const Zadanie &z2) {
        return z1.get_qj() < z2.get_qj();
    }
};

struct Problem::compareR {
    bool operator()(const Zadanie &z1, const Zadanie &z2) {
        return z1.get_rj() > z2.get_rj();
    }
};

int Problem::schrage_queue() {

    std::priority_queue<Zadanie, std::vector<Zadanie>, compareR> notReady(zadania.begin(), zadania.end());
    std::priority_queue<Zadanie, std::vector<Zadanie>, compareQ> Ready;
    std::vector<Zadanie> z;

    int t = 0;
    int cmax = 0;
    int cqmax = 0;

    while (!Ready.empty() || !notReady.empty()) {

        while (!notReady.empty() && notReady.top().get_rj() <= t) {
            Ready.push(notReady.top());
            notReady.pop();
        }

        if (!Ready.empty()) {
            Zadanie tmp = Ready.top();
            Ready.pop();

            z.push_back(tmp);
            t += tmp.get_pj();
            cmax = t + tmp.get_qj();
            cqmax = std::max(cqmax, cmax);
        } else if (!notReady.empty()) {
            t = notReady.top().get_rj();
        }
    }
    return cqmax;
}

int Problem::schrage_vector(){
    std::vector<Zadanie>N=zadania;
    std::vector<Zadanie>G;

    int t=0;
    int Cmax=0;

    std::sort(N.begin(),N.end(),[](Zadanie &a, Zadanie &b){
        return a.get_rj()<b.get_rj();
    });
    while((G.size()>0)||(N.size()>0)){
        while((N.size()>0)&&(N[0].get_rj()<=t)){
            G.push_back(N[0]);
            N.erase(N.begin());
        }
        if(G.size()==0){
            t=N[0].get_rj();
        } 
        else{
            int max_q_index=0;
            for(int i=1;i<G.size();i++){
                if(G[i].get_qj()>G[max_q_index].get_qj()){
                    max_q_index=i;
                }
            }
            t=t+G[max_q_index].get_pj();
            int c=t+G[max_q_index].get_qj();
            if(c>Cmax){
                Cmax=c;
            }
            G.erase(G.begin()+max_q_index);
        }
    }
    return Cmax;
}

int Problem::schrage_vector_podzial(){
    std::vector<Zadanie>N=zadania;
    std::vector<Zadanie>G;

    int t=0;
    int Cmax=0;

    // fikcyjne aktualnie wykonywane zadanie
    Zadanie l;
    std::sort(N.begin(), N.end(), [](const Zadanie &a, const Zadanie &b) {
        return a.get_rj() < b.get_rj();
    });
    while(G.size()>0||N.size()>0){
        while((N.size()>0)&&(N[0].get_rj()<=t)){
            G.push_back(N[0]);
            if(N[0].get_qj()>l.get_qj()){
                l.set_pj(t-N[0].get_rj());
                t=N[0].get_rj();
                if(l.get_pj()>0){
                    G.push_back(l);
                }
            }
            N.erase(N.begin());
        }
        if(G.size()==0){
            if(N.size()>0){
                t=N[0].get_rj();
            }
        } 
        else{
            int max_q_index=0;
            for(int i=1;i<G.size();i++){
                if(G[i].get_qj()>G[max_q_index].get_qj()){
                    max_q_index=i;
                }
            }
            t=t+G[max_q_index].get_pj();
            int c=t+G[max_q_index].get_qj();
            if(c>Cmax){
                Cmax=c;
            }
            G.erase(G.begin()+max_q_index);
        }
    }

    return Cmax;
}


int Problem::schrage_queue_podzial() {

    std::priority_queue<Zadanie, std::vector<Zadanie>, compareR> notReady(zadania.begin(), zadania.end());
    std::priority_queue<Zadanie, std::vector<Zadanie>, compareQ> Ready;
    Zadanie l;

    int t = 0;
    int cmax = 0;
    int cqmax = 0;

    while (!Ready.empty() || !notReady.empty()) {

        while (!notReady.empty() && notReady.top().get_rj() <= t) {
            Ready.push(notReady.top());
            notReady.pop();
        }

        if (!Ready.empty()) {

            if (Ready.top().get_qj() > l.get_qj()) {
                l.set_pj(t - Ready.top().get_rj());
                t = Ready.top().get_rj();

                if (l.get_pj() > 0) {
                    Ready.push(l);
                }
            }

            Zadanie tmp = Ready.top();
            Ready.pop();

            l = Ready.top();
            t += tmp.get_pj();
            cmax = t + tmp.get_qj();
            cqmax = std::max(cqmax, cmax);
        } else if (!notReady.empty()) {
            t = notReady.top().get_rj();
        }
    }
    return cqmax;
}


void Problem::r_minus_q_na_p(){
    std::sort(zadania.begin(),zadania.end(),[](const Zadanie &a,const Zadanie &b){
            float waga_a=(float)(a.get_rj()-a.get_qj())/a.get_pj();
            float waga_b=(float)(b.get_rj()-b.get_qj())/b.get_pj();
            return waga_a<waga_b;
        });
}
