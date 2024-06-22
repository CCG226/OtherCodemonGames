#ifndef CODEMONSECUIRTYZONEHEADER_H
#define CODEMONSECUIRTYZONEHEADER_H

#include <iostream>
using namespace std;
int ZoneScan(int level, string fileinput, string fileoutput);//pre-condition: will run 4 times in main each time for a different zone.- Description reads fileinput and outputs suspects to fileoutput and thier specfic warnings for each zone level.--Post-Condition returns the amount of violations in a specific zone
int Quartile3(int Codemoncount[], const int size, int AmountofCodemonAmountElements); //-Precondition: once all the number of codemon data from the file has been stored in a int array, this function will then activate. -Descripttion: useing bubble sort method to organize an array of numberofcodemon of all users in a file from greatest to least to find 3rd quartile.-Post condtion usesing formula (3/4) *(amount of array data + 1) to find the 3rd quartile index to return the 3rd quartile.
struct entrant //struct containing name, age, occupation, number of codemon, and secuirty level of every individual from the txt file
{
  string fName;
  string lName;
  int age;
  string Occupation;
  int numberOfCodemon;
  int securityLevel;

  
};
struct securityLevelComparison //contains a copy of a zone security level and a users security level to make a comparison.
{
  int RoomSecurityLevel;
  int UserSecurityLevel;
  

};




#endif