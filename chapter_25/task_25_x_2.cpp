#include <iostream>
#include <memory>
#include <vector>

class Shape
{

  public:
    virtual std::ostream& print(std::ostream&) const = 0;

    friend std::ostream& operator<<(std::ostream& out, const Shape& shape)
    {
        return shape.print(out);
    }

    virtual ~Shape() = default;
};

struct Point
{
    int m_x{};
    int m_y{};

    friend std::ostream& operator<<(std::ostream& out, const Point& point)
    {
        out << "Point(" << point.m_x << ", " << point.m_y << ")";
        return out;
    }
};

class Triangle : public Shape
{
  private:
    Point m_p1;
    Point m_p2;
    Point m_p3;

  public:
    Triangle(const Point& p1, const Point& p2, const Point& p3)
        : m_p1{p1}, m_p2{p2}, m_p3{p3}
    {
    }

    std::ostream& print(std::ostream& out) const override
    {
        out << "Triangle(" << m_p1 << ", " << m_p2 << ", " << m_p3 << ")";
        return out;
    }
};

class Circle : public Shape
{
  private:
    Point m_p;
    int m_radius{};

  public:
    Circle(const Point& p, const int radius) : m_p{p}, m_radius{radius} {}

    std::ostream& print(std::ostream& out) const override
    {
        out << "Circl(" << m_p << ", radius " << m_radius << ")";
        return out;
    }

    int getRadius() const { return m_radius; }
};

int getLargestRadius(std::vector<Shape*> v)
{

    int largestRadius{0};

    for (const auto* shape : v)
    {
        if (auto* c{dynamic_cast<const Circle*>(shape)})
        {
            largestRadius = std::max(largestRadius, c->getRadius());
        }
    }
    return largestRadius;
}

int main()
{
    std::vector<Shape*> v{new Circle{Point{1, 2}, 7},
                          new Triangle{Point{1, 2}, Point{3, 4}, Point{5, 6}},
                          new Circle{Point{7, 8}, 3}};

    for (auto shape : v)
    {
        std::cout << *shape << "\n";
    }

    std::cout << "The largest radius is: " << getLargestRadius(v)
              << '\n'; // write this function

    // delete each element in the vector here
    for (const auto* shape : v)
    {
        delete shape;
    }

    std::cout << "test with unique ptr \n";

    std::vector<std::unique_ptr<Shape>> v2;
    v2.reserve(3);
    v2.push_back(std::make_unique<Circle>(Point{1, 2}, 7));
    v2.push_back(
        std::make_unique<Triangle>(Point{1, 2}, Point{3, 4}, Point{5, 6}));
    v2.push_back(std::make_unique<Circle>(Point{7, 8}, 3));

    for (std::size_t i{0}; i < std::size(v2); ++i)
    {
        std::cout << *v2[i].get() << "\n";
    }

    return 0;
}
