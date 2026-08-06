#include <cassert>
#include <iostream>

int main()
{

    [[maybe_unused]] int x{1};

    {
        [[maybe_unused]] int x{2};
        std::cout << "this is x " << x << "\n";
    }
    std::cout << "outside block x: " << x << "\n";

    return 0;
}
