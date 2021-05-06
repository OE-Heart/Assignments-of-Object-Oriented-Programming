/*
 * @Author: Ou Yixin
 * @Date: 2021-05-04 20:24:16
 * @LastEditors: Ou Yixin
 * @LastEditTime: 2021-05-06 19:47:46
 * @Description: 
 * @FilePath: /Personal-Diary/pdlist.cpp
 */

#include "Entity.hpp"

int main(int argc, char *argv[])
{
    vector<Entity> diary;
    loadEntity(&diary);

    if (argc == 1)
    {
        for (vector<Entity>::size_type i = 0; i < diary.size(); i++)
        {
            cout << diary[i].getDate() << endl;
            for (vector<string>::size_type j = 0; j < diary[i].getContentSize(); j++)
            {
                cout << diary[i].getContent(j) << endl;
            }
            cout << "." << endl;
        }
    }
    else if (argc == 3)
    {
        for (vector<Entity>::size_type i = 0; i < diary.size(); i++)
        {
            
            if (diary[i].getDate() < argv[1]) continue;
            if (diary[i].getDate() > argv[2]) break;
            cout << diary[i].getDate() << endl;
            for (vector<string>::size_type j = 0; j < diary[i].getContentSize(); j++)
            {
                cout << diary[i].getContent(j) << endl;
            }
            cout << "." << endl;
        }
    }
    else
    {
        cout << "Command line parameters are wrong." << endl;
    }

    updateEntity(&diary);
}