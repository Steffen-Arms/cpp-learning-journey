#include <iostream>
#include <string>

template <typename T, typename U, typename W> class Triad
{
  private:
    T m_first{};
    U m_second{};
    W m_third{};

  public:
    Triad(/* args */);
    ~Triad();

    T getTriadFirst() { retrun m_first; }

    U getTriadSecond() { return m_second; }

    W getTriadThird() { return m_third; }

    void setTriad(T first, U second, W third)
    {
        m_first = first;
        m_second = second;
        m_third = third;
    }

    void print(const Triad& triad)
};

template <typename T, typename U, typename W>
void Triad<T, U, W>::print(const Triad& triad)
{
}

int main()
{
    Triad<int, int, int> t1{1, 2, 3};
    t1.print();
    std::cout << '\n';
    std::cout << t1.first() << '\n';

    using namespace std::literals::string_literals;
    const Triad t2{1, 2.3, "Hello"s};
    t2.print();
    std::cout << '\n';

    return 0;
}
