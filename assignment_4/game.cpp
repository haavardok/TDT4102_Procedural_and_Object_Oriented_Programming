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

    // Problem 4b
    string code{""};
    string guess{""};

    // Problem 4c
    code = randomizeString(size, 'A', 'A' + (letters - 1));
    //cout << code << endl;

    // Problem 4d
    guess = readInputToString(size, 'A', 'A' + (letters - 1));
    //cout << guess << endl;

    // Problem 4e
    cout << "There are " << checkCharactersAndPosition(code, guess)
         << " correct letter(s) in the correct place"
         << endl;

    // Problem 4f
    cout << "There are " << checkCharacters(code, guess, letters)
         << " correct letter(s)"
         << endl;
}

// Problem 4e
int checkCharactersAndPosition(const string& code, const string& guess)
{
    int correctGuesses{0};

    for (int i = 0; i < static_cast<int>(guess.size()); i++) {
        if (guess[i] == code[i]) {
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
        if ((code.find('A' + i) != string::npos) && (guess.find('A' + i) != string::npos)) {
            countGuess = countChar(guess, ('A' + i));
            countCode = countChar(code, ('A' + i));

            if (countGuess != countCode) {
                countGuess = countCode;
            }
            correctGuesses += countGuess;
        }
    }

    return correctGuesses;
}