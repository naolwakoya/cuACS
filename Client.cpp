#include "DataModel/Client.h"

Client::Client(int id, QString f, QString l, QString p, QString e, QString s, int a){
    clientID = id;
    fname = f;
    lname = l;
    phone = p;
    email = e;
    sex   = s;
    age   = a;
}

int     Client::getID(){return clientID;}
QString Client::getFname(){return fname;}
QString Client::getLname(){return lname;}
QString Client::getPhone(){return phone;}
QString Client::getEmail(){return email;}
QString Client::getSex(){return sex;}
int     Client::getAge(){return age;}


