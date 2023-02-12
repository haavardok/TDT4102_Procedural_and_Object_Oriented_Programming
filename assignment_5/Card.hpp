#pragma once
#include "std_lib_facilities.h"

// Problem 1a
enum class Suit {clubs = 1, diamonds, hearts, spades};

// Problem 1b
enum class Rank {two = 2, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace};

// Problem 1c
const std::map<Suit, string> suitTextMap {
    {Suit::clubs, "Clubs"},
    {Suit::diamonds, "Diamonds"},
    {Suit::hearts, "Hearts"},
    {Suit::spades, "Spades"}
};

string suitToString(Suit suit);

// Problem 1d
const std::map<Rank, string> rankTextMap {
    {Rank::two, "Two"},
    {Rank::three, "Three"},
    {Rank::four, "Four"},
    {Rank::five, "Five"},
    {Rank::six, "Six"},
    {Rank::seven, "Seven"},
    {Rank::eight, "Eight"},
    {Rank::nine, "Nine"},
    {Rank::ten, "Ten"},
    {Rank::jack, "Jack"},
    {Rank::queen, "Queen"},
    {Rank::king, "King"},
    {Rank::ace, "Ace"},
};

string rankToString(Rank rank);

// Problem 2a and 2b
class Card {
public:
    Card(Suit suit, Rank rank);
    Suit getSuit();
    Rank getRank();
    string toString();
private:
    Suit s;
    Rank r;
};
