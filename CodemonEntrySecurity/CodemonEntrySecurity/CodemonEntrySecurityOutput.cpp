
#include <iostream>
#include <string>
#include "CodemonEntryHeader.h"
using namespace std;
void printEntrant(string Fname, string Lname, int Age, string job, int CodemonParty)//outputs Team Picket suspect list of the 5 entrants
{
	cout << "The following entrants have been denied entry due to suspicions of Team Picket affiliations:" << endl;
	cout << "Name: " << Fname << " " << Lname << endl;
	cout << "Age: " << Age << endl;
	cout << "Occupation: " << job << endl;
	cout << "Number of Codemon: " << CodemonParty << endl;
	return;
}
void printEntrant()//outputs message ensuring that their are no suspects and all entrants are welcome.
{
	cout << "None of the entrants were suspected of spycraft, all were allowed to enter" << endl;
	return;
}