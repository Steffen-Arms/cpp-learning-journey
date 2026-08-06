#include <iostream>

int sumTo(int toThisPoint)
{
    int sum{0};
    for (int i = 1; i <= toThisPoint; i++)
    {
        sum += i;
    }
    return sum;
}

int main() { std::cout << "sum to 5: " << sumTo(5); }
