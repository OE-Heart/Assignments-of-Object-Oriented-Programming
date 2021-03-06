/*
 * @Author: Ou Yixin
 * @Date: 2021-05-04 20:23:59
 * @LastEditors: Ou Yixin
 * @LastEditTime: 2021-05-07 09:17:07
 * @Description: Main program of pdadd
 * @FilePath: /Personal-Diary/pdadd.cpp
 */

#include "Entity.hpp"

int main(int argc, char *argv[])
{
    vector<Entity> diary;
    loadEntity(&diary);

    string date_buf = argv[1];
    vector<string> content_buf;
    string s;
    getline(cin, s);
    while (s != ".")
    {
        content_buf.push_back(s);
        getline(cin, s);
    }
    
    Entity entity_buf;
    entity_buf.setDate(date_buf);
    entity_buf.setContent(content_buf);

    bool tag = false;
    vector<Entity>::size_type i;
    for (i = 0; i < diary.size(); i++)
    {
        if (diary[i].getDate() == date_buf) /*Check if the date is repetitive*/
        {
            tag = true;
            break;
        }
        else if (diary[i].getDate() > date_buf) break; /*Find the place to insert*/
    }

    if (tag) /*Replace the existing diary*/
    {
        diary[i] = entity_buf;
        cout << "Diary at date " << date_buf << " is replaced." << endl;
    }
    else /*Add diary in the order of date*/
    {
        diary.push_back(entity_buf);
        for(vector<Entity>::size_type j = diary.size()-1; j > i; j--)
        {
            diary[j] = diary[j-1];
        }
        diary[i] = entity_buf;
        cout << "Diary at date " << date_buf << " is added." << endl;
    }

    updateEntity(&diary);
}