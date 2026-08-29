#ifndef DECK_H
#define DECK_H
#include "Cards.h"
#include "Random.h"  // for Random::mt
#include <algorithm> // for std::shuffle
#include <assert.h>

class Deck
{

  private:
    static constexpr int deckSize{52};
    std::size_t cardIndex{0};

    std::array<Card, deckSize> m_deck{};

  public:
    constexpr Deck()
    {
        std::size_t index{0};
        for (auto rank : Card::allRanks)
        {
            for (auto suite : Card::allSuits)
            {
                m_deck[index] = Card{rank, suite};
                ++index;
            }
        }
    }

    Card dealCard()
    {
        assert(cardIndex < deckSize && "Deck ran out of cards");
        return m_deck[cardIndex++];
    }

    void shuffle()
    {
        std::shuffle(m_deck.begin(), m_deck.end(), Random::mt);
        cardIndex = 0;
    }
};

#endif
