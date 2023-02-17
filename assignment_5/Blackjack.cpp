#include "Blackjack.hpp"
#include "Card.hpp"

int Blackjack::getCardValue(Card card)
{
    Rank cardRank = card.getRank();
    int cardRankAsint = static_cast<int>(cardRank);
    return cardRankAsint;
}

// Helper functions:

bool isAce(Card card)
{
    if (rankTextMap.at((card.getRank())) == "Ace") {
        return true;
    }
    else {
        return false;
    }
}