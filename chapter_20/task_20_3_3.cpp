#include <algorithm>
#include <iostream>
#include <string>

void getBinary(int n)
{

    if (n == 0)
    {
        return;
    }
    getBinary(n / 2);
    std::cout << n % 2;
}

int main()
{

    int inputInt{0};

    do
    {
        std::cout << "Enter a positive Interger: ";
        std::cin >> inputInt;
    } while (inputInt <= 0);

    std::cout << '\n';

    getBinary(inputInt);
}
