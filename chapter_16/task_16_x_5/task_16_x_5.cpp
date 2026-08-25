#include "random.h"
#include <cctype>
#include <iostream>
#include <string_view>

namespace Settings
{
constexpr int maxWrongGuess{6};
}

namespace WordList
{

std::vector<std::string_view> words{"mystery",   "broccoli",  "account",
                                    "almost",    "spaghetti", "opinion",
                                    "beautiful", "distance",  "luggage"};

std::string_view getRandomWord()
{
    return words.at((Random::get<std::size_t>(0, words.size() - 1)));
}

} // namespace WordList

void startMessage()
{
    std::cout << "Welcome to C++man (a variant of Hangman) \n";
    std::cout << "To win: guess the word.  To lose: run out of pluses. \n";
}

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

bool checkInput(char inputUser)
{
    return std::isalpha(static_cast<unsigned char>(inputUser)) &&
           std::islower(inputUser);
}

///////////////////////////////
/////////////////////////////////////

class Session
{
  private:
    std::string_view gameWord{};

    std::vector<char> alreadyGuessedLetters{
        std::vector<char>(26, 'f')}; // 26 as there are 26 char in the alphabet

    std::vector<char> stackWrongGuesses{};

    void updateGuessedLetters(char inputUser)
    {
        alreadyGuessedLetters.at(static_cast<std::size_t>(inputUser - 'a')) =
            't';
    }

    bool isCharInWord(char inputUser)
    {
        for (char c : gameWord)
        {
            if (c == inputUser)
            {
                return true;
            }
        }
        return false;
    }

    void updateWrongGuesses(char inputUser)
    {
        if (!isCharInWord(inputUser))
        {
            std::cout << "Sry, '" << inputUser << "' is not in the word! \n";
            stackWrongGuesses.push_back(inputUser);
        }
    }

    bool alreadyGuessed(char letter)
    {
        if (alreadyGuessedLetters.at(static_cast<std::size_t>(letter - 'a')) ==
            't')
        {
            return true;
        }
        else
        {
            return false;
        }
    }

  public:
    std::string_view getWord() const { return gameWord; }

    Session(std::string_view word) { gameWord = word; }

    bool won()
    {
        for (char c : gameWord)
        {
            if (!alreadyGuessed(c))
            {
                return false;
            }
        }
        return true;
    }

    int getAmoungOfWrongGuesses()
    {
        return static_cast<int>(stackWrongGuesses.size());
    }

    void stateOfTheGame()
    {
        std::size_t wordLength{static_cast<size_t>(gameWord.length())};

        std::cout << "The word: ";
        for (std::size_t i{0}; i < wordLength; ++i)
        {
            if (alreadyGuessed(gameWord.at(i)))
            {
                std::cout << gameWord.at(i);
            }
            else
            {
                std::cout << "_";
            }
        }
        std::cout << "  ";
        std::cout << "Wrong guesses: ";
        std::cout << std::string(
            static_cast<std::size_t>(Settings::maxWrongGuess -
                                     getAmoungOfWrongGuesses()),
            'x');

        for (char c : stackWrongGuesses)
        {
            std::cout << c;
        }
        std::cout << '\n';
    }

    // also update the alreadyGuessedWords vector
    char getUserGuess()
    {

        while (true)
        {
            std::cout << "Enter your next letter: ";
            char inputUser{};
            std::cin >> inputUser;

            if (clearFailedExtraction())
            {
                std::cout << "Invalid Input. Please try again \n";
                continue;
            }
            if (!checkInput(inputUser))
            {
                std::cout << "Invalid Input. Not a lower case char \n";
                continue;
            }
            if (alreadyGuessed(inputUser))
            {
                std::cout << "You already guessed that. Try again \n";
                continue;
            }
            ignoreLine();
            updateWrongGuesses(inputUser);
            updateGuessedLetters(inputUser);
            return inputUser;
        }
    }
};

int main()
{

    startMessage();
    std::string_view randomWord = WordList::getRandomWord();

    Session newSession{randomWord};

    while (newSession.getAmoungOfWrongGuesses() < Settings::maxWrongGuess &&
           !newSession.won())
    {
        newSession.stateOfTheGame();
        newSession.getUserGuess();
        std::cout << '\n';
    }

    newSession.stateOfTheGame();

    if (newSession.getAmoungOfWrongGuesses() == Settings::maxWrongGuess)
    {
        std::cout << "You lost! Maybe next time. The word is: "
                  << newSession.getWord() << '\n';
    }
    else
    {
        std::cout << "You got it, champ! \n";
    }
}
