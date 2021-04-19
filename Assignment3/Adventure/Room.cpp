/*
 * @Author: Ou Yixin
 * @Date: 2021-04-15 15:06:35
 * @LastEditors: Ou Yixin
 * @LastEditTime: 2021-04-18 20:06:15
 * @Description: 
 * @FilePath: /Adventure/Room.cpp
 */

#include <iostream>
#include <map>
#include <vector>
#include "Room.hpp"
using namespace std;

/**
 * @description: Constructor of Room
 * @param {string} roomName
 * @param {vector<string>} exitNames
 * @return {*}
 */
Room::Room(string roomName, vector<string> exitNames)
{
    name = roomName;

    if (name == "lobby")
    {
        princess = false;
        monster = false;
    }
    else
    {
        srand(time(NULL));
    
        if (rand()%5 == 0)
        {
            princess = true;
            monster = false;
        }
        else if (rand()%7 == 0)
        {
            princess = false;
            monster = true;
        }
        else
        {
            princess = false;
            monster = false;
        }
    }
 
    vector<string>::iterator it;
    for (it = exitNames.begin(); it != exitNames.end(); it++)
    {
        int exitNum = rand()%6;
        if (rand()%6 >= exitNum)
        {
            exitMap[*it] = NULL;
        }
    }
}

bool Room::hasPrincess()
{
    return princess;
}

bool Room::hasMonster()
{
    return monster;
}

/**
 * @description: Determine whether the exit exists 
 * @param {string} exitName
 * @return {*}
 */
bool Room::existExit(string exitName)
{
    if (exitMap.count(exitName)) return true;
    else return false;
}

/**
 * @description: Go through the exit to the next room
 * @param {string} exitName
 * @return {*}
 */
Room *Room::goExit(string exitName)
{
    return exitMap[exitName];
}
 
void Room::printInfo()
{
    cout << "Welcome to " << name << ". " << "There are " << exitMap.size() << " exits: ";
 
    map<string, Room*>::iterator it;
    for(it = exitMap.begin(); it != exitMap.end(); it++)
    {
        cout << (*it).first << " ";
    }
    cout << endl;
 
    cout << "Enter your command(\"go\" followed by the name of one exit (e.g. go west)): ";
}

/**
 * @description: Set the exit to associate with the room 
 * @param {string} exitName
 * @param {Room} *room
 * @return {*}
 */
void Room::setExit(string exitName, Room *room)
{
    exitMap[exitName] = room;
}