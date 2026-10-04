#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdexcept>

using namespace std;

// ======================================================
// BASE CLASS
// Exp 2 : Class and Object
// Exp 4 : Encapsulation
// Exp 5 : Constructor and Destructor
// Exp 9 : Pure Virtual Function
// ======================================================

class Food
{
protected:
    int id;
    string name;
    double price;

public:

    // Constructor
    Food(int i = 0, string n = "", double p = 0)
    {
        id = i;
        name = n;
        price = p;
    }

    // Virtual Destructor
    virtual ~Food()
    {
    }

    // Encapsulation - Getter Functions
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

    // Pure Virtual Functions
    virtual double calculatePrice(int quantity) const = 0;

    virtual void display() const = 0;
};


// ======================================================
// VEG FOOD CLASS
// Exp 7 : Hierarchical + Multilevel Inheritance
// Exp 9 : Runtime Polymorphism
// ======================================================

class VegFood : public Food
{
public:

    VegFood(int i, string n, double p)
        : Food(i, n, p)
    {
    }

    double calculatePrice(int quantity) const override
    {
        return price * quantity;
    }

    void display() const override
    {
        cout << left
             << setw(5) << id
             << setw(20) << name
             << "Rs. " << price
             << "  [Veg]" << endl;
    }

    ~VegFood()
    {
    }
};


// ======================================================
// MULTILEVEL INHERITANCE
// Food -> VegFood -> SpecialVegFood
// Exp 7 : Multilevel Inheritance
// ======================================================

class SpecialVegFood : public VegFood
{
private:
    double specialCharge;

public:

    SpecialVegFood(int i, string n, double p, double charge)
        : VegFood(i, n, p)
    {
        specialCharge = charge;
    }

    double calculatePrice(int quantity) const override
    {
        return (price * quantity) +
               (specialCharge * quantity);
    }

    void display() const override
    {
        cout << left
             << setw(5) << id
             << setw(20) << name
             << "Rs. " << price
             << "  [Special Veg]" << endl;
    }

    ~SpecialVegFood()
    {
    }
};


// ======================================================
// NON-VEG FOOD CLASS
// Exp 7 : Hierarchical Inheritance
// Exp 9 : Runtime Polymorphism
// ======================================================

class NonVegFood : public Food
{
public:

    NonVegFood(int i, string n, double p)
        : Food(i, n, p)
    {
    }

    double calculatePrice(int quantity) const override
    {
        return (price * quantity) + 20;
    }

    void display() const override
    {
        cout << left
             << setw(5) << id
             << setw(20) << name
             << "Rs. " << price
             << "  [Non-Veg]" << endl;
    }

    ~NonVegFood()
    {
    }
};


// ======================================================
// CUSTOMER CLASS
// Exp 2 : Class and Object
// Exp 4 : Encapsulation
// Exp 5 : Constructor and Destructor
// ======================================================

class Customer
{
private:
    string name;
    string mobile;

public:

    // Default Constructor
    Customer()
    {
        name = "";
        mobile = "";
    }

    // Parameterized Constructor
    Customer(string n, string m)
    {
        name = n;
        mobile = m;
    }

    void display() const
    {
        cout << "\nCustomer Name : "
             << name << endl;

        cout << "Mobile Number : "
             << mobile << endl;
    }

    string getName() const
    {
        return name;
    }

    string getMobile() const
    {
        return mobile;
    }

    ~Customer()
    {
    }
};


// ======================================================
// ORDER ITEM CLASS
// ======================================================

class OrderItem
{
private:
    Food* food;
    int quantity;

public:

    OrderItem(Food* f, int q)
    {
        food = f;
        quantity = q;
    }

    double getTotal() const
    {
        // Runtime Polymorphism
        return food->calculatePrice(quantity);
    }

    void display() const
    {
        cout << left
             << setw(20)
             << food->getName()

             << setw(10)
             << quantity

             << "Rs. "
             << getTotal()
             << endl;
    }

    ~OrderItem()
    {
    }
};


// ======================================================
// ORDER CLASS
// Exp 3 : Member Functions
// Exp 6 : Function Overloading
// Exp 8 : Operator Overloading
// Exp 10 : File Handling
// Exp 11 : Exception Handling
// ======================================================

class Order
{
private:
    int orderId;
    Customer customer;
    vector<OrderItem> items;

public:

    // Constructor
    Order(int id, Customer c)
        : orderId(id), customer(c)
    {
    }


    // ==================================================
    // Exp 6 : FUNCTION OVERLOADING
    // ==================================================

    // Function 1
    void addItem(Food* food, int quantity)
    {
        if (quantity <= 0)
        {
            throw invalid_argument(
                "Quantity must be greater than zero!");
        }

        items.push_back(
            OrderItem(food, quantity));

        cout << "\nFood added successfully!"
             << endl;
    }


    // Function 2 - Overloaded Function
    void addItem(Food* food)
    {
        addItem(food, 1);
    }


    // ==================================================
    // REMOVE LAST ITEM
    // ==================================================

    void removeLastItem()
    {
        if (items.empty())
        {
            cout << "\nOrder is empty!"
                 << endl;
            return;
        }

        items.pop_back();

        cout << "\nLast item removed successfully!"
             << endl;
    }


    // ==================================================
    // CALCULATE TOTAL
    // ==================================================

    double calculateTotal() const
    {
        double total = 0;

        for (const auto &item : items)
        {
            total += item.getTotal();
        }

        return total;
    }


    // ==================================================
    // Exp 8 : RELATIONAL OPERATOR OVERLOADING
    // Compare two orders
    // ==================================================

    bool operator>(const Order& other) const
    {
        return calculateTotal() >
               other.calculateTotal();
    }


    // ==================================================
    // Exp 8 : BINARY OPERATOR OVERLOADING
    // Add total of two orders
    // ==================================================

    double operator+(const Order& other) const
    {
        return calculateTotal() +
               other.calculateTotal();
    }


    // ==================================================
    // Exp 8 : UNARY OPERATOR OVERLOADING
    // Increase Order ID by 1
    // ==================================================

    Order& operator++()
    {
        orderId++;
        return *this;
    }


    // ==================================================
    // DISPLAY ORDER
    // ==================================================

    void displayOrder() const
    {
        cout << "\n=========================================="
             << endl;

        cout << "              ORDER DETAILS"
             << endl;

        cout << "=========================================="
             << endl;

        cout << "Order ID : "
             << orderId
             << endl;

        customer.display();

        cout << "\n------------------------------------------"
             << endl;

        cout << left
             << setw(20) << "Food"
             << setw(10) << "Quantity"
             << "Amount"
             << endl;

        cout << "------------------------------------------"
             << endl;

        if (items.empty())
        {
            cout << "No items in order."
                 << endl;
        }
        else
        {
            for (const auto &item : items)
            {
                item.display();
            }
        }

        cout << "------------------------------------------"
             << endl;

        double subtotal = calculateTotal();

        double discount = 0;

        if (subtotal >= 500)
        {
            discount = subtotal * 0.10;
        }

        double gst =
            (subtotal - discount) * 0.05;

        double finalAmount =
            subtotal - discount + gst;

        cout << fixed
             << setprecision(2);

        cout << "Subtotal       : Rs. "
             << subtotal
             << endl;

        cout << "Discount       : Rs. "
             << discount
             << endl;

        cout << "GST (5%)       : Rs. "
             << gst
             << endl;

        cout << "------------------------------------------"
             << endl;

        cout << "FINAL BILL     : Rs. "
             << finalAmount
             << endl;

        cout << "=========================================="
             << endl;
    }


    // ==================================================
    // Exp 10 : FILE HANDLING - WRITE
    // ==================================================

    void saveToFile() const
    {
        ofstream fout(
            "orders.txt",
            ios::app);

        if (!fout)
        {
            cout << "Error opening file!"
                 << endl;

            return;
        }

        double subtotal =
            calculateTotal();

        double discount = 0;

        if (subtotal >= 500)
        {
            discount =
                subtotal * 0.10;
        }

        double gst =
            (subtotal - discount) * 0.05;

        double finalAmount =
            subtotal - discount + gst;

        fout << "=====================================\n";

        fout << "Order ID: "
             << orderId
             << "\n";

        fout << "Customer: "
             << customer.getName()
             << "\n";

        fout << "Mobile: "
             << customer.getMobile()
             << "\n";

        fout << "Total Bill: Rs. "
             << fixed
             << setprecision(2)
             << finalAmount
             << "\n";

        fout << "=====================================\n";

        fout.close();

        cout << "\nOrder saved to file successfully!"
             << endl;
    }


    // ==================================================
    // Exp 10 : FILE HANDLING - READ
    // ==================================================

    void viewPreviousOrders() const
    {
        ifstream fin("orders.txt");

        if (!fin)
        {
            cout << "\nNo previous orders found!"
                 << endl;

            return;
        }

        string line;

        cout << "\n=========================================="
             << endl;

        cout << "          PREVIOUS ORDERS"
             << endl;

        cout << "=========================================="
             << endl;

        while (getline(fin, line))
        {
            cout << line << endl;
        }

        fin.close();
    }


    ~Order()
    {
    }
};


// ======================================================
// MAIN FUNCTION
// Exp 1 : Basic C++
// Exp 12 : Complete Mini Project
// ======================================================

int main()
{
    // ==================================================
    // FOOD OBJECTS
    // ==================================================

    VegFood pizza(
        1,
        "Pizza",
        200);

    VegFood burger(
        2,
        "Burger",
        120);

    VegFood sandwich(
        3,
        "Sandwich",
        80);

    VegFood frenchFries(
        4,
        "French Fries",
        100);

    VegFood pasta(
        5,
        "Pasta",
        150);


    // Multilevel Inheritance Object
    SpecialVegFood specialThali(
        6,
        "Special Thali",
        250,
        30);


    NonVegFood biryani(
        7,
        "Biryani",
        180);

    NonVegFood chickenBurger(
        8,
        "Chicken Burger",
        160);


    // ==================================================
    // RUNTIME POLYMORPHISM
    // ==================================================

    vector<Food*> menu =
    {
        &pizza,
        &burger,
        &sandwich,
        &frenchFries,
        &pasta,
        &specialThali,
        &biryani,
        &chickenBurger
    };


    // ==================================================
    // CUSTOMER DETAILS
    // ==================================================

    string customerName;
    string mobile;

    cout << "=========================================="
         << endl;

    cout << "       FOOD ORDERING MANAGEMENT SYSTEM"
         << endl;

    cout << "=========================================="
         << endl;

    cout << "\nEnter Customer Name: ";
    getline(cin, customerName);

    cout << "Enter Mobile Number: ";
    getline(cin, mobile);


    Customer customer(
        customerName,
        mobile);


    Order order(
        101,
        customer);


    // Second Order
    Customer customer2(
        "Demo Customer",
        "9999999999");

    Order order2(
        102,
        customer2);


    int choice;


    // ==================================================
    // MAIN MENU
    // ==================================================

    do
    {
        cout << "\n\n============= MAIN MENU ============="
             << endl;

        cout << "1. Display Food Menu"
             << endl;

        cout << "2. Add Food to Order"
             << endl;

        cout << "3. Remove Last Food"
             << endl;

        cout << "4. View Order and Bill"
             << endl;

        cout << "5. Save Order to File"
             << endl;

        cout << "6. View Previous Orders"
             << endl;

        cout << "7. Demonstrate Operator Overloading"
             << endl;

        cout << "8. Exit"
             << endl;

        cout << "====================================="
             << endl;

        cout << "Enter your choice: ";
        cin >> choice;


        try
        {
            switch (choice)
            {

            // ==================================================
            // DISPLAY MENU
            // ==================================================

            case 1:
            {
                cout << "\n------------- FOOD MENU -------------"
                     << endl;

                cout << left
                     << setw(5) << "ID"
                     << setw(20) << "Food Name"
                     << "Price"
                     << endl;

                cout << "--------------------------------------"
                     << endl;


                for (Food* food : menu)
                {
                    // Runtime Polymorphism
                    food->display();
                }

                break;
            }


            // ==================================================
            // ADD FOOD
            // ==================================================

            case 2:
            {
                int foodId;
                int quantity;

                cout << "\nEnter Food ID: ";
                cin >> foodId;


                if (foodId < 1 ||
                    foodId > (int)menu.size())
                {
                    throw invalid_argument(
                        "Invalid Food ID!");
                }


                cout << "Enter Quantity: ";
                cin >> quantity;


                if (quantity <= 0)
                {
                    throw invalid_argument(
                        "Quantity must be greater than zero!");
                }


                Food* selectedFood =
                    menu[foodId - 1];


                order.addItem(
                    selectedFood,
                    quantity);

                break;
            }


            // ==================================================
            // REMOVE FOOD
            // ==================================================

            case 3:
            {
                order.removeLastItem();

                break;
            }


            // ==================================================
            // VIEW ORDER
            // ==================================================

            case 4:
            {
                order.displayOrder();

                break;
            }


            // ==================================================
            // SAVE ORDER
            // ==================================================

            case 5:
            {
                order.saveToFile();

                break;
            }


            // ==================================================
            // VIEW PREVIOUS ORDERS
            // ==================================================

            case 6:
            {
                order.viewPreviousOrders();

                break;
            }


            // ==================================================
            // OPERATOR OVERLOADING DEMONSTRATION
            // ==================================================

            case 7:
            {
                cout << "\n====================================="
                     << endl;

                cout << "    OPERATOR OVERLOADING DEMO"
                     << endl;

                cout << "====================================="
                     << endl;


                // Add food to second order
                order2.addItem(
                    &burger,
                    2);


                // ------------------------------
                // RELATIONAL OPERATOR >
                // ------------------------------

                if (order > order2)
                {
                    cout << "\nOrder 1 has greater total "
                         << "than Order 2."
                         << endl;
                }
                else
                {
                    cout << "\nOrder 2 has greater or equal "
                         << "total than Order 1."
                         << endl;
                }


                // ------------------------------
                // BINARY OPERATOR +
                // ------------------------------

                double combinedTotal =
                    order + order2;

                cout << "\nCombined Total of "
                     << "Both Orders : Rs. "
                     << combinedTotal
                     << endl;


                // ------------------------------
                // UNARY OPERATOR ++
                // ------------------------------

                cout << "\nOrder ID before ++ : 101"
                     << endl;

                ++order;

                cout << "Order ID after ++  : 102"
                     << endl;


                cout << "\nOperator Overloading "
                     << "demonstrated successfully!"
                     << endl;

                break;
            }


            // ==================================================
            // EXIT
            // ==================================================

            case 8:
            {
                cout << "\nThank you for using "
                     << "Food Ordering System!"
                     << endl;

                break;
            }


            default:
            {
                cout << "\nInvalid choice!"
                     << endl;

                break;
            }

            }
        }


        // ==================================================
        // Exp 11 : EXCEPTION HANDLING
        // ==================================================

        catch (exception &e)
        {
            cout << "\nERROR: "
                 << e.what()
                 << endl;
        }


    }
    while (choice != 8);


    return 0;
}
