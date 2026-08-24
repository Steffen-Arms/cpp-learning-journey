#include <iostream>
#include <vector>

void printElement(const auto& vector, int index)
{
    if (index < 0 || std::ssize(vector) < index)
    {
        std::cout << "Invalid index: " << index << "\n";
    }
    else
    {
        std::cout << "The element has value "
                  << vector[static_cast<size_t>(index)] << "\n";
    }
}

int main()
{
    std::vector v1{0, 1, 2, 3, 4};
    printElement(v1, 2);
    printElement(v1, 5);

    std::vector v2{1.1, 2.2, 3.3};
    printElement(v2, 0);
    printElement(v2, -1);

    return 0;
}
