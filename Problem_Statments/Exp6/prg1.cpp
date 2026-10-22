
#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
    int empID;
    string empName;
    float basicSalary, HRA, DA, grossSalary;

public:
    // Parameterized Constructor
    Employee(int id, string name, float salary)
    {
        empID = id;
        empName = name;
        basicSalary = salary;

        HRA = basicSalary * 0.20;
        DA = basicSalary * 0.10;
        grossSalary = basicSalary + HRA + DA;

        cout << "Employee object created!" << endl;
    }

    // Calculate Gross Salary
    void calculateSalary()
    {
        grossSalary = basicSalary + HRA + DA;
    }

    // Display Employee Details
    void display()
    {
        cout << "\n----- Employee Details -----" << endl;
        cout << "Employee ID    : " << empID << endl;
        cout << "Employee Name  : " << empName << endl;
        cout << "Basic Salary   : Rs. " << basicSalary << endl;
        cout << "HRA (20%)      : Rs. " << HRA << endl;
        cout << "DA (10%)       : Rs. " << DA << endl;
        cout << "Gross Salary   : Rs. " << grossSalary << endl;
    }

    // Destructor
    ~Employee()
    {
        cout << "\nEmployee object destroyed!" << endl;
    }
};

int main()
{
    int id;
    string name;
    float salary;

    cout << "Enter Employee ID: ";
    cin >> id;

    cin.ignore();
    cout << "Enter Employee Name: ";
    getline(cin, name);

    cout << "Enter Basic Salary: Rs. ";
    cin >> salary;

    {
        Employee e(id, name, salary);

        e.calculateSalary();
        e.display();
    } // Object is destroyed here

    return 0;
}
