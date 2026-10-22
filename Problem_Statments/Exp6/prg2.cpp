
#include <iostream>
using namespace std;

class Employee
{
public:
    // Calculate salary using Basic Salary only
    float calculateSalary(float basic)
    {
        return basic;
    }

    // Calculate salary using Basic Salary and HRA
    float calculateSalary(float basic, float hra)
    {
        return basic + hra;
    }

    // Calculate salary using Basic Salary, HRA and DA
    float calculateSalary(float basic, float hra, float da)
    {
        return basic + hra + da;
    }
};

int main()
{
    Employee e;

    float basic = 30000;
    float hra = 5000;
    float da = 3000;

    cout << "Salary using Basic Salary only: Rs. "
         << e.calculateSalary(basic) << endl;

    cout << "Salary using Basic Salary and HRA: Rs. "
         << e.calculateSalary(basic, hra) << endl;

    cout << "Salary using Basic Salary, HRA and DA: Rs. "
         << e.calculateSalary(basic, hra, da) << endl;

    return 0;
}
