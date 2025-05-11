#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include "problem.h"

/*
 *      Format danych w .DAT
 *
 *      liczba_zadan liczba_maszyn
 *      zad_1
 *      zad_2
 *      ...
 *      zad_n
 *
 *      Narazie przeglad zupelny dziala tylko dla dwoch maszyn
 */

int main()
{
    std::vector<std::string> files = {
        "../10_1-10.DAT",
        "../10_10-20.DAT",
        "../20_1-10.DAT",
        "../20_10-20.DAT",
        "../20_50-100.DAT",
        "../50_1-10.DAT",
        "../50_10-20.DAT",
        "../50_50-100.DAT"
        // Dodaj więcej plików, jeśli istnieją
    };

    for (const auto &file : files)
    {
        std::cout << "Processing file: " << file << std::endl;

        problem p(file);

        auto start = std::chrono::high_resolution_clock::now();
        int p_zup = p.przegladZaupelny();
        auto end = std::chrono::high_resolution_clock::now();
        auto p_zup_time = std::chrono::duration<double, std::milli>(end-start).count();

        start = std::chrono::high_resolution_clock::now();
        int lsa = p.LSA();
        end = std::chrono::high_resolution_clock::now();
        auto lsa_time = std::chrono::duration<double, std::milli>(end-start).count();

        start = std::chrono::high_resolution_clock::now();
        int lpt = p.LPT();
        end = std::chrono::high_resolution_clock::now();
        auto lpt_time = std::chrono::duration<double, std::milli>(end-start).count();

        start = std::chrono::high_resolution_clock::now();
        int pd = p.PD();
        end = std::chrono::high_resolution_clock::now();
        auto pd_time = std::chrono::duration<double, std::milli>(end-start).count();


        std::cout << "p_zup: " << p_zup << " time: " << p_zup_time << std::endl;
        std::cout << "lsa: " << lsa << ", time: " << lsa_time << ", error: " << static_cast<double>(lsa - p_zup) / p_zup * 100 << "%" << std::endl;
        std::cout << "lpt: " << lpt << ", time: " << lpt_time << ", error: " << static_cast<double>(lpt - p_zup) / p_zup * 100 << "%" << std::endl;
        std::cout << "pd: " << pd << ", time: " << pd_time << ", error: " << static_cast<double>(pd - p_zup) / p_zup * 100 << "%" << std::endl;
        std::cout << "----------------------------------------" << std::endl;
    }

    return 0;
}