#include <iostream>

double myPow(double x, int n){
    double pow = x;
    if (n > 0) {
        for (int i = 0; i < abs(n - 1); i++) {
            pow *= x;
        }
    }else if(n < 0){
        for (int i = 0; i < abs(n - 1); i++) {
            pow /= x;
        }
    }
    else {
        pow = 1;
    }
    return pow;
}

int main()
{
    double a = myPow(2, -2);
    std::cout << a;
}
