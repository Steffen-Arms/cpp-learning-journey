#include <iostream>

int calculate(int x, int y, char symbol)
{
    switch (symbol)
    {
    case '+':
        return x + y;

    case '-':
        return x - y;

    case '*':
        return x * y;

    case '/':
        return x / y;

    case '%':
        return x % y;

    default:
        std::cout << "Error: no valid symbol \n";
        return -1;
    }
}

int main()
{
    int solution = calculate(2, 5, '%');

    std::cout << "this is the solution: " << solution << "\n";

    return 0;
}
