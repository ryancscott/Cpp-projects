/*===========================================================================
Author: Ryan Scott
This program manipulates files containing a list of bird species and the 
number of times each bird was viewed at various locations. It then sorts
the birds alphabetically, determines how many species of bird were seen
at each location, and determines which species was observed the most. It 
also prompts the user for a range of values and outputs which species have
a count fulfilling these values and then outputs the sorted list to a file. 
============================================================================*/
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>

using namespace std;

struct birdType            //struct definition to store bird name and count 
{
   string birdSpecies;     //species of bird  
   int birdCount;          //number of the species observed
};

//function prototypes
void getData(ifstream& dataFile, birdType list[], int& listSize);
birdType getOne(ifstream& dataIn);
void printBirds(const birdType list[], int listSize);
void selectionSort(birdType list[], int listSize);
void largestCount(birdType list[], int listSize);
void range(birdType list[], int listSize);
void toFile(ofstream& dataFile,string name, birdType list[], int listSize);

//======================================================================
int main()
{
//variable declarations
string cityName;             //name of the bird watching location
char fileName[20];           //c-string to store file name
ifstream inFile;             //input file stream variable
ofstream outFile;            //output file stream variable
int number;                  //number of birds in file
const int ARRAY_SIZE = 200;  //maximum array size
birdType list[ARRAY_SIZE];   //array of struct variable to store bird info


//prompt user for input file    
cout << "Enter the input file name." << endl;
cin >> fileName;

//open input file
inFile.open(fileName);
//open output file
outFile.open("Scott.txt");

//if file is not found, print error message and terminate program 
if (!inFile)
{
   cout << " Error: No file found." << endl;
   system("pause");
   return 1;
}

//read and echo birdwatching location    
getline(inFile, cityName);
cout << cityName << endl << endl;

//call getData function to fill array of structs
getData(inFile, list, number);
printBirds(list, number);

cout << "========================================" << endl;
cout << "             Sorted list                " << endl;
cout << "========================================" << endl;

//function calls to sort and output list
selectionSort(list, number);
printBirds(list, number);

//output the number of different bird species observed
cout << "Number of different species observed: " << number <<  endl;

//function call to determine species with max count
largestCount(list, number);

//function call to prompt user for range and output birds in range
range(list, number);

//output sorted list to a file
toFile(outFile, cityName, list, number);

cout << "This program was written by Ryan Scott." << endl;

//close files
inFile.close();
outFile.close();

system("pause");
return 0;
}

//function definitions
//==================================================================
//input bird species from file
void getData(ifstream& dataFile, birdType list[], int& listSize)
{
   birdType item;
   listSize = 0;
 
   item = getOne(dataFile);
 
    while (dataFile)
      {
       list[listSize] = item;
       listSize++;
       item = getOne(dataFile);      
      }    
    dataFile.close();
     
}
//==================================================================
//input one bird species and count
birdType getOne(ifstream& dataIn)
{
  birdType one;

  dataIn >> one.birdSpecies >> one.birdCount;

 return one;
}
//==================================================================
//print out list of bird species and count
void printBirds(const birdType list[], int listSize)
{
     int looper;
     for(looper = 0; looper < listSize; looper++)
     {
      cout << setw(28) << left << list[looper].birdSpecies
           << right << list[looper].birdCount << endl << endl;
      }
}
//==================================================================
//function to sort list of birds by count, low to high
void selectionSort(birdType list[], int listSize)
{
 int index;
 int smallestIndex;
 int minIndex;
 birdType temp;
 
   for(index = 0; index < listSize - 1; index++)
    {
      smallestIndex = index;
      for (minIndex = index+1; minIndex < listSize; minIndex++)
         if (list[minIndex].birdSpecies < list[smallestIndex].birdSpecies)
             smallestIndex = minIndex;
             
      temp = list[smallestIndex];
      list[smallestIndex] = list[index];
      list[index] = temp;
      }
}              
//==================================================================
//function to output bird with largest number of counts
void largestCount(birdType list[], int listSize)
{
     int highestCount;
     int i;
     
      highestCount = 0; //assume largest has 0th index
      for (i=0; i < listSize;i++)       
        if (list[i].birdCount > list[highestCount].birdCount)
         highestCount = i;
      
    cout << "\nSpecies with the maximum number of birds reported: "  
         << list[highestCount].birdSpecies << ", "
         << list[highestCount].birdCount << " counts\n" << endl;
}    
//===================================================================
//function to prompt user for a range and output which birds have a
//count that satisfies this range
void range(birdType list[], int listSize)
{
     int low;
     int high;
     int index;
     int num;
     char Y, N;
     char cont;
     //allow multiple ranges
     do
     {
      cout << "Enter the low value for the bird count range:";
      cin >> low;
      cout << "\nEnter the high value for the bird count range:";
      cin >> high;
      cout << endl;
      cout << "Species of bird within the specified range are:\n" << endl;
          
      num = 0;
      for (index = 0; index < listSize; index++)
          if (list[index].birdCount <= high && list[index].birdCount >= low)
            {
              cout << list[index].birdSpecies << endl;
              num++;
             }
      //tell user if their range is empty      
      if (num == 0)
         cout << "There are no birds in this range.\n"; 
         
      cout << "\nEnter Y if you would like to enter another range"
          << " or N to stop.";
      cin >> cont;
      cout << endl;
     }
     while (cont == 'Y');
     
     if (cont == 'N')
     cout << "**Sorted list is in output file named Scott.txt\n" << endl;
}
//======================================================================
//output sorted list to file
void toFile(ofstream& dataFile, string name, birdType list[], int listSize)
{
int looper;

selectionSort(list, listSize);

dataFile << "Ryan Scott" << endl;
dataFile << name << endl << endl;
for (looper = 0; looper < listSize; looper++)
dataFile << setw(28) << left << list[looper].birdSpecies
           << right << list[looper].birdCount << endl << endl;
}
//=======================================================================

  

     
    














