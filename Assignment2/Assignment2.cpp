#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#define Upperbound 150

class Course{
public:
    string getName()
    {
        return name;
    }
    int Max()
    {
        int max = 0;

        return max;
    }
    int Min()
    {
        int min = Upperbound;

        return min;
    }
    double Average()
    {
        int sum = 0;

    }

private:
    int courseNum;
    string* courseName;
    int *stuScore;
};

class Stu{
public:
    Stu(int n, string* s)
    {
        stuNum = n;
        stuName = new string[n];
        for (int i = 0; i < n; i++)
        {
            
        }
    }
    string getName()
    {
        return name;
    }
    double Average()
    {
        int sum = 0;

    }

private:
    int stuNum;
    string* stuName;
    int stuID;
    int courseNum;
};

int main()
{
    int stuNum, courseNum;
    ifstream infile;   //输入流
    infile.open("in.txt", ios::in); 
    infile >> stuNum >> courseNum;

    Course* courseList = new Course[courseNum];
    Stu* stuList = new Stu[stuNum];

    string courseName;
    for (int i = 0; i < courseNum; i++)
    {
        infile >> courseName;
        
    }


    return 0;
}