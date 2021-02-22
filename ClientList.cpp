#include "DataModel/ClientList.h"
#include <algorithm>

void ClientList::add(Client* client){
    elements.push_back(client);
}

Client* ClientList::get(int index){
    int size = elements.size();
    if(index < 0 || index > size)
        return NULL;
    return elements.at(index);
}

Client* ClientList::find(int clientID){
    int size = elements.size();
    for (int i = 0; i < size; i++){
        if(clientID == elements.at(i)->getID())
            return elements.at(i);
    }
    return NULL;
}

int ClientList::getSize(){ return elements.size(); }

int ClientList::getLastID(){
    std::vector<int> ids;
    int size = elements.size();
    for(int i = 0; i < size; i++){
        int id = elements.at(i)->getID();
        ids.push_back(id);
    }
    std::sort(ids.begin(), ids.end());
    return ids.at(size-1);
}

ClientList::~ClientList() { elements.clear(); }
