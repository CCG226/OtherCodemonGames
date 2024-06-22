#include "CodemonForestheader.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
bool capture(int L_arm, int R_arm)//flying type capture function
{
	int Total_arm_span = L_arm + R_arm;//adds up arm lengths to get armspand of user
	return TriangularNumberCheck(Total_arm_span); // checks to see if armspand is triangular if true user captures flying type

}
bool capture(int RandNum)//poison type capture function
{
	const int LOWERBOUNDS = 1; // random number generator cant generate a num below 1
	const int UPPERBOUNDS = 100;// random number generator cant generate a num above 100
	const int SUCCESSVALUE = 43;// determines wheter or not capture is successfull
	bool is_valid_triangle = false; // checks if random number is traingular
	do
	{


		RandNum = rand() % (UPPERBOUNDS) + LOWERBOUNDS;// generates number between 1 and 100
		is_valid_triangle = TriangularNumberCheck(RandNum);// checks to see if Randnum is triangular
	} while (is_valid_triangle == false); // keeps looping until RandNum generates a triangular number
if(RandNum < SUCCESSVALUE)//if RandNum is less than 43 capture is succcessfull
	{
		return true;
	}
	else
		return false;
}
bool capture(int time, int Rock_battle_num, int User_battle_num)//rock type capture function
{
	const int ROCK_BATTLE_LOWERBOUND = 56;// random number generator cant generate a num below 56
	const int ROCK_BATTLE_UPPERBOUND = 4587;// random number generator cant generate a num above 4587
	bool is_valid_triangle= false;// checks if random number is traingular
	do
	{
	  Rock_battle_num = rand() % (ROCK_BATTLE_UPPERBOUND - ROCK_BATTLE_LOWERBOUND) + ROCK_BATTLE_LOWERBOUND; //generates random number between 56 - 4587
		is_valid_triangle = TriangularNumberCheck(Rock_battle_num);//checks to see if Random number for rock codemon is triangular
	} while (is_valid_triangle == false);//keeps looping intil triangular number is generated
	is_valid_triangle = false;
	do
	{
		
	  User_battle_num = rand() % (ROCK_BATTLE_UPPERBOUND - ROCK_BATTLE_LOWERBOUND) + ROCK_BATTLE_LOWERBOUND;//generates random number between 56 - 4587
		is_valid_triangle = TriangularNumberCheck(User_battle_num);//checks to see if Random number for user is triangular
	} while (is_valid_triangle == false);//keeps looping intil triangular number is generated
	if ((User_battle_num * time) > Rock_battle_num)// if randomly generated user value multiplied by time units is greater than randomly generated rock codemon number than capture is successful
	{
		return true;
	}
	else
		return false;
}
bool capture(bool pesticide, int WaterType, int PoisonType)//bug type capture function
{
	if (PoisonType >= 1 && WaterType >= 1)// if user has atleast one water type codemon and one poison type codemon the user can make a pesticide
	{
		pesticide = true;
	}
	else
		pesticide = false;
	if (pesticide == true)// if user has pesticide than they can capture the bug type 
	{
		return true;
	}
	else
		return false;
}
bool capture(int random, int Y, int M, int D)//water type capture function
{
	const int WATERLOWERBOUND = 1000; // cant generate an random number less than 1000
	const int WATERUPPERBOUND = 2023;// cant generate a random number greater than 2023
	const int THOUSANDSPLACE = 9999;//  used to generate the second half of the randomly generated water number at a max of 9999
	const int ZERO = 0;//  used to generate the second half of the randomly generated water number at a min of 0
	const int MAKE_TENTHOUSANDS_PLACE = 10000; //makes the randomly generated number between 1000 and 2023 a 8 digit number equilvent to the size of the bday nubmer
	int part_of_random = 0; // part of the randomly generated water number 
	int Random_plus_part_of_random;// other part of the randomly generated water number 
	bool is_valid_triangle = false;// checks if random number is traingular
	do
	{
		random = rand() % (WATERUPPERBOUND - WATERLOWERBOUND) + WATERLOWERBOUND;//generated a number between 1000-2023
		if (random == 2022)// maximum value that can be generated is 20219999 so is 2022 is generated it must be lowered at least by one 
		{
			random = random - 1;

		}
		part_of_random = rand() % (THOUSANDSPLACE - ZERO) + ZERO;// generates a number between 0-9999
		Random_plus_part_of_random = (random * MAKE_TENTHOUSANDS_PLACE) + part_of_random; //multiplies the randomly generated number between 1000-2023 by 10,000 and adds a randomly generated number between 0 -9999 to get a 8 -digit number to compare to the User_battle_value which is the bday number.
		is_valid_triangle = TriangularNumberCheck(Random_plus_part_of_random); //checks to see if the random number is triangular
	} while (is_valid_triangle == false);//keeps looping until a triangular number is generated
	int User_battle_value = Y + M + D;// creates 8-digit birthday number for user ex: year = 19900000 ,month = 00001200,day = 00000026, User_battle_value is the sum of year month and day
	if (User_battle_value < Random_plus_part_of_random)// is bday 8-digit number is less than randomly generated 8-digit number, cpature was successful
	{
		return true;
	}
	else
		return false;

}
bool capture()//dragon type capture function
{
	return true; //dragon types are always captured successfully 
}