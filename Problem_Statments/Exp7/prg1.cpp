
#include <iostream>
#include <string>
using namespace std;

// Base Class
class Employee
{
protected:
    int empID;
    string empName;
    string department;

public:
    void acceptEmployeeDetails()
    {
        cout << "Enter Employee ID: ";
        cin >> empID;

        cin.ignore();
        cout << "Enter Employee Name: ";
        getline(cin, empName);

        cout << "Enter Department: ";
        getline(cin, department);
    }

    void displayEmployeeDetails()
    {
        cout << "Employee ID   : " << empID << endl;
        cout << "Employee Name : " << empName << endl;
        cout << "Department    : " << department << endl;
    }
};

// Derived Class 1
class TeachingStaff : public Employee
{
private:
    string subject;
    string qualification;

public:
    void acceptDetails()
    {
        acceptEmployeeDetails();

        cout << "Enter Subject: ";
        getline(cin, subject);

        cout << "Enter Qualification: ";
        getline(cin, qualification);
    }

    void displayDetails()
    {
        cout << "\n--- Teaching Staff Details ---" << endl;
        displayEmployeeDetails();
        cout << "Subject       : " << subject << endl;
        cout << "Qualification : " << qualification << endl;
    }
};

// Derived Class 2
class NonTeachingStaff : public Employee
{
private:
    string designation;
    int workingHours;

public:
    void acceptDetails()
    {
        acceptEmployeeDetails();

        cout << "Enter Designation: ";
        getline(cin, designation);

        cout << "Enter Working Hours: ";
        cin >> workingHours;
    }

    void displayDetails()
    {
        cout << "\n--- Non-Teaching Staff Details ---" << endl;
        displayEmployeeDetails();
        cout << "Designation   : " << designation << endl;
        cout << "Working Hours : " << workingHours
             << " hours" << endl;
    }
};

int main()
{
    TeachingStaff t;
    NonTeachingStaff n;

    cout << "--- Enter Teaching Staff Information ---\n";
    t.acceptDetails();

    cout << "\n--- Enter Non-Teaching Staff Information ---\n";
    n.acceptDetails();

    t.displayDetails();
    n.displayDetails();

    return 0;
}
