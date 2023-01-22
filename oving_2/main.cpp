
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

// Problem 1b
void inputAndPrintInteger()
{
    cout << "\nInsert a number: ";
    int userInputInteger = 0;
    cin >> userInputInteger;
    cout << "You wrote: " << userInputInteger << "\n" << endl;
}

// Problem 1c
int inputInteger()
{
    cout << "Insert number: ";
    int userInput = 0;
    cin >> userInput;

    return userInput;
}

// Problem 1d
void inputIntegersAndPrintSum()
{
	int userInput1 = 0;
	int userInput2 = 0;

	cout << "\n";
	userInput1 = inputInteger();
	userInput2 = inputInteger();
	cout << "Sum: " << userInput1+userInput2 << "\n" << endl;
}

// Problem 1e
/*
	I chose to use inputInteger because it returns an integer after prompting the user for input.
	If I had used inputAndPrintInteger I would not be able to sum the two numbers since the function
	is decleared as a void function.
*/

// Problem 1f
bool isOdd(int userProvidedInteger)
{
	if (userProvidedInteger % 2 == 0) {
		return true;
	}
	else {
		return false;
	}
}

// Problem 1g
void printHumanReadableTime(int totalSeconds)
{
	int hours = totalSeconds / 3600;
	int minutes = (totalSeconds % 3600) / 60;
	int seconds = totalSeconds % 60;

	cout << "\n"
		 << hours << " timer, "
		 << minutes << " minutter og "
		 << seconds << " sekunder"
		 << "\n" << endl;
}

// Problem 2a
void inputMultipleIntegersAndPrintSum()
{
	int numbersToSum = 0;
	int number = 0;
	int sum = 0;

	cout << "How many numbers you are summing: ";
	cin >> numbersToSum;

	for(int i = 1; i <= numbersToSum; i++) {
		number = inputInteger();
		sum += number;
	}
	cout << "Sum: " << sum << "\n";
}

// Task 2b
void inputUnlimitedIntegersAndPrintSum()
{
	int number = 0;
	int sum = 0;

	while(1) {
		number = inputInteger();
		if(number != 0) {
			sum += number;
		}
		else {
			break;
		}
	}
	cout << "Summation finished with sum: " << sum << "\n";
}

// Problem 2c
/*
	In a, the problem specifies the user should decide beforehand how many numbers
	should be summed so a for loop is preferred here. In b the user can sum as many
	numbers as they want, so a while loop is most suitable.
*/

// Problem 2d
double inputDouble()
{
	cout << "Insert number: ";
    double userInput = 0.0;
    cin >> userInput;

    return userInput;
}

// Problem 2e
void convertNOKtoEur()
{
	double exchangeRate = 9.75;
	double sumInNOK = 0.0;
	double sumInEur = 0.0;

	cout << "\n";
	sumInNOK = inputDouble();
	if(sumInNOK < 0.0) {
		cout << "You entered a negative number." << endl;
		sumInNOK = inputDouble();
	}
	sumInEur = sumInNOK / exchangeRate;
	cout << fixed << setprecision(2) << sumInNOK << " NOK in Eur is: " << sumInEur << "\n" << endl;
}

// Problem 2f
/*
	Choose to use inputDouble in 2e since the conversion should be done through
	a division by a decimal. If using inputInteger the input is rounded off to
	closest integer and would return a wrong sum in Eur. The function returns
	a double since the user should input a double.
*/

// Problem 2g
void multiplicationTable()
{
	int width = 0;
	int height = 0;

	cout << "\nInput width: ";
	cin >> width;
	cout << "input height: ";
	cin >> height;
	cout << "\n";

	for(int i = 1; i <= height; i++) {
		cout << width << " * " << i << " = " << width * i << endl;
	}
	cout << "\n";
}

// Problem 1a
void menu()
{
	while (1) {
		cout << "Menu\n"
			<< "0)\tExit menu\n"
			<< "1)\tSum two numbers\n"
			<< "2)\tSum several numbers\n"
			<< "3)\tConvert NOK to Euro\n"
			<< "4)\tConvert seconds to time\n"
			<< "5)\tPrint multiplication table\n"
			<< "Choose option (0-5): ";

		int menu_choice;
		cin >> menu_choice;
		
		switch (menu_choice)
		{
		case 1:
			inputIntegersAndPrintSum();
			break;
		case 2:
			for (int i = 0; i <= 15; i++) {
				cout << i << ": ";
				cout << (isOdd(i) ? "true" : "false");
				cout << endl;
			}
			cout << endl;			
			break;
		case 3:
			convertNOKtoEur();
			break;
		
		case 4:
			printHumanReadableTime(10000);
			break;

		case 5:
			multiplicationTable();
			break;

		default:
			return; // quit program
			break;
		}
	}
}




// C++ programs start by executing the function main
int main() {
    // Pint the menu options to the user
    menu();

    // This lets the operating system (Windows, Mac, Linux, etc.) know that the program
    // did not encounter any errors
    return 0;
}

//------------------------------------------------------------------------------
