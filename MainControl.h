#ifndef MAINCONTROL_H
#define MAINCONTROL_H

#include "DataModel/Animal.h"
#include "DataModel/Bird.h"
#include "DataModel/Cat.h"
#include "DataModel/Dog.h"
#include "DataModel/Client.h"
#include "DataModel/CuacsData.h"
#include <QtSql>
#include <QFile>
#include <QFileInfo>
#include <QString>
#include <QDebug>

class MainControl{
public:
    MainControl();
    ~MainControl();
    bool loadPersistantDB();
    bool findUsername(QString);
    CuacsData getData();
    void addAnimal(int, QString, int, QString, QString, int, double, QString, AnimalType, bool, int, int, int, int, int, int, int, int, int, int, int, int);
    void addClient(int, QString, QString, QString, QString, QString, int);
    bool userIsClient();
private:
    QSqlDatabase acsPersistant;
    CuacsData    acsData;
    bool         isClient;
};
#endif // MAINCONTROL_H
