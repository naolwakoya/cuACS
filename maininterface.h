#ifndef MAININTERFACE_H
#define MAININTERFACE_H

#include <QMainWindow>
#include "MainControl.h"
#include "DataModel/defs.h"

namespace Ui {
class MainInterface;
}

class MainInterface : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainInterface(QWidget *parent = 0);
    ~MainInterface();
    void createAnimalTable();
    void createClientTable();
    void populateAnimalTable();
    void populateDetailedAnimal(int);
    void populateDetailedClient(int);
    void populateClientTable();
private slots:
    void on_loginButton_released();
    void on_addButton_released();
    void on_tableWidget_cellDoubleClicked(int row, int column);
    void on_viewListButton_released();
    void on_addClientButton_released();
    void on_tableWidgetClient_cellDoubleClicked(int row, int column);
    void on_clientListButton_released();

private:
    Ui::MainInterface *ui;
    MainControl *mainControl;
};

#endif // MAININTERFACE_H
