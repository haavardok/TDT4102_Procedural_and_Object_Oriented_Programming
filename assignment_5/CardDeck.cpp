#include "CardDeck.hpp"

// Problem 3b
//CardDeck::CardDeck(): cards(52) {};

// Problem 3c
void CardDeck::swap(unsigned int card1, unsigned int card2)
{
    Card temp = cards.at(card1);
    cards.at(card1) = cards.at(card2);
    cards.at(card2) = temp;
}

