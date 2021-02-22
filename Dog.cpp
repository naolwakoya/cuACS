#include "DataModel/Dog.h"

Dog::Dog(int id, QString n, int a, QString s, QString c, int h, double w, QString b, bool p)
    :Animal(id, n, a, s, c, h, w, b, DOG){
    protective = p;
}

bool Dog::isProtective(){return protective;}
