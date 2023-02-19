#pragma once
#include "CardDeck.hpp"

class Blackjack {
public:
    void playGame(void);
private:
    CardDeck deck;
    vector<Card> playerHand;
    vector<Card> dealerHand;
    int playerHandSum;
    int dealerHandSum;

    bool isAce(Card card);
    int getCardValue(Card card);
    int getHandScore(vector<Card> cardsOnHand);
    bool askPlayerDrawCard(void);
    void drawPlayerCard(void);
    void drawDealerCard(void);
};
