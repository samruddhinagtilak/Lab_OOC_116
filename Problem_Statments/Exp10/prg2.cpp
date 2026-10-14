#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream fout;
    ifstream fin;
    string record;

    // Append new records to file
    fout.open("sample.txt", ios::app);

    cout << "Enter records (-1 to stop):" << endl;

    while (getline(cin, record))
    {
        if (record == "-1")
            break;

        fout << record << endl;
    }

    fout.close();

    // Display all records
    fin.open("sample.txt");

    cout << "\nAll Records in File:" << endl;

    while (getline(fin, record))
    {
        cout << record << endl;
    }

    fin.close();

    return 0;
}
