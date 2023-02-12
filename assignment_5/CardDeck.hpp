#pragma once
#include "Card.hpp"

// Problem 3
class CardDeck {
public:
    CardDeck();
    void swap(unsigned int card1, unsigned int card2);
private:
    vector<Card> cards;
};
