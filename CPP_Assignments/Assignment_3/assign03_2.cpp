/*Write a class for Time and provide the functionality
Time()
Time(int h,int m,int s)
getHour()
getMinute()
getSeconds()
printTime()
setHour()
setMinute()
setSeconds()
In main create array of objects of Time.
Allocate the memory for the array and the object dynamically.*/

#include <iostream>
using namespace std;

class Time
{
private:
    int hrs;
    int min;
    int sec;

public:
    Time(int h, int m, int s) : hrs(h), min(m), sec(s) {};

    // Setters
    void setHours(int h)
    {
        this->hrs = h;
    }
    void setMinutes(int m)
    {
        this->min = m;
    }
    void setSeconds(int s)
    {
        this->sec = s;
    }

    // Getters
    int getHrs() { return this->hrs; }
    int getMin() { return this->min; }
    int getSec() { return this->sec; }

    void printTime()
    {
        cout << "Time : " << hrs << ":" << min << ":" << sec;
    }
    
};

int main()
{
    int number, hrs, min, sec;
    cout << "Enter the number you want to create time: " << endl;
    cin >> number;
    Time **ptr = new Time *[number];
   
    for (int i = 0; i < number; i++)
    {
        cout << "Enter the time in HH:MM:SS format : " << endl;
        cin >> hrs >> min >> sec;
        ptr[i] = new Time(hrs, min, sec);
    }
    
    for(int i = 0; i < number; i++){
        //cout<<"Time you entered : "<<ptr[i]->getHrs()<<" : "<<ptr[i]->getMin()<<" : "<<ptr[i]->getSec()<<endl;
        cout<<"Time you entered : ";
        ptr[i]->printTime();
    }

    for(int i = 0; i < number; i++){
        delete ptr[i];
        ptr[i] = NULL;
    }
    delete[] ptr;
    ptr=NULL;

    return 0;

}