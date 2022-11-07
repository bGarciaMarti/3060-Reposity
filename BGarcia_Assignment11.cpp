
//    Assignment12_21_1.cpp
//    By: Bren Garcìa Martì
//    Date: Oct 27, 2022
//    Course: CS 3060, 001 OOP with C++
//    Compiler Used: XCode

// Problem Statement: 21.1

// Binary Tree Template

// Write your own version of a class template that will create a binary tree that can hold values of any data type. Demonstrate the class with a driver program.
#include "EmployeeInfo.h"
#include "BinaryTree.h"
#include <iostream>
using namespace std;

int main()
{

    // Create an instance of BinaryTree
    BinaryTree<EmployeeInfo> tree;

    // Create an EmployeeInfo object
    EmployeeInfo emp1(1021, "John Williams");
    EmployeeInfo emp2(1057, "Bill Witherspoon");
        EmployeeInfo emp3(2487, "Jennifer Twain");
        EmployeeInfo emp4(3769, "Sophia Lancaster");
        EmployeeInfo emp5(1017, "Debbie Reece");
        EmployeeInfo emp6(1275, "George McMullen");
        EmployeeInfo emp7(1899, "Ashley Smith");
        EmployeeInfo emp8(4218, "Josh Plemmons");

    tree.insertNode(emp1);
    tree.insertNode(emp2);
        tree.insertNode(emp3);
        tree.insertNode(emp4);
    tree.insertNode(emp5);
        tree.insertNode(emp6);
        tree.insertNode(emp7);
    tree.insertNode(emp8);

        // Search for an employee
        char again = 'y';               // To hold yes
        int id;                                 // To hold ID number from user

        cout << "Would you like to search for an employee?\n";
        cout << "Enter Y for yes or N for No: ";
        cin >> again;
        if (again)
        {
                do
                {
                        cout << "Enter the ID number of the employee: ";
                        cin >> id;
                        // Create an EmployeeInfo object to store the user's
                        // search parameters
                        EmployeeInfo info;
                        info.setEmpID(id);

                        // If search finds what the user entered display the
                        // corresponding employee
                        if (tree.searchNode(info))
                        {
                                
                                cout << info.getEmpName() << endl;
                        }
                        else
                                cout << "ID not found!" << endl;

                        cout << "Would you like to search for an employee?\n";
                        cout << "Enter Y for yes or N for No: ";
                        cin >> again;
                }while (again == tolower('Y'));
        


    // Display in order
    tree.displayInOrder();
      //  cout << endl;
        //tree.displayPreOrder();
        //cout << endl;
        //tree.displayPostOrder();

        }
}
