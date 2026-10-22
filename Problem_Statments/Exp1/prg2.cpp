
#include <iostream>
using namespace std;

int main()
{
    int choice;
    double a, b;

    do
    {
        cout << "\n===== MENU-DRIVEN CALCULATOR =====" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Modulus" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 5)
        {
            cout << "Enter two numbers: ";
            cin >> a >> b;
        }

        switch (choice)
        {
            case 1:
                cout << "Addition = " << a + b << endl;
                break;

            case 2:
                cout << "Subtraction = " << a - b << endl;
                break;

            case 3:
                cout << "Multiplication = " << a * b << endl;
                break;

            case 4:
                if (b != 0)
                    cout << "Division = " << a / b << endl;
                else
                    cout << "Error: Division by zero is not allowed!" << endl;
                break;

            case 5:
                if (b != 0 &&
                    a == static_cast<int>(a) &&
                    b == static_cast<int>(b))
                {
                    cout << "Modulus = "
                         << static_cast<int>(a) % static_cast<int>(b)
                         << endl;
                }
                else if (b == 0)
                {
                    cout << "Error: Modulus by zero is not allowed!" << endl;
                }
                else
                {
                    cout << "Error: Modulus requires integer numbers!" << endl;
                }
                break;

            case 6:
                cout << "Exiting calculator. Thank you!" << endl;
                break;

            default:
                cout << "Invalid choice! Please select 1 to 6." << endl;
        }

    } while (choice != 6);

    return 0;
}
