#include <cstdint>
#include <iostream>

class Average
{
  private:
    std::int32_t m_overallSum{0};
    int m_howManyNumbers{0};

  public:
    auto getAverage() const
    {
        return static_cast<double>(m_overallSum) / m_howManyNumbers;
    }
    friend std::ostream& operator<<(std::ostream& out, const Average& avg);

    Average operator+=(int x)
    {
        m_overallSum += x;
        m_howManyNumbers += 1;

        return *this;
    }
};

std::ostream& operator<<(std::ostream& out, const Average& avg)
{
    if (avg.m_howManyNumbers == 0)
    {
        out << 0;
    }
    out << "This is the average: " << avg.getAverage() << '\n';
    return out;
}

int main()
{
    Average avg{};
    std::cout << avg << '\n';

    avg += 4;
    std::cout << avg << '\n'; // 4 / 1 = 4

    avg += 8;
    std::cout << avg << '\n'; // (4 + 8) / 2 = 6

    avg += 24;
    std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

    avg += -10;
    std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

    (avg += 6) += 10;         // 2 calls chained together
    std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

    Average copy{avg};
    std::cout << copy << '\n';

    return 0;
}
