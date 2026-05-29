#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    multiset<int> s;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }

    int q;
    cin >> q;

    while (q--)
    {
        int cmd;
        cin >> cmd;

        if (cmd == 1)
        {
            if (s.empty())
                cout << "Empty" << endl;
            else
                cout << *s.begin() << endl;
        }

        else if (cmd == 2)
        {
            if (!s.empty())
            {
                s.erase(s.begin());
            }

            if (s.empty())
                cout << "Empty" << endl;
            else
                cout << *s.begin() << endl;
        }

        else if (cmd == 0)
        {
            int x;
            cin >> x;

            s.insert(x);

            cout << *s.begin() << endl;
        }
    }

    return 0;
}