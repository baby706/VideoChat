#ifndef USER_H
#define USER_H

#include <QString>
class User
{
public:
    User(const QString& account, const QString& passwd);

    const QString& getAccount()const { return account; }
    const QString& getPasswd()const { return passwd; }

private:
    QString     account;
    QString     passwd;

};

#endif // USER_H
