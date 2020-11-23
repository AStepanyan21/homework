#include <iostream>

int lengths(char* str) {
    int index = 0;
    while (str[index] != '\0') {
        index++;
    }
    return index;
}

void replace_space(char* str, int space_count) {
    int buff = space_count * 2;
    int len = lengths(str);
    for (int i = 0; i < len - buff; i++) {
        if (str[i] == ' ') {
            for (int j = len - 1; j > i; j--) {
                str[j] = str[j - 2];
            }
            str[i] = '%';
            str[i + 1] = '2';
            str[i + 2] = '0';
        }
    }
    std::cout << str;
}


int main()
{
    char str[] = "Hello World  ";
    std::cout << str << std::endl;
    replace_space(str, 1);
}