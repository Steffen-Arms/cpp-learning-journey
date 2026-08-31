#include <algorithm>
#include <iostream>
#include <limits>
#include <string>

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
int main()
{
    std::size_t amountNames{0};
    std::cout << "How many names would you like to enter? ";
    std::cin >> amountNames;
    ignoreLine();

    std::string* namesArray{new std::string[amountNames]};

    for (std::size_t i{0}; i < amountNames; ++i)
    {
        std::cout << "Enter name #" << i << " ";
        std::getline(std::cin >> std::ws, namesArray[i]);
    }

    std::cout << '\n';
    std::sort(namesArray, namesArray + amountNames);

    std::cout << "Here is your sorted list: \n";
    for (std::size_t i{0}; i < amountNames; ++i)
    {
        std::cout << "Name #" << i << ": " << namesArray[i] << '\n';
    }

    delete[] namesArray;
}
