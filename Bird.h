#ifndef BIRD_H
#define BIRD_H

#include "DataModel/Animal.h"

class Bird: public Animal{
public:
    Bird(int, QString, int, QString, QString, int, double, QString, bool);// id, name, age, sex, color, height, weight,breed, flight
    bool canFly();
private:
    bool flight;
};

#endif // BIRD_H



