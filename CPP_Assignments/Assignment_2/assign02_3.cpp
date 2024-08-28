#include <iostream>
#include <string>
using namespace std;

class Address {
private:
    string building;
    string street;
    string city;
    int pin;

public:
    // Default constructor
    Address() : building(""), street(""), city(""), pin(0) {}

    // Parameterized constructor
    Address(string b, string s, string c, int p) : building(b), street(s), city(c), pin(p) {}

    // Getters
    string getBuilding() const {
        return building;
    }
    string getStreet() const {
        return street;
    }
    string getCity() const {
        return city;
    }
    int getPin() const {
        return pin;
    }

    // Setters
    void setBuilding(const string& b) {
        building = b;
    }
    void setStreet(const string& s) {
        street = s;
    }
    void setCity(const string& c) {
        city = c;
    }
    void setPin(int p) {
        pin = p;
    }

    // Function for address details
    void accept() {
        cout << "Enter building: ";
        cin>>building;
        cout << "Enter street: ";
        cin>>street;
        cout << "Enter city: ";
        cin>>city;
        cout << "Enter pin: ";
        cin >> pin;
        cin.ignore();  // To supress the newline character given by cin
    }

    // Function to display address details
    void display() const {
        cout << "Address Details:" << endl;
        cout << "Building: " << building << endl;
        cout << "Street: " << street << endl;
        cout << "City: " << city << endl;
        cout << "Pin: " << pin << endl;
    }
};

int main() {
    Address addr;
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Accept Address\n";
        cout << "2. Display Address\n";
        cout << "3. Set Building\n";
        cout << "4. Set Street\n";
        cout << "5. Set City\n";
        cout << "6. Set Pin\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // To supress the newline character given by cin

        switch (choice) {
        case 1:
            cout << "Accepting address details:\n";
            addr.accept();
            break;
        case 2:
            cout << "Displaying address details:\n";
            addr.display();
            break;
        case 3: {
            string building;
            cout << "Enter new building: ";
            getline(cin, building);
            addr.setBuilding(building);
            break;
        }
        case 4: {
            string street;
            cout << "Enter new street: ";
            getline(cin, street);
            addr.setStreet(street);
            break;
        }
        case 5: {
            string city;
            cout << "Enter new city: ";
            getline(cin, city);
            addr.setCity(city);
            break;
        }
        case 6: {
            int pin;
            cout << "Enter new pin: ";
            cin >> pin;
            cin.ignore();  // To consume the newline character left by cin
            addr.setPin(pin);
            break;
        }
        case 7:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}
