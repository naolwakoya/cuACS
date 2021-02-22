#ifndef ANIMAL_H
#define ANIMAL_H

#include <QString>
#include "DataModel/defs.h"

class Animal{
public:
    Animal(int, QString, int, QString, QString, int, double, QString, AnimalType); // id, name, age, sex, color, height, weight, breed, type
    int        getPetID();
    QString    getSex();
    QString    getName();
    int        getAge();
    int        getHeight();
    double     getWeight();
    QString    getBreed();
    QString    getColor();
    AnimalType getType();
    int        getPetFriendly();
    int        getPeopleFriendly();
    int        getTrainable();
    int        getCalmness();
    int        getPlayfulness();
    int        getHealth();
    int        getTemperament();
    int        getHotWeather();
    int        getColdWeather();
    int        getIntelligence();
    int        getExercise();
    int        getShyness();
    void       setName(QString);
    void       setHeight(int);
    void       setWeight(double);
    void       setAge(int);
    void       setPetFriendly(int);
    void       setPeopleFriendly(int);
    void       setTrainable(int);
    void       setCalmness(int);
    void       setPlayfulness(int);
    void       setHealth(int);
    void       setTemperament(int);
    void       setHotWeather(int);
    void       setColdWeather(int);
    void       setIntelligence(int);
    void       setExercise(int);
    void       setShyness(int);
protected:
    int        petID;
    QString    name;
    int        age;
    QString    sex;
    QString    color;
    int        height; // in cm
    double     weight; // in lbs
    AnimalType type;
    QString    breed;
    int        petFriendly;
    int        peopleFriendly;
    int        trainable;
    int        calmness;
    int        playfulness;
    int        health;
    int        temperament;
    int        hotWeather;
    int        coldWeather;
    int        intelligence;
    int        exercise;
    int        shyness;
};
#endif // ANIMAL_H
