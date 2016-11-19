#include "LiveRoomList.h"
#include <vector>
LiveRoomList* LiveRoomList::instance = 0;

LiveRoomList* LiveRoomList::getInstance()
{
    if(instance == 0)
    {
        instance = new LiveRoomList();
    }
    return instance;
}


LiveRoomList::LiveRoomList()
{

}


//添加房间列表中的房间
void LiveRoomList::insertLiveRoomList(OneLiveRoom* room)
{
    liveRoomList.push_back(room);
}

//删除房间列表中的房间
void LiveRoomList::removeLiveRoomList(OneLiveRoom* room)
{
    QString hostAccount = room->getHostAccount();
    vector<OneLiveRoom*>::iterator it;
    for(it = liveRoomList.begin();it != liveRoomList.end();it++)
    {
        QString account = (*it)->getHostAccount();
        if(account == hostAccount)
        {
            liveRoomList.erase(it);
            return;
        }
    }
}

//获取所有房间
vector <OneLiveRoom*> LiveRoomList::getAllRoom()
{
    return liveRoomList;
}
