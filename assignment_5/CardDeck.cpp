#include "CardDeck.hpp"

// Problem 3b
// Defining the constructor CardDeck():
CardDeck::CardDeck() { 
    // Since no default constructor exists for type 'Card', need to
    // manually put each card into the card deck:
    for (const auto& suit : suitTextMap) {
        for (const auto& rank : rankTextMap) {
            Card c{suit.first, rank.first};
            cards.push_back(c);
        }
    }
};

// Problem 3c
void CardDeck::swap(unsigned int card1, unsigned int card2)
{
    Card temp = cards.at(card1);
    cards.at(card1) = cards.at(card2);
    cards.at(card2) = temp;
}

// Problem 3d
void CardDeck::print()
{
    for (auto card : cards) {
        cout << card.toString() << endl;
    }
}

// Problem 3e
void CardDeck::shuffle()
{
    unsigned int firstCard{0};
    unsigned int lastCard = static_cast<unsigned int>(size(cards)-1);
    unsigned int randomCard{0};
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_int_distribution<unsigned int> distribution(firstCard, lastCard);

    // Shuffle every card in the deck with a random card
    for (unsigned int cardNumber = firstCard; cardNumber <= lastCard; cardNumber++) {
        randomCard = distribution(generator);
        CardDeck::swap(cardNumber, randomCard);
    }
}

// Problem 3f
// Returns a card from the card deck. Removes it from the card deck.
Card CardDeck::drawCard()
{
    Card topCard = cards.back();
    cards.pop_back();
    return topCard;
}
