#include <iostream>

struct Fraction
{
    int numerator{0};
    int denominator{0};
};

Fraction getFraction()
{
    Fraction tmp{};
    std::cout << "Enter a value for the numerator: ";
    std::cin >> tmp.numerator;
    std::cout << "Enter a value for the denominator: ";
    std::cin >> tmp.denominator;
    return tmp;
}

constexpr Fraction multFraction(const Fraction &x, const Fraction &y)
{
    return {x.numerator * y.numerator, x.denominator * y.denominator};
}

std::ostream &operator<<(std::ostream &out, const Fraction &f)
{
    return out << f.numerator << " / " << f.denominator << "\n";
}

int main()
{
    Fraction frac1{getFraction()};
    Fraction frac2{getFraction()};
    std::cout << "Your fractions multiplied together: "
              << multFraction(frac1, frac2);
}
