
#include "CodemonForestheader.h"
#include <iostream>
#include <string>
using namespace std;
int max(int num1, int num2)// simply finds max value via comparison  
{
  if (num1 > num2)
  {
    return num1;
  }
  else
  {
    return num2;
  }
}
char MostCommonCodemon(int max, int rock, int water, int dragon, int flying, int poison, int bug)//compares max value to the int value total amount captured of every time to determine most common type captured.
{
  if (max == rock)
  {
    return 'R';

  }
  else if (max == water)
  {
    return 'W';
  }
  else if (max == dragon)
  {
    return 'D';
  }
  else if (max == flying)
  {
    return 'F';
  }
  else if (max == poison)
  {
    return 'P';
  }
  else if (max == bug)
  {
    return 'B';
  }



}