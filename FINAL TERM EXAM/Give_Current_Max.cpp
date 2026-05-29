#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Student
{
public:
    string name;
    int roll;
    int marks;
};

class Compare
{
public:
    bool operator()(Student a, Student b)
    {
        if (a.marks == b.marks)
            return a.roll > b.roll;

        return a.marks < b.marks;
    }
};

int main()
{
    int N;
    cin >> N;

    priority_queue<Student, vector<Student>, Compare> pq;

    for (int i = 0; i < N; i++)
    {
        Student s;
        cin >> s.name >> s.roll >> s.marks;
        pq.push(s);
    }

    int Q;
    cin >> Q;

    while (Q--)
    {
        int cmd;
        cin >> cmd;

        if (cmd == 0)
        {
            Student s;
            cin >> s.name >> s.roll >> s.marks;
            pq.push(s);
        }
        else if (cmd == 2)
        {
            if (!pq.empty())
                pq.pop();
        }

        if (pq.empty())
        {
            cout << "Empty" << endl;
        }
        else
        {
            Student s = pq.top();
            cout << s.name << " " << s.roll << " " << s.marks << endl;
        }
    }

    return 0;
}