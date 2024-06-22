
#include "CodemonForestheader.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
char explore(int& Time, char previoustype)
{


	int randLetterEquivalent = 0; // random letter represented by a number 1-26 generated randomly
	static int tempRock = 0; // holds a rock type amount as a static variable so the total amount doesnt change everytime explore() is called
	static int tempDragon = 0; // holds a dragon type amount as a static variable so the total amount doesnt change everytime explore() is called
	static int tempPosion = 0;// holds a poison type amount as a static variable so the total amount doesnt change everytime explore() is called
	static int tempFlying = 0;// holds a flying type amount as a static variable so the total amount doesnt change everytime explore() is called
	static int tempBug = 0;// holds a bug type amount as a static variable so the total amount doesnt change everytime explore() is called
	static int tempWater = 0;// holds a water type amount as a static variable so the total amount doesnt change everytime explore() is called
	const int Z_EQUIVALENT = 26; //The letter Z is represented by 26
	const int A_EQUIVALENT = 1;//The letter A is represented by 1
	const int F_EQUIVALENT = 6;//The letter F is represented by 6
	const int P_EQUIVALENT = 16;//The letter P is represented by 16
	const int R_EQUIVALENT = 18;//The letter R is represented by 18
	const int B_EQUIVALENT = 2;//The letter B is represented by 2
	const int W_EQUIVALENT = 23;//The letter W is represented by 23
	int i = 0; //for upcoming while loop
	while (i == 0) //ensures while loop keeps going untul a codemon charcter type is found and returned
	{
		
		randLetterEquivalent = rand() % (Z_EQUIVALENT) + A_EQUIVALENT; //generates letter reprsented by an int 1 - 26
		Time = Time + 1; // Time represents the value TimeCount, which  is passed by refrence to keep track of time units in main.
		if (randLetterEquivalent == F_EQUIVALENT) // is random letter integer is 6 that mines that randdomly generated integer is F for flying type so that means the user just encounterd a flying type codemon.
		{
			tempFlying++;// adds a flying type encounter to flying type total in this function
			if ('F' == int(previoustype)) // if flying type was encounterd last encounter that means user just encountered a rare dragon type
			{
				tempFlying--; //Flying type is now a dragon type so subratact and add to tempDragon
				tempDragon++;
				return 'D'; //return charcter D for dragon

			}
			else
			{
				return 'F'; //return F for flying.

			}
		}
		if (randLetterEquivalent == P_EQUIVALENT)
		{
			tempPosion++;
			if ('P' == int(previoustype))
			{
				tempPosion--;
				tempDragon++;
				return 'D';

			}
			else
			{
				return 'P';

			}
		}
		if (randLetterEquivalent == R_EQUIVALENT)
		{
			tempRock++;
			if ('R' == int(previoustype))
			{
				tempRock--;
				tempDragon++;
				return 'D';

			}
			else
			{
				return 'R';

			}
		}
		if (randLetterEquivalent == B_EQUIVALENT)
		{
			tempBug++;
			if ('B' == int(previoustype))
			{
				tempBug--;
				tempDragon++;
				return 'D';

			}
			else
			{
				return 'B';

			}
		}
		if (randLetterEquivalent == W_EQUIVALENT)
		{
			tempWater++;
			if ('W' == int(previoustype))
			{
				tempWater--;
				tempDragon++;
				return 'D';

			}
			else
			{
				return 'W';

			}
		}
	}




}