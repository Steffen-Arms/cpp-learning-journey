#ifndef CARDS_H
#define CARDS_H

#include <array>
#include <iostream>

struct Card
{

    enum cardRank
    {
        rank_ace,
        rank_2,
        rank_3,
        rank_4,
        rank_5,
        rank_6,
        rank_7,
        rank_8,
        rank_9,
        rank_10,
        rank_jack,
        rank_queen,
        rank_king,

        max_ranks
    };

    static constexpr std::array cardRandArray{
        "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    static_assert(cardRandArray.size() == max_ranks);
    static constexpr std::array allRanks{
        rank_ace, rank_2, rank_3,  rank_4,    rank_5,     rank_6,    rank_7,
        rank_8,   rank_9, rank_10, rank_jack, rank_queen, rank_king,
    };
    static_assert(allRanks.size() == max_ranks);

    enum cardSuits
    {
        suit_club,
        suit_diamond,
        suit_heart,
        suit_spade,

        max_suits
    };

    static constexpr std::array cardSuitsArray{"C", "D", "H", "S"};
    static_assert(cardSuitsArray.size() == max_suits);
    static constexpr std::array allSuits{
        suit_club,
        suit_diamond,
        suit_heart,
        suit_spade,
    };
    static_assert(allSuits.size() == max_suits);

    friend std::ostream& operator<<(std::ostream& out, const Card& card)
    {
        out << cardRandArray[card.thisCardRank]
            << cardSuitsArray[card.thisCardSuits];
        return out;
    }

    static constexpr std::array rankValues{11, 2, 3,  4,  5,  6, 7,
                                           8,  9, 10, 10, 10, 10};
    static_assert(rankValues.size() == max_ranks);

    int getValue() const { return rankValues[thisCardRank]; }

    cardRank thisCardRank{};
    cardSuits thisCardSuits{};
};

#endif
