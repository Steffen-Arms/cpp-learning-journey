#include <iostream>

int readNumber()
{
    int x;
    std::cout << "enter a number \n";
    std::cin >> x;
    return x;
}

void writeAnswer(int output) { std::cout << "this is the outpup: " << output; }
