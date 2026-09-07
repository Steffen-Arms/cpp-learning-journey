#include <iostream>
#include <string>

constexpr std::size_t toUZ(int value)
{
    return static_cast<std::size_t>(value);
}

class MyString
{

  private:
    std::string thisString;

  public:
    MyString() = default;
    MyString(const std::string& s) : thisString(s) {};

    friend std::ostream& operator<<(std::ostream& out,
                                    const MyString& parameterString);

    MyString operator()(int index, int length)
    {
        return thisString.substr(toUZ(index), toUZ(length));
    };
};

std::ostream& operator<<(std::ostream& out, const MyString& parameterString)
{
    out << parameterString.thisString;
    return out;
}

int main()
{
    MyString s{"Hello, world!"};
    std::cout << s(7, 5) << '\n'; // start at index 7 and return 5 characters

    return 0;
}
