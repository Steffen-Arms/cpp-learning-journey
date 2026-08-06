#include <iostream>

int main()
{

    int outerIndex{5};

    while (outerIndex > 0)
    {
        int innerIndex{outerIndex};
        while (innerIndex > 0)
        {
            std::cout << innerIndex << ' ';
            innerIndex--;
        }
        std::cout << '\n';
        outerIndex--;
    }
}
