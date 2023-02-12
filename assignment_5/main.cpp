
#include "std_lib_facilities.h"
#include "Card.hpp"

//-------------------------------------------------------------------------------
/*
    ----Theory problems----
    
    Problem 1e
    By using symbols represented by suit and rank (enum class) for the cards
    instead of integers and strings, every symbol gets its own type. Thus it
    is easier for humans to understand which card one refers to instead of a
    simple integer value. The other advantage is that the compiler can catch
    errors made by the programmer, which it cannot if a card is represented
    by a string.

    Problem 3c
    The function CardDeck::swap() should be public because we want users of
    our code to be able to swap two cards in our CardDeck. If the function
    is kept private, one would not have access to the vector cards.
*/


// C++ programs start by executing the function main
int main() {

    // Problem 1f
    // Rank r = Rank::king;
    // Suit s = Suit::hearts;
    // string rank = rankToString(r);
    // string suit = suitToString(s);
    // cout << "Rank: " << rank << " Suit: " << suit << endl;

    // Problem 2f
    Card c{Suit::spades, Rank::ace};
    cout << c.toString() << endl;

    // This lets the operating system (Windows, Mac, Linux, etc.) know that the program
    // did not encounter any errors
    return 0;
}

//------------------------------------------------------------------------------
