#include<bits/stdc++.h>
using namespace std;

int main()
{
     stack <int>st;
     queue <int>q;
     

     
     int n,m;
     cin>>n>>m;


    //stack
     for(int i = 0; i< n; i++)
     {
        int x;
        cin>>x;
        st.push(x);
     }
     
     //queue
    for(int i = 0; i< m; i++)
     {
        int x;
        cin>>x;
        q.push(x);
     }
    
     
     if(n!=m) cout<<"NO"<<endl;
     else
     {
        bool flag = false;
        for(int i = 0; i< n; i++)
        {
            if(st.top() != q.front())
            {
                flag = true;
            }
            st.pop();
            q.pop();
        }

        if(flag) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
     }

    return 0;
}