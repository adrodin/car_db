#include "include/car.h"


Car::Car(){};
Car::Car(string vin,string mark,string model,int year, int mileage, int enginePower,string colour){
    this->vin = vin;
    this->mark = mark;
    this->model = model;
    this->year = year;
    this->mileage = mileage;
    this->enginePower = enginePower;
    this->colour = colour;
}
string Car::getVin(){
    return  this->vin;
}
string Car::getMark(){
    return this->mark;
}
string Car::getModel(){
    return this->model;
}
int Car::getYear(){
    return this->year;
}
int Car::getMileage(){
    return this->mileage;
}
int Car::getEnginePower(){
    return this->enginePower;
}
string Car::getColour(){
    return this->colour;
}

void Car::setMileage(int newMileage){
    if(this->mileage>newMileage){
        throw invalid_argument("New mileage cannot be less than previous");
    }
    else{
        this->mileage = newMileage;
    }
}
void Car::setEnginePower(int newEnginePower){
    if(newEnginePower<1){
        throw invalid_argument("New engine power cannot be less than 1");
    }
    else{
        this->enginePower = newEnginePower;
    }
}
void Car::setColour(string newColour){
    this->colour = newColour;
}

bool Car::checkVin(string vin){
    return vin.length()==17;
}