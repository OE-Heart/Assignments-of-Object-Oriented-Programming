#include <iostream>
#include <iomanip>
using namespace std;

#define foo 10
#define Upperbound 5

int main()
{
    string name[foo];
    int score1[foo], score2[foo], score3[foo];
    float average[foo];
    int min1 = Upperbound, min2 = Upperbound, min3 = Upperbound;
    int max1 = 0, max2 = 0, max3 = 0;
    int sum1 = 0, sum2 = 0, sum3 = 0;
    float average1, average2, average3;

    cout << "Please input the " << foo << " groups of data in the format of \"name score1 score2 score3\":"<< endl;

    for (int i = 0; i < foo; i++)
    {
        cin >> name[i] >> score1[i] >> score2[i] >> score3[i];
        average[i] = 1.0*(score1[i]+score2[i]+score3[i])/3;
        min1 = min(min1, score1[i]);
        min2 = min(min2, score2[i]);
        min3 = min(min3, score3[i]);
        max1 = max(max1, score1[i]);
        max2 = max(max2, score2[i]);
        max3 = max(max3, score3[i]);
        sum1 += score1[i];
        sum2 += score2[i];
        sum3 += score3[i];
    }

    average1 = 1.0*sum1/foo;
    average2 = 1.0*sum2/foo;
    average3 = 1.0*sum3/foo;

    cout << left;  //设置对齐方式为左对齐，默认为右对齐
    //cout << setfill(' ');  //设置空位置填充符号为空格，默认即为空格
    cout << setw(8) << "no"  //设置宽度为8，不足用填充符号补全
         << setw(8) << "name"
         << setw(8) << "score1"
         << setw(8) << "score2"
         << setw(8) << "score3"
         << setw(8) << "average" << endl;

    for (int i = 0; i < foo; i++)
    {
        cout << setw(8) << i+1
             << setw(8) << name[i]
             << setw(8) << score1[i]
             << setw(8) << score2[i]
             << setw(8) << score3[i]
             << setw(8) << average[i] << endl;
    }

    cout << setw(8) << ""
         << setw(8) << "average"
         << setw(8) << average1
         << setw(8) << average2
         << setw(8) << average3 << endl;

    cout << setw(8) << ""
         << setw(8) << "min"
         << setw(8) << min1
         << setw(8) << min2
         << setw(8) << min3 << endl;

    cout << setw(8) << ""
         << setw(8) << "max"
         << setw(8) << max1
         << setw(8) << max2
         << setw(8) << max3 << endl;

    return 0;
}