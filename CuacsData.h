#ifndef CUACSDATA_H
#define CUACSDATA_H

#include "DataModel/Animal.h"
#include "DataModel/AnimalList.h"
#include "DataModel/Client.h"
#include "DataModel/ClientList.h"
#include <QString>
#include <vector>

class CuacsData{
public:
    void        addAnimal(Animal*);
    void        addClient(Client*);
    bool        findUsername(QString);
    void        addUsername(QString);
    AnimalList& getAnimals();
    ClientList& getClients();
private:
    AnimalList animals;
    ClientList clients;
    std::vector<QString> staffUsernames;
};
#endif // CUACSDATA_H
