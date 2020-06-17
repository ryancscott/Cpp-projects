/*===========================================================================
Ryan Scott
This function calculates the body mass index (BMI) given a persons 
height and weight.
============================================================================*/
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<cmath>

using namespace std;

//struct variable type to store member data
struct memberType
{
   string firstName;  // member name
   int memberID;      // membership ID #
   double height;     // height in inches
   double weight;     // weight in pounds 
};
//struct to create nodes to build linked list
struct nodeType
{
   memberType memberInfo;
   nodeType *link;    
};

//function prototypes
void getData(ifstream& dataFile, nodeType *list);
void printScreen(nodeType *list);


int main()
{
  //variable declarations
  char fileName[20]; //c-string to store filename
  ifstream inFile;
  ofstream outFile;
  nodeType *first;
  
    
//prompt user for input file    
cout << "Enter the input file name." << endl;
cin >> fileName; 

//open input file
inFile.open(fileName);
//open output file
//outFile.open("Scott.txt");

//error message if file is missing or incorrect
if (!inFile)
{
   cout << " Error: No file found." << endl;
   system("pause");
   return 1;
}   
    
getData(inFile, first);
//printScreen(first);
    
    
 system("pause");
 return 0;   
}



//function definition
//function to input data from file into list
void getData (ifstream& dataFile, nodeType *list)
{
     nodeType *current, *first;
     
     
     //initiate first node in list
       list = new nodeType;
       dataFile >> (list->memberInfo.firstName)
                 >> (list->memberInfo.memberID)
                 >> (list->memberInfo.height)
                 >> (list->memberInfo.weight);
       list->link = NULL;
       first = list;
       
       cout <<    (list->memberInfo.firstName) << " "
           <<      (list->memberInfo.memberID) << " "
           <<      (list->memberInfo.height) << " "
           <<      (list->memberInfo.weight) << " "
           << "\n";
     while(dataFile)
     {   
     current = new nodeType; 
     
     

     list->link = current;
     dataFile >> (current->memberInfo.firstName)
              >> (current->memberInfo.memberID)
              >> (current->memberInfo.height)
              >> (current->memberInfo.weight);
    
    
      
     cout      <<    (current->memberInfo.firstName) << "  "
           <<    (current->memberInfo.memberID) << "  "
           <<    (current->memberInfo.height) << "  "
           <<    (current->memberInfo.weight) << "  "
           <<   endl;  
     
          
     current->link = NULL;
     list = current;
     }       
     list = first;
       
}
//function to print out member info, ordered by ID
void printScreen(nodeType *list)
{
     nodeType *current;
     current = list;
     
     while (current != NULL)
     {
     cout <<   (current->memberInfo.firstName) << "  "
          <<   (current->memberInfo.memberID) << "  "
          <<   (current->memberInfo.height) << "  "
          <<   (current->memberInfo.weight) << "  "
          <<   endl;   
     } 
}

/*function to calculate BMI
void calcBMI(nodeType *list)
{
     nodeType *current;
     double BMI;
     
     current = list;
     
     while (current != NULL)
     {
      BMI = (current->memberInfo.weight / pow(current->memberInfo.height, 2.0)*703;
      current = current->link;
     }
         
}
*/
