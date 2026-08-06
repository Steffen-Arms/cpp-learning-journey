#include <iostream>

int main()
{

    // int startA = 'a';

    // int index = 0;

    // while (index < 26)
    // {
    //     std::cout << "character: " << static_cast<char>(startA + index)
    //               << " number: " << startA + index << '\n';

    //     index++;
    // }

    char myChar{'a'};
    while (myChar <= 'z')
    {
        std::cout << myChar << ' ' << static_cast<int>(myChar) << '\n';
        ++myChar;
    }

    return 0;
}
