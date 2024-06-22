#ifndef CODEMONENTRYHEADER_H
#define CODEMONENTRYHEADER_H
#include <iostream>
#include <string>
using namespace std;
void printEntrant(string Fname, string Lname, int Age, string job, int CodemonParty);// pre-condition: there are team picket suspects in the group. Description: takes in all information about the suspected individuals. Post-condition - outputs all of suspected team picket members information.
void printEntrant();// pre-condition: there is no Team Picket suspects, Descrpition: takes in no parameters: Post- Condtion: outputs statement clarfying that there are no team picket members suspected in the entrant group
struct Entrant // struct with 3 string memebers and two int members under type Entrant all used to store a trainers user input info.
{
  string fName;
  string lName;
  int age;
  string Occupation;
  int numberOfCodemon;
};







#endif