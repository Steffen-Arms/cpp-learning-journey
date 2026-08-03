#include <iostream>
#include <string>

int main()
{

    // get user input
    double left_value{};
    double right_value{};
    std::cout << "Enter a double value: ";
    std::cin >> left_value;
    std::cout << "Enter a double value: ";
    std::cin >> right_value;
    std::cout << "Enter +,-,*,or /: *";
    char input_symbol{};
    std::cin >> input_symbol;

    if (input_symbol == '+')
        std::cout << left_value + right_value;
    else if (input_symbol == '-')
        std::cout << left_value + right_value;
    else if (input_symbol == '*')
        std::cout << left_value * right_value;
    else if (input_symbol == '/')
        std::cout << left_value / right_value;

    return 0;
}
