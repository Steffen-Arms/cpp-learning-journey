#include <iostream>
#include <string>
#include <string_view>

class Fruit
{
  private:
    std::string m_name{};
    std::string m_color{};

  public:
    Fruit(std::string_view name, std::string_view color)
        : m_name{name}, m_color{color}
    {
    }
    friend std::ostream& operator<<(std::ostream& out, const Fruit& fruit);
};

std::ostream& operator<<(std::ostream& out, const Fruit& fruit)
{
    out << "Fruit name: " << fruit.m_name << " ,Fruit color: " << fruit.m_color;
    return out;
}

class Apple : public Fruit
{
  private:
    double m_fiber{};

  public:
    Apple(std::string_view name, std::string_view color, double fiber)
        : Fruit(name, color), m_fiber{fiber}
    {
    }

    friend std::ostream& operator<<(std::ostream& out, const Apple& apple);
};

std::ostream& operator<<(std::ostream& out, const Apple& apple)
{
    out << static_cast<Fruit>(apple) << " , Apple: " << apple.m_fiber;
    return out;
}

class Banana : public Fruit
{
  public:
    using Fruit::Fruit;
};

int main()
{
    const Apple a{"Red delicious", "red", 4.2};
    std::cout << a << '\n';

    const Banana b{"Cavendish", "yellow"};
    std::cout << b << '\n';

    return 0;
}
