// CodemonEntrySecurity.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "CodemonEntryHeader.h"
using namespace std;

int main()
{
  const int AGELOWERBOUNDS = 5; // lowest age a entrant can be
  const int AGEUPPERBOUNDS = 100; // highest age a entrant can be
  const int CODEMONUPPERBOUNDS = 100; //highest amount of codemon an entrant can have
  const int CODEMONLOWERBOUNDS = 1; // lowest amount of codemon an entrant can have
  const int SIZE = 5; //the total number of entrants that can enter at a time (used for all arrays), 
  const int TEAMPICKETAGE = 30; //teampicket memebers are usually older than or at the age of 30, making 30 and up users suspects
  const int MAX_PARTY_SIZE = 6;//entrants with more than 6 codemon are suspicious 
  const int NOTHREAT = 0; //if there are no suspected entrants the threat level is 0
  struct Entrant trainer[SIZE]; // struct array to hold 5 elements for every memeber, each element a piece of the users data
  char playAgain = 'y'; // allows application to run again if user hits Y or y
  int suspectAlertLevel = 0; // starting suspect level
  string suspectFirstName[SIZE] = { " ",  " ", " ", " ", " "};//an array to store the first name of a suspect
  string suspectLastName[SIZE] = { " ",  " ", " ", " ", " " };//an array to store last name of suspect
  int suspectAge[SIZE] = {0, 0, 0, 0, 0}; //an array to store age of suspect
  string suspectOccupation[SIZE] = { " ",  " ", " ", " ", " " };//an array to store job of suspect
  int suspectCodemon[SIZE] = { 0, 0, 0, 0, 0 };//an array to store amount of codemon a suspect has
  cout << "---Now booting up Codémon Academy security system---" << endl;
  while (playAgain == 'y' || playAgain == 'Y') //keeps running while user types i y or Y 
  {
    
    for (int i = 0; i < SIZE; i++) //each run stores individual inputted entrant information inside each struct types array, an struct array for first name, last name, age, occupation, codemon total
    {
      cout << "Please input name, age, occupation, and the number of Codémon for entrant " << i + 1 << ":" << endl;//recieves all information from a indivdual entrant
      cin >> trainer[i].fName;
      cin >> trainer[i].lName;
      cin >> trainer[i].age;
      cin >> trainer[i].Occupation;
      cin >> trainer[i].numberOfCodemon;
      while (trainer[i].age < AGELOWERBOUNDS || trainer[i].age > AGEUPPERBOUNDS)//makes sure age is between 5 - 100
      {
        cout << "please enter an age between 5 and 100 " << endl;
        cin >> trainer[i].age;
      }
      while (trainer[i].Occupation != "Student" && trainer[i].Occupation != "Faculty" && trainer[i].Occupation != "Staff") //makes sure occupation is Student, Staff, or Faculty
      {
        cout << "Not a valid occupation, Please enter a valid occupation." << endl;
        cin >> trainer[i].Occupation;
      }
      while (trainer[i].numberOfCodemon < CODEMONLOWERBOUNDS || trainer[i].numberOfCodemon > CODEMONUPPERBOUNDS)//ensures codemon party is within 1 - 100
      {
        cout << "YOU can only have up 100 codemon, please enter an amount between 1 and 100 " << endl;
        cin >> trainer[i].numberOfCodemon;
      }
      if (trainer[i].age >= TEAMPICKETAGE || trainer[i].numberOfCodemon > MAX_PARTY_SIZE)//if entrant is 30 and up or has more than 6 codemon theri info is stored in a different array, one for keeping track of team picket members
      {
       suspectFirstName[i] = trainer[i].fName;
       suspectLastName[i] = trainer[i].lName;
       suspectAge[i] = trainer[i].age;
       suspectOccupation[i] = trainer[i].Occupation;
       suspectCodemon[i] = trainer[i].numberOfCodemon;
        suspectAlertLevel++;
      }
      
    }
    if (suspectAlertLevel == NOTHREAT) // if no entrants are suspicious, program runs this version of overloaded function printEntrant();
    {
      printEntrant();
    }
    else if (suspectAlertLevel > NOTHREAT) //if entrants are susupicious than, program runs this version of the overloaded func., with the parameters being the suspects user data
    {
      for (int i = 0; i < SIZE; i++)// to get indivual susepect to output indivudially in printEntrant(etc.)
      {
        if (suspectAge[i] != 0)//ensures only elements with actually information and not junk is outputted
        {
          printEntrant(suspectFirstName[i], suspectLastName[i], suspectAge[i], suspectOccupation[i], suspectCodemon[i]);
        }

      }

    }
    do
    {
      cout << "Would you like to play again? (y/n)" << endl;
      cin >> playAgain;
    } while (playAgain != 'Y' && playAgain != 'y' && playAgain != 'N' && playAgain != 'n');//gives user option to play again and ensures that type the right character
    for (int i = 0; i < SIZE; i++) //resets suspect list for the next run.
    {
      suspectFirstName[i] = " ";
      suspectLastName[i] = " ";
      suspectAge[i] = 0;
      suspectOccupation[i] = " ";
      suspectCodemon[i] = 0;
    }

  }

  cout << "Goodbye.";
  return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
