/*Write a class to find volume of a Cylinder by using following members. (volume of
Cylinder=3.14 * radius * radius *height) ( use static wherever needed. hint-PI)
Class having following member functions:
Cylinder()
Cylinder(double radius, double height)
getRadius()
setRadius()
getHeight()
setHeight()
calculateVolume()
Initialize members using constructor member initializer list.*/

#include <iostream>
using namespace std;

class Cylinder
{
private:
    static const double PI;
    double radius;
    double height;

public:
    // constructors
    Cylinder() : radius(0), height(0) {}
    Cylinder(double radius, double height) : radius(radius), height(height) {};

    // Setters
    void setRadius(double radius)
    {
        this->radius = radius;
    }
    void setHeight(double height)
    {
        this->height = height;
    }

    // Getters
    double getRadius() const { return radius; }
    double getHeight() const { return height; }

    double calculateVolume()
    {
        return (PI * radius * radius * height);
    }
};

const double Cylinder::PI = 3.14;

int main()
{
    double radius, height;
    cout << "Enter the radius and height of the cylinder" << endl;
    cin >> radius >> height;
    Cylinder ptr(radius, height);

    cout << "\nVolume of cylinder : " << ptr.calculateVolume() << endl;

    return 0;
}