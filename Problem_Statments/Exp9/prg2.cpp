
#include <iostream>
#include <string>
using namespace std;

// Base class
class Employee
{
protected:
    int empID;
    string name;
    float salary;

public:
    Employee(int id, string n, float s)
    {
        empID = id;
        name = n;
        salary = s;
    }

    // Virtual function
    virtual float calculateBonus()
    {
        return 0;
    }

    virtual void display()
    {
        cout << "Employee ID : " << empID << endl;
        cout << "Name        : " << name << endl;
        cout << "Salary      : Rs. " << salary << endl;
        cout << "Bonus       : Rs. "
             << calculateBonus() << endl;
    }

    virtual ~Employee() {}
};

// Derived class: Manager
class Manager : public Employee
{
public:
    Manager(int id, string n, float s)
        : Employee(id, n, s) {}

    float calculateBonus() override
    {
        return salary * 0.20;  // 20% bonus
    }
};

// Derived class: Developer
class Developer : public Employee
{
public:
    Developer(int id, string n, float s)
        : Employee(id, n, s) {}

    float calculateBonus() override
    {
        return salary * 0.10;  // 10% bonus
    }
};

int main()
{
    Manager m(101, "Rahul", 50000);
    Developer d(102, "Amit", 40000);

    cout << "--- Manager Details ---" << endl;
    m.display();

    cout << "\n--- Developer Details ---" << endl;
    d.display();

    return 0;
}
