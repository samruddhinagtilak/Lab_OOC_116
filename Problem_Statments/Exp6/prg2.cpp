
#include <iostream>
using namespace std;

class Box
{
private:
    float length, breadth, height;

public:
    // Default Constructor
    Box()
    {
        length = 1;
        breadth = 1;
        height = 1;
        cout << "Default constructor called." << endl;
    }

    // Parameterized Constructor
    Box(float l, float b, float h)
    {
        length = l;
        breadth = b;
        height = h;
        cout << "Parameterized constructor called." << endl;
    }

    // Copy Constructor
    Box(const Box &b)
    {
        length = b.length;
        breadth = b.breadth;
        height = b.height;
        cout << "Copy constructor called." << endl;
    }

    // Calculate Volume
    float calculateVolume()
    {
        return length * breadth * height;
    }

    // Display Box Information
    void display()
    {
        cout << "Length  : " << length << endl;
        cout << "Breadth : " << breadth << endl;
        cout << "Height  : " << height << endl;
        cout << "Volume  : " << calculateVolume() << endl;
    }

    // Destructor
    ~Box()
    {
        cout << "Destructor called. Box object destroyed."
             << endl;
    }
};

int main()
{
    cout << "\n--- Default Constructor ---" << endl;
    Box b1;
    b1.display();

    cout << "\n--- Parameterized Constructor ---" << endl;
    Box b2(5, 4, 3);
    b2.display();

    cout << "\n--- Copy Constructor ---" << endl;
    Box b3(b2);
    b3.display();

    cout << "\nEnd of program." << endl;

    return 0;
}
