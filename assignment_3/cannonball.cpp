#include "std_lib_facilities.h"
#include "cannonball.hpp"

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

    cout << "\n"
		 << hours << " timer, "
		 << minutes << " minutter og "
		 << seconds << " sekunder"
		 << "\n" << endl;
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