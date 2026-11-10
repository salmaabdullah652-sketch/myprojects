#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Person Class
class Person {
protected:
    string name;

public:
    Person(string n) {
        name = n;
    }

    virtual void display() {
        cout << "Name: " << name << endl;
    }
};

// Employee Class
class Employee : public Person {
public:
    int id;

    Employee(string n, int i) : Person(n) {
        id = i;
    }

    void display() override {
        cout << "Employee Name: " << name << endl;
        cout << "Employee ID: " << id << endl;
    }
};

// Medicine Class
class Medicine {
public:
    int id;
    string name;
    double price;
    int quantity;

    Medicine(int i, string n, double p, int q) {
        id = i;
        name = n;
        price = p;
        quantity = q;
    }

    void display() {
        cout << id << "\t"
             << name << "\t"
             << price << "\t"
             << quantity << endl;
    }
};

// Pharmacy Class
class Pharmacy {
public:
    vector<Medicine> medicines;

    // Add Medicine
    void addMedicine() {
        int id, q;
        string n;
        double p;

        cout << "Enter ID: ";
        cin >> id;

        cout << "Enter Name: ";
        cin >> n;

        cout << "Enter Price: ";
        cin >> p;

        cout << "Enter Quantity: ";
        cin >> q;

        medicines.push_back(Medicine(id, n, p, q));

        cout << "Added Successfully!\n";
    }

    // Display Medicines
    void displayMedicines() {

        if (medicines.empty()) {
            cout << "No Medicines Available!\n";
            return;
        }

        cout << "\nID\tName\tPrice\tQuantity\n";
        cout << "--------------------------------------\n";

        for (int i = 0; i < medicines.size(); i++) {
            medicines[i].display();
        }
    }

    // Search by ID
    void searchMedicine(int id) {
        for (int i = 0; i < medicines.size(); i++) {
            if (medicines[i].id == id) {
                medicines[i].display();
                return;
            }
        }

        cout << "Not Found!\n";
    }

    // Search by Name
    void searchMedicine(string n) {
        for (int i = 0; i < medicines.size(); i++) {
            if (medicines[i].name == n) {
                medicines[i].display();
                return;
            }
        }

        cout << "Not Found!\n";
    }

    // Sell Medicine
    void sellMedicine() {
        int id, q;

        cout << "Enter ID: ";
        cin >> id;

        for (int i = 0; i < medicines.size(); i++) {

            if (medicines[i].id == id) {

                cout << "Enter Quantity: ";
                cin >> q;

                if (q > 0 && q <= medicines[i].quantity) {

                    medicines[i].quantity -= q;

                    cout << "Sale Successful!\n";
                    cout << "Total Price: "
                         << q * medicines[i].price << endl;
                }
                else {
                    cout << "Not Enough Quantity!\n";
                }

                return;
            }
        }

        cout << "Not Found!\n";
    }
};

// Main Function
int main() {

    Pharmacy p;
    Employee e("Ahmed", 101);

    int choice;

    do {
        cout << "\n===== PHARMACY SYSTEM =====\n";

        cout << "1. Add Medicine\n";
        cout << "2. Display Medicines\n";
        cout << "3. Search by ID\n";
        cout << "4. Search by Name\n";
        cout << "5. Sell Medicine\n";
        cout << "6. Display Employee\n";
        cout << "0. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            p.addMedicine();
            break;

        case 2:
            p.displayMedicines();
            break;

        case 3: {
            int id;

            cout << "Enter ID: ";
            cin >> id;

            p.searchMedicine(id);
            break;
        }

        case 4: {
            string n;

            cout << "Enter Name: ";
            cin >> n;

            p.searchMedicine(n);
            break;
        }

        case 5:
            p.sellMedicine();
            break;

        case 6:
            e.display();
            break;

        case 0:
            cout << "Goodbye!\n";
            break;

        default:
            cout << "Wrong Choice!\n";
        }

    } while (choice != 0);

    return 0;
}
