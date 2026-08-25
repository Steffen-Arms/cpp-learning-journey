#include <iostream>
#include <limits>
#include <utility>
#include <vector>

template <typename T>
std::pair<std::size_t, std::size_t>
getMinMaxIndex(const std::vector<T>& inputVector)
{
    T minValue{inputVector.data()[0]};
    std::size_t minValueIndex{0};

    T maxValue{inputVector.data()[0]};
    std::size_t maxValueIndex{0};

    for (std::size_t index{1}; index < inputVector.size(); ++index)
    {
        if (inputVector[index] < minValue)
        {
            minValue = inputVector[index];
            minValueIndex = index;
        }
        else if (inputVector[index] > maxValue)
        {
            maxValue = inputVector[index];
            maxValueIndex = index;
        }
    }
    return std::pair(minValueIndex, maxValueIndex);
}

template <typename T> void printVector(const std::vector<T>& inputVector)
{
    bool comma{false};
    std::cout << "With array ( ";
    for (const auto& item : inputVector)
    {
        if (comma)
        {
            std::cout << ", ";
        }
        std::cout << item;
        comma = true;
    }
    std::cout << " ):\n";
}

template <typename T> void printVectorMinMax(const std::vector<T>& inputVector)
{
    printVector(inputVector);

    std::pair<std::size_t, std::size_t> minMax{getMinMaxIndex(inputVector)};

    std::cout << "The min element has index " << minMax.first << " and value "
              << inputVector[minMax.first] << "\n";

    std::cout << "The max element has index " << minMax.second << " and value "
              << inputVector[minMax.second] << "\n";
}

std::vector<int> getUserVector()
{
    std::cout << "Enter numbers to add (use -1 to stop): ";

    std::vector<int> stackVector{};

    int userInput{};

    while (true)
    {
        std::cin >> userInput;
        if (userInput == -1)
        {
            break;
        }
        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        stackVector.push_back(userInput);
    }

    return stackVector;
}

int main()
{
    std::vector v1{getUserVector()};

    printVector(v1);
    printVectorMinMax(v1);
}
