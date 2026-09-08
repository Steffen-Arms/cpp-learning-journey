#include <cassert>
#include <cmath>
#include <cstdint>
#include <iostream>

class FixedPoint2
{
  private:
    int16_t m_base{0};
    int8_t m_decimal{0};

    void handlingOverflow()
    {
        m_base += m_decimal / 100;
        m_decimal %= 100;
    }

  public:
    FixedPoint2(int16_t nonFractionalPart, int8_t fractionalPart)
        : m_base{nonFractionalPart}, m_decimal{fractionalPart}
    {
        // assert(m_decimal < 100 && "fractionalPart is to big");
        if (m_base < 0 || m_decimal < 0)
        {
            if (m_base > 0)
            {
                m_base = -m_base;
            }
            if (m_decimal > 0)
            {
                m_decimal = -m_decimal;
            }
        }
        if (m_decimal < -99 || m_decimal > 99)
        {
            handlingOverflow();
        }
    }

    FixedPoint2(double d)
        : FixedPoint2(static_cast<std::int16_t>(std::trunc(d)),
                      static_cast<std::int8_t>(std::round(d * 100) -
                                               std::trunc(d) * 100))
    {
    }

    explicit operator double() const
    {
        return m_base + (static_cast<double>(m_decimal) / 100);
    }

    friend bool testDecimal(const FixedPoint2& fp);
    friend bool operator==(FixedPoint2 fp1, FixedPoint2 fp2);
    friend FixedPoint2 operator+(FixedPoint2 fp1, FixedPoint2 fp2);
    friend FixedPoint2 operator+(FixedPoint2 fp1, FixedPoint2 fp2);
    friend std::istream& operator>>(std::istream& in, FixedPoint2& fp2);

    FixedPoint2 operator-() { return FixedPoint2{-static_cast<double>(*this)}; }
};

// You will need to make testDecimal a friend of FixedPoint2
// so the function can access the private members of FixedPoint2
bool testDecimal(const FixedPoint2& fp)
{
    if (fp.m_base >= 0)
        return fp.m_decimal >= 0 && fp.m_decimal < 100;
    else
        return fp.m_decimal <= 0 && fp.m_decimal > -100;
}

std::ostream& operator<<(std::ostream& out, const FixedPoint2& fp2)
{
    out << static_cast<double>(fp2);
    return out;
}

std::istream& operator>>(std::istream& in, FixedPoint2& fp2)
{
    double d{};
    in >> d;
    fp2 = FixedPoint2{d};
    return in;
}

bool operator==(FixedPoint2 fp1, FixedPoint2 fp2)
{
    return (fp1.m_base == fp2.m_base) && (fp1.m_decimal == fp2.m_decimal);
}

FixedPoint2 operator+(FixedPoint2 fp1, FixedPoint2 fp2)
{
    return FixedPoint2(static_cast<double>(fp1) + static_cast<double>(fp2));
}
FixedPoint2 operator-(FixedPoint2 fp1, FixedPoint2 fp2)
{
    return FixedPoint2(static_cast<double>(fp1) - static_cast<double>(fp2));
}

int main()
{
    assert(FixedPoint2{0.75} == FixedPoint2{0.75});    // Test equality true
    assert(!(FixedPoint2{0.75} == FixedPoint2{0.76})); // Test equality false

    // Test additional cases -- h/t to reader Sharjeel Safdar for these test
    // cases
    assert(FixedPoint2{0.75} + FixedPoint2{1.23} ==
           FixedPoint2{1.98}); // both positive, no decimal overflow
    assert(FixedPoint2{0.75} + FixedPoint2{1.50} ==
           FixedPoint2{2.25}); // both positive, with decimal overflow
    assert(FixedPoint2{-0.75} + FixedPoint2{-1.23} ==
           FixedPoint2{-1.98}); // both negative, no decimal overflow
    assert(FixedPoint2{-0.75} + FixedPoint2{-1.50} ==
           FixedPoint2{-2.25}); // both negative, with decimal overflow
    assert(FixedPoint2{0.75} + FixedPoint2{-1.23} ==
           FixedPoint2{-0.48}); // second negative, no decimal overflow
    assert(FixedPoint2{0.75} + FixedPoint2{-1.50} ==
           FixedPoint2{-0.75}); // second negative, possible decimal overflow
    assert(FixedPoint2{-0.75} + FixedPoint2{1.23} ==
           FixedPoint2{0.48}); // first negative, no decimal overflow
    assert(FixedPoint2{-0.75} + FixedPoint2{1.50} ==
           FixedPoint2{0.75}); // first negative, possible decimal overflow

    FixedPoint2 a{-0.48};
    assert(static_cast<double>(a) == -0.48);
    assert(static_cast<double>(-a) == 0.48);

    std::cout << "Enter a number: "; // enter 5.678
    std::cin >> a;
    std::cout << "You entered: " << a << '\n';
    assert(static_cast<double>(a) == 5.68);

    return 0;
}
