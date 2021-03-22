#include <fstream>
#include <iomanip>
using namespace std;

#define Upperbound 100

string courseList[];
string stuList[];

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
    string name;
    int stuNum;
};

class Stu{
public:
    string getName()
    {
        return name;
    }
    double Average()
    {
        int sum = 0;

    }

private:
    string name;
    int courseNum;
};

int main()
{

}