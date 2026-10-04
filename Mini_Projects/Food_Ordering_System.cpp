#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdexcept>

using namespace std;

// ================= FOOD CLASS =================
class Food
{
private:
    int id;
    string name;
    double price;

public:
    Food(int i, string n, double p)
    {
        id = i;
        name = n;
        price = p;
    }

    int getId() const
    {
        return id;
    }

    string getName() const
    {
        return name;
    }

    double getPrice() const
    {
        return price;
    }

    void display() const
    {
        cout << left << setw(5) << id
             << setw(20) << name
             << "Rs. " << price << endl;
    }
};

// ================= ORDER ITEM CLASS =================
class OrderItem
{
private:
    Food food;
    int quantity;

public:
    OrderItem(Food f, int q) : food(f), quantity(q)
    {
    }

    double getTotal() const
    {
        return food.getPrice() * quantity;
    }

    void display() const
    {
        cout << left << setw(20) << food.getName()
             << setw(10) << quantity
             << "Rs. " << getTotal() << endl;
    }
};

// ================= CUSTOMER CLASS =================
class Customer
{
private:
    string name;
    string mobile;

public:
    Customer()
    {
        name = "";
        mobile = "";
    }

    Customer(string n, string m)
    {
        name = n;
        mobile = m;
    }

    void display() const
    {
        cout << "\nCustomer Name : " << name << endl;
        cout << "Mobile Number : " << mobile << endl;
    }

    string getName() const
    {
        return name;
    }

    string getMobile() const
    {
        return mobile;
    }
};

// ================= ORDER CLASS =================
class Order
{
private:
    int orderId;
    Customer customer;
    vector<OrderItem> items;

public:

    Order(int id, Customer c) : orderId(id), customer(c)
    {
    }

    // Function Overloading
    void addItem(Food food, int quantity)
    {
        if (quantity <= 0)
        {
            throw invalid_argument("Quantity must be greater than zero!");
        }

        items.push_back(OrderItem(food, quantity));

        cout << "\nFood added successfully!" << endl;
    }

    void addItem(Food food)
    {
        addItem(food, 1);
    }

    void removeLastItem()
    {
        if (items.empty())
        {
            cout << "\nOrder is empty!" << endl;
            return;
        }

        items.pop_back();

        cout << "\nLast item removed successfully!" << endl;
    }

    double calculateTotal() const
    {
        double total = 0;

        for (const auto &item : items)
        {
            total += item.getTotal();
        }

        return total;
    }

    void displayOrder() const
    {
        cout << "\n==========================================" << endl;
        cout << "              ORDER DETAILS" << endl;
        cout << "==========================================" << endl;

        cout << "Order ID : " << orderId << endl;

        customer.display();

        cout << "\n------------------------------------------" << endl;
        cout << left << setw(20) << "Food"
             << setw(10) << "Quantity"
             << "Amount" << endl;

        cout << "------------------------------------------" << endl;

        if (items.empty())
        {
            cout << "No items in order." << endl;
        }
        else
        {
            for (const auto &item : items)
            {
                item.display();
            }
        }

        cout << "------------------------------------------" << endl;

        double subtotal = calculateTotal();

        cout << fixed << setprecision(2);
        cout << "Subtotal       : Rs. " << subtotal << endl;

        double discount = 0;

        if (subtotal >= 500)
        {
            discount = subtotal * 0.10;
        }

        double gst = (subtotal - discount) * 0.05;

        double finalAmount = subtotal - discount + gst;

        cout << "Discount (10%) : Rs. " << discount << endl;
        cout << "GST (5%)       : Rs. " << gst << endl;
        cout << "------------------------------------------" << endl;
        cout << "FINAL BILL     : Rs. " << finalAmount << endl;
        cout << "==========================================" << endl;
    }

    // File Handling
    void saveToFile() const
    {
        ofstream fout("orders.txt", ios::app);

        if (!fout)
        {
            cout << "Error opening file!" << endl;
            return;
        }

        double subtotal = calculateTotal();

        double discount = 0;

        if (subtotal >= 500)
        {
            discount = subtotal * 0.10;
        }

        double gst = (subtotal - discount) * 0.05;

        double finalAmount = subtotal - discount + gst;

        fout << "=====================================\n";
        fout << "Order ID: " << orderId << "\n";
        fout << "Customer: " << customer.getName() << "\n";
        fout << "Mobile: " << customer.getMobile() << "\n";

        fout << "Total Bill: Rs. "
             << fixed << setprecision(2)
             << finalAmount << "\n";

        fout << "=====================================\n";

        fout.close();

        cout << "\nOrder saved to file successfully!" << endl;
    }
};

// ================= MAIN FUNCTION =================
int main()
{
    vector<Food> menu =
    {
        Food(1, "Pizza", 200),
        Food(2, "Burger", 120),
        Food(3, "Sandwich", 80),
        Food(4, "French Fries", 100),
        Food(5, "Pasta", 150),
        Food(6, "Biryani", 180),
        Food(7, "Cold Drink", 50)
    };

    string customerName;
    string mobile;

    cout << "==========================================" << endl;
    cout << "       FOOD ORDERING MANAGEMENT SYSTEM" << endl;
    cout << "==========================================" << endl;

    cout << "\nEnter Customer Name: ";
    getline(cin, customerName);

    cout << "Enter Mobile Number: ";
    getline(cin, mobile);

    Customer customer(customerName, mobile);

    Order order(101, customer);

    int choice;

    do
    {
        cout << "\n\n============= MAIN MENU =============" << endl;
        cout << "1. Display Food Menu" << endl;
        cout << "2. Add Food to Order" << endl;
        cout << "3. Remove Last Food" << endl;
        cout << "4. View Order and Bill" << endl;
        cout << "5. Save Order" << endl;
        cout << "6. Exit" << endl;
        cout << "=====================================" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        try
        {
            switch (choice)
            {
            case 1:
            {
                cout << "\n------------- FOOD MENU -------------" << endl;

                cout << left << setw(5) << "ID"
                     << setw(20) << "Food Name"
                     << "Price" << endl;

                cout << "--------------------------------------" << endl;

                for (const auto &food : menu)
                {
                    food.display();
                }

                break;
            }

            case 2:
            {
                int foodId;
                int quantity;

                cout << "\nEnter Food ID: ";
                cin >> foodId;

                if (foodId < 1 || foodId > 7)
                {
                    throw invalid_argument("Invalid Food ID!");
                }

                cout << "Enter Quantity: ";
                cin >> quantity;

                if (quantity <= 0)
                {
                    throw invalid_argument(
                        "Quantity must be greater than zero!");
                }

                Food selectedFood = menu[foodId - 1];

                order.addItem(selectedFood, quantity);

                break;
            }

            case 3:
            {
                order.removeLastItem();
                break;
            }

            case 4:
            {
                order.displayOrder();
                break;
            }

            case 5:
            {
                order.saveToFile();
                break;
            }

            case 6:
            {
                cout << "\nThank you for using Food Ordering System!"
                     << endl;
                break;
            }

            default:
            {
                cout << "\nInvalid choice! Please try again."
                     << endl;
            }
            }
        }
        catch (exception &e)
        {
            cout << "\nERROR: " << e.what() << endl;
        }

    } while (choice != 6);

    return 0;
}
