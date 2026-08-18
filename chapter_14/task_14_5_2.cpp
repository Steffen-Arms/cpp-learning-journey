#include <iostream>

class Point3d
{
    int m_x;
    int m_y;
    int m_z;

  public:
    void setValues(int x, int y, int z)
    {
        this->m_x = x;
        this->m_y = y;
        this->m_z = z;
    }

    void print() const
    {
        std::cout << "< " << this->m_x << ", " << this->m_y << ", " << this->m_z
                  << ">";
    }

    bool isEqual(Point3d p1)
    {
        return (this->m_x == p1.m_x && this->m_y == p1.m_y &&
                this->m_z == p1.m_z);
    }
};

int main()
{
    Point3d point;
    point.setValues(1, 2, 3);

    point.print();
    std::cout << '\n';

    Point3d point1{};
    point1.setValues(1, 2, 3);

    Point3d point2{};
    point2.setValues(1, 2, 3);

    std::cout << "point 1 and point 2 are"
              << (point1.isEqual(point2) ? "" : " not") << " equal\n";

    Point3d point3{};
    point3.setValues(3, 4, 5);

    std::cout << "point 1 and point 3 are"
              << (point1.isEqual(point3) ? "" : " not") << " equal\n";

    return 0;
}
