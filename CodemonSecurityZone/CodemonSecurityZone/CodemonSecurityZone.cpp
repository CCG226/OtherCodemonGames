// CodemonSecurityZone.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Programmer: CHarles Gilmore
//Student ID: 12570663
//Section: 105
//Date: 10/14/2021
//File:CodemonSecurityZone.cpp

#include <iostream>
#include <fstream>
#include "CodemonSecuirtyZoneHeader.h"

using namespace std;
int main()
{
  int Libraryviolations = 0; // total violations from library zone 
  int TrainingRoomviolations = 0;// total violations from Training room zone 
  int FacultyLoungeviolations = 0;// total violations from FacultyLounge zone 
  int ChamberOfEkansviolations = 0;// total violations from chamber of ekans zone 
  const string LibraryZoneinput = "the_library.txt";// library zone data is read from this text file (.txt)
  const string LibraryZoneoutput = "the_library_warnings.txt"; //library zone suspects warnings are written on this text file(.txt)
  const string TrainingRoomZoneinput = "training_room.txt";//training room zone data is read from this text file (.txt)
  const string TrainingRoomZoneoutput = "training_room_warnings.txt";//training room zone suspects warnings are written on this text file(.txt)
  const string FacultyLoungeZoneinput = "faculty_lounge.txt";//Faculty lounge zone data is read from this text file (.txt)
  const string FacultyLoungeZoneoutput = "faculty_lounge_warnings.txt";//faculty lounge zone suspects warnings are written on this text file(.txt)
  const string ChamberOfEkansZoneinput = "the_chamber_of_ekans.txt";// Chamber of ekans zone data is read from this text file (.txt)
  const string ChamberOfEkansZoneoutput = "the_chamber_of_ekans_warnings.txt";//chamber of ekans zone suspects warnings are written on this text file(.txt)
  const int LibraryLevel = 1; //security level of library
  const int TrainingRoomLevel = 2; // security level of training room
  const int FacultyLoungeLevel = 3;// security level of faculty
  const int ChamberOfEkansLevel = 4;//security level of Chamber of Ekans
  cout << "Codemon security zones have been set in motion. " << endl;
  cout << "Scanning Entrant Data from Library Zone and tracking suspects in library warning file...." << endl;
  Libraryviolations = ZoneScan(LibraryLevel, LibraryZoneinput, LibraryZoneoutput); 
  cout << "Scanning Entrant Data from Training Room Zone and tracking suspects in training room warning file...." << endl;
  TrainingRoomviolations = ZoneScan(TrainingRoomLevel, TrainingRoomZoneinput, TrainingRoomZoneoutput);
  cout << "Scanning Entrant Data from Faculty Lounge Zone and tracking suspects in faculty lounge warning file...." << endl;
  FacultyLoungeviolations = ZoneScan(FacultyLoungeLevel, FacultyLoungeZoneinput, FacultyLoungeZoneoutput);
  cout << "Scanning Entrant Data from Chamber Of Ekans Zone and tracking suspects in chamber of ekans warning file...." << endl;
  ChamberOfEkansviolations = ZoneScan(ChamberOfEkansLevel, ChamberOfEkansZoneinput, ChamberOfEkansZoneoutput);
  cout << "\n\nSummary:\n" << endl; 
  cout << "Training Room: " << TrainingRoomviolations << " potential violations." << endl;// total violations from Training room zone
  cout << "The Chamber Of Ekans: " << ChamberOfEkansviolations << " potential violations." << endl;// total violations from chamber of ekans zone 
  cout << "The Library: " << Libraryviolations << " potential violations." << endl;// total violations from library zone 
  cout << "Faculty Lounge: " << FacultyLoungeviolations << " potential violations." << endl;// total violations from FacultyLounge zone 
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
