#ifndef DBCONTROL_H
#define DBCONTROL_H
#include <QString>
#include <QStringList>
#include <QDateTime>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QVariant>

class DBControl
{
public:
    static bool Create();
    static void Destroy();


protected:
    static QSqlDatabase *_mainDB;
    static bool checkTable(const QString &tblName);
    static bool createTable(const QString &tblName, const QStringList &fieldList);
    static void removeTable(const QString &tblName);
    static void checkDatabase();
};

class DBCard : public DBControl
{
public:
    DBCard(const QString &cardid = "");
    virtual ~DBCard();

    bool first();
    bool next();
    int id() const;
    QString cardid() const;
    QString name() const;
    QString gender() const;   //++++++++++++++++++++++++++
    QString occupation() const;   //++++++++++++++++++++++++++
    QString mailAddress() const;

    static int findId(const QString &cardid);   //++++++++++++++++++++++++
    static QString findName(const QString &cardid);
    static QString findCard(const QString &name);
    static QString findGender(const QString &cardid);   //++++++++++++++++++++++++++
    static QString findOccupation(const QString &cardid);   //++++++++++++++++++++++++++
    static QString findMailAddress(const QString &cardid);
    static bool addCard(const QString &cardid, const QString &name, const QString &gender, const QString &occupation, const QString &mailAddress);
    static void delCard(const QString &cardid);
    static bool updateName(const QString &cardid, const QString &newname,const QString &gender, const QString &occuption, const QString &mailAddress);
    static bool updateCardId(const QString &name, const QString &newcardid);
    static bool updateGender(const QString &cardid, const QString &newgender);  //++++++++++++++++++++++++++
    static bool updateOccupation(const QString &cardid, const QString &newoccupation);  //++++++++++++++++++++++++++

protected:
    QSqlQuery *q;
};

class DBLog : public DBControl
{
public:

    QString startTime;
    QString endTime;
    DBLog(const QString &cardid = "");
    virtual ~DBLog();

    bool first();
    bool next();
    int id() const;
    QDateTime date() const;
    QString cardid() const;
    QString gender() const;       //++++++++++++++++++++++++++
    QString occupation() const;   //++++++++++++++++++++++++++
    QString arriveLate() const;
    QString leaveEarly() const;


    static bool addLog(const QString &cardid, const QString &gender, const QString &occupation, QString &arriveLate, QString &quitEarly);
    static void delLog(int id);
    static void delLog(const QString &cardid);
    static void delOldLog(const QDateTime &d);
    static void delNewLog(const QDateTime &d);
    static void delLogNotIn(const QDateTime &d1, const QDateTime &d2);
    static void delLogBetween(const QDateTime &d1, const QDateTime &d2);

    static QString findArriveLate(const QString &cardid);
    static QString findLeaveEarly(const QString &cardid);

    static bool isFirstLog(const QString &cardid);
    static int findlogtimestoday(const QString &cardid);


protected:
    QSqlQuery *q;
};


class DBLogin : public DBControl
{
public:
    DBLogin(const QString &username = "");
    virtual ~DBLogin();

    bool first();
    bool next();
    QString username()const;
    QString password()const;
    static void addUsername(const QString &username, const QString &password);
    static void delUsername(const QString &username);
    static void updateUsername(const QString &username,const QString &password);

    static QString findPassword(const QString &username);



protected:
    QSqlQuery *q;
};

class DBAttendance:public DBControl
{
public:
    DBAttendance(const QString &cardid = "");
    virtual ~DBAttendance();

    bool first();
    bool next();
    QString cardid()const;
    QString name()const;
    int arriveLaterTimes()const;
    int leaveearlyTimes()const;
    int absenceTimes()const;

    static void addlog(const QString &cardid, const QString &name,int arriveLaterTimes, int leaveearlyTimes, int absenceTimes);
    static void updatelog(const QString &cardid,const QString &name,int arriveLaterTimes, int leaveearlyTimes, int absenceTimes);
    static void updatelogwitharrtimes(const QString &cardid, int arriveLaterTimes);
    static void updatelogwithleatimes(const QString &cardid, int leaveearlyTimes);
    static void updatelogwithabstimes(const QString &cardid, int absenceTimes);

    static int findarrTimes(const QString &cardid);
    static int findleaTimes(const QString &cardid);
    static int findabsTimes(const QString &cardid);


protected:
    QSqlQuery *q;

};



class DBSettime:public DBControl
{
public:
    DBSettime();
    virtual ~DBSettime();

    bool first();
    bool next();

    QString starttime()const;
    QString splitetime()const;
    QString endtime()const;

    static void addtimeonly(const QString &starttime="00:00:00",const QString &splitetime="00:00:00", const QString &endtime="00:00:00");
    static bool updatatime(const QString &starttime,const QString &splitetime, const QString &endtime);


    static QString findstarttime();
    static QString findsplite();
    static QString findendtime();


protected:
    QSqlQuery *q;

};


#endif // DBCONTROL_H
