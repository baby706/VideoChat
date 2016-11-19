#include "DllManager.h"
#include <QSqlError>
#include <QDebug>

DllManager* DllManager::instance = 0;

DllManager* DllManager::getInstance()
{
    if(instance == 0)
    {
        instance = new DllManager();
    }
    return instance;
}

DllManager::DllManager()
{
    dll = QSqlDatabase::addDatabase("QSQLITE");
}

bool DllManager::createConnect()
{
    dll.setDatabaseName("User.dll");
    if(!dll.open()){
            qDebug()<<dll.lastError().text();
            return false;
    }
    return true;
}

void DllManager::distroyConnect()
{
    dll.close();
    dll.removeDatabase("User.db");
}
