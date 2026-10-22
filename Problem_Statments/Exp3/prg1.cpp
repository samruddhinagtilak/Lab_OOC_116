
#include <iostream>
#include <cstdlib>
using namespace std;

class Fraction
{
private:
    int numerator, denominator;

public:
    // Accept fraction
    void accept()
    {
        cout << "Enter numerator: ";
        cin >> numerator;

        cout << "Enter denominator: ";
        cin >> denominator;

        while (denominator == 0)
        {
            cout << "Denominator cannot be zero. Enter again: ";
            cin >> denominator;
        }
    }

    // Find GCD
    int gcd(int a, int b)
    {
        a = abs(a);
        b = abs(b);

        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }

        return a;
    }

    // Display fraction in simplified form
    void display(int n, int d)
    {
        if (d < 0)
        {
            n = -n;
            d = -d;
        }

        int g = gcd(n, d);

        n = n / g;
        d = d / g;

        cout << n << "/" << d << endl;
    }

    // Add two fractions
    void add(Fraction f1, Fraction f2)
    {
        int n = f1.numerator * f2.denominator
              + f2.numerator * f1.denominator;

        int d = f1.denominator * f2.denominator;

        cout << "Addition: ";
        display(n, d);
    }

    // Subtract two fractions
    void subtract(Fraction f1, Fraction f2)
    {
        int n = f1.numerator * f2.denominator
              - f2.numerator * f1.denominator;

        int d = f1.denominator * f2.denominator;

        cout << "Subtraction: ";
        display(n, d);
    }
};

int main()
{
    Fraction f1, f2, result;

    cout << "Enter first fraction:\n";
    f1.accept();

    cout << "\nEnter second fraction:\n";
    f2.accept();

    cout << "\nResults:\n";
    result.add(f1, f2);
    result.subtract(f1, f2);

    return 0;
}
