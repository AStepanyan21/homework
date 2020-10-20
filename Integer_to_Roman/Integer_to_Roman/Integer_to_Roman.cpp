#include <iostream>

void intToRoman(int num) {
    std::string str_romans[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
    int values[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };

    std::string result = "";

    for (int i = 0; i < 13; ++i)
    {
        while (num - values[i] >= 0)
        {
            result += str_romans[i];
            num -= values[i];
        }
    }

    std::cout << result;
}

int main()
{
    int number = 42;
    intToRoman(number);
}
