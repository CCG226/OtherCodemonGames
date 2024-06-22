#include <iostream>
#include "CodemonSecuirtyZoneHeader.h"
#include <fstream>

using namespace std;
bool operator>(const securityLevelComparison& r, const securityLevelComparison& u)// overloads > oprator to check if a zones security level is greater than a user
{
  return(r.RoomSecurityLevel > u.UserSecurityLevel);

}
ostream& operator<<(ostream& out, const entrant& p) // overloads << output operator for entrant to output the info a suspect to a file
{
  out << "Name: " << p.fName << " " << p.lName << endl;
  out << "Age: " << p.age << endl;
  out << "Occupation: " << p.Occupation << endl;
  out << "Number of Codemon: " << p.numberOfCodemon << endl;
  out << "Security Level: " << p.securityLevel << endl;
  return out;
}
int ZoneScan(int level, string fileinput,string fileoutput)
{
  ifstream fin;
  ofstream fout;
  const int AMOUNT_OF_STRUCTS_MEMBERS = 6; //entrant contains 6 memebers.
  const int AGE = 30;// those 30 and up can potentially be a suspect
  const int SIZE = 100;//size of array
  const int UselessData = 0;// security level cant be 0 or less
  struct entrant EntrantZone[SIZE] = {}; //entrant data for EntrantZone is stored in a 100 sized struct array
  int CodemonCountCopyForQuartile[SIZE];// a copy of struct array of number of codemon that can be sorted witout disturbing the main struct array to find 3rd quartile
  int Quartilenum = 0; // Quartile number will be stored here 
  int AmountOfUsefulData = 0; //counts total amount of useful elements 
  int AmountOfUsers = 0;// total amount of entrants entering a zone
  int violations = 0; //counts violations
  string element = " ";//to count amount of elements in a file 
  int temp_warning_age = 0; //stores age of a suspect temporarly
  int temp_number_of_codemon = 0;//stores number of codemon temporarly
  fin.open(fileinput);//opens up a data file containing entrant info in the parameters zone.
  
  
  for (int i = 0; i < SIZE; i++) //each run stores individual entrant information inside each struct types array, an struct array for first name, last name, age, occupation, codemon total
  {

    fin >> EntrantZone[i].fName;
    fin >> EntrantZone[i].lName;
    fin >> EntrantZone[i].age;
    fin >> EntrantZone[i].Occupation;
    fin >> EntrantZone[i].numberOfCodemon;
    fin >> EntrantZone[i].securityLevel;
    
   
  }
  fin.close();//closes data input text file
  fin.open(fileinput); //opens up data input text file again
  while (fin >> element)// keeps going until no more useful data is left
  {
    AmountOfUsefulData++; //counts every piece of data in file 
  }
  
  AmountOfUsers = AmountOfUsefulData / AMOUNT_OF_STRUCTS_MEMBERS; //divides elements by amount of pieces of info from each entrant to find how many users are in a file
  for (int i = 0; i < SIZE; i++)
  {
    CodemonCountCopyForQuartile[i] = EntrantZone[i].numberOfCodemon; // creates a copy numberofcodemon array
  }
  
  Quartilenum = Quartile3(CodemonCountCopyForQuartile, SIZE, AmountOfUsers);
  fin.close();//closes data input text file again
  fout.open(fileoutput);//opens up a warning file to write in suspects in the specific zone 
  struct securityLevelComparison LevelCheck; //calls in struct to compare the zone and users security level with a overloaded operator
  LevelCheck.RoomSecurityLevel = level; //stores security level of zone into a int struct 
  for (int i = 0; i < SIZE; i++) //runs through entire entrant array.
  {  
    if ((EntrantZone[i].age >= AGE && EntrantZone[i].Occupation == "Student") || (level > EntrantZone[i].securityLevel && EntrantZone[i].securityLevel != UselessData) || (EntrantZone[i].numberOfCodemon > Quartilenum))// finds suspect
    {
      LevelCheck.UserSecurityLevel = EntrantZone[i].securityLevel;//if suspect found it stores their security level in Levelcheck struct as int
      fout << EntrantZone[i];// outputs all Name, occupation, number of codemon, and security level of a suspect with a overloaded << ouput operator into the output file
      if ((EntrantZone[i].age >= AGE && EntrantZone[i].Occupation == "Student")) // outputs a warning to fileoutput if age is greater than or equal to 30 and they are a student
      {
        temp_warning_age = EntrantZone[i].age;//avoids conflict with overloaded << operator for entrantzone struct
        fout << "Warning: Entrant is classifed as a student at the age of " << temp_warning_age << endl;
        violations++; //counts as a violation
      }
      if (EntrantZone[i].numberOfCodemon > Quartilenum)// outputs a warning if entrant has more codemon then 3rd quartile of codemon in region and outputs warning to fileoutput
      {
        temp_number_of_codemon = EntrantZone[i].numberOfCodemon;//avoids conflict with overloaded << operator for entrnatzone struct
        fout << "Warning: Entrant has too many codemon, entrant has " << temp_number_of_codemon << " codemon, the third quartile was " << Quartilenum << endl;
        violations++;//counts as a violation
      }
      if (LevelCheck.RoomSecurityLevel > LevelCheck.UserSecurityLevel) //uses overloaded greater than operator > to check if zone security level is higher than the users, if so a warning is outputted to file
      {

        fout << "Warning: Entrant with a level of " << LevelCheck.UserSecurityLevel << " entered a zone of level " << LevelCheck.RoomSecurityLevel << endl;
        violations++;//counts as a violation
      }
      fout << "\n" << endl;
    }
    
    
  }
  
  fout.close();//closes up a warning file to write in suspects in the specific zone 
  return violations; //returns total amount of violations 

}
