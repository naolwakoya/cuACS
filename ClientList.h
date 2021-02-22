#ifndef CLIENTLIST_H
#define CLIENTLIST_H

#include <vector>
#include "DataModel/Client.h"

class ClientList{
public:
    ~ClientList();
    void    add(Client*);
    Client* get(int); // get with index
    Client* find(int); // find with ID
    int     getSize();
    int     getLastID();
private:
    std::vector<Client*> elements;
};

#endif // CLIENTLIST_H
