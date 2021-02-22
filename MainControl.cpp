#include "MainControl.h"

MainControl::MainControl(){
    acsPersistant = QSqlDatabase::addDatabase("QSQLITE");
    QString path = QDir::currentPath() + QString("/persistant.sqlite");
    acsPersistant.setDatabaseName(path);
    acsPersistant.open();
}

MainControl::~MainControl(){ acsPersistant.close(); }

CuacsData MainControl::getData() { return acsData; }

bool MainControl::loadPersistantDB(){
    QSqlQuery query;

    query.exec("select * from username");
    while(query.next()){
        acsData.addUsername(query.value(0).toString());
    }

    query.exec("select * from animal");
    while(query.next()){
        int id =     query.value(0).toInt();
        QString nm = query.value(1).toString();
        int ag =     query.value(2).toInt();
        QString sx = query.value(3).toString();
        QString co = query.value(4).toString();
        int ht =     query.value(5).toInt();
        double wt =  query.value(6).toDouble();
        QString br = query.value(7).toString();
        int tp =     query.value(8).toInt();
        int pf =     query.value(9).toInt();
        int ppf =    query.value(10).toInt();
        int tr =     query.value(11).toInt();
        int cl =     query.value(12).toInt();
        int pl =     query.value(13).toInt();
        int he =     query.value(14).toInt();
        int te =     query.value(15).toInt();
        int ho =     query.value(16).toInt();
        int cw =     query.value(17).toInt();
        int in =     query.value(18).toInt();
        int ex =     query.value(19).toInt();
        int sh =     query.value(20).toInt();

        //nested query
        QSqlQuery typeQ;
        if(tp == 1){ // 1: bird table
            typeQ.prepare("select * from bird where animalID = :aID");
        }else if(tp == 2){ // 2: cat table
            typeQ.prepare("select * from cat where animalID = :aID");
        }else{ // dog table
            typeQ.prepare("select * from dog where animalID = :aID");
        }
        typeQ.bindValue(":aID", id);
        typeQ.exec();
        bool animal_attr = true;
        while(typeQ.next()){
            if(typeQ.value(1).toInt() == 0)
                animal_attr = false;
        }

        Animal* animal;
        if(tp == 1){
            animal = new Bird(id, nm, ag, sx, co, ht, wt, br, animal_attr);
        }else if(tp == 2){
            animal = new Cat(id, nm, ag, sx, co, ht, wt, br, animal_attr);
        }else{
            animal = new Dog(id, nm, ag, sx, co, ht, wt, br, animal_attr);
        }
        animal->setPetFriendly(pf);
        animal->setPeopleFriendly(ppf);
        animal->setTrainable(tr);
        animal->setCalmness(cl);
        animal->setPlayfulness(pl);
        animal->setHealth(he);
        animal->setTemperament(te);
        animal->setHotWeather(ho);
        animal->setColdWeather(cw);
        animal->setIntelligence(in);
        animal->setExercise(ex);
        animal->setShyness(sh);
        acsData.addAnimal(animal);
    }

    query.exec("select * from client");
    while(query.next()){
        int id = query.value(0).toInt();
        QString fn = query.value(1).toString();
        QString ln = query.value(2).toString();
        QString ph = query.value(3).toString();
        QString em = query.value(4).toString();
        QString sx = query.value(5).toString();
        int ag = query.value(6).toInt();

        Client* client = new Client(id, fn, ln, ph, em, sx, ag);
        acsData.addClient(client);
    }
    return true;
}

bool MainControl::findUsername(QString user){
    if(user == "adnan" || user == "muhanad"){
        isClient = false;
    }
    return acsData.findUsername(user);
}

bool MainControl::userIsClient(){
    return isClient;
}

// id, name, age, sex, color, height, weight, breed, type, pet friendly, people freinly, trainable,
// calmness, playfulness, health, temperament, hot weather, cold weather, intelligence, exercise, shyness
void MainControl::addAnimal(int id, QString name, int age, QString sex, QString color, int height, double weight, QString breed, AnimalType type, bool attr,
                            int petF, int pplF, int train, int calm, int play, int heal, int temper, int hot, int cold, int intel, int exer, int shy){
    QSqlQuery query;
    QSqlQuery typeQuery;
    query.prepare("insert into animal(animalID, name, age, sex, color, height, weight, breed, type, petfriendly, peoplefriendly,"
                  "trainable, calmness, playfulness, health, temperament, hot, cold, intelligence, exercise, shyness)"
                  " values(:i, :nm, :ag, :sx, :co, :ht, :wt, :br, :ty, :pe, :ppf, :tr, :cl, :pl, :hl, :te, :ho, :cw, :in, :ex, :sh)");
    query.bindValue(":i", id);
    query.bindValue(":nm", name);
    query.bindValue(":ag", age);
    query.bindValue(":sx", sex);
    query.bindValue(":co", color);
    query.bindValue(":ht", height);
    query.bindValue(":wt", weight);
    query.bindValue(":br", breed);
    query.bindValue(":pe", petF);
    query.bindValue(":ppf", pplF);
    query.bindValue(":tr", train);
    query.bindValue(":cl", calm);
    query.bindValue(":pl", play);
    query.bindValue(":hl", heal);
    query.bindValue(":te", temper);
    query.bindValue(":ho", hot);
    query.bindValue(":cw", cold);
    query.bindValue(":in", intel);
    query.bindValue(":ex", exer);
    query.bindValue(":sh", shy);

    if(type == BIRD){
        acsData.addAnimal(new Bird(id, name, age, sex, color, height, weight, breed, attr));
        query.bindValue(":ty", 1);
        typeQuery.prepare("insert into bird(animalID, flight) values(:typeID, :typeAttr)");
    }else if(type == CAT){
        acsData.addAnimal(new Cat(id, name, age, sex, color, height, weight, breed, attr));
        query.bindValue(":ty", 2);
        typeQuery.prepare("insert into cat(animalID, outdoor) values(:typeID, :typeAttr)");
    }else{
        acsData.addAnimal(new Dog(id, name, age, sex, color, height, weight, breed, attr));
        query.bindValue(":ty", 3);
        typeQuery.prepare("insert into dog(animalID, gaurd) values(:typeID, :typeAttr)");
    }
    typeQuery.bindValue(":typeID", id);
    if(attr == true){
        typeQuery.bindValue(":typeAttr", 1);
    }else{
        typeQuery.bindValue(":typeAttr", 0);
    }
    acsData.getAnimals().find(id)->setPetFriendly(petF);
    acsData.getAnimals().find(id)->setPeopleFriendly(pplF);
    acsData.getAnimals().find(id)->setTrainable(train);
    acsData.getAnimals().find(id)->setCalmness(calm);
    acsData.getAnimals().find(id)->setPlayfulness(play);
    acsData.getAnimals().find(id)->setHealth(heal);
    acsData.getAnimals().find(id)->setTemperament(temper);
    acsData.getAnimals().find(id)->setHotWeather(hot);
    acsData.getAnimals().find(id)->setColdWeather(cold);
    acsData.getAnimals().find(id)->setIntelligence(intel);
    acsData.getAnimals().find(id)->setExercise(exer);
    acsData.getAnimals().find(id)->setShyness(shy);
    query.exec();
    typeQuery.exec();
}


// id, fname, lname, phone, email, sex, age
void MainControl::addClient(int id, QString fn, QString ln, QString ph, QString em, QString sx, int ag){
    acsData.addClient(new Client(id, fn, ln, ph, em, sx, ag));

    QSqlQuery query;
    query.prepare("insert into client(clientID, fname, lname, phone, email, sex, age) values (:id, :fn, :ln, :ph, :em, :sx, :ag)");
    query.bindValue(":id", id);
    query.bindValue(":fn", fn);
    query.bindValue(":ln", ln);
    query.bindValue(":ph", ph);
    query.bindValue(":em", em);
    query.bindValue(":sx", sx);
    query.bindValue(":ag", ag);
    query.exec();

    QString usrname = fn+ln;
    usrname.toLower();
    acsData.addUsername(usrname);
    query.prepare("insert into username(uname) values(:un)");
    query.bindValue(":un", usrname);
    query.exec();
}
