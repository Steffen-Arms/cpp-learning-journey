#include <iostream>
#include <stdexcept>

class Fraction
{
  private:
    int m_numerator;
    int m_denominator;

  public:
    Fraction(int numerator, int denominator)
        : m_numerator{numerator}, m_denominator{denominator}
    {
        if (denominator == 0)
        {
            throw std::runtime_error("Denominator is 0");
        }
    }

    friend std::ostream& operator<<(std::ostream& out, const Fraction& f)
    {
        out << f.m_numerator << '/' << f.m_denominator;
        return out;
    }
};

int main()
{

    std::cout << "Enter the numerator: ";
    int numerator;
    std::cin >> numerator;
    std::cout << '\n';
    std::cout << "Enter the denominator: ";
    int denominator;
    std::cin >> denominator;

    try
    {
        Fraction f(numerator, denominator);
        std::cout << "Your fraction is: " << f << '\n';
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
