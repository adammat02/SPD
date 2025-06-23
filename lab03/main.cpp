#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include "problem.h"

int main()
{

    // Czesc kodu dla wygenerowanych testow

    std::vector<std::string> files = {
        "test3x2.dat",
        "test4x2.dat",
        "test6x2.dat",
        "test8x2.dat",
        "test10x2.dat",
        "test11x2.dat"

        // Dodaj więcej plików, jeśli istnieją
    };

    // for (const auto &file : files)
    // {
    //     std::cout << "Processing file: " << file << std::endl;
    //
    //     problem p(file);
    //
    //     auto start = std::chrono::high_resolution_clock::now();
    //     int p_zup = p.przegladZupelny();
    //     auto end = std::chrono::high_resolution_clock::now();
    //     auto p_zup_time = std::chrono::duration<double, std::milli>(end - start).count();
    //
    //     std::cout << "p_zup: " << p_zup << " time: " << p_zup_time << std::endl;
    //
    //     start = std::chrono::high_resolution_clock::now();
    //     int neh = p.NEH();
    //     end = std::chrono::high_resolution_clock::now();
    //     auto neh_time = std::chrono::duration<double, std::milli>(end - start).count();
    //
    //     std::cout << "neh: " << neh << ", time: " << neh_time << ", error: " << static_cast<double>(std::abs(neh - p_zup)) / p_zup * 100 << "%" << std::endl;
    //
    //     start = std::chrono::high_resolution_clock::now();
    //     int fneh = p.NEH_2();
    //     end = std::chrono::high_resolution_clock::now();
    //     auto fneh_time = std::chrono::duration<double, std::milli>(end - start).count();
    //
    //     std::cout << "fneh: " << fneh << ", time: " << fneh_time << ", error: " << static_cast<double>(std::abs(fneh - p_zup)) / p_zup * 100 << "%" << std::endl;
    //
    //     start = std::chrono::high_resolution_clock::now();
    //     int jh = p.Johnson();
    //     end = std::chrono::high_resolution_clock::now();
    //     auto jh_time = std::chrono::duration<double, std::milli>(end - start).count();
    //
    //     std::cout << "jh: " << jh << ", time: " << jh_time << ", error: " << static_cast<double>(std::abs(jh - p_zup)) / p_zup * 100 << "%" << std::endl;
    //
    //     std::cout << "----------------------------------------" << std::endl;
    // }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "################## Taillard #######################" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    // Czesc kodu dla plikow Taillard, tylko neh i fneh

    files = {
        "test20x5.dat",
        "test20x10.dat",
        "test20x20.dat",
        "test50x5.dat",
        "test50x10.dat",
        "test50x20.dat",

        // Dodaj więcej plików, jeśli istnieją
    };

    std::vector<int> true_values = {1278, 1582, 2297, 2724, 3037, 3886};

    for (int i = 0; i < files.size(); ++i)
    {
        std::cout << "Processing file: " << files[i] << std::endl;

        problem p(files[i]);

        auto start = std::chrono::high_resolution_clock::now();
        int neh = p.NEH();
        auto end = std::chrono::high_resolution_clock::now();
        auto neh_time = std::chrono::duration<double, std::milli>(end - start).count();

        std::cout << "neh: " << neh << ", time: " << neh_time << ", error: " << static_cast<double>(std::abs(neh - true_values[i])) / true_values[i] * 100 << "%" << std::endl;

        start = std::chrono::high_resolution_clock::now();
        int fneh = p.NEH_2();
        end = std::chrono::high_resolution_clock::now();
        auto fneh_time = std::chrono::duration<double, std::milli>(end - start).count();

        std::cout << "fneh: " << fneh << ", time: " << fneh_time << ", error: " << static_cast<double>(std::abs(fneh - true_values[i])) / true_values[i] * 100 << "%" << std::endl;

        std::cout << "----------------------------------------" << std::endl;
    }



    return 0;
}