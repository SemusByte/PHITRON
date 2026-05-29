#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        vector<int> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

    int flag = 0; 

    int prev = a[0];

    for(int i = 1; i< n; i++)
    {
        if(a[i] < prev)
        {
            flag = 1;
        }

        prev = a[i];
    }

    if(flag == 0)
    {
        cout <<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    }

    return 0;
}