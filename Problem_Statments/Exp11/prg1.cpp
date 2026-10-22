
#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
    int num;

    cout << "Enter a number: ";
    cin >> num;

    try {
        if (num < 0) {
            throw num;
        }

        cout << "Number is positive or zero: " << num << endl;
    }
    catch (int n) {
        cout << "Exception caught: Negative number " << n << endl;
    }

    return 0;
}
