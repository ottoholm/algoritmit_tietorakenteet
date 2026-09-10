#include <iostream>

int gcd(int a, int b) {

    int r = a % b;
    while (r > 0) {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

static int* allocate_array(unsigned n) {

    int* array = new int[n];

    for (unsigned i = 0; i < n; i++) {
        array[i] = i;
    }
    return array;
}

int linearSearch(int* a, int x, int n) {

    int i = 0; // index for going trought the array
    while (i < n && a[i] <= x) { // index less than size of array, x can still be same size
        if (a[i] == x) return i; // we found our x --> return index
        i++;
    }


    return -1;
}

int binarySearch(int* a, int x, int n) {
    int mid;
    int left = 0;
    int right = n - 1;

    while (left != right) {
        mid = (left + right) / 2; // find midpoint from array

        if(a[mid] == x) return mid;
        if (a[mid] > x) {
            right = mid - 1; // schoose left part
        }
        else {
            left = mid;
        }
    }
    if (a[mid] == x) return mid;

    return -1;
    
}

int main()
{
    std::cout << "Hello World!\n";
    //int a = 42; int b = 35;
    //std::cout << "gcd(" << a << "," << b << "): " << gcd(a, b) << std::endl;

    int n = 10000000;
    int* a = allocate_array(n);
    int x = 42455;
    std::cout << "linear_search(" << x << "," << n << ")= " << linearSearch(a, x, n) << std::endl;
}

