#include <iostream>
#include <math.h>

long long  maxPrimeFactors(long long num) {
    long long maxPrime = -1;
    while (num % 2 == 0) {
        maxPrime = 2;
        num /= 2;
    }

    for (int i = 3; i < sqrt(num); i+=2) {
        while (num % i == 0) {
            maxPrime = i;
            num = num / i;
        }
    }
    if (num > 2) {
        maxPrime = num;
    }
    return maxPrime;
}

int main()
{
    long long numer = 600851475143;
    std::cout << maxPrimeFactors(numer);
}
