#include <bits/stdc++.h>
using namespace std;

void print_left(list<int> l)
{
    cout << "L -> ";

    for (int val : l)
    {
        cout << val << " ";
    }

    cout << endl;
}

void print_right(list<int> l)
{
    cout << "R -> ";

    list<int> temp = l;
    temp.reverse();

    for (int val : temp)
    {
        cout << val << " ";
    }

    cout << endl;
}

int main()
{
    list<int> l;

    int q;
    cin >> q;

    while (q--)
    {
        int x, v;
        cin >> x >> v;

        if (x == 0)
        {
            l.push_front(v);
        }

        else if (x == 1)
        {
            l.push_back(v);
        }

        else if (x == 2)
        {
            if (v < l.size())
            {
                auto it = l.begin();

                advance(it, v);

                l.erase(it);
            }
        }

        print_left(l);
        print_right(l);
    }

    return 0;
}