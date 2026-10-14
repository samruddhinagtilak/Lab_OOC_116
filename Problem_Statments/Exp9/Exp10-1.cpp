#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;
    string line;

    fin.open("sample.txt");
    fout.open("sample1.txt");

    while (getline(fin, line))
    {
        cout << line << endl;
        fout << line << endl;
    }

    fin.close();
    fout.close();

    return 0;
}
