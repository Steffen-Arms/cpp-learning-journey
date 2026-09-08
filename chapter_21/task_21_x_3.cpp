#include <cassert>
#include <iostream>

class IntArray
{

  private:
    int m_length{0};
    int* m_internArray{nullptr};

  public:
    explicit IntArray(int arraySize)
        : m_length{arraySize}, m_internArray{new int[arraySize]}
    {
        assert(m_length > 0 && "length must be positive");
    }

    // copy constructor for deep copy
    IntArray(const IntArray& other)
        : m_length{other.m_length}, m_internArray{new int[other.m_length]}
    {
        for (int i{0}; i < m_length; ++i)
        {
            m_internArray[i] = other[i];
        }
    }

    IntArray& operator=(const IntArray& other)
    {
        if (this == &other)
        {
            return *this;
        }
        delete[] m_internArray;
        m_length = other.m_length;
        m_internArray = new int[other.m_length];
        for (int i{0}; i < m_length; i++)
        {
            m_internArray[i] = other.m_internArray[i];
        }

        return *this;
    }

    ~IntArray() { delete[] m_internArray; }

    int& operator[](const int index)
    {
        assert(index >= 0 && "Index must be positive");
        assert(index < m_length && "index must be smaller than length");
        return m_internArray[index];
    }

    const int& operator[](int index) const { return m_internArray[index]; }

    friend std::ostream& operator<<(std::ostream& out, IntArray& ownArray);
};

std::ostream& operator<<(std::ostream& out, IntArray& ownArray)
{
    out << ownArray[0];
    for (int i{1}; i < ownArray.m_length; i++)
    {
        out << ' ' << ownArray[i];
    }

    return out;
}

IntArray fillArray()
{
    IntArray a(5);

    a[0] = 5;
    a[1] = 8;
    a[2] = 2;
    a[3] = 3;
    a[4] = 6;

    return a;
}

int main()
{
    IntArray a{fillArray()};

    std::cout << a << '\n';

    auto& ref{a}; // we're using this reference to avoid compiler
                  // self-assignment errors
    a = ref;

    IntArray b(1);
    b = a;

    a[4] = 7;

    std::cout << b << '\n';

    return 0;
}
