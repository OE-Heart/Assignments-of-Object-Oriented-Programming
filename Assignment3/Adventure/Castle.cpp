/*
 * @Author: Ou Yixin
 * @Date: 2021-04-15 15:24:41
 * @LastEditors: Ou Yixin
 * @LastEditTime: 2021-04-18 20:05:05
 * @Description: 
 * @FilePath: /Adventure/Castle.cpp
 */

#include <iostream>
#include <vector>
#include "Room.hpp"
#include "Castle.hpp"
using namespace std;

Castle::Castle()
{
    Room* lobby = new Room("lobby", exitNames);
    rooms.push_back(lobby);
}
 
Castle::~Castle()
{
    while(!rooms.empty())
    {
        vector<Room*>::iterator p = rooms.end();
        rooms.pop_back();
        delete(*p);
    }
}

vector<string> Castle::exitNames = {"up", "down", "east", "west", "north", "south"};
 
void Castle::welcome()
{
    cout << "****************************************************************************************************" << endl
         << " Welcome to the castle, you have to explore in the castle with many levels and a lot of rooms." << endl
         << " Your task is to find a room where the princess is prisoned and take her leave the castle." << endl 
         << " There are many types of rooms, and each type of room has different types of exits." << endl
         << " Note that there's a monster in one of the rooms, which the exact location is not able to be aware." << endl
         << " But once the you meet a monster, the game is over." << endl
         << " Wish you good luck." << endl
         << "****************************************************************************************************" << endl;
} 

/**
 * @description: Add room to the castle
 * @param {string} name
 * @return {*}
 */
Room *Castle::addRoom(string name)
{
    Room *room = new Room(name, exitNames);
    rooms.push_back(room);
    return room;
}
 
void Castle::play()
{
    Castle::welcome();

    Room *nowRoom = rooms[0];
 
    string go, exitName, roomName;
 
    while(1)
    {
        nowRoom->printInfo();
        cin >> go >> exitName;
        if(!nowRoom->existExit(exitName))
        {
            cout << "Invalid command! You can only input \"go\" followed by the name of one exit to enter the room connected to that door" << endl;
            continue;
        }
 
        Room *newRoom = nowRoom->goExit(exitName);
        if(!newRoom)
        {
            roomName = "Room No." + to_string(rooms.size());
            newRoom = addRoom(roomName);
            nowRoom->setExit(exitName, newRoom);
            newRoom->setExit(oppoExit(exitName), nowRoom);
        }
        nowRoom = newRoom;
 
        if(nowRoom->hasMonster())
        {
            cout << "*********************************************" << endl
                 << " You enter a room with a monster! Game over!" << endl
                 << "*********************************************" << endl;
            return;
        }
 
        if(nowRoom->hasPrincess())
        {
            if(!foundPrincess){
                foundPrincess = true;
                cout << "**************************************************************************************" << endl
                     << " You find the princess! She is going to leave with you, find your way out the castle!" << endl
                     << "**************************************************************************************" << endl;
            }
        }
 
        if(foundPrincess && nowRoom == rooms[0])
        {
            cout << "********************************************************" << endl
                 << " Congratulations! You rescue the princess successfully!" << endl
                 << "********************************************************" << endl;
            return;
        }
    }
}
 
string Castle::oppoExit(string exitName)
{    
    vector<string>::iterator it;
    for(it = exitNames.begin(); it != exitNames.end(); it += 2) /*make sure that player can get back to the previous room*/
    {
        if((*it) == exitName) return *(it+1);
        if(*(it+1) == exitName) return *it;
    }

    return NULL;
}