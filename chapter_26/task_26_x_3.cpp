#include <iostream>
#include <string>

template <typename T, typename U> class Pair
{
  private:
    T m_x;
    U m_y;

  public:
    Pair(const T& x, const U& y) : m_x{x}, m_y{y} {}

    T& first() { return m_x; }

    const T& first() const { return m_x; }

    U& second() { return m_y; }

    const U& second() const { return m_y; }
};

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
template <typename U> class StringValuePair : public Pair<std::string, U>
{
  public:
    StringValuePair(std::string_view text, const U& y)
        : Pair<std::string, U>(static_cast<std::string>(text), y)
    {
    }
};

int main()
{
    StringValuePair<int> svp{"Hello", 5};
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

    return 0;
}
