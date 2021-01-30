

#ifndef V3_CAR_H
#define V3_CAR_H
#include <iostream>


using namespace std;

class Car{
private:
    string vin;
    string mark;
    string model;
    int year;
    int mileage;
    int enginePower;
    string colour;

public:
    Car();
    Car(string vin,string mark,string model,int year, int mileage, int enginePower,string colour);
    string getVin();
    string getMark();
    string getModel();
    int getYear();
    int getMileage();
    int getEnginePower();
    string getColour();
    static bool checkVin(string vin);

    void setMileage(int newMileage);
    void setEnginePower(int newEnginePower);
    void setColour(string newColour);







};

#endif //V3_CAR_H
