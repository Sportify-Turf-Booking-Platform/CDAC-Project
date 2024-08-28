/*Write a menu driven program to calculate volume of the box(length * width * height).
Provide parameterless, parameterized(with 3 parameters) and single paramaterized constructor.
Create the local objects in respective case and call the function to caluclate area.
Menu options -> 
1. Calculate Volume with default values
2. Calculate Volume with length,breadth and height with same value
3. Calculate Volume with different length,breadth and height values*/

#include<iostream>
using namespace std;
class container{
    double length;
    double height;
    double width;
    double volume;
    
    public: 
    //Constructors using Constructor Chaining
    container():container(1,1,1){} //parameterless constructor

    container(double value):container(value,value,value){} //single parameterized constructor
    
    container(double length,double height,double width){ //parameterized constructor
        this->length = length;
        this->height = height;
        this->width = width;
    }

    // void display(){
    //     cout<<"\nLength : "<<length<<"\nHeight : "<<height<<"\nWidth : "<<width<<endl;
    // }

    //Calculate Volume
    double calculateVolume(){
        volume = length * height * width;
        return volume;
    }

    //Set Calculated Volume
    double setVolume(double volume){
        this->volume = volume;
        return this->volume;
    }

    //Fetch Volume
    double getVolume() const{
        return volume;
    }

};

int main(){
    double length,height,width;
    int choice;
    container *cptr = NULL;

    //Menu-Driven Function Calls
    do {
        cout << "\n--- Volume Menu ---\n";
        cout << "1. Calculate volume of box with default values\n";
        cout << "2. Calculate Volume with length,breadth and height with same value\n";
        cout << "3. 3. Calculate Volume with different length,breadth and height values\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cptr = new container();
                cptr->setVolume(cptr->calculateVolume());
                cout<<"Volume calculated with default values : "<<cptr->getVolume();
                break;
            case 2:
                cout<<"Enter the value : "<<endl;
                cin>>length;
                cptr = new container(length);
                cptr->setVolume(cptr->calculateVolume());
                cout<<"Volume calculated with single value for all measures : "<<cptr->getVolume();
                break;
            case 3:
                cout<<"Enter the values for length,height,width respectively : "<<endl;
                cin>>length>>height>>width;
                cptr = new container(length,height,width);
                cptr->setVolume(cptr->calculateVolume());
                cout<<"Volume calculated with single value for all measures : "<<cptr->getVolume();
                break;
            case 4:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    //Deleting Dynamic Memory
    if(cptr!=NULL)
    {
        delete cptr;
        cptr=NULL;
    }    
}   