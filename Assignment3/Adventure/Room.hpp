/*
 * @Author: Ou Yixin
 * @Date: 2021-04-15 15:07:39
 * @LastEditors: Ou Yixin
 * @LastEditTime: 2021-04-18 19:21:56
 * @Description: 
 * @FilePath: /Adventure/Room.hpp
 */

#ifndef ROOM_HPP
#define ROOM_HPP

#include <vector>
#include <map>
using namespace std;
 
class Room 
{
public:
    Room(string roomName, vector<string> exitNames); 
    bool hasPrincess();
    bool hasMonster();
    bool existExit(string exitName);
    Room *goExit(string exitName);
    void printInfo();
    void setExit(string exitName, Room*);
 
private:
    string name;
    map<string, Room*> exitMap; 
    bool princess;
    bool monster;
};

#endif