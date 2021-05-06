/*
 * @Author: Ou Yixin
 * @Date: 2021-05-04 20:08:00
 * @LastEditors: Ou Yixin
 * @LastEditTime: 2021-05-06 13:52:28
 * @Description: 
 * @FilePath: /Personal-Diary/Entity.hpp
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#define DataFile ".Diary"

class Entity
{
private:
    string date;
    vector<string> content;
public:
    void setDate(string s);
    string getDate();
    void setContent(vector<string> content_buf);
    string getContent(vector<string>::size_type i);
    vector<string>::size_type getContentSize();
};

void loadEntity(vector<Entity>* diary);
void updateEntity(vector<Entity>* diary);