/**************************************************************************************
 * Program Name: LoadedDie.hpp
 * Author: Paul Leone
 * Date: 7/11/2019
 * Description: This is the header for for the LoadedDie class that is an instance
 * 		of the Die class that returns the results of the loaded die
 **************************************************************************************/

#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP
#include "Die.hpp"

class LoadedDie : public Die
{	private:
		int score;
	public:
		LoadedDie();
		int getScore();
		int getRandom();
};
#endif
