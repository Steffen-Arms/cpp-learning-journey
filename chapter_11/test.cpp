#include <iostream>

template <typename T> T max(T x, T y) { return (x < y) ? y : x; }

template <>
int max<int>(int x, int y) // the generated function max<int>(int, int)
{
    return (x < y) ? y : x;
}

int main()
{
    std::cout << max(1, 2)
              << '\n'; // instantiates and calls function max<int>(int, int)

    return 0;
}
