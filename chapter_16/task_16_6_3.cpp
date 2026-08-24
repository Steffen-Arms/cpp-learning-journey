#include <iostream>
#include <limits>
#include <vector>

template <typename T> void printArray(const std::vector<T>& arr)
{
    for (std::size_t index{0}; index < arr.size(); ++index)
    {
        std::cout << arr[index] << ' ';
    }

    if (arr.size() > 0)
        std::cout << '\n';
}

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// returns true if extraction failed, false otherwise
bool clearFailedExtraction()
{
    // Check for failed extraction
    if (!std::cin) // If the previous extraction failed
    {
        if (std::cin.eof()) // If the stream was closed
        {
            std::exit(0); // Shut down the program now
        }

        // Let's handle the failure
        std::cin.clear(); // Put us back in 'normal' operation mode
        ignoreLine();     // And remove the bad input

        return true;
    }

    return false;
}

template <typename T> T getUserNumber()
{

    T x{};
    while (true)
    {
        std::cout << "Enter a number between 1 and 9:";
        std::cin >> x;
        if (clearFailedExtraction())
        {
            std::cout << "Invalid input \n";
            continue;
        }
        ignoreLine();

        if (x <= 10 && x >= 1)
        {
            return x;
        }
    }
}

template <typename T>
void printUserNumberIndex(const std::vector<T>& arr, T userNumber)
{

    int indexUserNumber{-1};

    for (std::size_t i{0}; i < arr.size(); ++i)
    {
        if (arr[i] == userNumber)
        {
            indexUserNumber = static_cast<int>(i);
            break;
        }
    }
    if (indexUserNumber == -1)
    {
        std::cout << "The number " << userNumber << " was not found \n";
    }
    else
    {
        std::cout << "The number " << userNumber << " has index "
                  << indexUserNumber << "\n";
    }
}

int main()
{
    // std::vector arr{4, 6, 7, 3, 8, 2, 1, 9};
    std::vector arr{4.4, 6.6, 7.7, 3.3, 8.8, 2.2, 1.1, 9.9}; // Question 4

    // int userNumber{getUserNumber()};
    printArray(arr);

    using T = decltype(arr)::value_type;
    printUserNumberIndex(arr, getUserNumber<T>());

    return 0;
}
