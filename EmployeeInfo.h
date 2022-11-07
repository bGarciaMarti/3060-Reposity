#ifndef EMPLOYEEINFO_H
#define EMPLOYEEINFO_H
#include <string>
#include <iostream>
using namespace std;

// This class has two data members to hold the employee ID
// and the name of the employee.

class EmployeeInfo
{
private:
    int empID;      // To hold employee ID number
    string empName; // To hold employee name

public:
    // Default Constructor
    EmployeeInfo();

    // Constructor
    EmployeeInfo(int, string);

    // Mutators
    void setEmpID(int);
    void setEmpName(string);

    // Accessors
    int getEmpID();
    string getEmpName();

        // Overloaded operator. This works directly with
        // the insert function of BinaryTree.h more specifically
        // line 71. *For my knowledge*
        bool operator < (const EmployeeInfo &e)
        {
                if (empID < e.empID)
                        return true;
                return false;
        }
        // 124
        bool operator == (const EmployeeInfo &e)
        {
                if (empID == e.empID)
                        return true;
                return false;
        }

};
#endif
