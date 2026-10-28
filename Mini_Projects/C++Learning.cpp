/*
   Basic C++ Learning Platform
*/

#include <iostream>
#include <string>
using namespace std;

// Get menu choice
int getChoice()
{
    int choice;
    cin >> choice;
    return choice;
}

// Display theory and complete standalone code
void showConcept(int n)
{
    switch (n)
    {
    case 1:
        cout << "\n===== CLASS AND OBJECT =====\n";
        cout << "Theory:\n";
        cout << "A class is a blueprint for creating objects.\n";
        cout << "An object is an instance of a class.\n";
        cout << "Classes contain data members and member functions.\n";

        cout << R"(
----- COMPLETE CODE -----

#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    int rollno;
    string name;

    void input()
    {
        cout << "Enter roll number: ";
        cin >> rollno;

        cout << "Enter name: ";
        cin >> name;
    }

    void display()
    {
        cout << "Roll Number: " << rollno << endl;
        cout << "Name: " << name << endl;
    }
};

int main()
{
    Student s;
    s.input();
    s.display();
    return 0;
}
)";
        break;

    case 2:
        cout << "\n===== CONSTRUCTOR =====\n";
        cout << "Theory:\n";
        cout << "A constructor is a special member function.\n";
        cout << "It is called automatically when an object is created.\n";
        cout << "A default constructor takes no arguments.\n";
        cout << "A parameterized constructor accepts arguments.\n";

        cout << R"(
----- COMPLETE CODE -----

#include <iostream>
using namespace std;

class Demo
{
public:
    Demo()
    {
        cout << "Default constructor called.\n";
    }

    Demo(int n)
    {
        cout << "Parameterized constructor called.\n";
        cout << "Value = " << n << endl;
    }
};

int main()
{
    Demo a;
    Demo b(100);
    return 0;
}
)";
        break;

    case 3:
        cout << "\n===== ENCAPSULATION =====\n";
        cout << "Theory:\n";
        cout << "Encapsulation combines data and functions in a class.\n";
        cout << "Private data cannot be accessed directly from outside.\n";
        cout << "Public functions provide controlled access to data.\n";

        cout << R"(
----- COMPLETE CODE -----

#include <iostream>
using namespace std;

class BankAccount
{
private:
    int balance;

public:
    BankAccount()
    {
        balance = 0;
    }

    void deposit(int amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposit successful.\n";
        }
        else
        {
            cout << "Invalid amount.\n";
        }
    }

    void displayBalance()
    {
        cout << "Balance = " << balance << endl;
    }
};

int main()
{
    BankAccount account;
    int amount;

    cout << "Enter deposit amount: ";
    cin >> amount;

    account.deposit(amount);
    account.displayBalance();

    return 0;
}
)";
        break;

    case 4:
        cout << "\n===== ABSTRACTION =====\n";
        cout << "Theory:\n";
        cout << "Abstraction hides unnecessary implementation details.\n";
        cout << "It shows only the essential functionality to the user.\n";

        cout << R"(
----- COMPLETE CODE -----

#include <iostream>
using namespace std;

class Calculator
{
private:
    int add(int a, int b)
    {
        return a + b;
    }

public:
    void result()
    {
        int a, b;

        cout << "Enter two numbers: ";
        cin >> a >> b;

        cout << "Sum = " << add(a, b) << endl;
    }
};

int main()
{
    Calculator c;
    c.result();
    return 0;
}
)";
        break;

    case 5:
        cout << "\n===== INHERITANCE =====\n";
        cout << "Theory:\n";
        cout << "Inheritance allows one class to acquire another class's\n";
        cout << "accessible members. The existing class is the base class.\n";
        cout << "The new class is called the derived class.\n";

        cout << R"(
----- COMPLETE CODE -----

#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    string name;

    void showName()
    {
        cout << "Name: " << name << endl;
    }
};

class CollegeStudent : public Person
{
public:
    int rollno;

    void display()
    {
        showName();
        cout << "Roll Number: " << rollno << endl;
    }
};

int main()
{
    CollegeStudent s;

    cout << "Enter name: ";
    cin >> s.name;

    cout << "Enter roll number: ";
    cin >> s.rollno;

    s.display();
    return 0;
}
)";
        break;

    case 6:
        cout << "\n===== FUNCTION OVERLOADING =====\n";
        cout << "Theory:\n";
        cout << "Function overloading allows multiple functions to share\n";
        cout << "the same name but have different parameter lists.\n";
        cout << "The compiler selects the appropriate function.\n";

        cout << R"(
----- COMPLETE CODE -----

#include <iostream>
using namespace std;

class Addition
{
public:
    int add(int a, int b)
    {
        return a + b;
    }

    double add(double a, double b)
    {
        return a + b;
    }
};

int main()
{
    Addition obj;

    int x, y;
    cout << "Enter two integers: ";
    cin >> x >> y;

    cout << "Integer sum = " << obj.add(x, y) << endl;
    cout << "Decimal sum = " << obj.add(2.5, 3.5) << endl;

    return 0;
}
)";
        break;

    case 7:
        cout << "\n===== OPERATOR OVERLOADING =====\n";
        cout << "Theory:\n";
        cout << "Operator overloading gives an operator a special meaning\n";
        cout << "for objects of a user-defined class.\n";
        cout << "Here, the + operator adds two Number objects.\n";

        cout << R"(
----- COMPLETE CODE -----

#include <iostream>
using namespace std;

class Number
{
public:
    int value;

    Number(int n)
    {
        value = n;
    }

    Number operator+(Number n)
    {
        return Number(value + n.value);
    }
};

int main()
{
    int a, b;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    Number n1(a), n2(b);
    Number n3 = n1 + n2;

    cout << "Sum = " << n3.value << endl;
    return 0;
}
)";
        break;

    case 8:
        cout << "\n===== POLYMORPHISM =====\n";
        cout << "Theory:\n";
        cout << "Polymorphism means one interface can have different forms.\n";
        cout << "Runtime polymorphism can be achieved using virtual functions.\n";
        cout << "The called function depends on the actual object.\n";

        cout << R"(
----- COMPLETE CODE -----

#include <iostream>
using namespace std;

class Shape
{
public:
    virtual void draw()
    {
        cout << "Drawing a shape.\n";
    }

    virtual ~Shape() {}
};

class Circle : public Shape
{
public:
    void draw() override
    {
        cout << "Drawing a circle.\n";
    }
};

class Rectangle : public Shape
{
public:
    void draw() override
    {
        cout << "Drawing a rectangle.\n";
    }
};

int main()
{
    Circle c;
    Rectangle r;
    Shape *s;

    s = &c;
    s->draw();

    s = &r;
    s->draw();

    return 0;
}
)";
        break;

    case 9:
        cout << "\n===== TEMPLATES =====\n";
        cout << "Theory:\n";
        cout << "Templates allow functions or classes to work with\n";
        cout << "different data types without rewriting the code.\n";

        cout << R"(
----- COMPLETE CODE -----

#include <iostream>
using namespace std;

template <class T>
T maximum(T a, T b)
{
    return (a > b) ? a : b;
}

int main()
{
    int a, b;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << "Maximum = " << maximum(a, b) << endl;
    return 0;
}
)";
        break;

    case 10:
        cout << "\n===== DYNAMIC MEMORY ALLOCATION =====\n";
        cout << "Theory:\n";
        cout << "Dynamic memory is allocated during program execution.\n";
        cout << "The new operator allocates memory.\n";
        cout << "The delete operator releases allocated memory.\n";

        cout << R"(
----- COMPLETE CODE -----

#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0 || n > 1000)
    {
        cout << "Invalid size.\n";
        return 0;
    }

    int *arr = new int[n];

    cout << "Enter array elements:\n";

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Array elements: ";

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;

    delete[] arr;
    return 0;
}
)";
        break;

    case 11:
        cout << "\n===== EXCEPTION HANDLING =====\n";
        cout << "Theory:\n";
        cout << "Exception handling manages runtime errors.\n";
        cout << "try contains code that may cause an exception.\n";
        cout << "throw raises an exception and catch handles it.\n";

        cout << R"(
----- COMPLETE CODE -----

#include <iostream>
using namespace std;

int main()
{
    int a, b;

    cout << "Enter numerator and denominator: ";
    cin >> a >> b;

    try
    {
        if (b == 0)
            throw b;

        cout << "Result = " << (float)a / b << endl;
    }
    catch (int x)
    {
        cout << "Division by zero is not allowed.\n";
    }

    return 0;
}
)";
        break;

    case 12:
        cout << "\n===== ARRAY SORTING =====\n";
        cout << "Theory:\n";
        cout << "Sorting arranges elements in a particular order.\n";
        cout << "Bubble sort compares adjacent elements and swaps them\n";
        cout << "when they are in the wrong order.\n";

        cout << R"(
----- COMPLETE CODE -----

#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {40, 10, 30, 20, 50};
    int temp;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "Sorted array: ";

    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";

    cout << endl;
    return 0;
}
)";
        break;

    default:
        cout << "Invalid concept number.\n";
    }

    cout << "\n===== END OF THEORY AND CODE =====\n";
}

// Introduction
void introduction()
{
    cout << "\n===== INTRODUCTION TO C++ =====\n";
    cout << "C++ is a general-purpose programming language.\n";
    cout << "Developed by Bjarne Stroustrup.\n";

    cout << "\nFeatures:\n";
    cout << "1. Classes and Objects\n";
    cout << "2. Inheritance\n";
    cout << "3. Polymorphism\n";
    cout << "4. Encapsulation\n";
    cout << "5. Abstraction\n";
    cout << "6. Exception Handling\n";

    cout << "\nApplications:\n";
    cout << "1. Games\n";
    cout << "2. Operating Systems\n";
    cout << "3. Desktop Applications\n";
    cout << "4. Embedded Systems\n";
}

// Class and Object
void classObject()
{
    showConcept(1);

    class Student
    {
    public:
        int rollno;
        string name;

        void input()
        {
            cout << "Enter roll number: ";
            cin >> rollno;

            cout << "Enter name: ";
            cin >> name;
        }

        void display()
        {
            cout << "Roll Number: " << rollno << endl;
            cout << "Name: " << name << endl;
        }
    };

    Student s;
    s.input();
    s.display();
}

// Constructor
void constructorDemo()
{
    showConcept(2);

    class Demo
    {
    public:
        Demo()
        {
            cout << "Default constructor called.\n";
        }

        Demo(int n)
        {
            cout << "Parameterized constructor called.\n";
            cout << "Value = " << n << endl;
        }
    };

    Demo a;
    Demo b(100);
}

// Encapsulation
void encapsulationDemo()
{
    showConcept(3);

    class BankAccount
    {
    private:
        int balance;

    public:
        BankAccount()
        {
            balance = 0;
        }

        void deposit(int amount)
        {
            if (amount > 0)
            {
                balance += amount;
                cout << "Deposit successful.\n";
            }
            else
            {
                cout << "Invalid amount.\n";
            }
        }

        void displayBalance()
        {
            cout << "Balance = " << balance << endl;
        }
    };

    BankAccount account;
    int amount;

    cout << "Enter deposit amount: ";
    cin >> amount;

    account.deposit(amount);
    account.displayBalance();
}

// Abstraction
void abstractionDemo()
{
    showConcept(4);

    class Calculator
    {
    private:
        int add(int a, int b)
        {
            return a + b;
        }

    public:
        void result()
        {
            int a, b;

            cout << "Enter two numbers: ";
            cin >> a >> b;

            cout << "Sum = " << add(a, b) << endl;
        }
    };

    Calculator c;
    c.result();
}

// Inheritance
void inheritanceDemo()
{
    showConcept(5);

    class Person
    {
    public:
        string name;

        void showName()
        {
            cout << "Name: " << name << endl;
        }
    };

    class CollegeStudent : public Person
    {
    public:
        int rollno;

        void display()
        {
            showName();
            cout << "Roll Number: " << rollno << endl;
        }
    };

    CollegeStudent s;

    cout << "Enter name: ";
    cin >> s.name;

    cout << "Enter roll number: ";
    cin >> s.rollno;

    s.display();
}

// Function Overloading
void functionOverloadingDemo()
{
    showConcept(6);

    class Addition
    {
    public:
        int add(int a, int b)
        {
            return a + b;
        }

        double add(double a, double b)
        {
            return a + b;
        }
    };

    Addition obj;
    int a, b;

    cout << "Enter two integers: ";
    cin >> a >> b;

    cout << "Integer sum = " << obj.add(a, b) << endl;
    cout << "Decimal sum = " << obj.add(2.5, 3.5) << endl;
}

// Operator Overloading
void operatorOverloadingDemo()
{
    showConcept(7);

    class Number
    {
    public:
        int value;

        Number(int n)
        {
            value = n;
        }

        Number operator+(Number n)
        {
            return Number(value + n.value);
        }
    };

    int a, b;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    Number n1(a), n2(b);
    Number n3 = n1 + n2;

    cout << "Sum = " << n3.value << endl;
}

// Polymorphism
void polymorphismDemo()
{
    showConcept(8);

    class Shape
    {
    public:
        virtual void draw()
        {
            cout << "Drawing a shape.\n";
        }

        virtual ~Shape() {}
    };

    class Circle : public Shape
    {
    public:
        void draw() override
        {
            cout << "Drawing a circle.\n";
        }
    };

    class Rectangle : public Shape
    {
    public:
        void draw() override
        {
            cout << "Drawing a rectangle.\n";
        }
    };

    Circle c;
    Rectangle r;
    Shape *s;

    s = &c;
    s->draw();

    s = &r;
    s->draw();
}



// OOP Menu
void oopMenu()
{
    int choice;

    do
    {
        cout << "\n========== OOP MENU ==========\n";
        cout << "1. Class and Object\n";
        cout << "2. Constructor\n";
        cout << "3. Encapsulation\n";
        cout << "4. Abstraction\n";
        cout << "5. Inheritance\n";
        cout << "6. Function Overloading\n";
        cout << "7. Operator Overloading\n";
        cout << "8. Polymorphism\n";
        cout << "0. Back\n";
        cout << "Enter choice: ";

        choice = getChoice();

        switch (choice)
        {
        case 1: classObject(); break;
        case 2: constructorDemo(); break;
        case 3: encapsulationDemo(); break;
        case 4: abstractionDemo(); break;
        case 5: inheritanceDemo(); break;
        case 6: functionOverloadingDemo(); break;
        case 7: operatorOverloadingDemo(); break;
        case 8: polymorphismDemo(); break;
        case 0: break;
        default: cout << "Invalid choice.\n";
        }

    } while (choice != 0);
}

// Advanced Concepts Menu
void advancedMenu()
{
    int choice;

    do
    {
        cout << "\n======= ADVANCED CONCEPTS =======\n";
        cout << "1. Templates\n";
        cout << "2. Dynamic Memory Allocation\n";
        cout << "3. Exception Handling\n";
        cout << "4. Array Sorting\n";
        cout << "0. Back\n";
        cout << "Enter choice: ";

        choice = getChoice();

        

    } while (choice != 0);
}

// Main Function
int main()
{
    int choice;

    cout << "\n====================================\n";
    cout << "      BASIC C++ LEARNING PLATFORM\n";
    cout << "====================================\n";

    do
    {
        cout << "\n========== MAIN MENU ==========\n";
        cout << "1. Introduction and Theory\n";
        cout << "2. OOP Concepts\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";

        choice = getChoice();

        switch (choice)
        {
        case 1:
            introduction();
            break;

        case 2:
            oopMenu();
            break;


        case 0:
            cout << "Thank you for learning C++!\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
