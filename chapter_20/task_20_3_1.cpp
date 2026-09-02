#include <iostream>

int factorial(int i)
{
    if (i <= 1)
    {
        return 1;
    }
    else
    {
        return i * factorial(i - 1);
    }
}

int queersumme(int n)
{
    if (n < 10)
    {
        return n;
    }
    return queersumme(n / 10) + n % 10;
}

int main()
{
    std::cout << "These are the first 7 factorials: \n";
    for (int i{0}; i < 8; ++i)
    {
        std::cout << "Factorial of " << i << ": " << factorial(i) << '\n';
    }

    std::cout << "queersumme von 354 " << queersumme(354) << '\n';
}
