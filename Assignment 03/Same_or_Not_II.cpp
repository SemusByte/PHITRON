#include <bits/stdc++.h>
using namespace std;

class mystack
{
public:
    list<int> v;

    void push(int val)
    {
        v.push_back(val);
    }

    void pop()
    {
        v.pop_back();
    }

    int top()
    {
        return v.back();
    }
};

class myqueue
{
public:
    list<int> v;

    void push(int val)
    {
        v.push_back(val);
    }

    void pop()
    {
        v.pop_front();
    }

    int front()
    {
        return v.front();
    }
};

int main()
{
    mystack st;
    myqueue q;

    int n, m;
    cin >> n >> m;

    // stack
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.push(x);
    }

    // queue
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }

    if (n != m)
        cout << "NO" << endl;
    else
    {
        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            if (st.top() != q.front())
            {
                flag = true;
            }
            st.pop();
            q.pop();
        }

        if (flag)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }

    return 0;
}