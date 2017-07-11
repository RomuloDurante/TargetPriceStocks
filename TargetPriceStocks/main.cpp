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

void menu();

void calcmade();

//======================================================================
int main()
{
    int option = 0;
        menu();
    cin >> option;

switch (option)
    {
        case 1:
            Clear();
            calcmade(); // How the calculation is made

            break;

        case 2:

            break;

        case 3:
            Clear();
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
            cout << " Year    |   EPS - Minimum return rate of "<< perc <<    " | #Price to get desired return# \n";
            cout << "         |                                    |               \n";

                for ( int i=4; i >=0 ; i--)
                    {
                     cout <<" "<< FiveYears[i] <<" =>       "<< setprecision(4)<<"    "<< EstimatedPrice << " / " << perc;
                     cout << "            =>      (#";
                     cout << setprecision(4)<<"  "<< ( EstimatedPrice / growUp ) << "#)\n"; // here the heart of the analysis
                     EstimatedPrice = EstimatedPrice / growUp;// will tell us the price to pay to get the return what we want.

                    }
            cout <<"-----------------------------------------------------------------\n";

            break; // end case3;


}

    cout << " Would you like calculate again ? Y/N\n";
    char opt;
    cin >> opt;

    if ( opt == 'y')
    {
        Clear();
        return (main());
    }

    Clear();
    cout << " Exit >>> \n\n";



    return 0;
}

 //===============================FUNCTIONS===========================


void Clear()
{
    system("cls");
}

void menu()
{
   cout << " ***************************************\n";
   cout << " * Select the Option                   *\n";
   cout << " * [1] How the calculation is made     *\n";
   cout << " * [2] What data do I need to collect? *\n";
   cout << " * [3] START CALCULATING               *\n";
   cout << " ***************************************\n\n";
} // main menu;

void calcmade() //How the calculation is made
{
    cout << " Step 1: Design EPS growth over the next 5 years.\n";
    cout << " If the EPS growth of the company is greater than 15% we will use 15%\n";
    cout << " If it is less than 15% we will use 10%\n";
    cout << "-----------------------------------------------------------------\n\n";
    cout << " Step 2: Use the current P / L as follows:\n";
    cout << " If the current P / L is greater than 20 we will use a P / L of 17.\n";
    cout << " If it is less than 20 we will use a P / L 12\n";
    cout << "-----------------------------------------------------------------\n\n";
    cout << " Step 3: Carry out the calculation as follows:\n";
    cout << " Combine the current EPS (TTM) with the percentage set in step1 for the next 5 years\n";
    cout << " Multiply the estimated P / L defined in step2 by estimated EPS at the end of the fifth year\n";
    cout << " Calculate the profits paid in the form of dividends\n";
    cout << " Get the total share price\n";
    cout << "-----------------------------------------------------------------\n\n";
    cout << " Step 4: Design the price to pay to get the desired return:\n";
    cout << " After obtaining the total share price at the end of the fifth year\n";
    cout << " We will divide this value by the percentage we want to return\n";
    cout << " So we will get the price to be paid to have the expected return\n";
    cout << "-----------------------------------------------------------------\n\n";

}
