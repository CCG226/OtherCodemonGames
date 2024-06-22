// CodemonAcademy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Programmer:Charles Gilmore
// Student ID: 12570663
//section: 105
//File: HW2.cpp
//desc: determines whether or not to admit an applicant into Codemon Academy, if admitted their tuition is calculated as well

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
//prototype functions:
float isAdmitted(int TourneysWon, int CodemonInBox, float donation_percentage); // TourneysWon = TournementWins, CodemonInBox = CodemonBoxCount, donation_percentage = donation_percentage
float isAdmitted(int TourneysWon, float donation_percentage); // TourneysWon = TournementWins, donation_percentage = donation_percentage
float calculateDonationProbability(bool BrimfulResdience, int income, float donations);// BrimfulResidence = BrimfulParents, income = HouseHoldIncome, donations = BribeAmount
float calculateTuition(bool BrimfulResdience, int income, float AdmittedScore, int TourneysWon); // TourneysWon = TournementWins,  BrimfulResidence = BrimfulParents, income = HouseHoldIncome, AdmittedScore = TestScore
int main()
{
  char Continue = 'y'; //decide wheather or not to continue program on to another applicant
  while (Continue == 'y')
  {
    cout << "Welcome to the ofiicial Codemon Academy registartion site, apply to the best academy in Konta today and get results back immediately!\n" << endl;
    cout << "Let's start your Application.\n\n" << endl;
    int TournementWins = 0; //integer amount if Tournement wins an applicant has.
    int CodemonBoxCount = 0; //integer amount of Codemon an applicant has in their PC box.
    int HouseHoldIncome = 0; //decimal amount of income per year from appplicants household.
    char BrimfulResidenceQuestion = 'n'; //character (y/n) response from applicant for BrimfulResidence question.
    bool BrimfulParents = false; //boolean value that is true/false depending on wheather or not the applicants parents were in the TV show Brimful Residence.
    float BribeAmount = 0.0; // decimal amount applicant has donated to Codemon Academy.
    float TestScore = 0; //applicants isAdmittedscore.
    bool ApplicantAcceptance = false; //boolean value that determines if applicant is accepted.
    float donation_percentage = 0.0; // percentage value used to dertermine likelyhood of donations.
    float TuitionCost = 0.0; // accepted applicants total tuition cost.
    bool BrokeStudent = false; // determines if applicant is too poor for this school (making less than 30,000 in house hold income)
    const int PASSINGSCORE = 50; // used to compare to applicants test score, if they got 50 or above they are admitted.
    const int PARENTSINTVSHOWMINMUMINCOME = 200000; //MINMUM HOUSEHOLD INCOME required by academy in order to recognize the applicants parents status in Brimful Residence.
    const int TOURNEMENTWINSLOWERBOUND = 0; // used to ensure applicant enter a tournemnt win value below zero as thats not possible
    const int TOURNEMENTWINSUPPERBOUND = 50; // ensures applicant cant claim to have more than 50 tournement wins
    const int CODEMONBOXCOUNTUNKOWN = -1; // allows user to enter a -1 if they dont feel comfortable stating how many codemon they have
    const int CODEMONBOXCOUNTUPPERBOUND = 30;// applicant cant not state that they have more than 30 codemon as thats not possible.
    const int NOTENOUGHINCOME = 30000; //used to check to see if applicants make more than 30,000.
    const int DONATEDLESSTHAN100 = 100;//bribes under a $100 are ignored
    cout << "How many tournaments have you won?\n" << endl;
    cin >> TournementWins; //receiving applicants tourney win count.
    while (TournementWins < TOURNEMENTWINSLOWERBOUND || TournementWins > TOURNEMENTWINSUPPERBOUND) //ensures tourney win count is within the valid bounds 0 - 50.
    {
      cout << "Error, there are only 50 legal tournements around the globe annually, please enter your vaild tourney win count number.\n" << endl;
      cin >> TournementWins;
    }
    cout << "How many Codemon Do you own? If you dont feel confortable answering thsi question, please enter -1\n" << endl;
    cin >> CodemonBoxCount; //receiving appllicants Codemon party count.
    while (CodemonBoxCount < CODEMONBOXCOUNTUNKOWN || CodemonBoxCount > CODEMONBOXCOUNTUPPERBOUND) // ensures CodemonBoxCount is within the valid bounds 0 - 30.
    {
      cout << "A PC box can only store up to 30 Codemon, so therefore it is not possible to have more than 30 Codemon, please enter how many Codemon you own and "
        "if you dont feel confortable answering thsi question, please enter -1\n" << endl;
      cin >> CodemonBoxCount;
    }
    cout << "What is your household income?\n" << endl;
    cin >> HouseHoldIncome; //receiving applicants household income.
    if (HouseHoldIncome < NOTENOUGHINCOME)
    {
      cout << "Your Application has ended due to certain circumstances.\n" << endl;
      BrokeStudent = true;
    }
    if (BrokeStudent == false) //if student is broke (has less than 30k in income) the rest of the program will be ignored and the program will move on to the next student
    {
      cout << "Where your parents in the hit TV Show Brimful Residence?(y/n)\n" << endl;
      cin >> BrimfulResidenceQuestion; //receiving wheather or not applciants parents where in the 90's show
      while (BrimfulResidenceQuestion != 'y' && BrimfulResidenceQuestion != 'n') //checking to make sure user enters y or n.
      {
        cout << "please either select y if your parents were in the show or n if your parents were not in the show.\n" << endl;
        cin >> BrimfulResidenceQuestion;

      }
      if (BrimfulResidenceQuestion == 'y') // if applicants parents where in the show boolean variable Brimful Parents is true meaning applicant will get a discount added into their calculation later on.
      {
        BrimfulParents = true;
      }
      else
      {
        BrimfulParents = false;
      }

      cout << "How much has the athletic director recieved from you in donations?\n" << endl;
      cin >> BribeAmount; //receiving donation amount from applicant 
      if (BribeAmount <= DONATEDLESSTHAN100) //ignores bribes less than or equal to 100 dollars.
      {
        BribeAmount = 0;
      }
      if (BrimfulParents == true && HouseHoldIncome < PARENTSINTVSHOWMINMUMINCOME) // Academy secretly ignores applicants whose parents were in BrimfulResidence and have less than 200,000 as they are deemed as failures
      {
        BrimfulParents = false;
      }
      donation_percentage = calculateDonationProbability(BrimfulParents, HouseHoldIncome, BribeAmount); //takes in boolean representing wheather or parents were in the show, a float for income, and a float for donations made, returns float.
      if (CodemonBoxCount == CODEMONBOXCOUNTUNKOWN) // if applicants doesnt want to state their Codemon, only their TournementsWins data is sent to a seperate overloaded function.
      {
        TestScore = isAdmitted(TournementWins, donation_percentage); // takes in inputted int value TournementWins into parameter if CodemonBoxCount = -1,  returns a int TestScore that is used to determine wheather they passed or failed.

      }
      else
      {
        TestScore = isAdmitted(TournementWins, CodemonBoxCount, donation_percentage); // takes in inputted int value TournementWins and CodemonBoxCount into parameter if user enters thier CodemonBoxCount value, returns a int TestScore that is used to determine wheather they passed or failed.
      }


      if (TestScore >= PASSINGSCORE) // if applicant has a score greater than or equal to 50 they are admitted and tuition is calculated
      {
        ApplicantAcceptance = true;
        cout << "The student has been accepted with a score of: " << TestScore << "\n" << endl;
        TuitionCost = calculateTuition(BrimfulParents, HouseHoldIncome, TestScore, TournementWins); // takes in inputted boolean value, float HouseHoldIncome, and int TournementsWins and TestScore and returns their total tuition cost as a float
        cout << "You Total Tuition cost is: " << TuitionCost << endl;
      }
      else if (TestScore < PASSINGSCORE) //if applicants score is less than 50 they are not admitted
      {
        ApplicantAcceptance = false;
        cout << "Unfortunately you failed to meet the requirments to be accepted into this academy.\n" << endl;

      }
    }
    cout << "Move on to the next applicant(y/n)?\n " << endl;
    cin >> Continue; // if another applicant is around y can be clicked to reset program and n to end program.
    while (Continue != 'y' && Continue != 'n') //ensures user enters y or n.
    {
      cout << "Move on to the next applicant(y/n)?\n " << endl;
      cin >> Continue;

    }
  }
  return 0;
}
float isAdmitted(int TourneysWon, int CodemonInBox, float donation_percentage) // overloaded float function, The function determines wheather or not the applicant is accepted by calculting thier score. Applicants with a score of 50 are accepted. Does not pass by refrence.
{
  float total_points = 0; //used to add up all applicants points together based upon how many Tornements they won and how many Codemon they have
  float final_score = 0; //final score is the applicants actual score after donation percentage is added in
  const int TOURNEMENTPOINTRATE = 10; //for every tournement an applicant will always get 10 points is added to their score.
  const int CODEMONPOINTRATE = 2; //for  every Codemon an applicant has, 2 points will be added to their score
  total_points = (TourneysWon * TOURNEMENTPOINTRATE) + (CodemonInBox * CODEMONPOINTRATE); //total points is a sum of thier score based upon how man tournements they won times 10 plus how many Codemon they have times 2.
  final_score = total_points + (total_points * donation_percentage); //final score is total points plus thier totalpoints times a donation percentage, the higher the percentage the more points they will recieve
  return final_score; //final score is returned

}
float isAdmitted(int TourneysWon, float donation_percentage) // overloaded float function,The function determines wheather or not the applicant is accepted by calculting thier score. Applicants with a score of 50 are accepted. Does not pass by refrence.
{
  float total_points = 0; //used to add up all applicants points together based upon how many Tornements they won
  float final_score = 0; //final score is the applicants actual score after donation percentage is added in
  const int TOURNEMENTPOINTRATE = 10; //for every tournement an applicant will always get 10 points is added to their score.
  total_points = (TourneysWon * TOURNEMENTPOINTRATE); //total points is a sum of thier score based upon how man tournements they won times 10
  final_score = total_points + (total_points * donation_percentage); //final score is total points plus thier totalpoints times a donation percentage, the higher the percentage the more points they will recieve
  return final_score; //final score is returned


}
float calculateDonationProbability(bool BrimfulResidence, int income, float donations)// float function, The function determines the % likely of an applicant is to donate in the future and the percentage is added on to to their score, the more likely they are to donate the higher admitted score they get increaseing their chances of getting over a 50. 
{
  float donation_pvalue = 0.01; //every applicant has a 1% donation percentage(0.01)
  const int HOUSEHOLDINCOMEGREATERTHAN500000 = 500000; //ensures applicant has more than 500,000 to recieve a 20% bonus
  const int HOUSEHOLDINCOMELESSTHAN500000 = 500000; //ensures applicant has than 500,000 but more than 200,000 to recieve a 10% bonus
  const int HOUSEHOLDINCOMEGREATERTHAN200000 = 200000; //ensures applicant has than 500,000 but more than 200,000 to recieve a 10% bonus
  const int DONATED10000ORMORE = 10000; // ensures aaplicant has donated in the 10,000 - 100,000 range to geta 5% bonus
  const int DONATED100000ORMORE = 100000; //ensures applicant donated more than or equal to 100,000 for a 10% bonus
  const int DONATEDLESSTHAN100000 = 100000; // ensures aaplicant has donated in the 10,000 - 100,000 range to geta 5% bonus
  const float ADD10PERCENT = 0.1;  // adds 10% (0.1) to donation percentage
  const float ADD5PERCENT = 0.05; // adds 5% (0.05) to donation percentage
  const float ADD20PERCENT = 0.2; // adds 20% (0.2) to donation percentage
  if (BrimfulResidence == true) //if parents were in Brimful Residence, applicant gets a 10% (0.1) added to their donation percentage
  {
    donation_pvalue = donation_pvalue + ADD10PERCENT;
  }
  if (income > HOUSEHOLDINCOMEGREATERTHAN500000) //if applicants householdincome is greater than 500,000 they recieve a 20%(0.2) to donation %
  {
    donation_pvalue = donation_pvalue + ADD20PERCENT;
  }
  if (income <= HOUSEHOLDINCOMELESSTHAN500000 && income > HOUSEHOLDINCOMEGREATERTHAN200000) //if their householdincome is greater than 200,000 but less than 500,000 they recieve 10% (0.1) to their donation %
  {
    donation_pvalue = donation_pvalue + ADD10PERCENT;
  }
  if (donations >= DONATED100000ORMORE) // if applicant donated 100,000 or more they get a 10% (0.1) added to their donation percentage
  {
    donation_pvalue = donation_pvalue + ADD10PERCENT;
  }
  if (donations < DONATED100000ORMORE && donations >= DONATEDLESSTHAN100000) //if applicant  has more than or equak to 10,000 but less than 100,000 they get a 5% (0.05) added to their donation percentage.
  {
    donation_pvalue = donation_pvalue + ADD5PERCENT;

  }
  return donation_pvalue; //returns they total donation percentage value
}
float calculateTuition(bool BrimfulResdience, int income, float AdmittedScore, int TourneysWon)// float function, The function randomly determines the applicants Tuition and then adds Tuition based on their householdincome while also rewarding the applicant with scholarships to reduce tuition cost.
{
  float InitialTuition = 0.0; //randomized inital tuition
  float AddedTuition = 0.0; // added tution based upon household income
  float FinalTuitionCost = 0.0; // final tuition applicant will have to pay to go to thisacademy
  float TotalScholarships = 0.0; //total amount of money received from scholarships
  int HouseHoldIncomeRate = 0; // a determined rate based on householdincome per 100,000 dollars used to calculate added tuition.
  const float ADMITTEDSCORESCHOLARSHIPPOINTS = 100.0; //for every point they recieve on their admitted score 100 dollars is added to their scholarship
  const float TOURNEMENTSCHOLARSHIPPOINTS = 5000.00; //for every tournement won, 5,000 is added to their scholarship
  const float BRIMFULRESIDENCEPOINTS = 20000.00; // if parents were in BrimResidence 20,000 is added to their scholarship
  const float TUITIONADDEDBASEDONINCOME = 20000.00;//for every 100,000 in household income, 20,000 will be added to tuition
  const float NOTUITIONRATE = 3.50; // ensures applicant has to pay atleast 3.50 uf their tuition goes below 0
  const int GREATERTHAN100kHOUSEHOLDINCOME = 100000; //ensures extra tuition for applicants whose household income is greater than 100,000
  const int MAXTUITION = 1000000; //maximum amount of initial tuition
  const int MINTUITION = 50000; // minumium amount if initial tuition
  cout.setf(ios::fixed); //sets decimal point to second place after decimal
  cout.setf(ios::showpoint);
  cout.precision(2);
  srand(8); //seed 8
  InitialTuition = rand() * (MAXTUITION - MINTUITION) / (float)RAND_MAX + MINTUITION; // random inital tuition amount between 50,000 and 1,000,000
  cout << "Intial Tuition price: " << InitialTuition << endl;
  TotalScholarships = AdmittedScore * ADMITTEDSCORESCHOLARSHIPPOINTS; // 100 dollars for every 1 point on thier admitted score
  TotalScholarships = (TourneysWon * TOURNEMENTSCHOLARSHIPPOINTS) + TotalScholarships; // 5,000 dollars for every tournement won plus however much is already on scholarship
  if (BrimfulResdience == true) //if parents were in BrimfulResidence 20,000 is added to Scholarship funds
  {
    TotalScholarships = TotalScholarships + BRIMFULRESIDENCEPOINTS;
  }
  if (income >= GREATERTHAN100kHOUSEHOLDINCOME) //if household income is greater than 100,000 dollars, 20,000 will added in addition tuition costs per 100,000 dollars made in house hold income
  {

    for (int i = income; i >= 100000; i = i - 100000) //starts at however much applicant has in income and  continues while i is greater than 100,000. for loop subtracts 100,000 of i every loop
    {
      HouseHoldIncomeRate++; //for every 100,000 dollars taken off of the income HouseHoldIncomeRate goes up by 1 point, each point representing 100k.

    }
    AddedTuition = (HouseHoldIncomeRate * TUITIONADDEDBASEDONINCOME); //for every 100k 20,000 dollars will be added onto tuition

  }
  FinalTuitionCost = (InitialTuition + AddedTuition) - TotalScholarships; //final tuition cost applicant will have to pay is the intial tuition cost plus the added tuition costs subtracted by all the scholarship funds
  if (FinalTuitionCost < 0) //if scholarships funds end up covering the entire tuition, applicant will still have to pay 3.50 in tuition costs
  {
    FinalTuitionCost = NOTUITIONRATE;
  }
  cout << "Total Scholarship Funds: " << TotalScholarships << endl;
  cout << "Added Tuition fees: " << AddedTuition << endl;
  return FinalTuitionCost;
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
