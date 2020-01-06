/**********************************************************************************
 * Program Name: Game.hpp
 * Author: Paul Leone
 * Date: 7/11/2019
 * Description: This is the header file for the Game class that runs the War Game
 * 		simulation
 **********************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP
#include "Die.hpp"
#include "LoadedDie.hpp"
#include "Validate.hpp"
#include <string>
#include <vector>
#include <memory>

using std::string;
using std::vector;
using std::shared_ptr;

class Game
{	private:
		int rounds;
		int playerType;				//type of die selected
		int playerSides;			//how many sides on each die
		string winner;				//variable to display winner
		shared_ptr<Die> player1;
		shared_ptr<Die> player2;
	public:
		Game();
		int gameMenu();

		void setPlayer1(shared_ptr<Die> p1){	//initialize player 1
			player1 = p1;}
		shared_ptr<Die> getPlayer1(){
			return player1;}
		void setPlayer2(shared_ptr<Die> p2){	//initialize player 2
			player2 = p2;}
		shared_ptr<Die> getPlayer2(){
			return player2;}

		int Rounds();				//Ask user for number of rounds then validate input
		int dieType();				//Asker user for die type then validate input
		int setSides();				//initializes playerSides to sides() function
		int Sides();				//Ask user for the number of sides then validate input
		int getSides();
		string getWinner();			//returns the winner
		void game();				//sets up the game
		void Score(int, int);			//increment the score
		void roundWinner(int, int);		//determine the winner of each round
		void Winner();				//Determine the final winner of the game
		void Simulate();			//runs the game
		void Quit();				//quits the game 
};
#endif
