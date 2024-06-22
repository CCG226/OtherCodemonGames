#include <iostream>
#include "CodemonForestheader.h"
#include <math.h>
using namespace std;
bool TriangularNumberCheck(int num)
{
	const int	MULTIPLY_BY_8 = 8 ;// 8 needed to mulitple number by 8 for traingular number checker formula
	const int INCREASE_BY_ONE_FOR_PERFECT_SQUARE = 1;// an addition of one is needed for traingular number checker formula
	float numtest = sqrt((MULTIPLY_BY_8 * num) + INCREASE_BY_ONE_FOR_PERFECT_SQUARE); // formula to get a value which can be used to check if a number is traingular formula = sqrt(number times 8) + 1
	if (numtest == int(sqrt((MULTIPLY_BY_8 * num) + INCREASE_BY_ONE_FOR_PERFECT_SQUARE))) // if numtest value recieved from tranigular formula is a whole number than it is a triangular number.
	{
		return true;
	}
	else
		return false;

}