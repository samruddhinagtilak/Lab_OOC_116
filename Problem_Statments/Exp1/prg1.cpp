
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    string name;
    int units;
    double bill = 0;

    // Accept consumer details
    cout << "Enter Consumer Name: ";
    getline(cin, name);

    cout << "Enter Units Consumed: ";
    cin >> units;

    if (units < 0)
    {
        cout << "Invalid units consumed!" << endl;
        return 0;
    }

    // Calculate electricity bill using slab rates
    if (units <= 100)
    {
        bill = units * 5;
    }
    else if (units <= 200)
    {
        bill = (100 * 5) + (units - 100) * 7;
    }
    else if (units <= 300)
    {
        bill = (100 * 5) + (100 * 7)
               + (units - 200) * 10;
    }
    else
    {
        bill = (100 * 5) + (100 * 7)
               + (100 * 10) + (units - 300) * 12;
    }

    // Display consumer details and bill
    cout << "\n----- Electricity Bill -----" << endl;
    cout << "Consumer Name : " << name << endl;
    cout << "Units Consumed: " << units << endl;
    cout << fixed << setprecision(2);
    cout << "Payable Amount: Rs. " << bill << endl;

    return 0;
}
