﻿#include <iostream>
#include <cassert>

using namespace std;

bool isPrime(int x) {
    int divisors = 1 ; 
   
    for (int i = 2; i <= x; i++) {
        if (x % i == 0) 
            ++divisors;
    }

    return (divisors == 2); 
}

int main() {
    assert(!isPrime(0));
    assert(!isPrime(1));
    assert(isPrime(2));
    assert(isPrime(3));
    assert(!isPrime(4));
    assert(isPrime(5));
    assert(isPrime(7));
    assert(!isPrime(9));
    assert(isPrime(11));
    assert(isPrime(13));
    assert(!isPrime(15));
    assert(!isPrime(16));
    assert(isPrime(17));
    assert(isPrime(19));
    assert(isPrime(97));
    assert(!isPrime(99));
    assert(!isPrime(99));
    assert(isPrime(13417));

    cout << "Success!";

    return 0;
}