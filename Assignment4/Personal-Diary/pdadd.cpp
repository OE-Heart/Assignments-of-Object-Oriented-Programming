/*
 * @Author: Ou Yixin
 * @Date: 2021-05-04 20:23:59
 * @LastEditors: Ou Yixin
 * @LastEditTime: 2021-05-05 21:30:26
 * @Description: 
 * @FilePath: /Personal-Diary/pdadd.cpp
 */

#include "Entity.hpp"

int main(int argc, char *argv[])
{
    ifstream infile;
    infile.open(DataFile, ios::in);
    vector<Entity> diary;
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
        diary.push_back(entity_buf);
    }
    infile.close();

    date_buf = argv[1];
    entity_buf.setDate(date_buf);
    content_buf.clear();
    getline(cin, s);
    while (s != ".")
    {
        content_buf.push_back(s);
        getline(cin, s);
    }

    bool tag = false;
    vector<Entity>::size_type i;
    for (i = 0; i < diary.size(); i++)
    {
        if (diary[i].getDate() == date_buf)
        {
            tag = !tag;
            break;
        }
    }

    if (tag)
    {
        diary[i] = entity_buf;
    }
    else
    {
        diary.push_back(entity_buf);
    }

    ofstream outfile(DataFile);
    for (i = 0; i < diary.size(); i++)
    {
        outfile << diary[i].getDate() << endl;
        for (vector<string>::size_type j; i < diary[i].getContentSize(); i++)
        {
            outfile << diary[i].getContent(j) << endl;
        }
        outfile << "." << endl;
    }
    outfile.close();
}