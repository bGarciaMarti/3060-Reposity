//                                  HomeWork_Assignment4_11_8.cpp
//
//    By: Bren Garcìa Martì
//    Date: Sept 10, 2022
//    Course: CS 3060, 001 OOP with C++
//    Compiler Used: XCode
//
//    Problem Statement: Student monthly budget
//      Write a program that has a MonthlyBudget structure designed to hold each of these expense categories. The program should pass the structure to a function that asks the user to enter the amounts spent on each budget category during a month, The program should then pass the structure to a function that displays a report indicating the amount over or under each category, as well as the amount over or under for the entire monthly budget.
// The student has established the following monthly budget:
//  Housing...............500.00
//  Utilities.............150.00
//  Household expenses.....65.00
//  Transportation.........50.00
//  Food...................250.00
//  Medical................30.00
//  Insurance.............100.00
//  Entertainment.........150.00
//  Clothing...............75.00
//  Miscellaneous..........50.00
//
//
//                         /////// Algorithm ///////

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

// ~~~ // STRUCT // ~~~ //
struct monthlyBudget{
    double Housing, Utilities, Household_expenses, Transportation, Food, Medical, Insurance, Entertainment, Clothing, Miscellaneous ;
} ;

// ~~~ // CONSTANTS // ~~~ //
const int BUFFER = 10; //max input a user can give is 10 char
const int CATEGORY = 10; // how many categories the budget-struct has

const char* category_names[CATEGORY] = { "Housing", "Utilities", "Household_expenses", "Transportation", "Food", "Medical", "Insurance", "Entertainment", "Clothing", "Miscellaneous"}; // array of strings to for display purposes
const double budget_flags[CATEGORY] = {500.00, 150.00, 65.00, 50.00, 250.00, 30.00, 100.00, 150.00, 75.00, 50.00}; // the budget limits of each category, corresponding to their index in category_names


// Prompts/User Instuctions
const char * prompt = "\nThis is a student budget checkbook program.\n\n"
                            "Pleaes enter the amount spent on each category as they appear in a 00.00 format.\n";
const char * summaryBanner = "\n\n------------------------\n"
                             "    Student's Monthly Budget"
                             "\n------------------------\n";
const char * fairwell = "\n\n---------------------------------------------------\n"
                             "Student's Monthly Budget Analysis Completed. Adios~"
                             "\n---------------------------------------------------\n";

// ~~~ // FUNCTION PROTOTYPES // ~~~ //
// getting and validating input functions
void getDoubleInput(double *data);
void validateDouble(const char *buff);
void stripStr(char strArray[]);
void diffInputStr(char strArray[]);
void printMessage(const char* silly_message);
void input(struct monthlyBudget *silly_budget);
void brute_force_display_checkbook(struct monthlyBudget *silly_budget);

// ~~~ // MAIN // ~~~ //
int main()
{
    monthlyBudget budget; // declare a struct to hold the student's data
    printMessage(prompt); // introduce what the program does to the user and how to use it
    input(&budget);
    brute_force_display_checkbook(&budget);
    printMessage(fairwell);
    return 0;
} // end of main



// ~~~ // FUNCTIONS // ~~~ //

void input(struct monthlyBudget *silly_budget)
{   int i = 0; // incrementing variable
    double silly_input = -99.99; // a temporary variable to hold input
    double *dPtr = &silly_budget->Housing; // points to memory, not value
    
    while (i < CATEGORY) // while i is less than the number of categories in the budget
    {   silly_input = 0.0; //reset silly_input
        // cout << "\nHow much did you spend on " << *dPtr << ": "; // loop through the category names
        cout << "\nHow much did you spend on " << category_names[i] << ": "; // loop through the category names
        getDoubleInput(&silly_input); // get a valid input of a double data
        // silly_input now has a valid double in it
        
        //string catengate the category_names[i] to the end of the budget. call to give the value
        *dPtr = silly_input; //deference to get the string in category_names[i] and use
        
        // change getDoubleINput so that you are giving it a struct
        i++; //increment through the categories
        dPtr++; // doubles are 8 bytes, so this moves 8 bytes over the struct to the next struct-element, since they're all doubles
    }
} //end of input

// ~~~ // ~~~ // ~~~ // ~~~ // ~~~ // ~~~ //
void getDoubleInput(double *data)
{
char numInput[BUFFER] = {'\0'};
char *ptr; // = &data[0];
double num = 0.0;
bool withinRange = false; //No negative money, but all positives are possible
bool confirmation = false;
    do
    {
        while (withinRange == false)
        {
        diffInputStr(numInput); // get input from user with fgets cmd
        stripStr(numInput); //strip the new line character at the end of the string
        validateDouble(numInput); //make sure the input was a number
            num = strtod(numInput, &ptr); //strip off any not number data at the end of the numInput array

        if (ptr != numInput)
            {   *data = num;
                confirmation = true;
                // printf("The number double is %lf\n", num); //TESTING
                // printf("The string part is |%s|\n", ptr); //TESTING
                if (num > 0)
                {
                    withinRange = true; //make sure the input wasn't a negative number
                }
            }
             else // the data entry is char data
             {  printf("%s", "Error INVALID DATA.\nPlease enter only positive, numerical data in a 00.00 format.\n");
             }
        
        } // end of while (withinRange == false)
    } while (confirmation == false);
}// end of get getDoubleInput

// ~~~ // validateInt algorithm // ~~~ //
// Used to make sure the data for prices and percentages is in a 00.00 format.
// from LA09 Numeric Validation Exploration
// https://docs.google.com/document/d/1RPw7rgBRT-uycn3jEyMrTK-vbnt4SEvytk1CaepYXU4/edit
// ~~~ // ~~~ // ~~~ // ~~~ // ~~~ // ~~~ //
void  validateDouble(const char *buff)
{
char *end;
errno = 0;
double validInt = 0.0;
    //  num = strtod(numInput, &ptr);
    //long intTest = strtol(buff, &end, 10);
    double intTest = strtod(buff, &end);
    
    if (end == buff) {
        // fprintf(stderr, "%s not a decimal number\n", buff);
    }
    else if ('\0' != *end) {
        // fprintf(stderr, "%s extra characters at end of input: %s\n", buff, end); // TROUBLESHOOTING PURPOSES
        }
        else if ((LONG_MIN == intTest || LONG_MAX == intTest) && ERANGE == errno){
            // fprintf(stderr, "%s out of range of type long\n", buff); // TROUBLESHOOTING PURPOSES
        }
        else if (intTest > INT_MAX)    {
            // fprintf(stderr, "%f greater than INT_MAX\n", intTest); // TROUBLESHOOTING PURPOSES
        }
        else if (intTest < INT_MIN) {
            // fprintf(stderr, "%f less than INT_MIN\n", intTest); // TROUBLESHOOTING PURPOSES
        }
        else {
            validInt = (double)intTest;
            // printf("%f is double value ", intTest); // TROUBLESHOOTING PURPOSES
        }
} // end of validateDouble

// ~~~ // stripStr alrogithm // ~~~ //
// Algorithm: // strip a new line character off the end of a string/char array //
// ~~~ // ~~~ // ~~~ // ~~~ // ~~~ //
void stripStr(char strArray[])
{
    //if (strArray[0] != 1) // if the data entry is a char data
      //  { strArray[strcspn(strArray, "\n")] = 0; //strip off the \n at the end of the string }
    if (strArray[strlen(strArray) - 1] == '\n')
    {
        strArray[strlen(strArray) - 1] = '\0';
    }
    return;
} // end of stripStr

// ~~~ // diffInputStr alrogithm // ~~~ //
// Algorithm: // prompt the user // call fgets cmd // retun nothing //
// ~~~ // ~~~ // ~~~ // ~~~ // ~~~ //
void diffInputStr(char strArray[])
{
    // take input with fgets
    fgets(strArray, BUFFER, stdin); //read the input string using fgets
        //clear the buffer for fgets
        if (strchr(strArray, '\n') == NULL)
        { while ((getchar()) != '\n'); }
    return;
} // REFERENCE: https://www.geeksforgeeks.org/fgets-gets-c-language/

// ~~~ // printMessage alrogithm // ~~~ //
// print a string array 1 index-element at a time. This is to increase the ease for the programmer, while still retraining security of printing strings
// ~~~ // ~~~ // ~~~ // ~~~ // ~~~ //
void printMessage(const char* silly_message)
{
    int i = 0;
    for(i = 0; silly_message[i] != '\0'; i++) // while not end-of-string
    {
        printf("%c", silly_message[i]);
    }puts(""); //formatting
} // end of printMessage

void brute_force_display_checkbook(struct monthlyBudget *silly_budget)
{   int i = 0;
    printMessage(summaryBanner);
// Housing
    cout << "The " << category_names[i] << " expenses are at " << silly_budget->Housing << " which is "; // loop through the category names
    if (    silly_budget->Housing > budget_flags[i]    )
    {   cout << "over budget.\n------------------------\n"; }
    else
    {   cout << "under budget.\n------------------------\n"; }
    i++;
// Utilities
    cout << "The " << category_names[i] << " expenses are at " << silly_budget->Utilities << " which is "; // loop through the category names
    if (    silly_budget->Utilities > budget_flags[i]    )
    {   cout << "over budget.\n------------------------\n"; }
    else
    {   cout << "under budget.\n------------------------\n"; }
    i++;
// Household_expenses
    cout << "The " << category_names[i] << " expenses are at " << silly_budget->Household_expenses << " which is "; // loop through the category names
    if (    silly_budget->Household_expenses > budget_flags[i]    )
    {   cout << "over budget.\n------------------------\n"; }
    else
    {   cout << "under budget.\n------------------------\n"; }
    i++;
// Transportion
    cout << "The " << category_names[i] << " expenses are at " << silly_budget->Transportation << " which is "; // loop through the category names
    if (    silly_budget->Transportation > budget_flags[i]    )
    {   cout << "over budget.\n------------------------\n"; }
    else
    {   cout << "under budget.\n------------------------\n"; }
    i++;
//Food
    cout << "The " << category_names[i] << " expenses are at " << silly_budget->Food << " which is "; // loop through the category names
    if (    silly_budget->Food > budget_flags[i]    )
    {   cout << "over budget.\n------------------------\n"; }
    else
    {   cout << "under budget.\n------------------------\n"; }
    i++;
//Medical
    cout << "The " << category_names[i] << " expenses are at " << silly_budget->Medical << " which is "; // loop through the category names
    if (    silly_budget->Medical > budget_flags[i]    )
    {   cout << "over budget.\n------------------------\n"; }
    else
    {   cout << "under budget.\n------------------------\n"; }
    i++;
//Insurance
    cout << "The " << category_names[i] << " expenses are at " << silly_budget->Insurance << " which is "; // loop through the category names
    if (    silly_budget->Insurance > budget_flags[i]    )
    {   cout << "over budget.\n------------------------\n"; }
    else
    {   cout << "under budget.\n------------------------\n"; }
    i++;
// Entertainment
    cout << "The " << category_names[i] << " expenses are at " << silly_budget->Entertainment << " which is "; // loop through the category names
    if (    silly_budget->Entertainment > budget_flags[i]    )
    {   cout << "over budget.\n------------------------\n"; }
    else
    {   cout << "under budget.\n------------------------\n"; }
    i++;
// Clothing
    cout << "The " << category_names[i] << " expenses are at " << silly_budget->Clothing << " which is "; // loop through the category names
    if (    silly_budget->Clothing > budget_flags[i]    )
    {   cout << "over budget.\n------------------------\n"; }
    else
    {   cout << "under budget.\n------------------------\n"; }
    i++;
// Miscellaneous
    cout << "The " << category_names[i] << " expenses are at " << silly_budget->Miscellaneous << " which is "; // loop through the category names
    if (    silly_budget->Miscellaneous > budget_flags[i]    )
    {   cout << "over budget.\n------------------------\n"; }
    else
    {   cout << "under budget.\n------------------------\n"; }
    i++;
}


void display_checkbook(struct monthlyBudget *silly_budget)
{   int i = 0;
    double *dPtr = &silly_budget->Housing; // points to memory, not value
    
    printMessage(summaryBanner);
    while (i < CATEGORY) // while i is less than the number of categories in the budget
    {
        cout << "\nThe " << category_names[i] << " expenses are at " << *dPtr << " which is "; // loop through the category names
        if (    *dPtr > budget_flags[i]    )
        {   cout << "over budget.\n------------------------\n"; }
        else
        {   cout << "under budget.\n------------------------\n"; }
        // silly_input now has a valid double in it
        
        dPtr++;
        }
} // end of display_checkbook
