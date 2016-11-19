#include "UserHandle.h"
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <QSqlError>
#include "DllManager.h"

UserHandle::UserHandle()
{

}

//判断用户是否已存在
bool UserHandle::hasRecordByAccount(const QString& account)
{
    //qDebug() << "account-->" << account;
    bool ret = false;
    DllManager* instance = DllManager::getInstance();
    instance->createConnect();
    QSqlQuery query;
    query.prepare("SELECT ACCOUNT FROM TB_USER WHERE account = :account");
    query.bindValue(":account", account);
    if(!query.exec())
        qDebug()<<query.lastError().text(); 
    ret = query.next();
    //qDebug() << ret;
    instance->distroyConnect();
    return ret;
}

//判断账号密码
bool UserHandle::judgeUser(const QString& qAccount,const QString& qPasswd)
{
    DllManager* instance = DllManager::getInstance();
    instance->createConnect();
    QSqlQuery query;
    query.prepare("SELECT PASSWD FROM TB_USER WHERE account = :account");
    query.bindValue(":account",qAccount);
    if(!query.exec())
        qDebug()<<query.lastError().text();
    query.next();
    QString pwd = query.value(0).toString();
    //qDebug() << pwd;
    if(pwd == qPasswd)
    {
        return true;
    }else
    {
        return false;
    }
}

//向数据库中插入新用户
bool UserHandle::insertUser(const User & user)
{
    DllManager* instance = DllManager::getInstance();
    bool ret = false;
    instance->createConnect();
    QSqlQuery query;
    query.prepare("INSERT INTO TB_USER(account, passwd) "
                  " VALUES (:account, :passwd)");
    query.bindValue(":account", user.getAccount());
    query.bindValue(":passwd", user.getPasswd());

    ret = query.exec();
    if(!ret){
        qDebug()<<query.lastError().text();
    }

    instance->distroyConnect();
    return ret;
}
