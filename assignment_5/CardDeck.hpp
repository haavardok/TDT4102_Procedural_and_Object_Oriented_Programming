#pragma once
#include "Card.hpp"

// Problem 3
class CardDeck {
public:
    CardDeck(void);
    void print(void);
    void shuffle(void);
    Card drawCard(void);
private:
    vector<Card> cards;
    void swap(unsigned int card1, unsigned int card2);
};
