#include <iostream>

// Uses abbreviated function template (C++20) and `auto` return type to make
// this function work with any type of value See 'related content' box below for
// more info (you don't need to know how these work to use this function) We've
// opted to use an uppercase name here for consistency with the prior example,
// but it also makes it easier to see the call
consteval auto CONSTEVAL(auto value) { return value; }

// This function returns the greater of the two numbers if executing in a
// constant context and the lesser of the two numbers otherwise
constexpr int compare(int x, int y) // function is constexpr
{
    if (std::is_constant_evaluated())
        return (x > y ? x : y);
    else
        return (x < y ? x : y);
}

int main()
{
    std::cout << CONSTEVAL(compare(5, 6))
              << '\n'; // will execute at compile-time

    return 0;
}
