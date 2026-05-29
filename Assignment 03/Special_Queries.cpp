#include<bits/stdc++.h>
using namespace std;

int main()
{
    int Q;
    cin >> Q;

    queue<string> q;

    while(Q--)
    {
        int cmd;
        cin >> cmd;

        if(cmd == 0)
        {
            string name;
            cin >> name;

            q.push(name);
        }
        else
        {
            if(q.empty())
            {
                cout << "Invalid\n";
            }
            else
            {
                cout << q.front() << endl;
                q.pop();
            }
        }
    }

    return 0;
}