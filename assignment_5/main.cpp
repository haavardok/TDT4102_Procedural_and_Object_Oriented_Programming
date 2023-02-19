
#include "std_lib_facilities.h"
#include "Blackjack.hpp"

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
    The function CardDeck::swap() should be private because we don't want users
    of our code to be able to swap two cards in our CardDeck. The only time we
    would want to swap cards is when shuffeling the card deck.
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
    // Card c1{Suit::spades, Rank::ace};
    // Card c2{Suit::spades, Rank::jack};
    // Card c3{Suit::spades, Rank::king};
    // Card c4{Suit::spades, Rank::queen};
    // vector<Card> cards = {c1,c2,c3,c4};
    // cout << c.toString() << endl;

    // Testing the CardDeck::print() and CardDeck::swap() function
    //CardDeck cardDeck{};
    //cardDeck.shuffle();
    //cardDeck.print();
    //cardDeck.drawCard();
    
    Blackjack blackjack;
    blackjack.playGame();


    // This lets the operating system (Windows, Mac, Linux, etc.) know that the program
    // did not encounter any errors
    return 0;
}

//------------------------------------------------------------------------------
