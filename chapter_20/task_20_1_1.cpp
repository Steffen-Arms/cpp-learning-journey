#include <functional>
#include <iostream>

using ArithmeticFunction = std::function<int(int, int)>;

int add(int x, int y) { return x + y; }
int substract(int x, int y) { return x - y; }
int multiply(int x, int y) { return x * y; }
int divide(int x, int y) { return x / y; }

ArithmeticFunction getArithmeticFunction(char op)
{
    switch (op)
    {
    case '+':
        return &add;
    case '-':
        return &substract;
    case '*':
        return &multiply;
    case '/':
        return &divide;
    default:
        return nullptr;
    }
}

int main()
{
    std::cout << "Enter two integers and one operation of +,-,*,/ \n";
    int firstInt{0};
    std::cout << "First int: \n";
    std::cin >> firstInt;

    std::cout << "Second int: \n";
    int secondInt{0};
    std::cin >> secondInt;

    char op{};
    bool valid{false};
    while (!valid)
    {
        std::cout << "write operation +,-,*,/ \n";

        std::cin >> op;
        switch (op)
        {
        case '+':
        case '-':
        case '*':
        case '/':
            valid = true;
            break;
        default:
            std::cout << "Thats not a valid operation try again \n";
        }
    }

    ArithmeticFunction fct{getArithmeticFunction(op)};
    if (fct)
    {
        std::cout << firstInt << ' ' << op << ' ' << secondInt << " = "
                  << fct(firstInt, secondInt) << '\n';
    }
}
