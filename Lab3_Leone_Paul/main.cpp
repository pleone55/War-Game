/*****************************************************************************************
 * Program Name: main.cpp
 * Author: Paul Leone
 * Date: 7/11/2019
 * Description: This is the main function that runs the War Game program
 * ***************************************************************************************/

#include "Die.hpp"
#include "LoadedDie.hpp"
#include "Validate.hpp"
#include "Game.hpp"
#include <iostream>
#include <ctime>
#include <memory>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::shared_ptr;

int main()
{
	srand(time(0));
	Game war;						//game object

	//Prompt user to either play the game or quit
	int menu = war.gameMenu();

	//Create switch case to determine if the user wants to play or quit
	switch(menu)
	{
		case 1:						//plays the game
		{
			war.Rounds();
			int type = war.dieType();

			//create another switch to determine the type of die each player has
			switch(type)
			{
				case 1:				//Player 1 is regular and player 2 is loaded
				{
					shared_ptr<Die> player1 = shared_ptr<Die>(new Die());
					shared_ptr<Die> player2 = shared_ptr<Die>(new LoadedDie());
					war.setPlayer1(player1);
					war.setPlayer2(player2);
					war.game();
					war.Simulate();
				}
				break;

				case 2:				//Player 1 is loaded player 2 is loaded
				{
					shared_ptr<Die> player1 = shared_ptr<Die>(new LoadedDie());
					shared_ptr<Die> player2 = shared_ptr<Die>(new LoadedDie());
					war.setPlayer1(player1);
					war.setPlayer2(player2);
					war.game();
					war.Simulate();
				}
				break;

				case 3:				//Player 1 is loaded player 2 is regular
				{
					shared_ptr<Die> player1 = shared_ptr<Die>(new LoadedDie());
					shared_ptr<Die> player2 = shared_ptr<Die>(new Die());
					war.setPlayer1(player1);
					war.setPlayer2(player2);
					war.game();
					war.Simulate();
				}
				break;

				case 4:				//Player 1 is regular player 2 is regular
				{
					shared_ptr<Die> player1 = shared_ptr<Die>(new Die());
					shared_ptr<Die> player2 = shared_ptr<Die>(new Die());
					war.setPlayer1(player1);
					war.setPlayer2(player2);
					war.game();
					war.Simulate();
				}
				break;

			}
			break;
		}
		break;

		case 2:						//User quits the game
		{
			war.Quit();
		}
		break;
	}

	return 0;
}
