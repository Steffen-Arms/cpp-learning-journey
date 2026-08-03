#include <iostream>

int main()
{
    int input{};

    std::cout << "give me a number between 0 and 9";
    std::cin >> input;
    if (input == 2 or input == 3 or input == 5 or input == 7)
        std::cout << input << " is prime.";
    else
        std::cout << input << "is not prime";

    return 0;
}
