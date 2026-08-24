#include <iostream>
#include <string>
#include <string_view>
#include <vector>

template <typename T> bool isValueInArray(std::vector<T>& arr, T targetValue)
{

    for (const T& a : arr)
    {
        if (a == targetValue)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    std::vector<std::string_view> names{"Alex",  "Betty", "Caroline", "Dave",
                                        "Emily", "Fred",  "Greg",     "Holly"};

    std::string userInput{};

    std::cout << "Enter a name:";
    std::cin >> userInput;

    if (isValueInArray<std::string_view>(names, userInput))
    {
        std::cout << userInput << " was found. \n";
    }
    else
    {
        std::cout << userInput << " was not found. \n";
    }
}
