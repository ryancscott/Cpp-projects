//Author: Ryan Scott
/*====================================================================
This program computes the balance of various bank accounts at the end 
of the month for a local bank given the current balance and minimum
balance. It also prompts the user for their account number and type
of account (checkings vs. savings). 
====================================================================*/
#include<iostream>
#include<iomanip>

using namespace std;

int main() 
{
    //variable and constant declarations
    int acctNum;
    char acctType;
    char cont, again;
    double currentBal, minBal;
    double savSrvCharge=15.00, chkSrvCharge=28.00;
    const double savInterest=0.03;
    const double chkInterest1=0.04, chkInterest2=0.05;
    
    
    //manipulation of output 
    cout << fixed << showpoint << setprecision(2);

        
do
{    
    //prompt user for information
    cout << "Enter the account number." << endl;
    cin >> acctNum;
    cout << "Enter s or S for savings, or enter " <<
             "c or C for checkings." << endl;
    cin >> acctType;
    cout << "Enter the minimum balance allowed." << endl;
    cin >> minBal;
    cout << "Enter the current balance." << endl;
    cin >> currentBal;
    cout << "Account Number: " << acctNum << endl;
    cout << "Account Type: " << acctType << endl;
    cout << "Minimum Balance: " << minBal << endl;
    cout << "Current Balance: " << currentBal << endl;
    


    //if...else blocks to process user data and calculate
    //the balance of the specific account at the end of the month
    if (acctNum !=0 && currentBal !=0 && minBal !=0)
    {
       if (acctType == 's'|| acctType == 'S')
         {
          if (currentBal < minBal)
            currentBal = currentBal - savSrvCharge;
          else
            currentBal = currentBal + currentBal*savInterest;
            cout << "The new savings balance is: " 
                 << currentBal << endl;
          } 
       else if (acctType == 'c'|| acctType == 'C')
          {
          if (currentBal < minBal)
            currentBal = currentBal - chkSrvCharge;
          else 
              if (currentBal < (4000+minBal))
                currentBal = currentBal + currentBal*chkInterest1;
              else 
                currentBal = currentBal + currentBal*chkInterest2;
          cout << " The new checkings balance is : "
               << currentBal << endl;
          }
       else
        cout << "Invalid account type." << endl;
    }
    else 
       cout << "The input data may not be zero." << endl;
  
    cout << "Would you like to process another account?\nEnter"
            " Y or y for yes and N or n for no." << endl;
    cin >> cont;
    
      //determine whether additional accounts will be processed
      if (cont == 'Y' || cont == 'y')
        again = 'Y';
      else
        again = 'N'; 
}     
while (again == 'Y'); 

    cout << "This program was written by Ryan Scott." << endl;
    
 system("pause");
 return 0;   
}
