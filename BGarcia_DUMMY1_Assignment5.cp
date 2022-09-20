//
//    Assignment5_11_14.cpp
//    By: Bren Garcìa Martì
//    Date: Sept 19, 2022
//    Course: CS 3060, 001 OOP with C++
//    Compiler Used: XCode
//
//    Problem Statement: 11-14 Inventory Bins
//    Write a program that simulates inventory bins in a warehouse. Each bin holds a nubmer of the same type of parts. the program should use a structure that keeps the following data:
//      Description of the part kept in the bin
//      Number of parts in the bin
//  The program should have an array of 10 bins, initalized with the following data:
// ________________________________________________________________
//  Part Description_____________________Number of parks in the Bin
// ______________________________________________________________
//  Valve________________________________10
//  Bearing______________________________5
//  Bushing______________________________ 15
//  Coupling ______________________________21
//  Flange______________________________ 7
//  Gear_________________________________5
//  Gear Housing___________________________5
//  Vacuum Gripper________________________25
//  Cable______________________________ 18
//  Rod______________________________12
// ______________________________________________________________
// The program should have the following functions:
//      AddParts: a function that increases a specific bin's part count by a specified number
//      Removeparts: a function that decreases a specific bin's part count by a specified number
//  When the program runs, it should repeat a loop that performs the following steps: The user should see a list of what each bin holds and how many parts are in each bin. The user can choose to either quit the program or select a bin. When a bin is selected, the user can either add parts to it or remove parts from it. The loop then repeats, showing updated bin data on the screen.
//
//  INPUT VALIDATION: No bin can hold more than 30 parts, so don't let the user add more than a bin can hold. Also don't accept negative values for the number of parts being added or removed.
//
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
// call the initalize function
    // initalize function calls insert
    // insert creates a linked list


// ~~~ // CONSTANTS // ~~~ //
const int PARTS = 10; // how many categories the inventory has
const int BUFFER = 25; // a user can only put in 25 char as input
const int initial_inventory[PARTS] = {10, 5, 15, 21, 7, 5, 5, 25, 18, 12}; //global inventory array with the inital values
const char* inventory_names[PARTS] = { "Valve", "Bearing", "Bushing", "Coupling", "Flange", "Gear", "Gear Housing", "Vaccum Gripper", "Cable", "Rod"};
const char * menu = "\n----------MENU-----------\n"
    "Press 1 Add inventory to the bin\n"
    "Press 2 Remove inventory from the bin\n"
    "Enter -1 to exit the program\n"
    "-------------------------\n"
    "Pleaes enter a number to make a selection: ";

const char * inventory_banner = "\n----------INVENTORY-----------\n"
    "Part Description \t Number of Parts in the Bin\n"
    "------------------------------\n";

// ~~~ // STRUCT // ~~~ //
struct Inventory{
    char partDescription[BUFFER];
    int quantity;
    struct Inventory *nextPtr; // pointer to the next node
};
typedef struct Inventory InventoryNode; // synonym
typedef Inventory *InventoryNodePtr; // synonym for ListNode*


// ~~~ // FUNCTIONS // ~~~ //
void AddParts(int[]); // a function that increases a specific bin's part count by a specified number
void Removeparts(int[]); // a function that decreases a specific bin's part count by a specified number
void WhichPart(struct Inventory *silly_inventory);
void DisplayInventory(struct Inventory *silly_inventory);
// void InitializeInventory(struct Inventory *silly_inventory);
int isEmpty(InventoryNodePtr sillyPtr);
void printList(InventoryNodePtr currentPtr);
void insert(InventoryNodePtr *sillyPtr, char sillyName[BUFFER], int sillyQuant);

// ~~~ // insert alrogithm // ~~~ //
// insert new values into the list in sorted order.
// start at the headerPtr, and 'index' through the structs until the correct struct spot is found
// ~~~ // ~~~ // ~~~ // ~~~ // ~~~ //
void newNode(InventoryNodePtr *sillyPtr, char sillyName[BUFFER], int sillyQuant)
{
    InventoryNodePtr newPtr = new InventoryNodePtr; // create node
    if (newPtr != NULL) { // is space available
       // place values in node
        strcpy(newPtr->partDescription, sillyName);
        newPtr->quantity = sillyQuant;
        
        newPtr->nextPtr = NULL; // node does not link to another node YET

        InventoryNodePtr previousPtr = NULL;
        InventoryNodePtr currentPtr = (Inventory *) *sillyPtr;
        // loop to find the correct location in the list
         // 'index' through the struct-linked-list by looking at the nextPtr spot for NULL
         // the linked-list is sorted by part/description-alphebetically
         // REFERENCE: https://www.geeksforgeeks.org/strcmp-in-c-cpp/
      while (currentPtr != NULL && (strcmp(sillyName,currentPtr->partDescription) > 0) )
        {
           previousPtr = currentPtr; // walk to ...
           currentPtr = currentPtr->nextPtr; // ... next node
        }
        
        if (previousPtr == NULL)
        { // insert new node at beginning of list
           newPtr->nextPtr = *sillyPtr;
           *sillyPtr = newPtr;
        }
        else
        { // insert new node between previousPtr and currentPtr
           previousPtr->nextPtr = newPtr;
           newPtr->nextPtr = currentPtr;
        }
     }
     else {
        printf("%s not inserted. No memory available.\n", sillyName);
     }
    return;
} // end of insert()


void InitializeInventory(struct Inventory *silly_inventory, InventoryNodePtr startptr)
{
    InventoryNodePtr startPtr = NULL; // initially there are no nodes
    
    int i = 0;
    for (i=0; i < PARTS; i++)
    {
        newNode(&startPtr, inventory_names[i], initial_inventory[i]);
    }
    return;
}


int main()
{
    InventoryNodePtr startPtr = NULL; // initially there are no nodes
    
    Inventory inventory{
    };
    
    
    int i = 0; // for indexing
    int menuSelection = 0; // user input variable
    int *Ptr = NULL; // points to memory, not value, of first struct member
    
    
    Inventory * headPtr = NULL; //initally there is nothing in inventory
    
    // initalize the struct with all the inital inventory values
    for (i=0; i < PARTS; i++)
    {   *Ptr = initial_inventory[i];
        Ptr++; // the struct is ALL integers, so we can index through them via bytes and a Ptr
    } // end of initalizing struct inventory values
    
do // while (menuSelection != -1); // while the user hasn't entered -1
{
    DisplayInventory(&inventory);
    cout << menu;
    cin >> menuSelection; // assign user input to menuSelection
    switch(menuSelection)
        {
        case 1:
                WhichPart(headPtr);
            break;
        case 2:
            break;
        case -1:
            cout << "\n// ~~~ // ENDING PROGRAM. ADIOS~ // ~~~ //\n\n";
            break;
        default:
            cout << "ERROR  -   INVALID MENU SELECTION.";
        } // end of menu switch statement
} while (menuSelection != -1); // while the user hasn't entered -1
return 0;
} // end main()



void AddParts(int[]) // a function that increases a specific bin's part count by a specified number
{
    bool valid = false;
    int add = 0;
    while (valid == false)
    {
        cout << "Which item are we removing from? Enter it's name exactly";
        cout << "How many parts would you like to add to the bin: ";
        cin >> add;
        if (add < 0 )
        {
            cout << "ERROR - INVALID INPUT.\n Please enter a positive number of parts. Enter 0 and select the \"Remove\" option on the menu to remove inventory from bins";
        } // end of if negative input
        // else-if the value in the struct + inventory > 30 ERROR
        // else
        // change valid = true;
    }
    return;
} // end of AddParts
void Removeparts(int[]);

// ~~~ // find alrogithm // ~~~ //
// start at the headerPtr, and 'index' through the structs until the correct struct spot is found.
// search a linked list by name, retrieve the data information and copy the percentage and prices
// to variables we pass reference so they're changed at the place called
// ~~~ // ~~~ // ~~~ // ~~~ // ~~~ //
// char find(struct Inventory *silly_inventory, char sillyName[BUFFER], int *sillyInventory)
void WhichPart(struct Inventory *inventoryPtr)
{   // return node's data if a match is found
    return;
} // end of find

// ~~~ // isEmpty alrogithm // ~~~ //
// check if the Linked list has any elements in it.
// return 1 if the list is empty, 0 otherwise
// ~~~ // ~~~ // ~~~ // ~~~ // ~~~ //
int isEmpty(InventoryNodePtr sillyPtr)
{
    return sillyPtr == NULL;
}

// ~~~ // printList alrogithm // ~~~ //
// print all the data in a link list
// ~~~ // ~~~ // ~~~ // ~~~ // ~~~ //
void printList(InventoryNodePtr currentPtr)
{
    // if list is empty
    if (isEmpty(currentPtr)) {
        puts("The list is empty.\n");
        return;
    }
    else {
        puts("The list as is:");

        // while not the end of the list
        while (currentPtr != NULL) {
            cout << "Part description: " << currentPtr->partDescription;
            cout << "Quantity: " << currentPtr->quantity;
        cout << " --> ";
        currentPtr = currentPtr->nextPtr;
        }
        cout << "NULL\n";
    }
    return;
}
