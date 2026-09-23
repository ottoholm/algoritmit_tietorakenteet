#include <iostream>

// Task 3.1 a) taulukolla
long fibonacci_array(int n) {
    // Tallentaa kaiken tauluuun
    long* fib = new long[n + 1];  

    // Taulukon alustus
    fib[0] = 1;
    if (n >= 1) fib[1] = 1;

    // Fibonacci algoritmi
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    long result = fib[n];
    delete[] fib;  

    return result;
}

// Task 3.1 b) ilman taulukkoa
long fibonacci_no_array(int n) {
    if (n <= 1) return 1;

    int x = 1;
    int y = 1;
    long result;
    // Fibonacci algoritmi
    for (int i = 2; i <= n; i++) {
        result = x + y;
        y = x; // f(n-2)
        x = result; // f(n-1)
    }
    return result;
}

// Task 3.2 Ackerman funktio
long ackerman(int m, int n) {
    long result;
    if (m == 0) result = n + 1;
    else if (n == 0) result = ackerman(m - 1, 1);
    else result = ackerman(m - 1, ackerman(m, n - 1));
    return result;
}
int main()
{
    std::cout << "Hello World!\n";
    std::cout << fibonacci_array(6) << std::endl;
    std::cout << fibonacci_no_array(6) << std::endl;
    std::cout << ackerman(2, 2) << std::endl;
}