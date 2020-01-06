/************************************************************************************
 * Program Name: Die.hpp
 * Author: Paul Leone
 * Date: 7/11/2019
 * Description: This is the header file for the Die class that has a member variable
 * 		that repesents the number of sides of the die and a function that
 * 		returns a random integer depending on die size.
 ************************************************************************************/

#ifndef DIE_HPP
#define DIE_HPP

class Die
{	private:
		int score;		//increment the score

	protected:
		int N;

	public:
		Die();
		void setDie(int &);	//reference parameter to initialize N
		int getDie();
		void setScore();
		int getScore();
		virtual int getRandom();
};
#endif
