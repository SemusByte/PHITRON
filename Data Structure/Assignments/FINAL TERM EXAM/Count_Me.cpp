#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore();

    while (t--)
    {
        string s;
        getline(cin, s);

        stringstream ss(s);
        map<string, int> mp;

        string word;

        string ans;
        int mx = 0;

        while (ss >> word)
        {
            mp[word]++;

            if (mp[word] > mx)
            {
                mx = mp[word];
                ans = word;
            }
        }

        cout << ans << " " << mx << endl;
    }

    return 0;
}