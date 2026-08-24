#include <iostream>
#include <vector>

void question4()
{
    std::cout << "Enter 3 integer: ";
    std::vector<int> input(3);
    std::cin >> input[0] >> input[1] >> input[2];

    std::cout << "The sum is: " << input[0] + input[1] + input[2] << "\n";
    std::cout << "The product is: " << input[0] * input[1] * input[2] << "\n";
}

int main()
{

    std::vector test{1, 4, 9, 16, 25};

    std::vector<double> temperature(365);

    question4();
}
