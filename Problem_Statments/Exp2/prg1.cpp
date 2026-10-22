
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Employee
{
private:
    int empID;
    string empName;
    string department;
    double basicSalary;

public:
    // Accept employee details
    void acceptDetails()
    {
        cout << "Enter Employee ID: ";
        cin >> empID;

        cin.ignore();

        cout << "Enter Employee Name: ";
        getline(cin, empName);

        cout << "Enter Department: ";
        getline(cin, department);

        cout << "Enter Basic Monthly Salary: Rs. ";
        cin >> basicSalary;
    }

    // Calculate annual salary
    double calculateAnnualSalary()
    {
        return basicSalary * 12;
    }

    // Display employee information
    void displayDetails()
    {
        cout << "\n===== EMPLOYEE INFORMATION =====" << endl;
        cout << "Employee ID       : " << empID << endl;
        cout << "Employee Name     : " << empName << endl;
        cout << "Department        : " << department << endl;

        cout << fixed << setprecision(2);
        cout << "Basic Monthly Salary: Rs. "
             << basicSalary << endl;

        cout << "Annual Salary     : Rs. "
             << calculateAnnualSalary() << endl;
    }
};

int main()
{
    Employee e;

    e.acceptDetails();
    e.displayDetails();

    return 0;
}
