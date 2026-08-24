#include <iostream>
#include <vector>

int main()
{
    std::vector test{'h', 'e', 'l', 'l', 'o'};

    std::cout << "The array has " << std::size(test) << " elements. \n";

    std::cout << test[1] << test.at(1) << "\n";
}
