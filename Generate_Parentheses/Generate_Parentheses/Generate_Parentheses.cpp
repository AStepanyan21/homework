#include <iostream>


void printParenthesis(int pos, int n, int open, int close)
{
    static char str[8];
    if (n > 0) {
        if (close == n)
        {
            std::cout << str << std::endl;

        }
        else
        {
            if (open > close)
            {
                str[pos] = ')';
                printParenthesis(pos + 1, n, open, close + 1);
            }

            if (open < n)
            {
                str[pos] = '(';
                printParenthesis(pos + 1, n, open + 1, close);
            }
        }
    }
}




int main()
{
    int n;
    std::cin >> n;
    printParenthesis(0,n,0,0);
}