#ifndef DLLMANAGER_H
#define DLLMANAGER_H

#include <QSqlDatabase>

class DllManager
{
public:
    static DllManager* getInstance();
    bool createConnect();
    void distroyConnect();

private:
    static DllManager* instance;
    QSqlDatabase dll;
    DllManager();
};

#endif // DLLMANAGER_H
