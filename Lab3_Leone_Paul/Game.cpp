/*************************************************************************************
 * Program Name: Game.cpp
 * Author: Paul Leone
 * Date: 7/11/2019
 * Description: This is the .cpp file for the Game class that sets up the War Game.
 * ***********************************************************************************/

#include "Game.hpp"
#include "Die.hpp"
#include "LoadedDie.hpp"
#include "Validate.hpp"
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::shared_ptr;

/****************************************************************************
 * This is the Game constructor that initializes the member variables
 * **************************************************************************/

Game::Game()
{
	winner = " ";
	playerType = 0;
	playerSides = 0;
}

/***************************************************************************
 * This is the menu function that displays the menu options for the user
 * *************************************************************************/

int Game::gameMenu()
{
	int choice;
	bool input = false;

	//display the menu options for the game
	cout << "\n";
	cout << "--War Game with Dice Design--\n";
	cout << "1. Play game\n";
	cout << "2. Exit game\n";

	//read and validate user input
	while(!input){
		cin >> choice;

		//validate for proper input
		if(cin.fail()){
			cin.clear();
			cin.ignore();
			cout << "Please enter an integer choice\n";
		}
		else if(choice < 0 || choice > 2){
			cout << "Please enter an integer from the choices given\n";
		}
		else
			input = true;
	}

	return choice;
}

/********************************************************************************
 * This is the member function that prompts the user for the number of rounds
 * then validates user input.
 * ******************************************************************************/

int Game::Rounds()
{
	string s = " ";
	bool input = false;

	//Prompt user and validate user input
	cout << "Please enter the number of rounds you would like to play: ";
	
	while(!input){
		cin >> rounds;
		cout<< "\n";

		//validate if integer was used
		if(cin.fail()){
			cin.clear();
			cin.ignore();
			cout << "Please enter an integer to continue\n";
		}
		else if(s.empty()){
			cin.clear();
			cin.ignore();
			cout << "Cannot be left blank\n";
		}
		else
			input = true;
	}

	return rounds;
}

/*******************************************************************************
 * This is the member function that prompts the user for the die type they wish
 * to play with and validates input
 * *****************************************************************************/

int Game::dieType()
{
	string s = " ";
	bool input = false;

	cout << "Please choose the dice type for each of the players\n";
	cout << "1. Player 1: Regular / Player 2: Loaded\n";
	cout << "2. Player 1: Loaded / Player 2: Loaded\n";
	cout << "3. Player 1: Loaded / Player 2: Regular\n";
	cout << "4. Player 1: Regular / Player 2: Regular\n";

	//Validate user input
	while(!input){
		cin >> playerType;

		//Validate if an integer was entered
		if(cin.fail()){
			cin.clear();
			cin.ignore();
			cout << "Please enter an integer choice\n";
		}
		else if(s.empty()){
			cin.clear();
			cin.ignore();
			cout << "Cannot be left empty\n";
		}
		else if(playerType < 0 || playerType > 4){
			cin.clear();
			cin.ignore();
			cout << "Please choose from the options listed\n";
		}
		else
			input = true;
	}

	return playerType;
}

/********************************************************************************
 * This is the member function that returns the player type of dice
 * ******************************************************************************/

/*int Game::getType()
{
	return playerType;
}
*/
/*******************************************************************************
 * This is the member function that initializes the playerSides member variable
 * to the Sides() function
 * *****************************************************************************/

int Game::setSides()
{
	playerSides = Sides();
}

/******************************************************************************
 * This is the member function that prompts the user for the number of sides
 * of each of the player's die and validates input
 * ****************************************************************************/

int Game::Sides()
{
	int sides; 
	string s = " ";
	bool input = false;

	cout << "Enter the number of sides for the player's die, no greater than 20: ";
	
	//Validate input
	while(!input){
		cin >> sides;

		if(cin.fail()){
			cin.clear();
			cin.ignore();
			cout << "Please enter an integer\n";
		}
		else if(s.empty()){
			cin.clear();
			cin.ignore();
			cout << "Cannot be empty\n";
		}
		else if(sides < 0 || sides > 20){
			cin.clear();
			cin.ignore();
			cout << "Please enter an integer from 1-20\n";
		}
		else
			input = true;
	}

	return sides;
}

/******************************************************************************
 * This is the member function that returns the playerSides variable
 * ****************************************************************************/

int Game::getSides()
{
	return playerSides;
}

/*************************************************************************
 * This is the member function that returns the winner
 * ***********************************************************************/

string Game::getWinner()
{
	return winner;
}

/*******************************************************************************
 * This is the member function that sets the game up and sets up dice size
 * *****************************************************************************/

void Game::game()
{
	cout << "Player 1\n";
	int die1 = setSides();			//set the sides for player 1
	player1->setDie(die1); 

	cout << "Player 2\n";
	int die2 = setSides();			//set the sides for player 2
	player2->setDie(die2);
}

/*****************************************************************************
 * This is the member function that increments the score of each player 
 * after each roll and each round
 * ***************************************************************************/

void Game::Score(int roll1, int roll2)
{
	int p1Score = 0, p2Score = 0;

	//initialize the variables
	p1Score = roll1;
	p2Score = roll2;

	//Determine point system for the players for each roll
	if(p1Score > p2Score){
		player1->setScore();
	}
	else if(p1Score < p2Score){
		player2->setScore();
	}
	else if(p1Score == p2Score){
		cout << "No points awarded. It is a tie.\n";
	}
}

/****************************************************************************
 * This is the member function that determines the winner of each round
 * **************************************************************************/

void Game::roundWinner(int roll1, int roll2)
{
	if(roll1 > roll2){
		cout << "\nPlayer 1 wins\n";
	}
	else if(roll1 < roll2){
		cout << "\nPlayer 2 wins\n";
	}
	else if(roll1 == roll2){
		cout << "\nIt is a tie\n";
	}
}

/**************************************************************************
 * This is the member function that determines the final winner
 * ************************************************************************/

void Game::Winner()
{
	int p1Score = player1->getScore();
	int p2Score = player2->getScore();

	//Determine the winner and display the winner
	if(p1Score > p2Score){
		winner = "Player 1";
	}
	else if(p1Score < p2Score){
		winner = "Player 2";
	}
	else if(p1Score == p2Score){
		winner = "Tie";
	}
}

/*************************************************************************
 * This is the member function that runs the simulation of the game
 * ***********************************************************************/

void Game::Simulate()
{
	string p1 = " ", p2 = " ";			//string variables used to display results

	//Determine the type of dice for each player calling appropriate functions
	if(playerType == 1){
		p1 = "Regular Dice";
		p2 = "Loaded Dice";
	}
	else if(playerType == 2){
		p1 = "Loaded Dice";
		p2 = "Loaded Dice";
	}
	else if(playerType == 3){
		p1 = "Loaded Dice";
		p2 = "Regular Dice";
	}
	else if(playerType == 4){
		p1 = "Regular Dice";
		p2 = "Regular Dice";
	}

	//iterate loop to display each round and increment the score
	for(int i = 0; i < rounds; i++){
		int player1Roll = 0, player2Roll = 0;
		cout << "\n\n";

		cout << "Round: " << (i + 1) << "\n";
		player1Roll = player1->getRandom();
		player2Roll = player2->getRandom();

		//increment the score for each player
		Score(player1Roll, player2Roll);

		//Display the type of die chosen and the number of sides
		cout << "Player 1: " << p1 << " & " << player1->getDie() << " side(s)" << "\n";
		cout << "Player 2: " << p2 << " & " << player2->getDie() << " side(s)" << "\n";

		//Display the number of rolls 
		cout << "Player 1: " << player1Roll << "\n";
		cout << "Player 2: " << player2Roll << "\n";

		//Display the round winner
		roundWinner(player1Roll, player2Roll);
		cout << "Player 1: " << player1->getScore() << "\n";
		cout << "Player 2: " << player2->getScore() << "\n";
	}

	//Display the final score and winner
	cout << "\n\n";
	cout << "Final Score\n";
	cout << "Player 1: " << player1->getScore() << "\n";
	cout << "Player 2: " << player2->getScore() << "\n";
	Winner();
	cout << "\n";
	cout << "Final Winner: " << getWinner() << "\n";
	cout << "\n";
}

/***********************************************************************
 * This is the member function that prompts when the game quits
 * *********************************************************************/

void Game::Quit()
{
	cout << "Game End.\n";
}

