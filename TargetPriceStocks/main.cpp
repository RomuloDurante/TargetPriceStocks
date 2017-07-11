/*

Hello..
This program will calculate the target stock prices. The technique I use takes into account
In Earnings Per Share - EPS - and Fundamental Analysis based on the book "Getting Started in Value Investing" (Charles Mizrahi).
Basically it uses the percentage that the EPS has grown in the last 10 years to be able to estimate a possible
Predicting that future profits will grow at the same rate as in the past.

This is my first code in c++, I'm learning programing, English and how to use GitHub. I have basic knowledge of c ++,
as soon as my skills are increased I will improve the code.
Romulo Durante
*/

#include <iostream>
#include <iomanip> // using setprecision
#include <stdlib.h>

using namespace std;

//======================================================================
void Clear();

//======================================================================
int main()
{
string Company = "";
   cout << " Enter the name of Company: ";   // Data required for calculation
   cin >> Company;
   Clear();
//---------------------------------------------------------------------------
int CurrentYear = 0;
    cout << " Enter the current year: "; // Data required for calculation
    cin >> CurrentYear;
    Clear();
//---------------------------------------------------------------------------
 float Payout = 0;
    cout << " Enter the Dividend Payout% : "; // Current company payout
    cin >> Payout;
    Clear();
//---------------------------------------------------------------------------
    cout << " Enter EPS of the year " << CurrentYear - 10 << ": ";
float TenYearsAgoEPS = 0;  //It is necessary to obtain the EPS ten years ago
    cin >> TenYearsAgoEPS;  // To be able to calculate the percentage they grew in 10 years
    Clear();
//---------------------------------------------------------------------------
     cout << " Enter EPS of the current year " << CurrentYear << ": ";
float EpsAtual = 0; // You need the current EPS to compare with the EPS of 10 years ago
     cin >> EpsAtual;// in order to get the percentage that  grew
     Clear();
//---------------------------------------------------------------------------
     cout << " Enter company P/L: ";// Pl will be used to estimate the current price of the company
int pl = 0;
     cin >> pl;
     Clear();
//-----------------------------------------------------------------------------
int FiveYears[5]; // Serves to number the years, in this technique is used the calculation of 5 years in a row
   CurrentYear--;

   for( int i=0; i < 5; i++ )
      {
       FiveYears[i] = CurrentYear + 1;
       CurrentYear = FiveYears[i];
       }
//---------------------------------------------------------------------------------
float growUp=0;
     string perc = "";
     growUp = (EpsAtual * 100) / TenYearsAgoEPS;

    if ( growUp > 15)
        {
         growUp = 1.15;           // here calculate the percent we will use
         perc = "15%";
         }
          else
          {
           growUp = 1.10;
           perc = "10%";
          }
//--------------------------------------------------------------------------------
     if( pl > 20)
       {
        pl = 17;
        }                        // here calculate the P/L we will use
        else
        {
         pl = 12;
         }
//-------------------------------------------------------------------------------------------
cout << "-----------------------------------------------------------------\n";
cout << "                     Parameters used                             \n";
cout << " " << Company <<                                                "\n";
cout << " P/L:" << pl << " | EPS " << FiveYears[1] - 11 << ": $";
cout << setprecision(3)<< TenYearsAgoEPS;                            // here shows the data base used
cout << " | Payout:" << Payout << "%\n";
cout << "-----------------------------------------------------------------\n";
//----------------------------------------------------------------------------------------------
cout << "-----------------------------------------------------------------\n";
cout << " Year    |   Projection of "<< perc <<    "   |  EPS estimated\n";
cout << "         |                       |               \n";

float sum = 0;

     for ( int i=0; i < 5 ; i++)
        {
         cout <<" "<< FiveYears[i] <<"     =>      "<< setprecision(3) << EpsAtual << " + " << perc << "      =>       ";
         cout << setprecision(3) << (EpsAtual * growUp) << "\n";
         EpsAtual = EpsAtual * growUp; // Here shows year-on-year earnings per share
         sum = EpsAtual + sum;
          }
//------------------------------------------------------------------------------------------------
cout <<"-----------------------------------------------------------------\n";
cout << " The sum of the profits that will be received: $" << setprecision(4)<< sum << "\n\n";
cout <<"-----------------------------------------------------------------\n";
 //--------------------------------------------------------------------------------------------------
float EstimatedPrice = 0;
float Divid = 0;
      Divid = (( Payout /100 )* sum );
      EstimatedPrice = (EpsAtual * pl) + Divid;
//--------------------------------------------------------------------------------------------------
cout << "-----------------------------------------------------------------\n";
cout << " Year    |   EPS - Minimum return rate of "<< perc <<    "   | Price to get desired return \n";
cout << "         |                                      |               \n";

    for ( int i=4; i >=0 ; i--)
        {
         cout <<" "<< FiveYears[i] <<"    =>       "<< setprecision(4)<<"    "<< EstimatedPrice << " / " << perc;
         cout << "               =>      (";
         cout << setprecision(4)<<"  "<< ( EstimatedPrice / growUp ) << " )\n"; // here the heart of the analysis
         EstimatedPrice = EstimatedPrice / growUp;              // will tell us the price to pay to get the return what we want.

        }
cout <<"-----------------------------------------------------------------\n";

system("pause");

    return 0;
}

 //===============================FUNCTIONS===========================


void Clear()
{
    system("cls");
}
