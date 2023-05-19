#include "std_lib_facilities.h"
#include "game.hpp"
#include "utilities.hpp"

// Problem 4a
void playMastermind(void)
{
    /*
        Defining variables with constexpr because these constants are known
        before compiling takes place. If constant is not known beforehand, 
        const is to be used instead.
    */
    constexpr int size{4};
    constexpr int letters{6};

    int numTriesLeft{10};

    // Problem 4b
    string code{""};
    string guess{""};

    // Problem 4c
    code = randomizeString(size, 'A', 'A' + (letters - 1));
    //cout << code << endl;

    // Problem 4d, 4g and 4h
    while((checkCharactersAndPosition(code, guess) < size) && numTriesLeft >= 1) {
        guess = readInputToString(size, 'A', 'A' + (letters - 1));
    
        // Problem 4e
        cout << "There are " << checkCharactersAndPosition(code, guess)
            << " correct letter(s) in the correct place"
            << endl;

        // Problem 4f
        cout << "There are " << checkCharacters(code, guess, letters)
            << " correct letter(s)"
            << endl;

        numTriesLeft--;
        if (guess == code) {
            break;
        }
        cout << numTriesLeft << " tries left.\n" << endl;
    }

    // Problem 4j
    if (numTriesLeft >= 1) {
        cout << "Congratulations, you guessed the code!" << endl;
    }
    else {
        cout << "You did not manage to guess correct this game. Better luck next time." << endl;
    }
}

// Problem 4e
int checkCharactersAndPosition(const string& code, const string& guess)
{
    int correctGuesses{0};

    for (unsigned int i = 0; i < static_cast<unsigned int>(guess.size()); i++) {
        if (guess.at(i) == code.at(i)) {
            correctGuesses++;
        }
    }

    return correctGuesses;
}

// Problem 4f
int checkCharacters(const string& code, const string& guess, const int& letters)
{
    int correctGuesses{0};
    int countGuess{0};
    int countCode{0};
    
    for (int i = 0; i < letters; i++) {
        if ((code.find(static_cast<char>('A' + i)) != string::npos) && (guess.find(static_cast<char>('A' + i)) != string::npos)) {
            countGuess = countChar(guess, (static_cast<char>('A' + i)));
            countCode = countChar(code, (static_cast<char>('A' + i)));

            if (countGuess != countCode) {
                countGuess = countCode;
            }
            correctGuesses += countGuess;
        }
    }

    return correctGuesses;
}