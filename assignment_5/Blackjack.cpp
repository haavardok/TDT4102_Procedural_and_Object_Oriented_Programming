#include "Blackjack.hpp"
#include "Card.hpp"

// Problem 4b
bool Blackjack::isAce(Card card)
{
    if (rankTextMap.at((card.getRank())) == "Ace") {
        return true;
    }
    else {
        return false;
    }
}

// Problem 4c
int Blackjack::getCardValue(Card card)
{
    Rank cardRank = card.getRank();
    int cardRankAsInt = static_cast<int>(cardRank);
    return cardRankAsInt;
}

// Problem 4d
int Blackjack::getHandScore(vector<Card> cardsOnHand)
{
    int score{0};

    for (const auto& card : cardsOnHand) {
        if ((score >= 11) && (isAce(card))) {
            score += 1;
        }
        else if (isAce(card)) {
            score += 11;
        }
        else if ((getCardValue(card) > 10) && (getCardValue(card) < 14)) {
            score += 10;
        }
        else {
            score += getCardValue(card);
        }
    }
    return score;
}

// Problem 4e
bool Blackjack::askPlayerDrawCard()
{
    string answer{""};
    cout << "Draw another card? [y/n] ";
    cin >> answer;

    if (answer == "y") return true;
    else return false;
}

// Problem 4f
void Blackjack::drawPlayerCard()
{
    Card drawnCard = deck.drawCard();
    playerHand.push_back(drawnCard);
    playerHandSum = getHandScore(playerHand);
    cout << "You got:\t" << drawnCard.toString() << endl;
}

void Blackjack::drawDealerCard()
{
    Card drawnCard = deck.drawCard();
    dealerHand.push_back(drawnCard);
    dealerHandSum = getHandScore(dealerHand);
    //cout << "Dealer got:\t" << drawnCard.toString() << endl;
}

// Problem 4g
void Blackjack::playGame()
{
    // Defining constants and variables for game:
    constexpr int blackJack{21};
    bool playerWin{false};

    // Shuffeling the card deck before playing:
    deck.shuffle();

    // Game starts by dealing two cards to both player and dealer:
    drawPlayerCard();
    drawPlayerCard();
    drawDealerCard();
    drawDealerCard();
    
    cout << "Your hand is:\t\t" << playerHandSum << endl;
    cout << "Dealer's card is:\t" << dealerHand.at(0).toString() << endl;

    while(playerHandSum < 21 && askPlayerDrawCard()) {
        drawPlayerCard();
        cout << "Your hand is:\t\t" << playerHandSum << endl;
    }

    while(dealerHandSum < 17) {
        cout << "Dealer draws a new card." << endl;
        drawDealerCard();
    }

    cout << "Your hand is:\t\t" << playerHandSum << endl;
    cout << "Dealer's hand is:\t" << dealerHandSum << endl;

    if (playerHandSum > blackJack) {
        cout << "You got a too high sum!" << endl;
    }
    else if (dealerHandSum > 21) {
        cout << "Dealer's sum is too high!" << endl;
    }
    else if ((dealerHandSum == blackJack) && (dealerHand.size() == 2)) {
        cout << "Dealer got blackjack!" << endl;
    }
    else if ((playerHandSum == blackJack) && (playerHand.size() == 2)) {
        cout << "You got blackjack!" << endl;
        playerWin = true;
    }
    else if ((dealerHandSum <= blackJack) && (playerHandSum < dealerHandSum)) {
        cout << "The dealer won!" << endl;
    }
    else if ((playerHandSum <= 21) && (playerHandSum > dealerHandSum)) {
        cout << "You won!" << endl;
        playerWin = true;
    }
    else {
        cout << "You and dealer got a draw!" << endl;
    }

    if (playerWin) {
        cout << "You win!" << endl;
    }
}
