
#include <iostream>
#include <exception>
using namespace std;

class InvalidMarksException : public exception {
public:
    const char* what() const noexcept override {
        return "Marks must be between 0 and 100!";
    }
};

int main() {
    int marks;

    cout << "Enter marks (0-100): ";
    cin >> marks;

    try {
        if (marks < 0 || marks > 100) {
            throw InvalidMarksException();
        }

        cout << "Valid marks: " << marks << endl;
    }
    catch (const InvalidMarksException& e) {
        cout << "Exception caught: " << e.what() << endl;
    }

    return 0;
}
