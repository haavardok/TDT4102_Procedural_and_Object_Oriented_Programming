#pragma once
#include "CardDeck.hpp"

class Blackjack {
public:
    int getCardValue(Card card);
private:
    CardDeck deck;
    vector<Card> playerHand;
    vector<Card> dealerHand;
    int playerHandSum;
    int dealerHandSum;
};

bool isAce(Card card);
