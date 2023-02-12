#include "Card.hpp"

// Problem 1c
string suitToString(Suit suit)
{
    return suitTextMap.at(suit);
}

// Problem 1d
string rankToString(Rank rank)
{
    return rankTextMap.at(rank);
}

// Problem 2b
Card::Card(Suit suit, Rank rank): s{suit}, r{rank} {};

// Problem 2c
Suit Card::getSuit()
{
    return s;
}

// Problem 2d
Rank Card::getRank()
{
    return r;
}

// Problem 2e
string Card::toString()
{
    return rankToString(r) + " of " + suitToString(s);
}
