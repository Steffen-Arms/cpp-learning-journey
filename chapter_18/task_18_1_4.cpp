#include <array>
#include <iostream>
#include <iterator>

int array[]{6, 3, 2, 9, 7, 1, 5, 4, 8};

int bubbleSort()
{
    bool noSwap{true};
    // Index start with Index = N as we start to sort the biggest Elelent at
    // the end of the array and then we work iteratly to the start of the
    // array
    for (int i{std::size(array) - 1}; i > 0; --i)
    {
        for (int j{0}; j < i; ++j)
        {

            // here we sort so the final array is in ascending order
            if (array[j] > array[j + 1])
            {
                std::swap(array[j], array[j + 1]);
                noSwap = false;
            }
        }
        if (noSwap)
        {
            return static_cast<int>(
                (static_cast<int>(std::size(array)) - 1 - i));
        }
        noSwap = true;
    }
    return -1;
}
int main()
{

    int returnValue{bubbleSort()};

    if (returnValue > 0)
    {
        std::cout << "Loop terminate earlier on iteration: " << returnValue
                  << "\n";
    }

    std::cout << "This is the array \n";
    for (std::size_t i{0}; i < std::size(array); ++i)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << '\n';

    return 0;
}
