#include <cstdint>
#include <iostream>

int main()
{

    char input_char{};
    std::cout << "one single character pls:";
    std::cin >> input_char;

    std::cout << "You entererd '" << input_char << ", which has ASCII code "
              << static_cast<short>(input_char) << "\n";

    int a{input_char};
    std::cout << "int a " << a << "\n";
    std::cout << "implicit casting: " << input_char + 0;
}
