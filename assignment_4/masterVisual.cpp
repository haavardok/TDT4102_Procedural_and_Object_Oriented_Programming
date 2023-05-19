#include "masterVisual.h"
#include "std_lib_facilities.h"
#include "game.hpp"
#include "utilities.hpp"

// Problem 4a
void playMastermindVisual(void)
{
    /*
        Defining variables with constexpr because these constants are known
        before compiling takes place. If constant is not known beforehand, 
        const is to be used instead.
    */

    MastermindWindow mwin{900, 20, winW, winH, 4, "Mastermind"};

    constexpr int size{4};
    constexpr int letters{6};
	constexpr char startLetter{'A'};

    int numTriesLeft{6};

    string code{""};
    string guess{""};

    code = randomizeString(size, startLetter, startLetter + (letters - 1));
	mwin.setCodeHidden(true);
	addGuess(mwin, code, startLetter);
    // cout << code << endl;

    while((checkCharactersAndPosition(code, guess) < size) && numTriesLeft >= 0) {
        guess = mwin.getInput(size, 'A', 'A' + (letters - 1));
    
        cout << "There are " << checkCharactersAndPosition(code, guess)
            << " correct letter(s) in the correct place"
            << endl;

        cout << "There are " << checkCharacters(code, guess, letters)
            << " correct letter(s)"
            << endl;
		
		addGuess(mwin, guess, startLetter);
		addFeedback(mwin, checkCharactersAndPosition(code, guess), checkCharacters(code, guess, letters));

        numTriesLeft--;
        if (guess == code) {
            break;
        }
        cout << numTriesLeft << " tries left.\n" << endl;
    }

    if (numTriesLeft >= 1) {
        cout << "Congratulations, you guessed the code!" << endl;
    }
    else {
        cout << "You did not manage to guess correct this game. Better luck next time." << endl;
    }

	cout << "Closing game ..." << endl;
}

void addGuess(MastermindWindow &mwin, const std::string code, const char startLetter)
{
	Guess newGuess = {code, startLetter};
	mwin.guesses.push_back(newGuess);
}

void addFeedback(MastermindWindow &mwin, const int correctPosition, const int correctCharacter)
{
	mwin.feedbacks.push_back({correctPosition, correctCharacter});
}

void MastermindWindow::drawCodeHider()
{
	if(code_hidden) {
		draw_rectangle(Point{padX, 3 * padY}, winW - size * padX, padY, Color::black);
	}
}

MastermindWindow::MastermindWindow(int x, int y, int w, int h, int size, const std::string &title) 
: AnimationWindow(x, y, w, h, title),
guessBtn{{upperLeftCornerBtn.x, upperLeftCornerBtn.y}, btnW, btnH, "Add"},
guess{{upperLeftCornerInBox.x, upperLeftCornerInBox.y}, inBoxW, inBoxH, ""},
size(size)
{
	add(guess);
	add(guessBtn);
	guessBtn.setCallback(std::bind(&MastermindWindow::newGuess, this));
};

string MastermindWindow::wait_for_guess()
{

	std::map<int, Color> colorConverter{
    {1, Color::red},
    {2, Color::green},
    {3, Color::yellow},
    {4, Color::blue},
    {5, Color::blue_violet},
    {6, Color::dark_cyan}
	};

	while (!button_pressed && !should_close())
	{
		for(int guessIndex = 0; guessIndex < static_cast<int>(guesses.size()); guessIndex++) {
			Guess guess = guesses.at(guessIndex);
			int xPos = padX;
			const int yPos = 3*padY+2*padY*guessIndex;

			for (int i=0; i<size; i++) {
				draw_rectangle({xPos,yPos}, padX, padY, colorConverter.at(guess.code.at(i)-guess.startLetter+1));
				xPos += 2*padX;
			}
		}

		for(int feedbackIndex = 0; feedbackIndex < static_cast<int>(feedbacks.size()); feedbackIndex++) {
			Feedback feedback = feedbacks.at(feedbackIndex);
			int xPos = 9*padX+radCircle;
			const int yPos = 3.5*padY+2*padY*(feedbackIndex+1);
			
			for (int i=0; i<size; i++) {
				Color indicatorColor = Color::beige;
				if (i < feedback.correctPosition) {
					indicatorColor = Color::black;
				}
				else if (i < (feedback.correctPosition + std::max<int>(0,feedback.correctCharacter-feedback.correctPosition))) {
					indicatorColor = Color::grey;
				}
				draw_circle({xPos, yPos}, radCircle, indicatorColor);
				xPos += 2*radCircle;
			}
		}

		drawCodeHider();
		next_frame();
	}

	button_pressed = false;

	string newGuess = guess.getText();
	guess.setText("");
	
	return newGuess;
}

string MastermindWindow::getInput(unsigned int n, char lower, char upper)
{
	bool validInput = false;
	string guess;
	while (!validInput && !should_close())
	{
		guess.clear();
		string input = wait_for_guess();
		if (input.size() == n)
		{
			for (unsigned int i = 0; i < n; i++)
			{
				char ch = input.at(i);
				if (isalpha(ch) && toupper(ch) <= upper && lower <= toupper(ch))
				{
					guess += toupper(ch);
				}
				else
					break;
			}
		}
		if (guess.size() == n)
		{
			validInput = true;
		}
		else
		{
			cout << "Invalid input guess again" << endl;
		}
	}
	return guess;
}

void MastermindWindow::setCodeHidden(bool hidden) {
	code_hidden = hidden;
}
