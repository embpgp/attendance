#include "DBControl.h"
#include <QDebug>
#include <stdio.h>
#include <QMessageBox>

/*****************************************************************/
/* DBControl class                                               */
/*****************************************************************/
QSqlDatabase *DBControl::_mainDB = NULL;
bool DBControl::Create()  // 创建 数据库
{
    if(_mainDB != NULL)
        return true;
    _mainDB = new QSqlDatabase;
    *_mainDB = QSqlDatabase::addDatabase("QSQLITE", "attendance");
    _mainDB->setDatabaseName("attendance.db");
    if(!_mainDB->open())
    {
        delete _mainDB;
        _mainDB = NULL;
        QSqlDatabase::removeDatabase("attendance");
        return false;
    }
    checkDatabase();
    return true;
}

void DBControl::Destroy()  // 删除 数据库
{
    if(_mainDB == NULL)
        return;
    _mainDB->close();
    delete _mainDB;
    _mainDB = NULL;
    QSqlDatabase::removeDatabase("attendance");
}

bool DBControl::checkTable(const QString &tblName)   // 检查 表是否 存在
{
    if(_mainDB == NULL)
        return false;
    QSqlQuery q(*_mainDB);
    QString sql = QString("SELECT COUNT(*) FROM sqlite_master WHERE [name] = '%1'").arg(tblName);
    if(!q.exec(sql))
        return false;
    if(!q.first())
    {
        q.finish();
        return false;
    }
    int count = q.value(0).toInt();
    q.finish();
    return (count > 0);
}

void DBControl::removeTable(const QString &tblName)  // 删除 表
{
    if(_mainDB == NULL)
        return;
    QSqlQuery q(*_mainDB);
    QString sql = QString("DROP TABLE [%1]").arg(tblName);
    q.exec(sql);
    q.finish();
}

bool DBControl::createTable(const QString &tblName, const QStringList &fieldList)  // 创建 表
{
    if(_mainDB == NULL)
        return false;
    if(fieldList.count() <= 0)
        return false;
    if(checkTable(tblName))
        return true;
    QSqlQuery q(*_mainDB);
    QString sql = QString("CREATE TABLE [%1] (").arg(tblName);
    QStringList::const_iterator i;
    for(i = fieldList.constBegin(); i != fieldList.constEnd(); ++i)
    {
        sql += (*i);
        sql += ",";
    }
    if(sql.at(sql.length() - 1) == ',')
        sql = sql.left(sql.length() - 1);
    else
        return false;
    sql += ")";
    bool ret = q.exec(sql);
    q.finish();
    return ret;
}

void DBControl::checkDatabase()  // 创建 表
{
    if(_mainDB == NULL)
        return;
    if(!checkTable("tbl_id"))
    {
        createTable("tbl_id", QStringList()
                    <<"[id] INTEGER  NOT NULL PRIMARY KEY AUTOINCREMENT"
                    <<"[cardid] TEXT  UNIQUE NOT NULL"
                    <<"[name] TEXT  NOT NULL"
                    <<"[gender] TEXT  NOT NULL"             //++++++++++++++++++++++++++
                    <<"[occupation] TEXT  NOT NULL"         //++++++++++++++++++++++++++
                    <<"[mailAddress] TEXT NOT NULL"
                    );
    }
    if(!checkTable("tbl_log"))
    {
        createTable("tbl_log", QStringList()
                    <<"[id] INTEGER  NOT NULL PRIMARY KEY AUTOINCREMENT"
                    <<"[date] TimeStamp NOT NULL DEFAULT (datetime('now','localtime'))"
                    <<"[cardid] TEXT  NOT NULL"
                    <<"[gender] TEXT  NOT NULL"           //++++++++++++++++++++++++++
                    <<"[occupation] TEXT  NOT NULL"       //++++++++++++++++++++++++++
                    <<"[arriveLate] TEXT  NOT NULL"
                    <<"[leaveEarly] TEXT  NOT NULL"

                    );
    }
    if(!checkTable("tbl_setTime"))
    {
        createTable("tbl_setTime", QStringList()
                    <<"[id] INTEGER  NOT NULL PRIMARY KEY AUTOINCREMENT"
                    <<"[startTime] TIMESTAMP DEFAULT CURRENT_TIMESTAMP NOT NULL"
                    <<"[endTime] TEXT  NOT NULL"

                    );
    }
    if(!checkTable("tbl_login"))     //管理员表
    {
        createTable("tbl_login", QStringList()
                    <<"[id] INTEGER  NOT NULL PRIMARY KEY AUTOINCREMENT"
                    <<"[username] TEXT UNIQUE NOT NULL "
                    <<"[password] TEXT  NOT NULL"
                    );
    }
    if(!checkTable("tbl_attendance"))     //出勤表
    {
        createTable("tbl_attendance", QStringList()
                    <<"[id] INTEGER  NOT NULL PRIMARY KEY AUTOINCREMENT"
                    <<"[cardid] TEXT UNIQUE NOT NULL "
                    <<"[name] TEXT  NOT NULL"
                    <<"[arriveLateTimes] INT  NOT NULL"
                    <<"[leaveearlyTimes] INT NOT NULL"
                    <<"[absenceTimes] INT NOT NULL"
                    );
    }
}



/*****************************************************************/
/* DBCard class                                                  */
/*****************************************************************/
DBCard::DBCard(const QString &cardid)  // 根据Card ID 查询 tbl_id 表中的记录
    : q(NULL)
{
    QString sql = QString("SELECT [id],[cardid],[name],[gender],[occupation], [mailAddress] FROM [tbl_id]");   //++++++++++++++++++++++++++
    if(!cardid.isEmpty())
        sql += QString(" WHERE [cardid] = '%1'").arg(cardid);
    q = new QSqlQuery(*_mainDB);
    q->exec(sql);
    if(!q->isActive())
    {
        delete q;
        q = NULL;
    }
    else
        q->first();
}

DBCard::~DBCard()
{
    if(q)
        delete q;
}

bool DBCard::first()
{
    if(q == NULL)
        return false;
    return q->first();
}

bool DBCard::next()
{
    if(q == NULL)
        return false;
    return q->next();
}



int DBCard::id() const   // 返回 q->value(0) 给 id()
{
    if(q == NULL)
        return -1;
    if(!q->isActive())
        return -1;
    if(!q->isValid())
        return -1;
    return q->value(0).toInt();
}

QString DBCard::cardid() const   // 返回 q->value(1) 给 cardid()
{
    if(q == NULL)
        return QString();
    if(!q->isActive())
        return QString();
    if(!q->isValid())
        return QString();
    return q->value(1).toString();
}

QString DBCard::name() const   // 返回 q->value(2) 给 name()
{
    if(q == NULL)
        return QString();
    if(!q->isActive())
        return QString();
    if(!q->isValid())
        return QString();
    return q->value(2).toString();
}

QString DBCard::gender() const  //++++++++++++++++++++++++++++
{
    if(q == NULL)
        return QString();
    if(!q->isActive())
        return QString();
    if(!q->isValid())
        return QString();
    return q->value(3).toString();
}

QString DBCard::occupation() const   //++++++++++++++++++++++++
{
    if(q == NULL)
        return QString();
    if(!q->isActive())
        return QString();
    if(!q->isValid())
        return QString();
    return q->value(4).toString();
}

QString DBCard::mailAddress() const   //++++++++++++++++++++++++
{
    if(q == NULL)
        return QString();
    if(!q->isActive())
        return QString();
    if(!q->isValid())
        return QString();
    return q->value(5).toString();
}



QString DBCard::findName(const QString &cardid)   // 根据 Card ID 查找 Name
{
    QString sql = QString("SELECT [name] FROM [tbl_id] WHERE [cardid] = '%1'").arg(cardid);
    QSqlQuery q(*_mainDB);
    q.exec(sql);
    if(!q.isActive())
        return QString();
    if(!q.first())
        return QString();
    QString ret = q.value(0).toString();
    q.finish();
    return ret;
}

int DBCard::findId(const QString &cardid)   // 根据 Card ID 查找 id      +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
{
    QString sql = QString("SELECT [id] FROM [tbl_id] WHERE [cardid] = '%1'").arg(cardid);
    QSqlQuery q(*_mainDB);
    q.exec(sql);
    if(!q.isActive())
        return 0;
    if(!q.first())
        return 0;
    int ret = q.value(0).toInt();
    q.finish();
    return ret;
}

QString DBCard::findCard(const QString &name)   // 根据 Name 查找 Card ID
{
    QString sql = QString("SELECT [cardid] FROM [tbl_id] WHERE [name] = '%1'").arg(name);
    QSqlQuery q(*_mainDB);
    q.exec(sql);
    if(!q.isActive())
        return QString();
    if(!q.first())
        return QString();
    QString ret = q.value(0).toString();
    q.finish();
    return ret;
}

QString DBCard::findGender(const QString &cardid)  //+++++++++++++++++++++++++
{
    QString sql = QString("SELECT [gender] FROM [tbl_id] WHERE [cardid] = '%1'").arg(cardid);
    QSqlQuery q(*_mainDB);
    q.exec(sql);
    if(!q.isActive())
        return QString();
    if(!q.first())
        return QString();
    QString ret = q.value(0).toString();
    q.finish();
    return ret;
}

QString DBCard::findOccupation(const QString &cardid)  //+++++++++++++++++++++++++++++
{
    QString sql = QString("SELECT [occupation] FROM [tbl_id] WHERE [cardid] = '%1'").arg(cardid);
    QSqlQuery q(*_mainDB);
    q.exec(sql);
    if(!q.isActive())
        return QString();
    if(!q.first())
        return QString();
    QString ret = q.value(0).toString();
    q.finish();
    return ret;
}

QString DBCard::findMailAddress(const QString &cardid)
{
    QString sql = QString("SELECT [mailAddress] FROM [tbl_id] WHERE [cardid] = '%1'").arg(cardid);
    QSqlQuery q(*_mainDB);
    q.exec(sql);
    if(!q.isActive())
        return QString();
    if(!q.first())
        return QString();
    QString ret = q.value(0).toString();
    q.finish();
    return ret;
}



bool DBCard::addCard(const QString &cardid, const QString &name ,const QString &gender, const QString &occupation, const QString &mailAddress)   //添加卡, 插入 Card ID 、 Name 至 tbl_id
{
    if(findName(cardid).isEmpty() && findCard(name).isEmpty())
    {
        QString sql = QString(
                    "INSERT INTO [tbl_id] ([cardid], [name], [gender], [occupation], [mailAddress]) VALUES ('%1', '%2', '%3', '%4', '%5')"
                    ).arg(cardid).arg(name).arg(gender).arg(occupation).arg(mailAddress);
        QSqlQuery q(*_mainDB);
         q.exec(sql);
        q.finish();

        return true;
    }
    else
    {
        return false;
    }
}

void DBCard::delCard(const QString &cardid)   // 删除 卡
{
    QString sql = QString(
            "DELETE FROM [tbl_id] WHERE [cardid] = '%1'").arg(cardid);
    QSqlQuery q(*_mainDB);
    q.exec(sql);
    q.finish();
}

bool DBCard::updateName(const QString &cardid, const QString &newname, const QString &gender, const QString &occuption, const QString &mailAddress)   //   更新 卡的 Name < 即 先删除 再添加卡 >
{
    if(!findCard(newname).isEmpty())
        return false;
    if(!findName(cardid).isEmpty())
        delCard(cardid);
    return addCard(cardid, newname, gender, occuption, mailAddress);
}



/*
bool DBCard::updateCardId(const QString &name, const QString &newcardid)   // 更新 卡的 Card ID < 同上 >
{
    if(!findName(newcardid).isEmpty())
        return false;
    QString c = findCard(name);
    if(!c.isEmpty())
        delCard(c);
    return addCard(newcardid, name);
}

bool DBCard::updateGender(const QString &cardid, const QString &newgender)    //++++++++++++++++++++++++++
{
    if(!findCard(newgender).isEmpty())
        return false;
    if(!findGender(cardid).isEmpty())
        delCard(cardid);
    return addCard(cardid, newgender);
}

bool DBCard::updateOccupation(const QString &cardid, const QString &newoccupation)     //++++++++++++++++++++++++++
{
    if(!findCard(newoccupation).isEmpty())
        return false;
    if(!findOccupation(cardid).isEmpty())
        delCard(cardid);
    return addCard(cardid, newoccupation);
}
*/


/*****************************************************************/
/* DBLog class                                                   */
/*****************************************************************/
DBLog::DBLog(const QString &cardid)   // 根据 Card ID 查找 tbl_log表中 相应的记录
    : q(NULL)
{
    QString sql = QString("SELECT [id], [date], [cardid], [gender], [occupation], [arriveLate], [leaveEarly], [arriveLateTimes] FROM [tbl_log]");  //++++++++++++++++++++++++++
    if(!cardid.isEmpty())
        sql += QString(" WHERE [cardid] = '%1'").arg(cardid);
    q = new QSqlQuery(*_mainDB);
    q->exec(sql);
    if(!q->isActive())
    {
        delete q;
        q = NULL;
    }
    q->first();

}

DBLog::~DBLog()
{
    if(q)
        delete q;
}

bool DBLog::first()
{
    if(q == NULL)
        return false;
    return q->first();
}

bool DBLog::next()
{
    if(q == NULL)
        return false;
    return q->next();
}



int DBLog::id() const   // 返回 q->value(0) 给 id()
{
    if(q == NULL)
        return -1;
    if(!q->isActive())
        return -1;
    if(!q->isValid())
        return -1;
    return q->value(0).toInt();
}

QDateTime DBLog::date() const // 返回 q->value(1) 给 date()
{
    if(q == NULL)
        return QDateTime();
    if(!q->isActive())
        return QDateTime();
    if(!q->isValid())
        return QDateTime();
    return q->value(1).toDateTime();
}

QString DBLog::cardid() const  // 返回 q->value(2) 给 cardid()
{
    if(q == NULL)
        return QString();
    if(!q->isActive())
        return QString();
    if(!q->isValid())
        return QString();
    return q->value(2).toString();
}

QString DBLog::gender() const     //+++++++++++++++++++++++++++++++
{
    if(q == NULL)
        return QString();
    if(!q->isActive())
        return QString();
    if(!q->isValid())
        return QString();
    return q->value(3).toString();
}

QString DBLog::occupation() const  //+++++++++++++++++++++++++++++++
{
    if(q == NULL)
        return QString();
    if(!q->isActive())
        return QString();
    if(!q->isValid())
        return QString();
    return q->value(4).toString();
}

QString DBLog::arriveLate() const
{
    if(q == NULL)
        return QString();
    if(!q->isActive())
        return QString();
    if(!q->isValid())
        return QString();
    return q->value(5).toString();
}

QString DBLog::leaveEarly() const
{
    if(q == NULL)
        return QString();
    if(!q->isActive())
        return QString();
    if(!q->isValid())
        return QString();
    return q->value(6).toString();
}


QString DBLog::findArriveLate(const QString &cardid)
{
    QString sql = QString("SELECT [arriveLate] FROM [tbl_log] WHERE [cardid] = '%1'").arg(cardid);
    QSqlQuery q(*_mainDB);
    q.exec(sql);
    if(!q.isActive())
        return QString();
    if(!q.first())
        return QString();
    QString ret = q.value(0).toString();
    q.finish();
    return ret;
}

QString DBLog::findLeaveEarly(const QString &cardid)
{
    QString sql = QString("SELECT [leaveEarly] FROM [tbl_log] WHERE [cardid] = '%1'").arg(cardid);
    QSqlQuery q(*_mainDB);
    q.exec(sql);
    if(!q.isActive())
        return QString();
    if(!q.first())
        return QString();
    QString ret = q.value(0).toString();
    q.finish();
    return ret;
}

QString DBLog::findArriveLateTimes(const QString &cardid)
{
    QString sql = QString("SELECT MAX([arriveLateTimes]) FROM [tbl_log] WHERE [cardid] = '%1'").arg(cardid);
    QSqlQuery q(*_mainDB);
    q.exec(sql);
    if(!q.isActive())
        return QString();
    if(!q.first())
        return QString();
    QString ret = q.value(0).toString();
    q.finish();
    return ret;
}

bool DBLog::isFirstLog(const QString &cardid) //判断是否第一次刷卡
{
    QDateTime d = QDateTime::currentDateTime();
    char sql[512];
    sprintf(sql, "SELECT COUNT(*) from [tbl_log] where  date between '%d-%02d-%02d' and '%d-%02d-%02d'",
            d.date().year(), d.date().month(), d.date().day(),
            d.date().year(), d.date().month(), d.date().day()+1
           );
    QString add = QString(" and cardid = '%1'").arg(cardid);
    QByteArray ba = add.toLatin1();
    strcat(sql,ba.data());

    qDebug()<<"sql ......."<<sql;
    QSqlQuery q(*_mainDB);
    q.exec(sql);
    if(!q.isActive())
        return bool();
    if(!q.first())
        return bool();
    int ret = q.value(0).toInt();

    q.finish();
    if(0 == ret)
        return true;
    else
        return false;

}






bool DBLog::addLog(const QString &cardid, const QString &gender, const QString &occupation, QString &arriveLate, QString &leaveEarly)   // 添加 记录 至 tbl_log
{
    QString sql = QString(
                "INSERT INTO [tbl_log] ([cardid],[gender],[occupation],[arriveLate],[leaveEarly]) VALUES ('%1','%2','%3','%4','%5')"
            ).arg(cardid).arg(gender).arg(occupation).arg(arriveLate).arg(leaveEarly);
    QSqlQuery q(*_mainDB);
    bool ret = q.exec(sql);
    q.finish();
    return ret;
}

void DBLog::delLog(int id)  // 根据 ID 删除 tbl_log 中的相应记录
{
    QString sql = QString(
            "DELETE FROM [tbl_log] WHERE [id] = %1").arg(id);
    QSqlQuery q(*_mainDB);
    q.exec(sql);
    q.finish();
}

void DBLog::delLog(const QString &cardid)
{
    QString sql = QString(
            "DELETE FROM [tbl_log] WHERE [cardid] = %1").arg(cardid);
    QSqlQuery q(*_mainDB);
    q.exec(sql);
    q.finish();
    qDebug()<<"Delete Old Already !!!!!!!!!!!!!!!!!!!!!!!!";
}

void DBLog::delOldLog(const QDateTime &d)  // 删除时间点前的 tab_log 记录
{
    char sql[512];
    sprintf(sql, "DELETE FROM [tbl_log] WHERE [date] < '%d-%02d-%02d %02d:%02d:%02d'",
            d.date().year(), d.date().month(), d.date().day(),
            d.time().hour(), d.time().minute(), d.time().second());
    QSqlQuery q(*_mainDB);
    q.exec(sql);
    q.finish();
}

void DBLog::delNewLog(const QDateTime &d)  // 删除时间点后的 tab_log 记录
{
    char sql[512];
    sprintf(sql, "DELETE FROM [tbl_log] WHERE [date] > '%d-%02d-%02d %02d:%02d:%02d'",
            d.date().year(), d.date().month(), d.date().day(),
            d.time().hour(), d.time().minute(), d.time().second());
    QSqlQuery q(*_mainDB);
    q.exec(sql);
    q.finish();
}

void DBLog::delLogNotIn(const QDateTime &dt1, const QDateTime &dt2)  //删除 tbl_log表中 当前时间点前和后 的记录, 只保留 当前时间点的 记录
{
    QDateTime d1(dt1), d2(dt2);
    if(d1 > d2)
    {
        QDateTime d = d1;
        d1 = d2;
        d2 = d1;
    }
    char sql[512];
    sprintf(sql, "DELETE FROM [tbl_log] WHERE [date] < '%d-%02d-%02d %02d:%02d:%02d' OR [date] > '%d-%02d-%02d %02d:%02d:%02d'",
            d1.date().year(), d1.date().month(), d1.date().day(),
            d1.time().hour(), d1.time().minute(), d1.time().second(),
            d2.date().year(), d2.date().month(), d2.date().day(),
            d2.time().hour(), d2.time().minute(), d2.time().second());
    QSqlQuery q(*_mainDB);
    q.exec(sql);
    q.finish();
}

void DBLog::delLogBetween(const QDateTime &dt1, const QDateTime &dt2)  // 删除 tbl_log表中 当前时间点的 记录
{
    QDateTime d1(dt1), d2(dt2);
    if(d1 > d2)
    {
        QDateTime d = d1;
        d1 = d2;
        d2 = d1;
    }
    char sql[512];
    sprintf(sql, "DELETE FROM [tbl_log] WHERE [date] >= '%d-%02d-%02d %02d:%02d:%02d' AND [date] <= '%d-%02d-%02d %02d:%02d:%02d'",
            d1.date().year(), d1.date().month(), d1.date().day(),
            d1.time().hour(), d1.time().minute(), d1.time().second(),
            d2.date().year(), d2.date().month(), d2.date().day(),
            d2.time().hour(), d2.time().minute(), d2.time().second());
    QSqlQuery q(*_mainDB);
    q.exec(sql);
    q.finish();
}



int DBLog::findlogtimestoday(const QString &cardid)
{
    QDateTime d = QDateTime::currentDateTime();
    char sql[512];
    sprintf(sql, "SELECT COUNT(*) from [tbl_log] where  date between '%d-%02d-%02d' and '%d-%02d-%02d'",
            d.date().year(), d.date().month(), d.date().day(),
            d.date().year(), d.date().month(), d.date().day()+1
           );
    QString add = QString(" and cardid = '%1'").arg(cardid);
    QByteArray ba = add.toLatin1();
    strcat(sql,ba.data());

    qDebug()<<"sql ......."<<sql;
    QSqlQuery q(*_mainDB);
    if(!q.exec(sql))
    {
        qDebug()<<"q.exec ....";
    }
    if(!q.isActive())
    {

        return -1;
    }
    if(!q.first())
    {

        return -1;
    }
    int ret = q.value(0).toInt();
    qDebug()<<"ret ..."<<ret;
    q.finish();
    return ret;

}


/*****************************************************************/
/* DBLogin class                                                   */
/*****************************************************************/
DBLogin::DBLogin(const QString &username)
    : q(NULL)
{
    QString sql = QString("SELECT [id], [username], [password] FROM [tbl_login]");  //++++++++++++++++++++++++++
    if(!username.isEmpty())
        sql += QString(" WHERE [username] = '%1'").arg(username);
    q = new QSqlQuery(*_mainDB);
    q->exec(sql);
    if(!q->isActive())
    {
        delete q;
        q = NULL;
        qDebug()<<"q is NULL";
    }
    q->first();

}

DBLogin::~DBLogin()
{
    if(q)
        delete q;
}


bool DBLogin::first()
{
    if(q == NULL)
        return false;
    return q->first();
}

bool DBLogin::next()
{
    if(q == NULL)
        return false;
    return q->next();
}


QString DBLogin::username() const
{
    if(q == NULL)
        return QString();
    if(!q->isActive())
        return QString();
    if(!q->isValid())
        return QString();
    return q->value(1).toString();
}

QString DBLogin::password() const
{
    if(q == NULL)
        return QString();
    if(!q->isActive())
        return QString();
    if(!q->isValid())
        return QString();
    return q->value(2).toString();
}

void DBLogin::addUsername(const QString &username, const QString &password)
{
    QString sql = QString(
                "INSERT INTO [tbl_login] ([username],[password]) VALUES ('%1','%2')"
            ).arg(username).arg(password);
    QSqlQuery q(*_mainDB);
    q.exec(sql);
    q.finish();
}

void DBLogin::delUsername(const QString &username)
{
    QString sql = QString(
            "DELETE FROM [tbl_login] WHERE [username] = '%1'").arg(username);
    QSqlQuery q(*_mainDB);
    q.exec(sql);
    q.finish();
}

void DBLogin::updateUsername(const QString &username, const QString &password)
{
    QString sql = QString(
                "UPDATE [tbl_login] SET [password] ='%1' WHERE [username] = '%2'").arg(password).arg(username);
    QSqlQuery q(*_mainDB);
    q.exec(sql);
    q.finish();

}

QString DBLogin::findPassword(const QString &username)
{
    QString sql = QString("SELECT [password] FROM [tbl_login] WHERE [username] = '%1'").arg(username);
    QSqlQuery q(*_mainDB);
    if(!q.exec(sql))
    {
        qDebug()<<"q.exec ....";
    }
    if(!q.isActive())
    {

        return QString();
    }
    if(!q.first())
    {

        return QString();
    }
    QString ret = q.value(0).toString();//select 查询的时候只列举了一列，所以索引直接是0
    q.finish();
    return ret;
}





/*****************************************************************/
/* DBAttendance class                                                  */
/*****************************************************************/
DBAttendance::DBAttendance(const QString &cardid)  // 根据Card ID 查询 tbl_attendance 表中的记录
    : q(NULL)
{
    QString sql = QString("SELECT [id],[cardid],[name],[arriveLaterTimes],[leaveearlyTimes], [absenceTimes] FROM [tbl_attendance]");   //++++++++++++++++++++++++++
    if(!cardid.isEmpty())
        sql += QString(" WHERE [cardid] = '%1'").arg(cardid);
    q = new QSqlQuery(*_mainDB);
    q->exec(sql);
    if(!q->isActive())
    {
        delete q;
        q = NULL;
    }
    else
        q->first();
}

DBAttendance::~DBAttendance()
{
    if(q)
        delete q;
}

bool DBAttendance::first()
{
    if(q == NULL)
        return false;
    return q->first();
}

bool DBAttendance::next()
{
    if(q == NULL)
        return false;
    return q->next();
}

QString DBAttendance::cardid() const   // 返回 q->value(1) 给 cardid()
{
    if(q == NULL)
        return QString();
    if(!q->isActive())
        return QString();
    if(!q->isValid())
        return QString();
    return q->value(1).toString();
}

QString DBAttendance::name() const   // 返回 q->value(2) 给 name()
{
    if(q == NULL)
        return QString();
    if(!q->isActive())
        return QString();
    if(!q->isValid())
        return QString();
    return q->value(2).toString();
}

int DBAttendance::arriveLaterTimes() const   // 返回 q->value(3) 给 arriveLaterTimes()
{
    if(q == NULL)
        return -1;
    if(!q->isActive())
        return -1;
    if(!q->isValid())
        return -1;
    return q->value(3).toInt();
}

int DBAttendance::leaveearlyTimes() const   // 返回 q->value(4) 给 leaveearlyTimes()
{
    if(q == NULL)
        return -1;
    if(!q->isActive())
        return -1;
    if(!q->isValid())
        return -1;
    return q->value(4).toInt();
}

int DBAttendance::absenceTimes() const   // 返回 q->value(5) 给 absenceTimes()
{
    if(q == NULL)
        return -1;
    if(!q->isActive())
        return -1;
    if(!q->isValid())
        return -1;
    return q->value(5).toInt();
}


void DBAttendance::addlog(const QString &cardid, const QString &name, int arriveLaterTimes, int leaveearlyTimes, int absenceTimes)
{
    QString sql = QString(
                "INSERT INTO [tbl_attendance] ([cardid],[name],[arriveLaterTimes],[leaveearlyTimes],[leaveEarly],[absenceTimes]) VALUES ('%1','%2','%3','%4','%5')"
            ).arg(cardid).arg(name).arg(arriveLaterTimes).arg(leaveearlyTimes).arg(absenceTimes);
    QSqlQuery q(*_mainDB);
    q.exec(sql);
    q.finish();

}

void DBAttendance::updatelog(const QString &cardid, const QString &name, int arriveLaterTimes, int leaveearlyTimes, int absenceTimes)
{
    QString sql = QString(
                "UPDATE [tbl_attendance] SET [name] ='%1' [arriveLaterTimes]='%2' [leaveearlyTimes]='%3' [absenceTimes] = '4' WHERE [cardid] = '%5'").arg(name).arg(arriveLaterTimes).arg(leaveearlyTimes).arg(absenceTimes).arg(cardid);
    QSqlQuery q(*_mainDB);
    q.exec(sql);
    q.finish();
}


void DBAttendance::updatelogwitharrtimes(const QString &cardid, int arriveLaterTimes)
{
    QString sql = QString(
               "UPDATE [tbl_attendance] SET [arriveLaterTimes]='%1'  WHERE [cardid] = '%2'").arg(arriveLaterTimes).arg(cardid);
    QSqlQuery q(*_mainDB);
    q.exec(sql);
    q.finish();
}

void DBAttendance::updatelogwithleatimes(const QString &cardid, int leaveearlyTimes)
{
    QString sql = QString(
               "UPDATE [tbl_attendance] SET [leaveearlyTimes]='%1'  WHERE [cardid] = '%2'").arg(leaveearlyTimes).arg(cardid);
    QSqlQuery q(*_mainDB);
    q.exec(sql);
    q.finish();
}

void DBAttendance::updatelogwithabstimes(const QString &cardid, int absenceTimes)
{
    QString sql = QString(
               "UPDATE [tbl_attendance] SET [absenceTimes]='%1'  WHERE [cardid] = '%2'").arg(absenceTimes).arg(cardid);
    QSqlQuery q(*_mainDB);
    q.exec(sql);
    q.finish();
}

int DBAttendance::findarrTimes(const QString &cardid)
{
    QString sql = QString("SELECT [arriveLaterTimes] FROM [tbl_attendance] WHERE [cardid] = '%1'").arg(cardid);
    QSqlQuery q(*_mainDB);
    if(!q.exec(sql))
    {
        qDebug()<<"q.exec ....";
    }
    if(!q.isActive())
    {

        return -1;
    }
    if(!q.first())
    {

        return -1;
    }
    int ret = q.value(0).toInt();
    q.finish();
    return ret;
}

int DBAttendance::findleaTimes(const QString &cardid)
{
    QString sql = QString("SELECT [leaveearlyTimes] FROM [tbl_attendance] WHERE [cardid] = '%1'").arg(cardid);
    QSqlQuery q(*_mainDB);
    if(!q.exec(sql))
    {
        qDebug()<<"q.exec ....";
    }
    if(!q.isActive())
    {

        return -1;
    }
    if(!q.first())
    {

        return -1;
    }
    int ret = q.value(0).toInt();
    q.finish();
    return ret;
}
int DBAttendance::findabsTimes(const QString &cardid)
{
    QString sql = QString("SELECT [absenceTimes] FROM [tbl_attendance] WHERE [cardid] = '%1'").arg(cardid);
    QSqlQuery q(*_mainDB);
    if(!q.exec(sql))
    {
        qDebug()<<"q.exec ....";
    }
    if(!q.isActive())
    {

        return -1;
    }
    if(!q.first())
    {

        return -1;
    }
    int ret = q.value(0).toInt();
    q.finish();
    return ret;
}
