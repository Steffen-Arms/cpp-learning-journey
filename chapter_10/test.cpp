#include <iostream>

void addAndPrint(auto x, auto y) { std::cout << x + y << '\n'; }

int main()
{
    addAndPrint(2, 3);     // case 1: call addAndPrint with int parameters
    addAndPrint(4.5, 6.7); // case 2: call addAndPrint with double parameters

    return 0;
}
