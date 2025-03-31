#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>

class Zadanie {
    int n;
    int pj;
    int rj;
    int qj;
public:
    Zadanie(int n, int pj, int rj, int qj);
    int get_n() const;
    int get_pj() const;
    int get_rj() const;
    int get_qj() const;
    void print() const;
};

Zadanie::Zadanie(int n, int pj, int rj, int qj): n(n), pj(pj), rj(rj), qj(qj) {};
int Zadanie::get_n() const {return n;}
int Zadanie::get_pj() const {return pj;}
int Zadanie::get_rj() const {return rj;}
int Zadanie::get_qj() const {return qj;}
void Zadanie::print() const {
    std::cout << n << " " << pj << " " << rj << " " << qj << std::endl;
}

class Problem {
    std::vector<Zadanie> zadania;

public:
    explicit Problem(const std::vector<Zadanie>& zad);
    int calc_c() const;
    void heur_sort(float r, float q);
    std::vector<int> PrzegladZupelny();
    void print() const;
};

Problem::Problem(const std::vector<Zadanie>& zad): zadania(zad) {}
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


int main() {
    std::vector<Zadanie> zadania;
    int n = 0;

    std::ifstream file("../schrage/SCHRAGE2.DAT");
    file >> n;

    for (int j = 0; j < n; j++) {
        int p, r, q;
        file >> r >> p >> q;
        zadania.emplace_back(j, p, r, q);
    }

    Problem problem(zadania);

    problem.heur_sort(1,0);

    std::cout << "Cmax: " << problem.calc_c() << std::endl;

    std::vector<int> out = problem.PrzegladZupelny();

    std::cout << "Najlepsze rozwiazanie: " << out[0] << std::endl;
    std::cout << "czas " << out[1] << std::endl;

    return 0;
}