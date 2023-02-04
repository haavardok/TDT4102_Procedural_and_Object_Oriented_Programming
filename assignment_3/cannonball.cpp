#include "std_lib_facilities.h"
#include "cannonball.hpp"
#include "utilities.hpp"
#include "cannonball_viz.h"

// Problem 2a
double acclY()
{
    return -9.81;
}

// Problem 2b
double velY(double initVelocityY, double time)
{
    return initVelocityY + acclY() * time;
}

// Problem 2c
double posX(double initPosition, double initVelocity, double time)
{
    return initPosition + (initVelocity * time); // Hor. accl = 0 m/s^2
}

double posY(double initPosition, double initVelocity, double time)
{
    return initPosition + (initVelocity * time) + (acclY() * pow(time,2)) / 2;
}

// Problem 2d
void printTime(double time)
{
    int hours = static_cast<int>(time) / 3600;
    int minutes = (static_cast<int>(time) % 3600) / 60;
    double seconds = fmod(time, 60);

    cout << hours << " hours, "
		 << minutes << " minutes and "
		 << seconds << " seconds"
		 << endl;
}

// Problem 2e
double flightTime(double initVelocity)
{
    return - (2 * initVelocity) / acclY();
}

// Problem 4a
double getUserInputTheta()
{
    double userInput = 0.0;
    cout << "Insert value of Theta: ";
    cin >> userInput;

    return userInput;
}

double getUserInputAbsVelocity()
{
    double userInput = 0.0;
    cout << "Insert value of absolute velocity: ";
    cin >> userInput;

    return userInput;
}

double degToRad(double deg)
{
    return deg * (3.1416 / 180);
}

double getVelocityX(double theta, double absVelocity)
{
    return absVelocity * cos(degToRad(theta));
}

double getVelocityY(double theta, double absVelocity)
{
    return absVelocity * sin(degToRad(theta));
}

vector<double> getVelocityVector(double theta, double absVelocity)
{
    vector<double> velocityVector(2);
    velocityVector.at(0) = getVelocityX(theta, absVelocity);
    velocityVector.at(1) = getVelocityY(theta, absVelocity);

    return velocityVector;
}

// Problem 4b
double getDistanceTraveled(double velocityX, double velocityY)
{
    double timeInAir = flightTime(velocityY);
    return posX(0.0, velocityX, timeInAir);
}

// Problem 4c
double targetPractice(double distanceToTarget, double velocityX, double velocityY)
{
    double distanceTraveled = getDistanceTraveled(velocityX, velocityY);
    return distanceToTarget - distanceTraveled;
}

// Problem 5d
void playTargetPractice()
{
    int    timeSteps{100};
    int    fieldLength{1000};
    int    numberOfGuesses{10};
    char   gameOn{'X'};
    double cannonAngle{0.0};
    double cannonballVelocity{0.0};
    double timeInAir{0.0};
    double distanceToGoal{0.0};
    vector<double> velocityVector(2);

    int goalLocation = randomWithLimits(100,fieldLength);

    cout << "Start game [y/n]: ";
    cin >> gameOn;

    switch(gameOn)
    {
    case 'y':
        cout << "The game will now start with your first guesses of Theta and velocity\n";
        cout << "Goal location is " << goalLocation << " meters away!" << endl;
        
        while(numberOfGuesses) {
            distanceToGoal = static_cast<double>(goalLocation);
            cannonAngle = getUserInputTheta();
            cannonballVelocity = getUserInputAbsVelocity();
            velocityVector = getVelocityVector(cannonAngle, cannonballVelocity);
            timeInAir = flightTime(velocityVector.at(1));
            distanceToGoal = targetPractice(distanceToGoal, velocityVector.at(0), velocityVector.at(1));

            cout << "The air time of the cannonball was ";
            printTime(timeInAir);

            cannonBallViz(static_cast<double>(goalLocation), fieldLength, velocityVector.at(0), velocityVector.at(1), timeSteps);

            if(abs(distanceToGoal) <= 5.0) {
                cout << "\nCongratulations! You hit the target :)\nClosing game ..." << endl;
                break;
            }
            cout << "Miss. The distance to the goal is " << distanceToGoal << " m" << endl;

            if(numberOfGuesses-1 == 0) {
                cout << "\nYou lost!\nClosing game ..." << endl;
                break;
            }
            cout << numberOfGuesses-1 << " tries left. Try again!\n" << endl;
            numberOfGuesses--;
        }
        break;
    case 'n':
        cout << "Quitting game ...";
    default:
        return;
        break;
    }
}