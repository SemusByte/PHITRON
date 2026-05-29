#include<bits/stdc++.h>
using namespace std;

int main()
{
     int n;
     cin>> n;

     vector<int> a(n);

     for(int i = 0; i < n; i++)
     {
        cin>> a[i];
     }

     int flag = 0;

     for(int i =0 ; i< n; i++)
     {
        auto it = find(a.begin()+i+1,a.end(),a[i]);

        if(it != a.end())
        {
            flag = 1;
            break;
        }
     }

     if(flag == 1) cout << "YES"<< endl;
     else cout << "NO"<< endl;

    return 0;
}