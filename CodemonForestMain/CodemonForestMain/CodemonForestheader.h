#ifndef CODEMONFORESTHEADER_H
#define CODEMONFORESETHEADER_H
#include <iostream>
using namespace std;
char explore(int& Time, char previoustype); //Pre-conditions: User must have captured less than  20 codemon to continue exploring the forest. Description: generates a random character for every time unit and uses previous value of previous function to reward uuser with a dragon type. Post Condition: returns character value equivalent to a codemon type that the user will encounter.
bool TriangularNumberCheck(int num); //Pre-condition: to capture a flying, posion, rock, or water type codemon a traingular number is required. Description: ensures number taken is a triangular number. Post-condition: returns false if number is not triangular, and true if it is triangular
bool capture(int L_arm, int R_arm);//FLYING::: Pre-condition: User runs into a wild flying type ('F'), Description: requires user arm lengths inputs, if sum of arms is a triangular number user captures a flying type, Post-condtion: returns true if Left arm + right arm = triangular number
bool capture(int RandNum); //POISON:::  Pre-Condition: User runs into a poison type ('P'), Description: requires a empty int value, that int value is randomized, checked in TriangluarNumberCheck, and checked if it is less than 43; Post-condition: returns true if random int is traingular and less than 43
bool capture(int time, int Rock_battle_num, int User_battle_num); //ROCK::: Pre-Condition: User runs into a rock type ('R'); Descritption: User_battle_num is randomized, checked as traiangular and multipled time and the compared to a randomized triangular rock_battle_num, Post-condition: returns true if User_battle_num * time) > Rock_battle_num
bool capture(bool pesticide, int WaterType, int PoisonType); //BUG::: Pre-Condition: User runs inti a bug type('B'), Descriptions: uses watertype and posiontype codemon to create a pesticde to capture Bug codemon, Post-Condition: returns ture if user has at least one watertype and at least one poison type.
bool capture(int random, int Y, int M, int D); //WATER::: Pre-condition: user runs into a water type('W'), Description: takes in users bday and a random triangular number and compares them. Post- condtion: returns true if your bday value is less than the random triangular value;
bool capture(); //DRAGON::: Pre-condition: user runs into a dragon type ('D'), Description: takes in nothing, Post-condtion: always returns true.
int max(int num1, int num2);//pre-condition user recieves an acceptable score, therefore there most popular codemon type will be outputted by first finding their common capture type, Description: takes in two different int amounts of a specific type of codemon and compares them to find biggest value, Post-condition: returns biggest number
char MostCommonCodemon(int max, int rock, int water, int dragon, int flying, int poison, int bug); ////pre-condition user recieves an acceptable score, therefore there most popular codemon type is needed, Description: compares maximum value from max function to the values of the total amount of each type captured, Post-condition: returns a the character of the most popular codemon type
template <typename R, typename S, typename D> 
void testSummary(R ranking,S special_rank_info, D DragonTypeAmount) //Pre-conditon users score is determined by how long it takes from them to finish(Time count) and ranking info is outputted based on score, Description: outputs different information based on a ranking system, (so different data types, so a template is used to solve that issue) and ranking information as well as rewarding the besct scoreres with dragon types, Post-condition:outputs summary of data as a template 
{
	if (ranking == "SUPER")
	{
		cout << "Student's test ranking: " << ranking << endl;
		cout << "Student's emotional Message: " << special_rank_info << endl;
		cout << "Student will be rewarded: " << DragonTypeAmount << " Dragon type Codemon(s)" << endl;
	}
	else if (ranking == "ACCEPTABLE")
	{
		DragonTypeAmount = 0;
		cout << "Student's test ranking: " << ranking << endl;
		cout << "Student's favorite letter: " << special_rank_info << endl;
		cout << "Student will be rewarded: " << DragonTypeAmount << " Dragon type Codemon(s)" << endl;
	}
	else if (ranking == "DIMINISHING")
	{
		DragonTypeAmount = 0;
		cout << "Student's test ranking: " << ranking << endl;
		cout << "Student's Total Exploration Time: " << special_rank_info << endl;
		cout << "Student will be rewarded: " << DragonTypeAmount << " Dragon type Codemon(s)" << endl;
	}
	return;
	
}
#endif



