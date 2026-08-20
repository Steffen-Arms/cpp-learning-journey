#include <cassert>
#include <iostream>

class Point2d
{
  private:
    double m_x{0.0};
    double m_y{0.0};

  public:
    constexpr Point2d() {}

    constexpr Point2d(double x, double y) : m_x{x}, m_y{y} {}

    void print() { std::cout << "Point2d(" << m_x << ", " << m_y << ") \n"; }
};

#include <iostream>

int main()
{
    Point2d first{};
    Point2d second{3.0, 4.0};

    //[[maybe_unused]] Point2d third{4.0}; // should error if uncommented

    first.print();
    second.print();

    return 0;
}
