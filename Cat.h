#ifndef CAT_H
#define CAT_H

#include "DataModel/Animal.h"

class Cat: public Animal{
public:
    Cat(int, QString, int, QString, QString, int, double, QString, bool);// id, name, age, sex, color, height, weight, breed, declawed
    bool isOutdoor();
private:
    bool outdoor;
};

#endif // CAT_H

