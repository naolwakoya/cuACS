#include "DataModel/AnimalList.h"
#include <algorithm>

void AnimalList::add(Animal* animal){
    elements.push_back(animal);
}

Animal* AnimalList::get(int index){
    int size = elements.size();
    if(index < 0 || index > size)
        return NULL;
    return elements.at(index);
}

Animal* AnimalList::find(int animalID){
    int size = elements.size();
    for (int i = 0; i < size; i++){
        if(animalID == elements.at(i)->getPetID())
            return elements.at(i);
    }
    return NULL;
}

int AnimalList::getSize(){ return elements.size(); }

int AnimalList::getLastID(){
    std::vector<int> ids;
    int size = elements.size();
    for(int i = 0; i < size; i++){
        int id = elements.at(i)->getPetID();
        ids.push_back(id);
    }
    std::sort(ids.begin(), ids.end());
    return ids.at(size-1);
}

AnimalList::~AnimalList() { elements.clear(); }
