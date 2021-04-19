/*
 * @Author: Ou Yixin
 * @Date: 2021-04-15 15:23:15
 * @LastEditors: Ou Yixin
 * @LastEditTime: 2021-04-18 19:43:44
 * @Description: 
 * @FilePath: /Adventure/Castle.hpp
 */

#ifndef CASTLE_HPP
#define CASTLE_HPP
 
#include <vector>
#include "Room.hpp"
using namespace std;
 
class Castle 
{
public:
    Castle();
    ~Castle();
    void welcome();
    Room *addRoom(string name);
    void play();
 
private:
    vector<Room*> rooms;
    bool foundPrincess = false; 
    string static oppoExit(string exitName);
    vector<string> static exitNames;
};
 
#endif