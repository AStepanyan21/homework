#include <iostream>

int sum(int number) {
    int count = 0;
    for (int i = 0; i < number; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            count += i;
        }
    }
    return count;
}

int main()
{
    int number;
    std::cin >> number;
    std::cout << sum(number) << std::endl;
    return 0;
}
