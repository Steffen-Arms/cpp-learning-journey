#include <iostream>

void printCStyleString(const char string[])
{

    while (true)
    {
        if (*string == '\0')
        {
            break;
        }
        else
        {
            std::cout << *string;
            ++string;
        }
    }
    std::cout << '\n';
}

void printBackwards(const char str[])
{

    int length{0};
    const char* ptr;

    // find terminator
    while (true)
    {
        if (*str == '\0')
        {
            --str;
            ptr = str;
            break;
        }
        ++str;
        ++length;
    }
    while (length > 0)
    {
        std::cout << *ptr;
        --ptr;
        --length;
    }
    std::cout << '\n';
}

int main()
{
    const char testString[]{"Hello world!"};

    printCStyleString(testString);
    printBackwards(testString);
}
