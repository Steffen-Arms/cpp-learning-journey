#include <iostream>

namespace Constant
{
constexpr double gravity{9.8};

}

namespace
{

double getTowerHight()
{
    std::cout << "Enter the height of the tower man: ";
    double towerhight{};
    std::cin >> towerhight;
    return towerhight;
}

/// @brief monitor the fall of the ball
/// @param towerHeight /
void calculateAndPrintBallFall(double towerHeight)
{

    double currentBallHeight = towerHeight;
    int seconds = 0;

    while (currentBallHeight > 0)
    {
        std::cout << "At " << seconds
                  << " seconds, the ball is at height: " << currentBallHeight
                  << " meters\n";
        seconds++;
        currentBallHeight =
            towerHeight - (Constant::gravity * (seconds * seconds) / 2.0);
    }

    std::cout << "At " << seconds << " seconds, the ball is on the ground.\n";
}
} // namespace
///////////////

int main()
{

    const double towerHeight{getTowerHight()};

    calculateAndPrintBallFall(towerHeight);
}
