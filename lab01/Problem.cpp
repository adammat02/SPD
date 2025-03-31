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