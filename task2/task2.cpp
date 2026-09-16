#include <iostream>
#include <chrono>
#include <random>
#include <vector>

// Binary Search
int binarySearch(int a[], int x, int size) {

    int startPoint = 0;
    int endPoint = size -1;
    int midPoint;

    while (startPoint != endPoint)
    {
        midPoint = (startPoint + endPoint) / 2;

        if (a[midPoint] < x) {
            startPoint = midPoint;
        }
        else if (a[midPoint] > x) {
            endPoint = midPoint;
        }
        else {
            return midPoint;
        }
    }

    return -1;
}

// Linear Search
int linearSearch(int a[], int x, int size) {

    for (int i = 0; i < size; i++) {
        if (a[i] == x) {
            return i;
        }
    }

    return -1;
}

// Time measurements for binary and linear search
void measurePerformance(int size) {

    std::vector<int> array(size); // Vector for larger arrays

    // Fill the array 1,2,3....size
    for (int i = 0; i < size; i++) {
        array[i] = i;
    }

    // gets randon number from the array
    std::mt19937 generator(100);
    std::uniform_int_distribution<int> distribution(0, size - 1);
    int x = distribution(generator);

    // Many repetitions and lets count the avarages
    const int repetitions = 1000;

    // Measure binary search
    auto startBinary = std::chrono::steady_clock::now();
    for (int i = 0; i < repetitions; i++) {
        binarySearch(array.data(), x, size);
    }
    auto endBinary = std::chrono::steady_clock::now();

    // Measure linear search
    auto startLinear = std::chrono::steady_clock::now();
    for (int i = 0; i < repetitions; i++) {
        linearSearch(array.data(), x, size);
    }
    auto endLinear = std::chrono::steady_clock::now();


    // Count the total time from the searches
    auto binaryTime = std::chrono::duration_cast<std::chrono::microseconds>(endBinary - startBinary).count();
    auto linearTime = std::chrono::duration_cast<std::chrono::microseconds>(endLinear - startLinear).count();

    std::cout << "Array size: " << size << "\n";
    std::cout << "Binary search total time: " << binaryTime << " microseconds\n";
    std::cout << "Linear search total time: " << linearTime << " microseconds\n";
    std::cout << "Average binary search time: " << static_cast<double>(binaryTime) / repetitions << " microseconds\n";
    std::cout << "Average linear search time: " << static_cast<double>(linearTime) / repetitions << " microseconds\n\n" << endl;

}

int main()
{
    std::cout << "Hello World!\n";

    
    int array[] = { 1, 4, 6, 11, 13, 16, 19, 20, 25, 27, 29, 30, 32, 36, 39, 42, 45, 48, 49, 53 };
    int x = 19;

    //Binary search
    int resultIndexBinary = binarySearch(array, x, 20);
    std::cout << "Result index from binary search is: " << resultIndexBinary << "\n";

    //Linear search
    int resultIndexLinear = linearSearch(array, x, 20);
    std::cout << "Result index from linear search is: " << resultIndexLinear << "\n";

    //Time measurements
    measurePerformance(100000);
    measurePerformance(1000000);
    measurePerformance(10000000);
}

