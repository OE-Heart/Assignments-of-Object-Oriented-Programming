/*
 * @Author: Ou Yixin
 * @Date: 2021-05-04 20:08:00
 * @LastEditors: Ou Yixin
 * @LastEditTime: 2021-05-06 11:18:27
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
    vector<string> content;
    string date;
public:
    void setDate(string s);
    string getDate();
    void setContent(vector<string> content_buf);
    string getContent(vector<string>::size_type i);
    vector<string>::size_type getContentSize();
    //void loadEntity(ifstream infile, )
};