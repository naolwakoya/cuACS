#ifndef ANIMALLIST_H
#define ANIMALLIST_H

#include <vector>
#include "DataModel/defs.h"
#include "DataModel/Animal.h"

class AnimalList{
public:
    ~AnimalList();
    void    add(Animal*);
    Animal* get(int); // get with index
    Animal* find(int); // find with ID
    int     getSize();
    int     getLastID();
private:
    std::vector<Animal*> elements;
};
#endif // ANIMALLIST_H
