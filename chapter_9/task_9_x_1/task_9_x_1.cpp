#include "random.h" // https://www.learncpp.com/cpp-tutorial/global-random-numbers-random-h/
#include <cstdlib>
#include <iostream>
#include <limits>

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool clearFailedExtraction()
{

    if (!std::cin)
    {
        if (std::cin.eof())
        {
            std::exit(0);
        }

        std::cin.clear();
        ignoreLine();

        return true;
    }
    return false;
}

// return user guess and handel bad user input
int getGuess(int count, int min, int max)
{

    while (true)
    {
        std::cout << "Guess #" << count << ": ";
        int guess{};
        std::cin >> guess;

        if (clearFailedExtraction())
        {
            std::cout << "This input is invalid. Try again \n";
            continue;
        }
        ignoreLine();

        // now check if the guess number is valid
        if (guess < min || guess > max)
        {
            std::cout << "This guess is to big or to small. Try again. \n";
            continue;
        }
        return guess;
    }
}

bool playAgain()
{
    // Keep asking the user if they want to play again until they pick y or n.
    while (true)
    {

        std::cout << "Would you like to play again (y/n)? \n";
        char ch{};
        std::cin >> ch;

        if (clearFailedExtraction())
        {
            std::cout << "Invalid input try again \n";
            continue;
        }
        ignoreLine();

        switch (ch)
        {
        case 'y':
            return true;
        case 'n':
            return false;
        default:
            std::cout << "wrong character! \n";
        }
    }
}

// Returns true if the user won, false if they lost
// We don't use the return value in this program, but it doesn't add complexity
// to have it, and may be useful in a future update (e.g. if we wanted to move
// the won/lost messages out of the function, or conditionalize other behavior
// based on won/lost)
bool playHiLo(int guesses, int min, int max)
{
    std::cout << "Let's play a game. I'm thinking of a number between " << min
              << " and " << max << ". You have " << guesses
              << " tries to guess what it is.\n";
    const int number{
        Random::get(min, max)}; // this is the number the user needs to guess

    // Loop through all of the guesses
    for (int count{1}; count <= guesses; ++count)
    {

        int guess{getGuess(count, min, max)};

        if (guess > number)
            std::cout << "Your guess is too high.\n";
        else if (guess < number)
            std::cout << "Your guess is too low.\n";
        else // guess == number, so the user won
        {
            std::cout << "Correct! You win!\n";
            return true;
        }
    }

    // The user lost
    std::cout << "Sorry, you lose. The correct number was " << number << '\n';
    return false;
}

int main()
{
    constexpr int guesses{7}; // the user has this many guesses
    constexpr int min{1};
    constexpr int max{100};

    do
    {
        playHiLo(guesses, min, max);
    } while (playAgain());

    std::cout << "Thank you for playing.\n";

    return 0;
}
