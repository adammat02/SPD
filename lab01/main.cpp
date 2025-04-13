#include <iostream>
#include "Problem.h"

int main() {

    Problem problem("../schrage/SCHRAGE3.DAT");

    //problem.heur_sort(1,-1);

    std::cout << "Heur cmax: " << problem.calc_c() << std::endl;

    // std::vector<int> out = problem.PrzegladZupelny();
    //
    // std::cout << "Najlepsze rozwiazanie: " << out[0] << std::endl;
    // std::cout << "czas " << out[1] << std::endl;
    auto start1 = std::chrono::high_resolution_clock::now();
    std::cout << "Schrage: " << problem.schrage_queue() << std::endl;
    auto end1 = std::chrono::high_resolution_clock::now();
    std::cout<<"czas wyk1: "<<std::chrono::duration<double, std::milli>(end1-start1).count()<<std::endl;
    auto start2 = std::chrono::high_resolution_clock::now();
    std::cout << "Schrage: " << problem.schrage_vector() << std::endl;
    auto end2 = std::chrono::high_resolution_clock::now();
    std::cout<<"czas wyk2: "<<std::chrono::duration<double, std::milli>(end2-start2).count()<<std::endl;

    auto start3 = std::chrono::high_resolution_clock::now();
    std::cout << "Schrage: " << problem.schrage_queue_podzial() << std::endl;
    auto end3 = std::chrono::high_resolution_clock::now();
    std::cout<<"czas wyk3: "<<std::chrono::duration<double, std::milli>(end3-start3).count()<<std::endl;
    auto start4 = std::chrono::high_resolution_clock::now();
    std::cout << "Schrage: " << problem.schrage_vector_podzial() << std::endl;
    auto end4 = std::chrono::high_resolution_clock::now();
    std::cout<<"czas wyk4: "<<std::chrono::duration<double, std::milli>(end4-start4).count()<<std::endl;

    auto start5=std::chrono::high_resolution_clock::now();
    problem.r_minus_q_na_p();
    std::cout<<"Heur cmax dla (r-q)/p: "<<problem.calc_c()<<std::endl;
    auto end5=std::chrono::high_resolution_clock::now();
    std::cout<<"czas (r-q)/p: "<<std::chrono::duration<double,std::milli>(end5-start5).count()<<std::endl;

    return 0;
}