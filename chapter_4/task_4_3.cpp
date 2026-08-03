#include <iostream>

void ball_height(double tower_hight, int seconds)
{
    double current_hight = tower_hight - 9.8 * seconds * seconds / 2;

    if (current_hight > 0)
        std::cout << "At " << seconds
                  << " seconds, the ball is at height: " << current_hight
                  << " meters \n";
    else
        std::cout << "At " << seconds
                  << " seconds, the ball is at height: " << 0 << " meters \n";
}

int main()
{
    double tower_hight;

    std::cout << "Enter the height of the tower in meters: ";
    std::cin >> tower_hight;

    ball_height(tower_hight, 0);
    ball_height(tower_hight, 1);
    ball_height(tower_hight, 2);
    ball_height(tower_hight, 3);
    ball_height(tower_hight, 4);
    ball_height(tower_hight, 5);
}
