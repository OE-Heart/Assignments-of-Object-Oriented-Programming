#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#define Upperbound 150  //单科分数上限
#define BLANK 10  //对齐长度

class Course{
public:
    Course()
    {
        courseNum = 0;
    }

    string getCourseName(int ID)  //get the name of course according to ID
    {
        return courseName[ID];
    }

    int getCourseNum()  //get the number of courses
    {
        return courseNum;
    }

    void updateCourseNum(int n)
    {
        courseNum = n;
        courseName = new string[courseNum];
    }
    
    void updateCourseName(int i, string name)
    {
            courseName[i] = name;
    }

    int queryID(string name)  //query the ID of course
    {
        int i;
        for (int i = 0; i < courseNum; i++)
        {
            if (name == courseName[i]) return i;
        }
        return -1;
    }

private:
    string* courseName;
    int courseNum;
};

class Stu{
public:
    Stu()
    {
        takenCourseNum = 0;
    }

    double Average()  //caluculte the average score of all courses the student takes
    {
        int sum = 0;
        for (int i = 0; i < takenCourseNum; i++)
        {
            sum += courseScore[i];
        }
        return 1.0*sum/takenCourseNum;
    }

    int getScore(int ID)  //get score according to courseID
    {
        int i;
        for (i = 0; i < takenCourseNum; i++)
        {
            if (courseID[i] == ID) return courseScore[i];
        }
        return -1;
    }

    string getStuName()  //get student name
    {
        return stuName;
    }

    void updateStu(string name, int num, string* courseNames, int* scores, Course* list)
    {
        stuName = name;
        takenCourseNum = num;
        courseID = new int[num];
        courseScore = new int[num];
        for (int i = 0; i < num; i++)
        {
            courseID[i] = list->queryID(courseNames[i]);
            courseScore[i] = scores[i];
        }
    }

private:
    string stuName;
    int takenCourseNum;
    int* courseID;
    int* courseScore;
};

double averageCourseScore(Stu* stuList, int num, int ID)  //calculate the average score of a certain course of all students
{
    int sum = 0;
    int stuNum = 0;
    for (int i = 0; i < num; i++)
    {
        int score = stuList[i].getScore(ID);
        if (score != -1)
        {
            sum += score;
            stuNum++;
        }
    }
    return 1.0*sum/stuNum;
}

int maxCourseScore(Stu* stuList, int num, int ID)  //get the maximum score of a certain course in all students
{
    int max = 0;
    for (int i = 0; i < num; i++)
    {
        int score = stuList[i].getScore(ID);
        if (score > max)
        {
            max = score;
        }
    }
    return max;
}

int minCourseScore(Stu* stuList, int num, int ID)  //get the minimum score of a certain course in all students
{
    int min = Upperbound;
    for (int i = 0; i < num; i++)
    {
        int score = stuList[i].getScore(ID);
        if (score != -1 && score < min)
        {
            min = score;
        }
    }
    return min;
}

int main()
{
    int stuNum, courseNum;
    ifstream infile;   //输入流
    infile.open("in.txt", ios::in); 
    infile >> stuNum >> courseNum;

    Course courseList;
    courseList.updateCourseNum(courseNum);

    Stu* stuList = new Stu[stuNum];

    string courseName;
    for (int i = 0; i < courseNum; i++)
    {
        infile >> courseName;
        courseList.updateCourseName(i, courseName);
    }

    string stuName;
    int takenCourseNum;
    for (int i = 0; i < stuNum; i++)
    {
        infile >> stuName >> takenCourseNum;
        string* takenCourseName = new string[takenCourseNum];
        int* score = new int[takenCourseNum];
        for (int j = 0; j < takenCourseNum; j++)
        {
            infile >> takenCourseName[j] >> score[j];
        }
        stuList[i].updateStu(stuName, takenCourseNum, takenCourseName, score, &courseList);
    }

    cout << left;  //设置对齐方式为左对齐，默认为右对齐
    //cout << setfill(' ');  //设置空位置填充符号为空格，默认即为空格
    cout << setw(BLANK) << "no"  //设置宽度为BLANK，不足用填充符号补全
         << setw(BLANK) << "name";
    for (int i = 0; i < courseNum; i++)
    {
        cout << setw(BLANK) << courseList.getCourseName(i);
    }
    cout << setw(BLANK) << "average" << endl;

    for (int i = 0; i < stuNum; i++)
    {
        cout << setw(BLANK) << i+1
             << setw(BLANK) << stuList[i].getStuName();
        for (int j = 0; j < courseNum; j++)
        {
            int score = stuList[i].getScore(j);
            if (score != -1)
            {
                cout << setw(BLANK) << score;
            }
            else
            {
                cout << setw(BLANK) << "";
            }
        }
        cout << setw(BLANK) << stuList[i].Average() << endl;
    }

    cout << setw(BLANK) << ""
         << setw(BLANK) << "average";
    for (int i = 0; i < courseNum; i++)
    {
        cout << setw(BLANK) << averageCourseScore(stuList, stuNum, i);
    }
    cout << endl;

    cout << setw(BLANK) << ""
         << setw(BLANK) << "max";
    for (int i = 0; i < courseNum; i++)
    {
        cout << setw(BLANK) << maxCourseScore(stuList, stuNum, i);
    }
    cout << endl;

    cout << setw(BLANK) << ""
         << setw(BLANK) << "min";
    for (int i = 0; i < courseNum; i++)
    {
        cout << setw(BLANK) << minCourseScore(stuList, stuNum, i);
    }
    cout << endl;

    system("pause");

    return 0;
}