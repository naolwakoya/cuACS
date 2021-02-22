#include "maininterface.h"
#include "ui_maininterface.h"

MainInterface::MainInterface(QWidget *parent):QMainWindow(parent),ui(new Ui::MainInterface){
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->pageLogin);

    mainControl = new MainControl();
    if(mainControl->loadPersistantDB()){
        ui->statusBar->showMessage("Persistant database loaded.", 4000);
    }else{
        ui->statusBar->showMessage("Persistant database was not loaded successfully.", 4000);
    }
    createAnimalTable();
    populateAnimalTable();
    createClientTable();
    populateClientTable();
}

MainInterface::~MainInterface(){
    delete ui;
}

void MainInterface::createAnimalTable(){
    QFont font("Courier 10 Pitch", 9);
    ui->tableWidget->setColumnCount(9);
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Animal ID"));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Name"));
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Age"));
    ui->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("Sex"));
    ui->tableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem("Color"));
    ui->tableWidget->setHorizontalHeaderItem(5, new QTableWidgetItem("Height (cm)"));
    ui->tableWidget->setHorizontalHeaderItem(6, new QTableWidgetItem("Weight (lbs)"));
    ui->tableWidget->setHorizontalHeaderItem(7, new QTableWidgetItem("Breed"));
    ui->tableWidget->setHorizontalHeaderItem(8, new QTableWidgetItem("Type"));
    ui->tableWidget->horizontalHeader()->setFont(font);
    ui->tableWidget->verticalHeader()->setFont(font);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->resizeColumnsToContents();
}

void MainInterface::createClientTable(){
    QFont font("Courier 10 Pitch", 9);
    ui->tableWidgetClient->setColumnCount(7);
    ui->tableWidgetClient->setHorizontalHeaderItem(0, new QTableWidgetItem("Client ID"));
    ui->tableWidgetClient->setHorizontalHeaderItem(1, new QTableWidgetItem("First Name"));
    ui->tableWidgetClient->setHorizontalHeaderItem(2, new QTableWidgetItem("Last Name"));
    ui->tableWidgetClient->setHorizontalHeaderItem(3, new QTableWidgetItem("Phone"));
    ui->tableWidgetClient->setHorizontalHeaderItem(4, new QTableWidgetItem("Email"));
    ui->tableWidgetClient->setHorizontalHeaderItem(5, new QTableWidgetItem("Sex"));
    ui->tableWidgetClient->setHorizontalHeaderItem(6, new QTableWidgetItem("Age"));
    ui->tableWidgetClient->horizontalHeader()->setFont(font);
    ui->tableWidgetClient->verticalHeader()->setFont(font);
    ui->tableWidgetClient->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidgetClient->resizeColumnsToContents();

}

void MainInterface::populateClientTable(){
    int numClients = mainControl->getData().getClients().getSize();
    int rowCount = 0;
    for (int i = 0; i < numClients; i++){
        int id        = mainControl->getData().getClients().get(i)->getID();
        QString fname = mainControl->getData().getClients().get(i)->getFname();
        QString lname = mainControl->getData().getClients().get(i)->getLname();
        QString phone = mainControl->getData().getClients().get(i)->getPhone();
        QString email = mainControl->getData().getClients().get(i)->getEmail();
        QString sex   = mainControl->getData().getClients().get(i)->getSex();
        int age       = mainControl->getData().getClients().get(i)->getAge();

        QTableWidgetItem *cId = new QTableWidgetItem(QString::number(id));
        cId->setFlags(cId->flags() & ~Qt::ItemIsEditable);
        cId->setTextAlignment(Qt::AlignCenter);

        QTableWidgetItem *cfn = new QTableWidgetItem(fname);
        cfn->setFlags(cfn->flags() & ~Qt::ItemIsEditable);
        cfn->setTextAlignment(Qt::AlignCenter);

        QTableWidgetItem *cln = new QTableWidgetItem(lname);
        cln->setFlags(cln->flags() & ~Qt::ItemIsEditable);
        cln->setTextAlignment(Qt::AlignCenter);

        QTableWidgetItem *cph = new QTableWidgetItem(phone);
        cph->setFlags(cph->flags() & ~Qt::ItemIsEditable);
        cph->setTextAlignment(Qt::AlignCenter);

        QTableWidgetItem *cem = new QTableWidgetItem(email);
        cem->setFlags(cem->flags() & ~Qt::ItemIsEditable);
        cem->setTextAlignment(Qt::AlignCenter);

        QTableWidgetItem *csx = new QTableWidgetItem(sex);
        csx->setFlags(csx->flags() & ~Qt::ItemIsEditable);
        csx->setTextAlignment(Qt::AlignCenter);

        QTableWidgetItem *cag = new QTableWidgetItem(QString::number(age));
        cag->setFlags(cag->flags() & ~Qt::ItemIsEditable);
        cag->setTextAlignment(Qt::AlignCenter);

        ui->tableWidgetClient->setRowCount(rowCount+1);
        ui->tableWidgetClient->setItem(rowCount,0,cId);
        ui->tableWidgetClient->setItem(rowCount,1,cfn);
        ui->tableWidgetClient->setItem(rowCount,2,cln);
        ui->tableWidgetClient->setItem(rowCount,3,cph);
        ui->tableWidgetClient->setItem(rowCount,4,cem);
        ui->tableWidgetClient->setItem(rowCount,5,csx);
        ui->tableWidgetClient->setItem(rowCount,6,cag);
        rowCount++;
    }
}

void MainInterface::populateAnimalTable(){
    int numAnimals =  mainControl->getData().getAnimals().getSize();
    int rowCount = 0;
    for(int i = 0; i < numAnimals; i++){
        int id        = mainControl->getData().getAnimals().get(i)->getPetID();
        QString name  = mainControl->getData().getAnimals().get(i)->getName();
        int age       = mainControl->getData().getAnimals().get(i)->getAge();
        QString sex   = mainControl->getData().getAnimals().get(i)->getSex();
        QString color = mainControl->getData().getAnimals().get(i)->getColor();
        int height    = mainControl->getData().getAnimals().get(i)->getHeight();
        double weight = mainControl->getData().getAnimals().get(i)->getWeight();
        QString breed = mainControl->getData().getAnimals().get(i)->getBreed();
        QString type  = "Dog";
        if (mainControl->getData().getAnimals().get(i)->getType() == BIRD){
            type = "Bird";
        }else if(mainControl->getData().getAnimals().get(i)->getType() == CAT){
            type = "Cat";
        }
        QTableWidgetItem *aId = new QTableWidgetItem(QString::number(id));
        aId->setFlags(aId->flags() & ~Qt::ItemIsEditable);
        aId->setTextAlignment(Qt::AlignCenter);

        QTableWidgetItem *aName = new QTableWidgetItem(name);
        aName->setFlags(aName->flags() & ~Qt::ItemIsEditable);
        aName->setTextAlignment(Qt::AlignCenter);

        QTableWidgetItem *aAge = new QTableWidgetItem(QString::number(age));
        aAge->setFlags(aAge->flags() & ~Qt::ItemIsEditable);
        aAge->setTextAlignment(Qt::AlignCenter);

        QTableWidgetItem *aSex = new QTableWidgetItem(sex);
        aSex->setFlags(aSex->flags() & ~Qt::ItemIsEditable);
        aSex->setTextAlignment(Qt::AlignCenter);

        QTableWidgetItem *aColor = new QTableWidgetItem(color);
        aColor->setFlags(aColor->flags() & ~Qt::ItemIsEditable);
        aColor->setTextAlignment(Qt::AlignCenter);

        QTableWidgetItem *aHeight = new QTableWidgetItem(QString::number(height));
        aHeight->setFlags(aHeight->flags() & ~Qt::ItemIsEditable);
        aHeight->setTextAlignment(Qt::AlignCenter);

        QTableWidgetItem *aWeight = new QTableWidgetItem(QString::number(weight));
        aWeight->setFlags(aWeight->flags() & ~Qt::ItemIsEditable);
        aWeight->setTextAlignment(Qt::AlignCenter);

        QTableWidgetItem *aBreed = new QTableWidgetItem(breed);
        aBreed->setFlags(aBreed->flags() & ~Qt::ItemIsEditable);
        aBreed->setTextAlignment(Qt::AlignCenter);

        QTableWidgetItem *aType = new QTableWidgetItem(type);
        aType->setFlags(aType->flags() & ~Qt::ItemIsEditable);
        aType->setTextAlignment(Qt::AlignCenter);

        ui->tableWidget->setRowCount(rowCount+1);
        ui->tableWidget->setItem(rowCount,0,aId);
        ui->tableWidget->setItem(rowCount,1,aName);
        ui->tableWidget->setItem(rowCount,2,aAge);
        ui->tableWidget->setItem(rowCount,3,aSex);
        ui->tableWidget->setItem(rowCount,4,aColor);
        ui->tableWidget->setItem(rowCount,5,aHeight);
        ui->tableWidget->setItem(rowCount,6,aWeight);
        ui->tableWidget->setItem(rowCount,7,aBreed);
        ui->tableWidget->setItem(rowCount,8,aType);
        rowCount++;
    }
}


void MainInterface::on_loginButton_released(){
    QString userName = ui->usernameLine->text();
    if(mainControl->findUsername(userName)){
        ui->statusBar->showMessage("Login Successful.", 4000);
        ui->stackedWidget->setCurrentWidget(ui->pageStaff);
        ui->tabWidget->setCurrentWidget(ui->tab);
        if(mainControl->userIsClient()){
            ui->tabWidget->setTabEnabled(1, false);
            ui->tabWidget->setTabEnabled(2, false);
            ui->tabWidget->setTabEnabled(3, false);
        }else{
            ui->tabWidget->setTabEnabled(1, true);
            ui->tabWidget->setTabEnabled(2, true);
            ui->tabWidget->setTabEnabled(3, true);
        }
    }
}

void MainInterface::on_addButton_released(){
    int aid = mainControl->getData().getAnimals().getLastID();
    aid += 1;
    QString aName = ui->inputName->text();
    int aAge = ui->inputAge->value();
    QString aSex = ui->inputSex->currentText();
    QString aColor = ui->inputColot->text();
    int aHeight = ui->inputHeight->value();
    double aWeight = ui->inputWeight->value();
    QString aBreed = ui->inputBreed->text();
    AnimalType aType;
    if(ui->inputType->currentText() == "Bird"){
        aType = BIRD;
    }else if(ui->inputType->currentText() == "Cat"){
        aType = CAT;
    }else{
        aType = DOG;
    }
    int pe = ui->inputPetFriendly->currentText().toInt();
    int ppf = ui->inputPeopleFriendly->currentText().toInt();
    int tr = ui->inputTrainable->currentText().toInt();
    int cl = ui->inputCalmness->currentText().toInt();
    int pl = ui->inputPlayfulness->currentText().toInt();
    int hl = ui->inputHealth->currentText().toInt();
    int te = ui->inputTemperament->currentText().toInt();
    int ho = ui->inputHotWeather->currentText().toInt();
    int cw = ui->inputColdWeather->currentText().toInt();
    int in = ui->inputIntelligence->currentText().toInt();
    int ex = ui->inputExercise->currentText().toInt();
    int sh = ui->inputShyness->currentText().toInt();

    mainControl->addAnimal(aid, aName, aAge, aSex, aColor, aHeight, aWeight, aBreed, aType, true, pe, ppf, tr, cl, pl, hl, te, ho , cw, in , ex, sh);

    ui->tableWidget->clear();
    populateAnimalTable();
    ui->tabWidget->setCurrentIndex(0);
    ui->inputName->clear();
    ui->inputAge->clear();
    ui->inputColot->clear();
    ui->inputHeight->clear();
    ui->inputWeight->clear();
    ui->inputBreed->clear();
    ui->inputPetFriendly->setCurrentIndex(0);
    ui->inputPeopleFriendly->setCurrentIndex(0);
    ui->inputTrainable->setCurrentIndex(0);
    ui->inputCalmness->setCurrentIndex(0);
    ui->inputPlayfulness->setCurrentIndex(0);
    ui->inputHealth->setCurrentIndex(0);
    ui->inputTemperament->setCurrentIndex(0);
    ui->inputHotWeather->setCurrentIndex(0);
    ui->inputColdWeather->setCurrentIndex(0);
    ui->inputIntelligence->setCurrentIndex(0);
    ui->inputExercise->setCurrentIndex(0);
    ui->inputShyness->setCurrentIndex(0);

}

void MainInterface::on_tableWidget_cellDoubleClicked(int row, int column){
    ui->stackedWidget->setCurrentWidget(ui->pageViewAnimal);
    QTableWidgetItem *petItem = ui->tableWidget->item(row, 0);
    int petID = petItem->text().toInt();
    populateDetailedAnimal(petID);
    if(mainControl->userIsClient()){
        ui->label_33->setVisible(false);
        ui->label_34->setVisible(false);
        ui->label_35->setVisible(false);
        ui->label_36->setVisible(false);
        ui->label_37->setVisible(false);
        ui->label_40->setVisible(false);
        ui->label_41->setVisible(false);
        ui->label_42->setVisible(false);
        ui->label_43->setVisible(false);
        ui->label_44->setVisible(false);
        ui->label_45->setVisible(false);
        ui->label_62->setVisible(false);
        ui->label_64->setVisible(false);
        ui->showPetFriendly->setVisible(false);
        ui->showPeopleFriendly->setVisible(false);
        ui->showTrainable->setVisible(false);
        ui->showCalmness->setVisible(false);
        ui->showPlayfulness->setVisible(false);
        ui->showHealth->setVisible(false);
        ui->showTemperament->setVisible(false);
        ui->showHotWeather->setVisible(false);
        ui->showColdWeather->setVisible(false);
        ui->showIntelligence->setVisible(false);
        ui->showExcercise->setVisible(false);
        ui->showShyness->setVisible(false);
    }else{
        ui->label_33->setVisible(true);
        ui->label_34->setVisible(true);
        ui->label_35->setVisible(true);
        ui->label_36->setVisible(true);
        ui->label_37->setVisible(true);
        ui->label_40->setVisible(true);
        ui->label_41->setVisible(true);
        ui->label_42->setVisible(true);
        ui->label_43->setVisible(true);
        ui->label_44->setVisible(true);
        ui->label_45->setVisible(true);
        ui->label_62->setVisible(true);
        ui->label_64->setVisible(true);
        ui->showPetFriendly->setVisible(true);
        ui->showPeopleFriendly->setVisible(true);
        ui->showTrainable->setVisible(true);
        ui->showCalmness->setVisible(true);
        ui->showPlayfulness->setVisible(true);
        ui->showHealth->setVisible(true);
        ui->showTemperament->setVisible(true);
        ui->showHotWeather->setVisible(true);
        ui->showColdWeather->setVisible(true);
        ui->showIntelligence->setVisible(true);
        ui->showExcercise->setVisible(true);
        ui->showShyness->setVisible(true);
    }
}

void MainInterface::populateDetailedAnimal(int id){
    QString type = "Dog";
    if(mainControl->getData().getAnimals().find(id)->getType() == BIRD){
        type = "Bird";
    }else if(mainControl->getData().getAnimals().find(id)->getType() == CAT){
        type = "Cat";
    }
    ui->showPetID->setText(QString::number(id));
    ui->showPetType->setText(type);
    ui->showPetName->setText(mainControl->getData().getAnimals().find(id)->getName());
    ui->showPetAge->setText(QString::number(mainControl->getData().getAnimals().find(id)->getAge()));
    ui->showPetHeight->setText(QString::number(mainControl->getData().getAnimals().find(id)->getHeight()));
    ui->showPetWeight->setText(QString::number(mainControl->getData().getAnimals().find(id)->getWeight()));
    ui->showPetSex->setText(mainControl->getData().getAnimals().find(id)->getSex());
    ui->showPetColor->setText(mainControl->getData().getAnimals().find(id)->getColor());
    ui->showPetBreed->setText(mainControl->getData().getAnimals().find(id)->getBreed());
    ui->showPetFriendly->setText(QString::number(mainControl->getData().getAnimals().find(id)->getPetFriendly()));
    ui->showPeopleFriendly->setText(QString::number(mainControl->getData().getAnimals().find(id)->getPeopleFriendly()));
    ui->showTrainable->setText(QString::number(mainControl->getData().getAnimals().find(id)->getTrainable()));
    ui->showCalmness->setText(QString::number(mainControl->getData().getAnimals().find(id)->getCalmness()));
    ui->showPlayfulness->setText(QString::number(mainControl->getData().getAnimals().find(id)->getPlayfulness()));
    ui->showHealth->setText(QString::number(mainControl->getData().getAnimals().find(id)->getHealth()));
    ui->showTemperament->setText(QString::number(mainControl->getData().getAnimals().find(id)->getTemperament()));
    ui->showHotWeather->setText(QString::number(mainControl->getData().getAnimals().find(id)->getHotWeather()));
    ui->showColdWeather->setText(QString::number(mainControl->getData().getAnimals().find(id)->getColdWeather()));
    ui->showIntelligence->setText(QString::number(mainControl->getData().getAnimals().find(id)->getIntelligence()));
    ui->showExcercise->setText(QString::number(mainControl->getData().getAnimals().find(id)->getExercise()));
    ui->showShyness->setText(QString::number(mainControl->getData().getAnimals().find(id)->getShyness()));
}

void MainInterface::on_viewListButton_released(){
    ui->stackedWidget->setCurrentWidget(ui->pageStaff);
    ui->tabWidget->setCurrentIndex(0);
}

void MainInterface::on_addClientButton_released(){
    int cid = mainControl->getData().getClients().getLastID();
    cid++;
    QString fname = ui->inputClientfname->text();
    QString lname = ui->inputClientlname->text();
    QString phone = ui->inputClientphone->text();
    QString email = ui->inputClientemail->text();
    QString sex = ui->inputClientSex->currentText();
    int age = ui->inputClientAge->value();

    mainControl->addClient(cid, fname, lname, phone, email, sex, age);
    ui->tableWidgetClient->clear();
    populateClientTable();
    ui->tabWidget->setCurrentIndex(2);

    ui->inputClientfname->clear();
    ui->inputClientlname->clear();
    ui->inputClientphone->clear();
    ui->inputClientemail->clear();
    ui->inputClientAge->clear();
}

void MainInterface::on_tableWidgetClient_cellDoubleClicked(int row, int column){
    ui->stackedWidget->setCurrentWidget(ui->pageViewClient);
    QTableWidgetItem *cItem = ui->tableWidgetClient->item(row, 0);
    int cID = cItem->text().toInt();
    populateDetailedClient(cID);
}

void MainInterface::populateDetailedClient(int cID){
    ui->showClientID->setText(QString::number(cID));
    ui->showClientFname->setText(mainControl->getData().getClients().find(cID)->getFname());
    ui->showClientLname->setText(mainControl->getData().getClients().find(cID)->getLname());
    ui->showClientPhone->setText(mainControl->getData().getClients().find(cID)->getPhone());
    ui->showClientEmail->setText(mainControl->getData().getClients().find(cID)->getEmail());
    ui->showClientSex->setText(mainControl->getData().getClients().find(cID)->getSex());
    ui->showClientAge->setText(QString::number(mainControl->getData().getClients().find(cID)->getAge()));
}

void MainInterface::on_clientListButton_released(){
    ui->stackedWidget->setCurrentWidget(ui->pageStaff);
    ui->tabWidget->setCurrentIndex(2);
}
