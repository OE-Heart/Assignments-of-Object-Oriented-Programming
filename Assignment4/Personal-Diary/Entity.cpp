/*
 * @Author: Ou Yixin
 * @Date: 2021-05-04 20:26:17
 * @LastEditors: Ou Yixin
 * @LastEditTime: 2021-05-06 11:12:05
 * @Description: 
 * @FilePath: /Personal-Diary/Entity.cpp
 */

#include "Entity.hpp"

void Entity::setDate(string s)
{
    date = s;
}

string Entity::getDate()
{
    return date;
}

    
void Entity::setContent(vector<string> content_buf)
{
    content.clear();
    content = content_buf;
}

string Entity::getContent(vector<string>::size_type i)
{
    return content[i];
}

vector<string>::size_type Entity::getContentSize()
{
    return content.size();
}