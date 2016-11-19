#ifndef LIVEROOMLIST_H
#define LIVEROOMLIST_H

#include <vector>
#include <QTcpSocket>
#include "OneLiveRoom.h"
using namespace std;

class LiveRoomList
{
public:
    static LiveRoomList* getInstance();

    void insertLiveRoomList(OneLiveRoom*);
    void removeLiveRoomList(OneLiveRoom*);
    vector <OneLiveRoom*> getAllRoom();

private:
    vector <OneLiveRoom*> liveRoomList;         //房间列表

    static LiveRoomList* instance;
    LiveRoomList();
};

#endif // LIVEROOMLIST_H
