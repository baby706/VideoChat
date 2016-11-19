#ifndef USERHANDLE_H
#define USERHANDLE_H

#include "User.h"

class UserHandle
{
public:
    UserHandle();
    bool insertUser(const User&);
    bool hasRecordByAccount(const QString& account);
    bool judgeUser(const QString &qAccount,const QString &qPasswd);
};

#endif // USERHANDLE_H
