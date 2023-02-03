#pragma once

// Problem 1a
double acclY();

// Problem 1b
double velY(double initVelocityY, double time);

// Problem 1c
double posX(double initPosition, double initVelocity, double time);
double posY(double initPosition, double initVelocity, double time);

// Problem 1d
void printTime(double time);

// Problem 1e
double flightTime(double initVelocity);

// Problem 4a
double getUserInputTheta();

double getUserInputAbsVelocity();

double degToRad(double deg);

double getVelocityX(double theta, double absVelocity);

double getVelocityY(double theta, double absVelocity);

vector<double> getVelocityVector(double theta, double absVelocity);

// Problem 4b
double getDistanceTraveled(double velocityX, double velocityY);

// Problem 4c
double targetPractice(double distanceToTarget, double velocityX, double velocityY);
