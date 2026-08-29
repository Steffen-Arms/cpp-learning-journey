
#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

struct Player
{
    int playerScore{0};
    std::vector<Card> playerCards;

    void addCard(Card newCard)
    {
        playerCards.push_back(newCard);
        playerScore += Card::rankValues[newCard.thisCardRank];
    }

    int getPlayerScore()
    {
        int score{0};
        for (Card item : playerCards)
        {
            score += Card::rankValues[item.thisCardRank];
        }
        return score;
    }
};

#endif
