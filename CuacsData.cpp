#include "DataModel/CuacsData.h"

void CuacsData::addAnimal(Animal* animal){ animals.add(animal); }

void CuacsData::addClient(Client* client){ clients.add(client); }

bool CuacsData::findUsername(QString uname){
    int size = staffUsernames.size();
    for (int i = 0; i<size; i++){
        if(uname == staffUsernames.at(i))
            return true;
    }
    return false;
}
void CuacsData::addUsername(QString uname){ staffUsernames.push_back(uname); }
AnimalList& CuacsData::getAnimals(){return animals;}
ClientList& CuacsData::getClients(){return clients;}
