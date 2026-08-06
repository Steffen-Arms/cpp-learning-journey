#include <iostream>

int main()
{

    static constexpr int bounce{5};

    int outerIndex{1};

    while (outerIndex <= bounce)
    {
        int diff{bounce - outerIndex};
        int diffIndex{0};
        while (diffIndex < diff)
        {
            std::cout << "  ";
            diffIndex++;
        }

        int innerIndex{outerIndex};
        while (innerIndex > 0)
        {
            std::cout << innerIndex << ' ';
            innerIndex--;
        }
        std::cout << '\n';
        outerIndex++;
    }
}
