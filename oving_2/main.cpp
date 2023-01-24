
#include "std_lib_facilities.h"
#include "AnimationWindow.h"

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

	for(int j = 1; j <= height; j++) {
		for(int i = 1; i <= width; i++) {
			cout << setw(4) << i * j;
		}
		cout << "\n";
	}
	cout << "\n";
}

// Problem 3a
double discriminant(double a, double b, double c)
{
	return pow(b,2) - 4*a*c;
}

// Problem 3b
void printRealRoots(double a, double b, double c)
{
	double x1 = 0.0;
	double x2 = 0.0;

	if(discriminant(a,b,c) > 0) {
		x1 = (-b - sqrt(discriminant(a,b,c))) / 2*a;
		x2 = (-b + sqrt(discriminant(a,b,c))) / 2*a;
		cout << "x1 = " << fixed << setprecision(2) << x1 << endl;
		cout << "x2 = " << x2 << endl;
	}
	else if(discriminant(a,b,c) == 0) {
		x1 = -b / 2*a;
		cout << "x = " << x1 << endl;
	}
	else {
		cout << "The equation has no real solution ://\n";
	}
}

// Problem 3c
void solveQuadraticEquation()
{
	double a = 0.0;
	double b = 0.0;
	double c = 0.0;

	cout << "\nInsert a, b and c: " << endl;
	a = inputDouble();
	b = inputDouble();
	c = inputDouble();
	printRealRoots(a,b,c);
	cout << "\n";
}

// Problem 3d
/*
	Done in the menu under "Problem 1a".
*/

// Problem 3e
/*
	Done in terminal after running code. Gives results as expected.
*/

// Problem 4
void pythagoras()
{
	Point point1{200,275}, point2{275,275}, point3{200,175};
	AnimationWindow win{100, 100, 500, 500, "Pythagoras"};

	win.draw_triangle(point1, point2, point3, Color::black);
	win.draw_quad(point3, Point{100,175}, Point{100,275}, point1, Color::green_yellow);
	win.draw_quad(point1, Point{200,350}, Point{275,350}, point2, Color::red);
	win.draw_quad(point3, point2, Point{375,200}, Point{300,100}, Color::blue);

	win.wait_for_close();
}

// Problem 5
vector<int> calculateBalance(double deposit, int interest, int years)
{
	vector<int> balance(years);
	balance.at(0) = static_cast<int>(deposit);

	return;
}

void newBalance()
{
	// Balance = Deposit * (1+interest/100)^years
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
			<< "6)\tSolve quadratic equation\n"
			<< "7)\tDraw Pythagoras\n"
			<< "Choose option (0-7): ";

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
		
		case 6:
			solveQuadraticEquation();
			break;

		case 7:
			pythagoras();
			break;

		default:
			return; // quit program
			break;
		}
	}
}




// C++ programs start by executing the function main
int main() {
    // Print the menu options to the user
    menu();

    // This lets the operating system (Windows, Mac, Linux, etc.) know that the program
    // did not encounter any errors
    return 0;
}

//------------------------------------------------------------------------------
