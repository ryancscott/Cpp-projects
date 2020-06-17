
//Author: Ryan Scott
//====================================================================
//This program prompts the user to enter the initial and
//final odometer readings for a 5 day business trip (M-F) as
//well as the amount of gas consumed each day. The data is used to 
//calculate the average miles per gallon consumed by the car 
//throughout the course of the trip.
//====================================================================

#include<iostream>
#include<string>
#include<iomanip>
//^preprocessor directives with header
//files to access appropriate libraries

using namespace std;

int main()
{ 
    //variable declaration
    int odometer1, odometer2; //first and second odometer readings        
    double milesTraveled, averageMpg, totalGas; //assigned from calculation
    double gal1, gal2, gal3, gal4, gal5;//daily gas use
    const int number_of_days = 5;//used in output statement
    string firstName, lastName; //name the businessman of interest
    
    
    //ask user to enter the businessman's first name
    cout << "Please enter the businessman's first name." << endl;
    cin >> firstName;
    cout << " The businessman's first name is " << firstName << endl;
    
    //ask user to enter the businessman's last name
    cout << "Please enter the businessman's last name." << endl;
    cin >> lastName;
    cout << " The businessman's last name is " << lastName << endl;
    
    //prompt user for odometer readings
    cout << "Please enter Monday's initial odometer reading "
    "as an integer." << endl;
    cin >> odometer1;
    cout << "The intial odometer reading is " << odometer1 << endl; 
    //^echo the inital odometer reading
    
    cout << "Please enter Friday's ending odometer reading "
    "as an integer." << endl;
    cin >> odometer2;
    cout << "The final odometer reading is " << odometer2 << endl; 
    // ^echo the final reading
    
    cout << fixed << showpoint; //output data manipulation
    
    //Prompt the user for gallons of gas used per day
    cout << setprecision(2);
    cout << "Please enter how much gas was consumed on "
    "Monday." << endl;
    cin >> gal1;
    cout << "The number of gallons consumed on day one: " 
    << gal1 << endl;
    
    cout << setprecision(2);
    cout << "Please enter how much gas was consumed on "
    "Tuesday." << endl;
    cin >> gal2;
    cout << "The number of gallons consumed on day two: " 
    << gal2 << endl;
    
    cout << setprecision(2);
    cout << "Please enter how much gas was consumed on " 
    "Wednesday." << endl;
    cin >> gal3;
    cout << "The number of gallons consumed on day one: " 
    << gal3 << endl;
    
    cout << setprecision(2);
    cout << "Please enter how much gas was consumed on "
    "Thursday." << endl;
    cin >> gal4;
    cout << "The number of gallons consumed on day one: "
    << gal4 << endl;
    
    cout << setprecision(2);
    cout << "Please enter how much gas was consumed on "
    "Friday." << endl;
    cin >> gal5;
    cout << "The number of gallons consumed on day one: "
    << gal5 << endl;
    
    //calculation of total number of miles traveled 
    milesTraveled = odometer2-odometer1;
    cout << endl;
    
    //calculation of total amount of gas used
    totalGas = gal1+gal2+gal3+gal4+gal5;
    cout << endl;
    
    //calculation of the average mpg during the trip
    averageMpg = milesTraveled/totalGas;
    cout << endl;
    
    //output result of calculations
    cout << setprecision(2);
    cout << "The total number of miles traveled during the "
    << number_of_days << " day trip: " << milesTraveled << endl;
    cout << "The total gallons of gas used: " << totalGas << endl;
    cout << "The average miles per gallon: " << averageMpg << endl;
    cout << endl;
    
    //termination statement
    cout << "This program was written by Ryan Scott." << endl;
    
    system("pause");
    return 0;
}
