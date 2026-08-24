#include <iostream>
#include <string>
#include <string_view>
#include <vector>

int main()
{
    std::vector<std::string_view> names{"Alex",  "Betty", "Caroline", "Dave",
                                        "Emily", "Fred",  "Greg",     "Holly"};

    std::string userInput{};

    std::cout << "Enter a name: \n";
    std::cin >> userInput;

    bool found{false};

    for (std::string_view name : names)
    {
        if (name == userInput)
        {
            std::cout << name << "was found.";
            found = true;
            break;
        }
    }

    if (!found)
    {
        std::cout << userInput << " was not found.";
    }
}
