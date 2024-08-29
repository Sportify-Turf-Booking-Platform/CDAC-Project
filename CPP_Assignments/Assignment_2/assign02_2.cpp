/* Imagine a tollbooth at a bridge. Cars passing by the booth are expected to pay a fifty-cent toll.
Mostly they do, but sometimes a car goes by without paying.
The tollbooth keeps track of the number of cars that have gone by and of the total amount of money
collected. Model this tollbooth with a class called tollbooth.
The two data items are a type unsigned int to hold the total number of cars, and a type double to
hold the total amount of money collected.
A constructor initializes all data members to 0. A member function called payingCar() increments
the car total and adds 0.50 to the cash total. An other function, called nopayCar()
increments the car total but adds nothing to the cash total. Finally, a member function called
printOnConsole() displays the two totals and number of paying as well as non paying cars total.
*/
#include<iostream>
using namespace std;

class TollBooth {
    unsigned int totalCars;
    unsigned int payingCars;
    unsigned int nonPayingCars;
    double totalCollection;

public:
    //Default Constructor 
    //Using Constructor Member Initializer List
    TollBooth() :totalCars(0), payingCars(0), nonPayingCars(0), totalCollection(0.0) {}

    // Function to keep track of paying car and total money collected
    void payingCar() {
        totalCars++;
        payingCars++;
        totalCollection += 0.50;
    }

    // Function to keep track of non-paying car and total cars
    void nopayCar() {
        totalCars++;
        nonPayingCars++;
    }

    //Getters
    int getTotalCars() const{return totalCars;}
    int getPayingCars() const{return payingCars;}
    int getNonPayingCars() const{return nonPayingCars;}
    double getTotalCollection() const{return totalCollection;}


    // Function to display the totals on console
    void printOnConsole() const {
        cout << "Total cars passed: " << totalCars << endl;
        cout << "Paying cars: " << payingCars << endl;
        cout << "Non-paying cars: " << nonPayingCars << endl;
        cout << "Total money collected: $" << totalCollection << "\n"<<endl;
    }
};

int main() {
    int choice,car;
    TollBooth b1;
 
    // b1.payingCar();
    // b1.nopayCar();
    // b1.payingCar();
    // b1.payingCar();
    // b1.nopayCar();

    do{
        cout<<"\n............Menu.............\n"<<endl;
        cout<<"1. Press if toll is paid."<<endl;
        cout<<"2. Press if toll is not paid."<<endl;
        cout<<"3. View total car passed. "<<endl;
        cout<<"4. View cars who paid toll."<<endl;
        cout<<"5. View cars which not paid toll."<<endl;
        cout<<"6. View total money collected."<<endl;
        cout<<"7. View all data. "<<endl;
        cout<<"8. Exit. "<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        cout<<"\n";
        switch (choice)
        {
            case 1: 
                cout<<"Enter car no. : ";
                cin>>car;
                b1.payingCar();
                cout<<"50 cents toll paid by car no. - "<<car<<endl;
                break;
            case 2:
                cout<<"Enter car no. : ";
                cin>>car; 
                b1.nopayCar();
                cout<<"Toll is not paid by car no. - "<<car<<endl;
                break;
            case 3: 
                cout<<"Total Car passed till now : "<<b1.getTotalCars()<<endl;
                break;
            case 4:
                cout<<"Total number of cars which PAID toll : "<<b1.getPayingCars()<<endl;
                break;
            case 5:
                cout<<"Total number of cars which NOT PAID toll : "<<b1.getNonPayingCars()<<endl;
                break;
            case 6: 
                cout<<"Total money collected till now : $"<<b1.getTotalCollection()<<endl;
                break;
            case 7: 
                b1.printOnConsole();
                cout<<endl;
                break;
            case 8: 
                cout << "Exiting the program.\n\n";
                break;
            default:
                cout<<"Invalid choice, please try again !"<<endl;
        }
    }while(choice!=8);


    // Display the totals
    b1.printOnConsole();

    return 0;
}