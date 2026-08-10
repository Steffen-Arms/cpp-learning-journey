#include <iostream>
#include <limits>

int main()
{
    int x;
    while (true)
    {
        std::cout << "Zahl: ";
        std::cin >> x;

        if (std::cin.eof())
        {
            std::cout << "\n[EOF empfangen, mache trotzdem weiter]\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::cout << "Du hast eingegeben: " << x << '\n';
        if (x == 0)
            break;
    }
}
