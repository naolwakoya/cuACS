#include "DataModel/Bird.h"

Bird::Bird(int id, QString n, int a, QString s, QString c, int h, double w, QString b, bool fly)
    :Animal(id, n, a, s, c, h, w, b, BIRD){
    flight = fly;
}

bool Bird::canFly(){return flight;}
