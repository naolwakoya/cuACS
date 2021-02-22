#ifndef DOG_H
#define DOG_H

#include "DataModel/Animal.h"

class Dog: public Animal{
public:
    Dog(int, QString, int, QString, QString, int, double, QString, bool);// id, name, age, sex, color, height, weight, breed, protective
    bool isProtective();
private:
    bool protective;
};
#endif // DOG_H
