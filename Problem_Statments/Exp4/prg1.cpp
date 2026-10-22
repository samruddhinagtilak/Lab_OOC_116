
#include <iostream>
#include <string>
using namespace std;

class LibraryBook
{
private:
    int bookID;
    string bookName;
    bool issued;

public:
    void acceptDetails()
    {
        cout << "Enter Book ID: ";
        cin >> bookID;

        cin.ignore();
        cout << "Enter Book Name: ";
        getline(cin, bookName);

        issued = false;
    }

    void issueBook()
    {
        if (!issued)
        {
            issued = true;
            cout << "Book issued successfully!" << endl;
        }
        else
        {
            cout << "Book is already issued." << endl;
        }
    }

    void returnBook()
    {
        if (issued)
        {
            issued = false;
            cout << "Book returned successfully!" << endl;
        }
        else
        {
            cout << "Book was not issued." << endl;
        }
    }

    void display()
    {
        cout << "\n--- Library Book Details ---" << endl;
        cout << "Book ID   : " << bookID << endl;
        cout << "Book Name : " << bookName << endl;
        cout << "Status    : "
             << (issued ? "Issued" : "Available") << endl;
    }
};

int main()
{
    LibraryBook b;

    b.acceptDetails();
    b.display();

    b.issueBook();
    b.display();

    b.returnBook();
    b.display();

    return 0;
}
