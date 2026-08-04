#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter you full name:";
    std::string name{};
    std::getline(std::cin >> std::ws, name);
    std::cout << "Enter your age: ";
    int age{};
    std::cin >> age;
    std::cout << "Your age + length of name is: "
              << static_cast<int>(name.length()) + age << "\n";
}
