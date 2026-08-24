#include <iostream>
#include <vector>

void printStack(const std::vector<int>& stack)
{
    if (stack.empty())
    {
        std::cout << "\t(Stack: empty) \n";
    }
    else
    {
        std::cout << " (Stack: ";
        for (auto element : stack)
        {
            std::cout << element << " ";
        }
        std::cout << " ) \n";
    }
}

int main()
{
    std::vector<int> list{};

    printStack(list);

    list.push_back(1);
    std::cout << "Push " << list.back();
    printStack(list);

    list.push_back(2);
    std::cout << "Push " << list.back();
    printStack(list);

    list.push_back(3);
    std::cout << "Push " << list.back();
    printStack(list);

    list.pop_back();
    std::cout << "Pop   ";
    printStack(list);

    list.push_back(4);
    std::cout << "Push " << list.back();
    printStack(list);

    list.pop_back();
    std::cout << "Pop   ";
    printStack(list);

    list.pop_back();
    std::cout << "Pop   ";
    printStack(list);

    list.pop_back();
    std::cout << "Pop   ";
    printStack(list);

    return 0;
}
