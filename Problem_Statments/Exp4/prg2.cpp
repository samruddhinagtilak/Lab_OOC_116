
#include <iostream>
#include <string>
using namespace std;

class Patient
{
private:
    int patientID;
    string patientName;
    int age;
    float consultationFee;

public:
    void registerPatient()
    {
        cout << "Enter Patient ID: ";
        cin >> patientID;

        cin.ignore();
        cout << "Enter Patient Name: ";
        getline(cin, patientName);

        cout << "Enter Age: ";
        cin >> age;

        cout << "Enter Consultation Fee: Rs. ";
        cin >> consultationFee;
    }

    float calculateCharges()
    {
        return consultationFee;
    }

    void display()
    {
        cout << "\n--- Patient Information ---" << endl;
        cout << "Patient ID   : " << patientID << endl;
        cout << "Patient Name : " << patientName << endl;
        cout << "Age          : " << age << endl;
        cout << "Consultation Charges: Rs. "
             << calculateCharges() << endl;
    }
};

int main()
{
    Patient p;

    p.registerPatient();
    p.display();

    return 0;
}
