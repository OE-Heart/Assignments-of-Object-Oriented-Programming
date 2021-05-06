/*
 * @Author: Ou Yixin
 * @Date: 2021-05-04 20:24:35
 * @LastEditors: Ou Yixin
 * @LastEditTime: 2021-05-06 14:18:05
 * @Description: 
 * @FilePath: /Personal-Diary/pdremove.cpp
 */

#include "Entity.hpp"

int main(int argc, char *argv[])
{
    vector<Entity> diary;
    loadEntity(&diary);

    string date_buf = argv[1];

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
        for (vector<Entity>::size_type j = i; j < diary.size()-1; j++)
        {
            diary[j] = diary[j+1];
        }
        diary.pop_back();
    }
    else
    {
        cout << "Diary at date " << date_buf  << " doesn't exist.\n";
        return 0;
    }

    updateEntity(&diary);
    cout << "Diary at date " << date_buf  << " is removed successfully.\n";
    return 1;
}