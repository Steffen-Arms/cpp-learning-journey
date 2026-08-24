#include <iostream>
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

int main()
{
    std::vector v1{3, 8, 2, 5, 7, 8, 3};
    std::vector v2{5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6};

    printVectorMinMax(v1);
    printVectorMinMax(v2);
}
