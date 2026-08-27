#include <iostream>

void test(char array[])
{
    std::cout << "Enter your rolls: ";
    std::cin >> array;
    std::cout << "You entered: " << array << '\n';
}

int main()
{
    char rolls[255]{}; // declare array large enough to hold 254 characters +
                       // null terminator

    test(rolls);

    return 0;
}
