#include "EmployeeInfo.h"
#include <iostream>
#include <string>
using namespace std;

//*********************************************************
// Default constructor intializes the data members        *
//*********************************************************
EmployeeInfo::EmployeeInfo()
{
        empName = "";
    empID = 0;
}

//*********************************************************
// Constructor sets the data members                      *
//*********************************************************
EmployeeInfo::EmployeeInfo(int ID, string name)
{
        empName = name;
    empID = ID;
}

//*********************************************************
// setEmpID stores the employee ID number                 *
//*********************************************************
void EmployeeInfo::setEmpID(int ID)
{
    empID = ID;
}

//*********************************************************
// setEmpName stores the full name of the employee        *
//*********************************************************
void EmployeeInfo::setEmpName(string name)
{
    empName = name;
}

//*********************************************************
// getEmpID returns the employee ID number                *
//*********************************************************
int EmployeeInfo::getEmpID()
{
    return empID;
}

//*********************************************************
// getEmpName returns the full name of the employee       *
//*********************************************************
string EmployeeInfo::getEmpName()
{
    return empName;
}

