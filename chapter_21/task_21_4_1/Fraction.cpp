#include "Fraction.h"

Fraction operator*(const Fraction& f1, const Fraction& f2)
{
    return Fraction{f1.m_numerator * f2.m_numerator,
                    f1.m_denominator * f2.m_denominator};
}

Fraction operator*(const Fraction& f1, int value)
{
    return Fraction{f1.m_numerator * value, f1.m_denominator};
}

Fraction operator*(int value, const Fraction& f1)
{
    return Fraction{f1.m_numerator * value, f1.m_denominator};
}

std::ostream& operator<<(std::ostream& out, const Fraction& fraction)
{
    return out << fraction.m_numerator << "/" << fraction.m_denominator;
}

std::istream& operator>>(std::istream& in, Fraction& fraction)
{
    int numenator{0};
    char divider{};
    int denominator{1};

    if (in >> numenator >> divider >> denominator)
    {
        if (denominator == 0)
        {
            in.setstate(std::ios_base::failbit);
            return in;
        }
        else
        {
            fraction = Fraction{numenator, denominator};
        }
    }

    return in;
}
