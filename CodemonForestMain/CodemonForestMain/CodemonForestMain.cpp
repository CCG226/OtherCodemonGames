// CodemonForest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CodemonForestheader.h"
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

int main()
{
 
  int RockTypeCount = 0; // counts amount of rock type codemon captured
  int WaterTypeCount = 0;// counts amount of water type codemon captured
  int DragonTypeCount = 0;// counts amount of dragon type codemon captured
  int FlyingTypeCount = 0;// counts amount of flying type codemon captured
  int BugTypeCount = 0;// counts amount of bug type codemon captured
  int PoisonTypeCount = 0; // counts amount of poison type codemon captured
  int maxfindtest1 = 0; //since arrays cant be used multiple max variables are needed to compare and find the max value of the 6 type count totals
  int maxfindtest2 = 0;
  int maxfindtest3 = 0;
  int maxfindtest4 = 0;
  int maxfindtest5 = 0;
  int maxfindtestFinal = 0;
  char PreviousType = ' '; //holds previously randomly generated codemon type character from explore function
  char Encounteredtype = ' '; // holds currently generated codemon type character from explore function
  int CodemonCount = 0; //total amount of codemon captured
  int TimeCount = 0; // counts time increment, increments by one per every random generation in explore func.
  bool CaptureAttempt= false; // determines wheather or not a codemon was captured succcesffully
  int Leftarm = 0; // intger value of users left arm
  int Rightarm = 0; // integer value of users right arm
  int Bday_year_input = 0; // input of users birth year inputted by user
  int year = 0; // holds year user was born
  int Bday_month_input = 0; // input of users birth month inputted by user
  int month = 0; // holds month user was born
  int Bday_day_input = 0;// input of users birth day inputted by user
  int day = 0;// holds day user was born
  string Score = " "; //becomes one of the three possible scores a user may recieve based upon their completion of the forest in a certian amount of time
  string Super_statement = " "; // stores statement made by user in summary
  char Acceptable_Favorite_Codemon = ' ';// stores character representing most common type caought by user
  int Time_wasted = 0; //stores total time user spent in forest 
  const int MAX_CODEMON = 20; //maximum amount a user can catch of codemon
  const int GET_YEAR = 10000; // used to create user's year value for capture() function for water types.
  const int GET_MONTH = 100; // used to create user's month value for capture() function  for water types
  const int GREATER_THAN_ZERO = 0; // prevents user from entering a negative number. 
  const int ARM_LIMIT = 1000; // 1000cm is max arm length a human can have in this world.
  const int MAX_MONTH = 12;  //no more than 12 months
  const int MAX_YEAR = 2021; // latest in year in this universe
  const int MAX_DAY = 31; // no more than 31 days in a month
  const int Super_time_requirment = 50; // must complete forest task in 50 time units or less to get this score
  const int Acceptable_time_requirment = 200; // must complete forest task in 200 time units or less to get this score.
  srand(time(NULL)); // random seed to randomize program
  cout << "Welcome to the Codemon forest, go catch some Codemon, Goodluck!" << endl; // opening statement
  cout << "What is the length of your left arm?" << endl;
  cin >> Leftarm; // recieves left arm length from user
  while (Leftarm < 0 || Leftarm >= 1000) // makes sure Leftarm is within boundaries
  {
    cout << "Please be reasonable, what is the length of your left arm?" << endl;
    cin >> Leftarm;

  }
  cout << "What is the length of your right arm?" << endl;
  cin >> Rightarm; // recieves right arm length from user
  while (Rightarm < 0 || Rightarm >= 1000)// makes sure Rightarm is within boundaries
  {
    cout << "Please be reasonable, what is the length of your right arm?" << endl;
    cin >> Rightarm;

  }
  do 
  {
    cout << "Enter your Birthday year, ex:1990" << endl;
    cin >> Bday_year_input; // recieves birth year and ensures that year is between 1-2021
   
  }while(Bday_year_input < GREATER_THAN_ZERO && Bday_year_input >= MAX_YEAR);
  year = Bday_year_input * GET_YEAR; //multiplies year by 10000 ex: 1234 * 10000 = 12340000
  do
  {
    cout << "Enter your Birthday month numerically, ex:01 = January" << endl;
    cin >> Bday_month_input; // recieves birth month and ensures month is between 1-12

  } while (Bday_month_input < GREATER_THAN_ZERO&& Bday_month_input >= MAX_MONTH);
  month = Bday_month_input * GET_MONTH; // multiplies month ny 100 ex: 12 * 100 = 00001200
  do
  {
    cout << "Enter your Birthday day, ex: 26" << endl;
    cin >> Bday_day_input; // recieves birth day and ensures date is between 1-31

  } while (Bday_day_input < GREATER_THAN_ZERO && Bday_day_input >= MAX_DAY);
  day = Bday_day_input; // int day holds onto bday input 
  while (CodemonCount < MAX_CODEMON)
  {
    
    Encounteredtype = explore(TimeCount, PreviousType); // encountered type recives a character (P,F,B,R,W,G) from explore function
    PreviousType = Encounteredtype; // holds onto a  copy of encounteredtype that is put back into the explore function so that a dragon type can be determined if the user runs into two types in a row.
    if (Encounteredtype == 'F') // if flying type encourntered
    {
      cout << "User encountered Flying Codemon at time "<< TimeCount << endl;
      CaptureAttempt = capture(Leftarm, Rightarm); // sends user to capture func. to see if they capture the codemon
      if (CaptureAttempt == true) //true means capture attempt was successful
      {
        cout << "Capture successful\n\n" << endl;
        FlyingTypeCount = FlyingTypeCount + 1; // adds a  flying type to user 
        CodemonCount++; // adds a codemon to total
        
        CaptureAttempt = false; //resest captureattempt value to false for the next encounter
      }
      else // outputs a failure message if capture attempt is unsuccessful
        cout << "Capture unsuccessful\n\n" << endl;
    }
    if (Encounteredtype == 'P')
    {
      cout << "User encountered Poison Codemon at time " << TimeCount << endl;
      int randomNumber = 0;
      CaptureAttempt = capture(randomNumber);
      if (CaptureAttempt == true)
      {
        cout << "Capture successful\n\n" << endl;
        PoisonTypeCount = PoisonTypeCount + 1;
        CodemonCount++;
        CaptureAttempt = false;
      }
      else
        cout << "Capture unsuccessful\n\n" << endl;
    }
    if (Encounteredtype == 'R')
    {
      cout << "User encountered Rock Codemon at time " << TimeCount << endl;
      int RockCodemonRandNum = 0;
      int UserRandNum = 0;
     
      CaptureAttempt = capture(TimeCount, RockCodemonRandNum, UserRandNum);
      if (CaptureAttempt == true)
      {
        cout << "Capture successful\n\n" << endl;
        RockTypeCount = RockTypeCount + 1;
        CodemonCount++;
        CaptureAttempt = false;
      }
      else
        cout << "Capture unsuccessful\n\n" << endl;
    }
    if (Encounteredtype == 'B')
    {
      cout << "User encountered Bug Codemon at time " << TimeCount << endl;
      bool Pesticde = false;
      CaptureAttempt = capture(Pesticde, WaterTypeCount,PoisonTypeCount);
      if (CaptureAttempt == true)
      {
        cout << "Capture successful\n\n" << endl;
        BugTypeCount = BugTypeCount + 1;
        CodemonCount++;
        CaptureAttempt = false;
      }
      else
        cout << "Capture unsuccessful\n\n" << endl;
    }
    if (Encounteredtype == 'W')
    {
      cout << "User encountered Water Codemon at time " << TimeCount << endl;
      int RandWaterNum = 0;
      CaptureAttempt = capture(RandWaterNum, year, month, day);
      if (CaptureAttempt == true)
      {
        cout << "Capture successful\n\n" << endl;
        WaterTypeCount = WaterTypeCount + 1;
        CodemonCount++;
        CaptureAttempt = false;
      }
      else
        cout << "Capture unsuccessful\n\n" << endl;
    }
    if (Encounteredtype == 'D')
    {
      cout << "User encountered Dragon Codemon at time " << TimeCount << endl;
      CaptureAttempt = capture();
      if (CaptureAttempt == true)
      {
        cout << "Capture successful\n\n" << endl;
        DragonTypeCount = DragonTypeCount + 1;
        CodemonCount++;
        CaptureAttempt = false;
      }
      else
        cout << "Capture unsuccessful\n\n" << endl;
    }
  }
  if (TimeCount <= Super_time_requirment)// if time units is less than or equal to 50, the user got a SUPER score
  {
    Score = "SUPER"; //score is a SUPER score
    cout << "Congrats you got a SUPER score, the academy would love to hear a message from you!" << endl;
    cout << "Your Statement: ";
    cin >> Super_statement; //user gets to write a special message for their victory
    cout << "\n";
    if (DragonTypeCount == 0) // if the didnt catch any dragon types they get atleast one.
    {
      DragonTypeCount++;
    }
    testSummary(Score, Super_statement,DragonTypeCount);// sends ranking data to template in header to be outputted

  }
  else if (TimeCount <= Acceptable_time_requirment) //if user gets less than or equal to 200 time unit score they get an ACCEPTABLE score
  {
    Score = "ACCEPTABLE"; // score is ACCEPTABLE score
    
    maxfindtest1 = max(RockTypeCount, WaterTypeCount); // a series of comparisons made by the max funnction to determine the most common type captured
    maxfindtest2 = max(maxfindtest1, DragonTypeCount);
    maxfindtest3 = max(maxfindtest2, FlyingTypeCount);
    maxfindtest4 = max(maxfindtest3, BugTypeCount);
    maxfindtest5 = max(maxfindtest4, PoisonTypeCount);
    maxfindtestFinal = maxfindtest5;
    Acceptable_Favorite_Codemon = MostCommonCodemon(maxfindtestFinal, RockTypeCount, WaterTypeCount, DragonTypeCount, FlyingTypeCount, PoisonTypeCount, BugTypeCount); // returns a character representing most common type
    testSummary(Score, Acceptable_Favorite_Codemon, DragonTypeCount);// sends ranking data to template in header to be outputted

  }
  else if(TimeCount  > Acceptable_time_requirment) // if they took longer than 200 time units they get a DIMINISHING score
  {
    Score = "DIMINISHING"; //Score is DIMINISHING score
    Time_wasted = TimeCount; // total amount of time user wasted failing the test
    testSummary(Score, Time_wasted, DragonTypeCount);// sends ranking data to template in header to be outputted
  }



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


