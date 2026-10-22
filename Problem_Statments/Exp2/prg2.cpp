
#include <iostream>
#include <string>
using namespace std;

class Product
{
private:
    int productID;
    string productName;
    int quantity;
    float unitPrice;

public:
    // Accept product details
    void acceptDetails()
    {
        cout << "Enter Product ID: ";
        cin >> productID;

        cin.ignore();
        cout << "Enter Product Name: ";
        getline(cin, productName);

        cout << "Enter Quantity: ";
        cin >> quantity;

        cout << "Enter Unit Price: ";
        cin >> unitPrice;
    }

    // Calculate total cost
    float calculateTotalCost()
    {
        return quantity * unitPrice;
    }

    // Display product information
    void displayDetails()
    {
        cout << "\n----- Product Information -----" << endl;
        cout << "Product ID   : " << productID << endl;
        cout << "Product Name : " << productName << endl;
        cout << "Quantity     : " << quantity << endl;
        cout << "Unit Price   : Rs. " << unitPrice << endl;
        cout << "Total Cost   : Rs. "
             << calculateTotalCost() << endl;
    }
};

int main()
{
    Product p;

    p.acceptDetails();
    p.displayDetails();

    return 0;
}
