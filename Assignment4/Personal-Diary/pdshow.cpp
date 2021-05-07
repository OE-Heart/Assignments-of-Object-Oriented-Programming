/*
 * @Author: Ou Yixin
 * @Date: 2021-05-04 20:24:23
 * @LastEditors: Ou Yixin
 * @LastEditTime: 2021-05-07 09:18:42
 * @Description: Main program of pdshow
 * @FilePath: /Personal-Diary/pdshow.cpp
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
        if (diary[i].getDate() == date_buf) /*Find the place to show*/
        {
            tag = !tag;
            break;
        }
    }

    if (tag)
    {
        for (vector<string>::size_type j = 0; j < diary[i].getContentSize(); j++)
        {
            cout << diary[i].getContent(j) << endl;
        }
    }
    else /*Diary doesn't exist*/
    {
        cout << "Diary at date " << date_buf << " doesn't exist.\n";
        return -1;
    }

    updateEntity(&diary);
    return 0;
}