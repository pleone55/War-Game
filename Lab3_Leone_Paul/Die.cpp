/*******************************************************************************************
 * Program Name: Die.cpp
 * Author: Paul Leone
 * Date: 7/11/2019
 * Description: This is the .cpp file for the Die class that contains the functions to 
 * 		initialize the member variables and return the score and the random number
 * 		generated from the roll
 *******************************************************************************************/

#include "Die.hpp"
#include <iostream>
#include <cmath>
#include <cstdlib>

/*******************************************************************************
 * This is the constructor that initializes the member variables
 * *****************************************************************************/

Die::Die()
{
	N = 0;
	score = 0;
}

/******************************************************************************
 * This is the member function that takes a reference parameter and initializes
 * the N member variable
 * ****************************************************************************/

void Die::setDie(int &n)
{
	N = n;
}

/******************************************************************************
 * This is the member function that returns the N member variable
 * ****************************************************************************/

int Die::getDie()
{
	return N;
}

/*****************************************************************************
 * This is the member function that increments the total score
 * ***************************************************************************/

void Die::setScore()
{
	score++;
}

/****************************************************************************
 * This is the member function that returns the score member variable
 * **************************************************************************/

int Die::getScore()
{
	return score;
}

/****************************************************************************
 * This is the member function that returns a random number of the die
 * **************************************************************************/

int Die::getRandom()
{
	return (rand() % N + 1);
}
