/************************************************************************************
 * Program Name: LoadedDie.cpp
 * Author: Paul Leone
 * Date: 7/11/2019
 * Description: This is the .cpp file of the LoadedDie class that is an instance of
 * 		the Die class. Initializes and returns the loaded die result
 ************************************************************************************/

#include "LoadedDie.hpp"
#include <iostream>
#include <cmath>
#include <cstdlib>

/*******************************************************************************
 * Constructor that initializes the score member variable
 * *****************************************************************************/

LoadedDie::LoadedDie() : Die()
{
	score = 0;
}

/*******************************************************************************
 * Member function that returns the score member variable
 * *****************************************************************************/

int LoadedDie::getScore()
{
	return score;
}

/******************************************************************************
 * Member function that returns the loaded number
 * ****************************************************************************/

int LoadedDie::getRandom()
{
	if(rand() % 2 == 0){
		int t = 0;
		t = rand() % 4 + 3;
		return t;
	}
	else{
		int i = 0;
		i = rand() % N + 1;
		return i;
	}
}
