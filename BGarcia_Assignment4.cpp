//    Assignment4_11_8.cpp
//    By: Bren Garcìa Martì
//    Date: Sept 14, 2022
//    Course: CS 3060, 001 OOP with C++
//    Compiler Used: XCode
//
//    Problem Statement: 11-8
//    Add a function to Programming Challenge 7 that allows the user to search the structure array for a particular customer's account. It should accept part of the customer's name as an argument and then search for an account with a name that matches it. All acounts that match should be displayed. If no account matches, a message saying so should be displayed.
//  11-7 Write a program that uses a structure to store the following data about customer account:
//  Name
//  Address
//  City, state, ZIP
//  Telephone Number
//  Account Balance
//  Date of Last Payment
//    The program should use an array of at least 10 structures. It should let the user enter data into the array, change the contents of any element, and display all the data stored in the array. The program should have a menu-driven user interface.
//    Input Validation: when the data for a new account is entered, be sure the user enters data for all the fields. No negative account balances should be entered.
//

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// ~~~ // STRUCT // ~~~ //
struct Accounts
{
    string name, address, city, state, ZIP_CODE, phone_no;
    double account_balance;
    string last_payment_date;
};

// ~~~ // CONSTANTS // ~~~ //
const int SIZE = 2;
const char * menu = "\n----------MENU-----------\n"
    "Press 1 to make a new account entry\n"
    "Press 2 to change account information\n"
    "Press 3 to display all accounts' information\n"
    "Press 4 to search for a particular account\n"
    "Enter -1 to exit the program\n"
    "-------------------------\n"
    "Pleaes enter a number to make a selection: ";

// ~~~ // FUNCTION PROTOTYPES // ~~~ //
void displayAccounts(struct Accounts sillyAccount[]);
void findCustomer(struct Accounts sillyAccount[], string name);
void newEntry(struct Accounts sillyAccount[], int i);
void changeDetails(struct Accounts sillyAccount[], int account_number);
// ~~~ // SPECIAL FUNCTIONS // ~~~ //
void printMessage(const char* silly_message);
bool yesOrNo(void);

int main()
{
    int menuSelection = 0, accountNumber = 0, i = 0;
    Accounts account[SIZE]; // array of Accounts
    Accounts customer; // a structure of the account objects
    string fullName;
    
    do // while (menuSelection != -1); // while the user hasn't entered -1, and we haven't reached the bank's maximum number of accounts
    {
    printMessage(menu); // prompt user with menu
    cin >> menuSelection; // assign user input to menuSelection
    switch(menuSelection)
        {
        case 1:
            newEntry(account, i); // give newEntry account-array and index i
            break;
        case 2:
            cout << "What is the account number to make changes to: ";
            cin >> accountNumber;
            changeDetails(account, accountNumber);
            break;
        case 3:
            displayAccounts(account);
            break;
        case 4:
            cout << "What is the full name on the account to be searched for: ";
            cin >> fullName;
            findCustomer(account, fullName);
            break;
        case -1:
            cout << "\n// ~~~ // ENDING PROGRAM. ADIOS~ // ~~~ //\n\n";
            break;
        default:
            cout << "ERROR  -   INVALID MENU SELECTION.";
        } // end of menu switch statement
        
    } while (menuSelection != -1); // while the user hasn't entered -1, and we haven't reached the bank's maximum number of accounts
    return 0;
}

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
// ~~~ // yesOrNo alrogithm // ~~~ //
// used when the user is prompted with something like  confirm = yesOrNo("Confirm?\nEnter Y or N: "); this is to keep users trapped in while loops and similar unitl the confirm returns a true boolean. Using a switch case because the only valid inputs are Y and N.
// ~~~ // ~~~ // ~~~ // ~~~ // ~~~ //
bool yesOrNo(void)
{
    char answer[3] = {'\0'};
        bool confirm = false;
        while (answer[0] != '>') // the user will PROBABLY never accidentally put in >
        {
            fgets(answer, 2, stdin);
            if (strchr(answer, '\n') == NULL)
            {
                while ((getchar()) != '\n');
            }

            answer[0] = (toupper(answer[0])); // convert all input to uppercase
             // clear the buffer
            switch (answer[0])
            {
            case 'Y':
                confirm = true;
                answer[0] = '>'; // change answer to leave the while Y/N loop
                break;
            case 'N':
                confirm = false;
                answer[0] = '>';
                    break;
            default:
                puts("Invalid input. Please enter a 'Y'/'y' or an 'N'/'n'.");
                    break;
            } // end of switch case for answer var
    } // end of while (answer != 'B')
return confirm;
} // end of confirmation

void displayAccounts(struct Accounts sillyAccount[])
{
    for (int j = 0; j < SIZE; j++) // cycle through all the accounts'
    {   cout << "Account no.: " << j << endl;
        cout << "Account Holder's:\n";
        cout << "Name: " << sillyAccount[j].name << endl;
        cout << "Street address: " << sillyAccount[j].address << endl;
        cout << "City: " << sillyAccount[j].city << endl;
        cout << "State: " << sillyAccount[j].state << endl;
        cout << "ZIP CODE: " << sillyAccount[j].ZIP_CODE << endl;
        cout << "Phone no.: " << sillyAccount[j].phone_no << endl;
        cout << "Balance: " << sillyAccount[j].account_balance << endl;
        cout << "-------------------------------" << endl;
    }
    return;
} // end of displayAccounts

void findCustomer(struct Accounts sillyAccount[], string name)
{
    return;
} // end of findCustomer
void newEntry(struct Accounts sillyAccount[], int i)
{
    return;
}

void changeDetails(struct Accounts sillyAccount[], int account_number)
{   bool change = false;
    cout << "You are making changes to the data on account " << account_number << endl;
    cout << "Do you want to make changes to the name on file? (Enter a 'Y'/'y' or an 'N'/'n')";
    cin.ignore(); // clear buffer into the newline character is reached
    change = yesOrNo();
    if (change == true)
        {cout << "Enter the new full name for the account: ";
        getline (cin, sillyAccount[account_number].name); //store the input into
            cin.ignore(); // clear buffer into the newline character is reached
        cout << "\n";
        }
    change = false; // reset the bool-flag
    cout << "Do you want to make changes to the address on file? (Enter a 'Y'/'y' or an 'N'/'n')";
    change = yesOrNo();
    if (change == true)
        {   cout << "Enter the new street address for the account: ";
                getline (cin, sillyAccount[account_number].address);
                cin.ignore(); // clear buffer into the newline character is reached
                cout << "\n";
            cout << "Enter the new city: ";
                getline (cin, sillyAccount[account_number].city);
                cin.ignore(); // clear buffer into the newline character is reached
                cout << "\n";
            cout << "Enter the new state: ";
                getline (cin, sillyAccount[account_number].state);
                cin.ignore(); // clear buffer into the newline character is reached
                cout << "\n";
            cout << "Enter the new ZIP code: ";
                getline (cin, sillyAccount[account_number].ZIP_CODE);
                cin.ignore(); // clear buffer into the newline character is reached
                cout << "\n";
        }
    change = false; // reset the bool-flag
    cout << "Do you want to make changes to the phone number on file? (Enter a 'Y'/'y' or an 'N'/'n')";
    change = yesOrNo();
    if (change == true)
    {   cout << "Enter the new phone number: ";
        cin >> sillyAccount[account_number].phone_no;
        cout << "\n";
    }
    change = false; // reset the bool-flag
    cout << "Do you want to make changes to the account balance? (Enter a 'Y'/'y' or an 'N'/'n')";
    change = yesOrNo();
    if (change == true)
    {   cout << "Enter the account balance: ";
        cin >> sillyAccount[account_number].account_balance;
        while (sillyAccount[account_number].account_balance < 0) //if a negative value is entered
        {
            cout << "ERROR - INVALID NEGATIVE ENTRY - ";
            cout << "Enter a positive account balance: ";
            cin >> sillyAccount[account_number].account_balance;
        }
        cout << "\n";
    }
    change = false; // reset the bool-flag
    cout << "Do you want to make changes to the date of last payment? (Enter a 'Y'/'y' or an 'N'/'n')";
    change = yesOrNo();
    if (change == true)
    {   cout << "Enter the date of last payment: ";
        cin.ignore();
        getline(cin, sillyAccount[account_number].last_payment_date);
        cout << "\n";
    }
    return;
} // end of changeDetails
