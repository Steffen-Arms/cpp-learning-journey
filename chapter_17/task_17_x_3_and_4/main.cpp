#include "Cards.h"
#include "Deck.h"
#include "Player.h"
#include "inputValidation.h"

namespace Settings
{
int valueDealerStop{17};
int valueGetBusts{21};
} // namespace Settings

void dealerTurn(Player& dealer, Deck& currentDeck)
{
    while (dealer.getPlayerScore() < Settings::valueDealerStop)
    {
        Card newCard{currentDeck.dealCard()};
        dealer.addCard(newCard);
        std::cout << "The dealer flips a " << newCard
                  << ". They now have: " << dealer.playerScore << '\n';
    }
}

// return false if Player already bust, and true overwise
bool playerTurn(Player& player, Deck& currentDeck)
{
    while (true)
    {
        std::cout << "(h) to hit, or (s) to stand: ";
        char userInput;
        std::cin >> userInput;
        ignoreLine();

        if (clearFailedExtraction())
        {
            std::cout << "wrong input try again \n";
            continue;
        }
        else
        {
            switch (userInput)
            {
            case 'h':
            {
                Card newCard{currentDeck.dealCard()};
                player.addCard(newCard);
                std::cout << "You where dealt " << newCard
                          << ". You now have: " << player.playerScore << '\n';
                if (player.playerScore > Settings::valueGetBusts)
                {
                    return false;
                };
                continue;
            }
            case 's':
                return true;
            default:
                std::cout << "Wrong input try again";
                continue;
            }
        }
    }
}

bool playBlackjack()
{
    Deck newDeck{};
    newDeck.shuffle();
    Player player1{};
    Player dealer{};

    player1.addCard(newDeck.dealCard());
    player1.addCard(newDeck.dealCard());

    dealer.addCard(newDeck.dealCard());

    std::cout << "The dealer is showing " << dealer.getPlayerScore() << '\n';
    std::cout << "You have score: " << player1.getPlayerScore() << '\n';

    if (!playerTurn(player1, newDeck))
    {
        return false;
    }
    else
    {
        dealerTurn(dealer, newDeck);
        if (dealer.playerScore > Settings::valueGetBusts)
        {
            std::cout << "The dealer went bust! \n";
            return true;
        }
    }
    if (player1.playerScore > dealer.playerScore)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    if (playBlackjack())
    {
        std::cout << "You win! \n";
    }
    else
    {
        std::cout << "You lose! \n";
    }

    return 0;
}
