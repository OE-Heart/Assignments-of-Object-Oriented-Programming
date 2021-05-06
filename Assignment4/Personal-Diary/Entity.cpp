/*
 * @Author: Ou Yixin
 * @Date: 2021-05-04 20:26:17
 * @LastEditors: Ou Yixin
 * @LastEditTime: 2021-05-06 18:58:13
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

void loadEntity(vector<Entity>* diary)
{
    ifstream infile;
    infile.open(DataFile, ios::in);
    if (infile)
    {
        Entity entity_buf;
        vector<string> content_buf;
        string date_buf;
        string s;
        while (!infile.eof())
        {
            getline(infile, date_buf);
            entity_buf.setDate(date_buf);
            content_buf.clear();
            getline(infile, s);
            while (s != ".")
            {
                content_buf.push_back(s);
                getline(infile, s);
            }
            entity_buf.setContent(content_buf);
            (*diary).push_back(entity_buf);
        }
        infile.close();
    }
}

void updateEntity(vector<Entity>* diary)
{
    ofstream outfile;
    outfile.open(DataFile, ios::out);
    bool first = true;
    for (vector<Entity>::size_type i = 0; i < (*diary).size(); i++)
    {
        if (first) first = false;
        else outfile << endl;
        outfile << (*diary)[i].getDate() << endl;
        for (vector<string>::size_type j = 0; j < (*diary)[i].getContentSize(); j++)
        {
            outfile << (*diary)[i].getContent(j) << endl;
        }
        outfile << ".";
    }
    outfile.close();
}