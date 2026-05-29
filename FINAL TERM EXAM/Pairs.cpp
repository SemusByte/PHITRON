#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<string, int>> v;

    for (int i = 0; i < n; i++)
    {
        string s;
        int x;

        cin >> s >> x;

        v.push_back({s, x});
    }

    sort(v.begin(), v.end(), [](pair<string,int> a, pair<string,int> b)
    {
        if (a.first == b.first)
        {
            return a.second > b.second;
        }

        return a.first < b.first;
    });

    for (auto p : v)
    {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}