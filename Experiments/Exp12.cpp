#include <iostream>
#include <string>

using namespace std;


class Account
{
protected:

    int accountNumber;
    string accountHolder;
    double balance;

public:

    Account(int accNo, string name, double bal)
    {
        accountNumber = accNo;
        accountHolder = name;
        balance = bal;
    }

    virtual void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;

            cout << "Deposited: Rs."
                 << amount << endl;
        }
    }

    virtual void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;

            cout << "Withdrawn: Rs."
                 << amount << endl;
        }
        else
        {
            cout << "Insufficient Balance!"
                 << endl;
        }
    }

    virtual void display()
    {
        cout << "\nAccount Number: "
             << accountNumber << endl;

        cout << "Account Holder: "
             << accountHolder << endl;

        cout << "Balance: Rs."
             << balance << endl;
    }

    virtual ~Account()
    {
    }
};


class SavingsAccount : public Account
{
private:

    double interestRate;

public:

    SavingsAccount(int accNo,
                   string name,
                   double bal,
                   double rate)
        : Account(accNo, name, bal)
    {
        interestRate = rate;
    }

    void applyInterest()
    {
        double interest =
            balance * interestRate / 100;

        balance += interest;

        cout << "Interest Added: Rs."
             << interest << endl;
    }

    void display() override
    {
        cout << "\n--- Savings Account ---"
             << endl;

        Account::display();

        cout << "Interest Rate: "
             << interestRate << "%"
             << endl;
    }
};


class CheckingAccount : public Account
{
private:

    double transactionFee;

public:

    CheckingAccount(int accNo,
                    string name,
                    double bal,
                    double fee)
        : Account(accNo, name, bal)
    {
        transactionFee = fee;
    }

    void withdraw(double amount) override
    {
        double total = amount + transactionFee;

        if (total <= balance)
        {
            balance -= total;

            cout << "Withdrawn: Rs."
                 << amount << endl;

            cout << "Transaction Fee: Rs."
                 << transactionFee << endl;
        }
        else
        {
            cout << "Insufficient Balance!"
                 << endl;
        }
    }

    void display() override
    {
        cout << "\n--- Checking Account ---"
             << endl;

        Account::display();

        cout << "Transaction Fee: Rs."
             << transactionFee << endl;
    }
};


int main()
{
    SavingsAccount savings(
        1001,
        "Samruddhi",
        5000,
        3
    );

    CheckingAccount checking(
        1002,
        "Rahul",
        3000,
        20
    );


    savings.display();

    savings.deposit(1000);

    savings.withdraw(500);

    savings.applyInterest();

    savings.display();


    checking.display();

    checking.deposit(1500);

    checking.withdraw(1000);

    checking.display();


    return 0;
}
