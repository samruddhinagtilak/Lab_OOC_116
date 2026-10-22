
#include <iostream>
using namespace std;

class Matrix
{
private:
    int a[2][2];

public:
    // Input matrix
    void input()
    {
        cout << "Enter 4 matrix elements:\n";

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cin >> a[i][j];
            }
        }
    }

    // Display matrix
    void display()
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Overload + operator
    Matrix operator+(Matrix m)
    {
        Matrix temp;

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                temp.a[i][j] = a[i][j] + m.a[i][j];
            }
        }

        return temp;
    }

    // Overload - operator
    Matrix operator-(Matrix m)
    {
        Matrix temp;

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                temp.a[i][j] = a[i][j] - m.a[i][j];
            }
        }

        return temp;
    }

    // Overload == operator
    bool operator==(Matrix m)
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                if (a[i][j] != m.a[i][j])
                    return false;
            }
        }

        return true;
    }
};

int main()
{
    Matrix m1, m2, sum, difference;

    cout << "Enter first matrix:\n";
    m1.input();

    cout << "Enter second matrix:\n";
    m2.input();

    sum = m1 + m2;
    difference = m1 - m2;

    cout << "\nAddition of matrices:\n";
    sum.display();

    cout << "\nSubtraction of matrices:\n";
    difference.display();

    if (m1 == m2)
        cout << "\nBoth matrices are equal." << endl;
    else
        cout << "\nMatrices are not equal." << endl;

    return 0;
}
