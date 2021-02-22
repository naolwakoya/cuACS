#ifndef CLIENT_H
#define CLIENT_H

#include <QString>

class Client{
public:
    Client(int, QString, QString, QString, QString, QString, int);
    int     getID();
    QString getFname();
    QString getLname();
    QString getPhone();
    QString getEmail();
    QString getSex();
    int     getAge();

private:
    int     clientID;
    QString fname;
    QString lname;
    QString phone;
    QString email;
    QString sex;
    int     age;
};
#endif // CLIENT_H
