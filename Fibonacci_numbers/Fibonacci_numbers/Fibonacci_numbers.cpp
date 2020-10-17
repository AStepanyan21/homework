#include <iostream>

int count = 0;
int even_valued = 0;

void fibonachi_numbers(int num1, int num2) {
    
    int num3;
    num3 = num1 + num2;
    if (num3 <= 4000000) {
        if (num3 % 2 == 0) {
            even_valued += num3;
        }
        count += 1;
        return fibonachi_numbers(num2, num3);
    }
    else {
        std::cout << even_valued;
    }
}

int main()
{
     fibonachi_numbers(0,1);
}
