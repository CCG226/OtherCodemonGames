#include <iostream>
#include <math.h> 
#include "CodemonSecuirtyZoneHeader.h"
using namespace std;
int Quartile3(int Codemoncount[], const int size, int AmountofCodemonAmountElements)
{
	const float UPPER_MIDDLE_HALF = 3.0 / 4.0; // multplies n by 0.75 aka the upper middle have aka the 3rd quartile 
	float Quartile_index = 0;//stores index of 3rd quartile
	int Qindex = 0;//ensures the index of 3rd quartile is a integer
	int Bigger_num = 0;// temporary storage to organize array from least to greatest 

	for (int i = 0; i < AmountofCodemonAmountElements; i++) //uses bubble sort method to sort integer array num of codemon from least to greates 
	{
		for (int j = 0; j < AmountofCodemonAmountElements - i; j++)
		{
			if (Codemoncount[j] > Codemoncount[j + 1]) //if current array element is greater than next array element
			{
				Bigger_num = Codemoncount[j];//then current array element is stored in a temporary integer for the bigger number
				Codemoncount[j] = Codemoncount[j+1];//the current array element and next array element swap places to order from small to big 
				Codemoncount[j+1]= Bigger_num;// the next array element is then set to the bigger number
			}
		}
	}
	Quartile_index = floor(UPPER_MIDDLE_HALF * (AmountofCodemonAmountElements + 1)); //3rd quartile formula is (3/4) * (number of usefull array elements + 1) and the it is rounded down to nearest integer
	Qindex = int(Quartile_index); //ensures the quartile index in an integer
	return Codemoncount[Qindex]; //returns 3rd quartile by returnings the copy of int array with its index being that of where the third quartile is.

}