/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Name: Ryan Scott
This program processes student test scores from a file and calculates 
the average by dropping the lowest test score and using the high score
twice. It also calculates the class average and counts the number of 
students in Excellent, Satisfactory, and Failing categories. Output
is to the screen.
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>

using namespace std;

int main()
{
//variable declarations
int t1, t2, t3, t4, t5;                  //5 test scores
double studentCount;                     //number of students 
int failCount, satisCount, excelCount;   //number of students in each range
double avgSum;                           //sum of averages
int classAverage;                        //class average
int studentAverage;                      //student's average
char grade;                              //grade assigned according to average
string firstName, lastName;              //student's first/last name
ifstream inFile;                         //input from file

//function prototypes
int calc_grade(int);
int calc_average(int,int,int,int,int);
int class_average(double, double);
void category(double, int&, int&, int&);


//open the file to read name and test scores
inFile.open("Project3_data.txt");

//if file is not found, print error message and terminate program 
if (!inFile) 
    {
       cout << "Error: File not found.\n";
       cout << "Check that file name is correct.\n\n";
       system ("PAUSE");
       return 1;                 
    }    

//initialize necessary counts to zero
avgSum = 0;                     
studentCount = 0;   
excelCount = 0;
satisCount = 0;
failCount = 0;

//output header
cout << "Student            Test1   Test2" << 
  "   Test3   Test4   Test5   Average**    Grade" << endl;
cout << endl;

//process students while there is still data in the file
while (!inFile.eof())
{
      
//read information from file
inFile >> firstName >> lastName >> t1 >> t2 >> t3 >> t4 >> t5;

//function calls to determine averages and corresponding letter grade
studentAverage = calc_average(t1,t2,t3,t4,t5);
grade = calc_grade(studentAverage);

//keep track of the average sum and number of students processed
avgSum = avgSum + studentAverage;
studentCount = studentCount+1;

//call function to increment appropriate category count
category(studentAverage, excelCount, satisCount, failCount);

//output student name, test scores, average, and grade
cout << setw(7) << left << lastName <<","<< setfill(' ') 
     << left << setw(12) << firstName << right<< t1 
     << setw(8) << t2 << setw(8) << t3 << setw(8) << t4 
     << setw(8) << t5 << setw(10) << studentAverage 
     << setw(11) << grade << endl;
}
//explain how average is calculated
cout << "\n** average is calculated by dropping"
" the low score and adding the high score twice\n" << endl;

//function call to calculate class average
classAverage = class_average(avgSum,studentCount);

cout << endl;
cout << "The number of students in the class is " << studentCount << endl;
cout << "Class Average = " << classAverage << endl;
cout << endl;
cout << "Number of students in each category.\n" << endl;
cout << setw(12)<< left <<"Excellent: "<< setw(4) << right << excelCount << endl;
cout << setw(12)<< left <<"Satisfactory: "<< setw(2) << right << satisCount << endl;
cout << setw(12)<< left <<"Failing: " << setw(4) << right << failCount <<"\n"<< endl;

//close the input file
inFile.close();
//termination statement
cout << "This program (project 3) was written by Ryan Scott." << endl;
system("PAUSE");
return 0;
}

// function declarations
// function to determine the students letter grade from their average
int calc_grade(int studentAverage)
{
    char grade;
    if (studentAverage >= 90)
      grade = 'A';
    else if (studentAverage < 90 && studentAverage >= 80)
      grade = 'B';
    else if (studentAverage < 80 && studentAverage >= 70)
      grade = 'C';
    else if (studentAverage < 70 && studentAverage >= 60)
      grade = 'D';
    else if (studentAverage < 60)
      grade = 'F';
    
 return grade;
}  
//function to determine the students high and low score 
//and calculate the average
int calc_average(int t1,int t2,int t3,int t4,int t5)
{
    int scores[5]={t1,t2,t3,t4,t5};
    int highScore, lowScore;
    int maxIndex = 0;
    int index;
    int lowIndex = 0;
    double studentAvg;
    //determine high and low scores
    for (index = 0; index < 5; index++)
    {
        if (scores[maxIndex] < scores[index])
            maxIndex = index;
            highScore = scores[maxIndex];
        if (scores[lowIndex] > scores[index])
            lowIndex = index;
            lowScore = scores[lowIndex];
    }   
    
    //calculate and round average to nearest integer
    setprecision(2);
    studentAvg = static_cast<double>(t1+t2+t3+t4+t5-lowScore+highScore)/5;
    index = static_cast<int>(studentAvg+0.5);

 return index;   
}  
//function calculates class average
int class_average(double avgSum, double studentCount)
{
    int average;
    average = static_cast<int>(avgSum/studentCount+0.5);
    return average;
}
//function determines which count category to update
void category(double studentAverage,int& excelCount, int& satisCount, int& failCount)
{
    
    if (studentAverage >= 90)
      excelCount++;
    else if (studentAverage < 90 && studentAverage >= 80)
      satisCount++;
    else if (studentAverage < 80 && studentAverage >= 70)
      satisCount++;
    else if (studentAverage < 70 && studentAverage >= 60)
      failCount++;
    else if (studentAverage < 60)
      failCount++;
}










