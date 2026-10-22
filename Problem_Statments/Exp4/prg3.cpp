
#include <iostream>
#include <string>
using namespace std;

class MobileRecharge
{
private:
    string mobileNumber;
    float balance;

public:
    void acceptDetails()
    {
        cout << "Enter Mobile Number: ";
        cin >> mobileNumber;

        cout << "Enter Initial Balance: Rs. ";
        cin >> balance;
    }

    void recharge(float amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Recharge successful!" << endl;
        }
        else
        {
            cout << "Invalid recharge amount." << endl;
        }
    }

    void deductBalance(float amount)
    {
        if (amount <= 0)
        {
            cout << "Invalid amount." << endl;
        }
        else if (amount <= balance)
        {
            balance -= amount;
            cout << "Balance deducted successfully!" << endl;
        }
        else
        {
            cout << "Insufficient balance!" << endl;
        }
    }

    void display()
    {
        cout << "\n--- Mobile Account Details ---" << endl;
        cout << "Mobile Number : " << mobileNumber << endl;
        cout << "Current Balance: Rs. " << balance << endl;
    }
};

int main()
{
    MobileRecharge m;
    float amount;

    m.acceptDetails();

    cout << "\nEnter recharge amount: Rs. ";
    cin >> amount;
    m.recharge(amount);

    cout << "\nEnter amount to deduct: Rs. ";
    cin >> amount;
    m.deductBalance(amount);

    m.display();

    return 0;
}
