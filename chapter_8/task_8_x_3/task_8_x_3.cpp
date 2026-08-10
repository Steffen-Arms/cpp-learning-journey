#include "random.h"
#include <iostream>

int main()
{

    while (true)
    {
        std::cout << "Ich denke mir eine Zahl zwischen 1 und 100 aus und du "
                     "musst die erraten. Du hast 7 versuche. \n";

        std::uniform_int_distribution myRandom{1, 100};

        int myRandomNumber = myRandom(Random::mt);

        bool won = false;
        int guess;
        for (int i{1}; i <= 7; i++)
        {
            std::cout << "Guess # " << i << ": ";
            std::cin >> guess;
            std::cout << "\n";
            if (guess == myRandomNumber)
            {
                char playagain{'a'};
                do
                {
                    won = "true";
                    std::cout << "Gluckwunsch du hast gewonnnen. Willst du "
                                 "nochmal spielen? (y/n) \n";

                    std::cin >> playagain;
                } while (playagain != 'y' && playagain != 'n');

                if (playagain == 'n')
                {
                    return 0;
                }
                else
                {
                    break;
                }
            }
            else if (guess < myRandomNumber)
            {
                std::cout << "Deine Zahl ist zu niedrig \n";
            }
            else
            {
                std::cout << "Deine Zahl ist zu hoch \n";
            }
        }

        if (!won)
        {
            char playagain{'a'};
            std::cout
                << "sorry, dass nachste mal klappt es. Die richtige zahl war: "
                << myRandomNumber << '\n';
            do
            {
                std::cout << "Willst du nochmal spielen? (y/n)";
                std::cin >> playagain;
                std::cout << '\n';
            } while (playagain != 'y' && playagain != 'n');

            if (playagain == 'n')
                break;
        }
    }

    return 0;
}
