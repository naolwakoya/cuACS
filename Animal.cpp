#include "DataModel/Animal.h"

// id, name, age, sex, color, height, weight, breed, type(dog/cat/bird)
Animal::Animal(int id, QString n, int a, QString s, QString c, int ht, double wt, QString b, AnimalType animaltype){
    petID  = id;
    name   = n;
    age    = a;
    sex    = s;
    color  = c;
    height = ht;
    weight = wt;
    breed  = b;
    type   = animaltype;
}

int        Animal::getPetID(){return petID;}
QString    Animal::getSex(){return sex;}
QString    Animal::getName(){return name;}
int        Animal::getAge(){return age;}
int        Animal::getHeight(){return height;}
double     Animal::getWeight(){return weight;}
QString    Animal::getBreed(){return breed;}
QString    Animal::getColor(){return color;}
AnimalType Animal::getType(){return type;}
int        Animal::getPetFriendly(){return petFriendly;}
int        Animal::getPeopleFriendly(){return peopleFriendly;}
int        Animal::getTrainable(){return trainable;}
int        Animal::getCalmness(){return calmness;}
int        Animal::getPlayfulness(){return playfulness;}
int        Animal::getHealth(){return health;}
int        Animal::getTemperament(){return temperament;}
int        Animal::getHotWeather(){return hotWeather;}
int        Animal::getColdWeather(){return coldWeather;}
int        Animal::getIntelligence(){return intelligence;}
int        Animal::getExercise(){return exercise;}
int        Animal::getShyness(){return shyness;}
void       Animal::setName(QString n){name = n;}
void       Animal::setHeight(int h){height = h;}
void       Animal::setWeight(double w){weight = w;}
void       Animal::setAge(int a){age = a;}
void       Animal::setPetFriendly(int pf){petFriendly = pf;}
void       Animal::setPeopleFriendly(int pf){peopleFriendly = pf;}
void       Animal::setTrainable(int t){trainable = t;}
void       Animal::setCalmness(int c){calmness = c;}
void       Animal::setPlayfulness(int p){playfulness = p;}
void       Animal::setHealth(int h){health = h;}
void       Animal::setTemperament(int t){temperament = t;}
void       Animal::setHotWeather(int h){hotWeather = h;}
void       Animal::setColdWeather(int c){coldWeather = c;}
void       Animal::setIntelligence(int i){intelligence = i;}
void       Animal::setExercise(int e){exercise = e;}
void       Animal::setShyness(int s){shyness = s;}

//Animal::~Animal(){}
