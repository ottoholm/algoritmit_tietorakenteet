#include <iostream>
#include <utility>      //swap funktio käyttöön
#include <random>       // random numerot
#include <chrono>       // ajan laskenta
#include <vector>       // Trapeeks iso taulukko

void simpleSort(std::vector<float>& a, int n) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (a[j] < a[i])
                std::swap(a[j], a[i]);
}

// Time measurements for binary and linear search
void measurePerformance(int size) {

    std::vector<float> array(size);

    // Random generattorin alustus
    std::mt19937 generator(100);
    std::uniform_real_distribution<float> distribution(0.0, 100.0); // random float 0-100

    // Taulukon alustus satunnaisilla luvuilla
    for (int i = 0; i < size; i++) {
        array[i] = distribution(generator);
    }

    // Muutama toistoja keskiarvon toteamiseksi jos haluuaa
    const int repetitions = 1;

    // Ajan mittaus
    auto startSort = std::chrono::steady_clock::now();
    for (int i = 0; i < repetitions; i++) {
        simpleSort(array, size);
    }
    auto endSort = std::chrono::steady_clock::now();

    // Kokonaismäärä lajitteluihin kuluneesta ajasta
    auto sortTime = std::chrono::duration_cast<std::chrono::microseconds>(endSort - startSort).count();

    std::cout << "Array size: " << size << "\n";
    std::cout << "Sort time: " << sortTime / 1000000 << " seconds\n";
    std::cout << "Average sort time: " << static_cast<double>(sortTime) / repetitions / 1000000 << " seconds\n";
}

int main()
{
    std::cout << "Hello World!\n";

    //measurePerformance(10000);        // Tähän meni keskimäärin 1.23 sekunttia
    //measurePerformance(100000);       // ja tähän taas 148.733
    //measurePerformance(1000000);      // Tätä en nyt lähtehnyt kokeilee
    //measurePerformance(10000000);     // Mutta sehän kasvaa aina kymmenkertaisesti edelliseen tulokseen
    std::cout << "Bye World!\n";
}
