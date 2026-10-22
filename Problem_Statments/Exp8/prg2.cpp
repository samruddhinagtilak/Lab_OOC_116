
#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    int rollNo;
    string name;
    float marks;

public:
    // Overload extraction operator >>
    friend istream& operator>>(istream& in, Student& s)
    {
        cout << "Enter Roll Number: ";
        in >> s.rollNo;

        cout << "Enter Name: ";
        in >> ws;
        getline(in, s.name);

        cout << "Enter Marks: ";
        in >> s.marks;

        return in;
    }

    // Overload insertion operator <<
    friend ostream& operator<<(ostream& out, const Student& s)
    {
        out << "\n--- Student Details ---" << endl;
        out << "Roll Number: " << s.rollNo << endl;
        out << "Name       : " << s.name << endl;
        out << "Marks      : " << s.marks << endl;

        return out;
    }
};

int main()
{
    Student s;

    cin >> s;
    cout << s;

    return 0;
}
