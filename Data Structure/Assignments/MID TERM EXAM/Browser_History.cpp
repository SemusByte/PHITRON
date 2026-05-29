#include<bits/stdc++.h>
using namespace std;

int main()
{
    list<string> browser;

    string s;

    while(cin >> s && s != "end")
    {
        browser.push_back(s);
    }

    int q;
    cin >> q;

    auto cur = browser.begin();

    while(q--)
    {
        string cmd;
        cin >> cmd;

        // visit
        if(cmd == "visit")
        {
            string address;
            cin >> address;

            bool found = false;

            for(auto it = browser.begin(); it != browser.end(); it++)
            {
                if(*it == address)
                {
                    cur = it;
                    cout << *cur << endl;
                    found = true;
                    break;
                }
            }

            if(found == false)
            {
                cout << "Not Available" << endl;
            }
        }

        // next
        else if(cmd == "next")
        {
            auto temp = cur;
            temp++;

            if(temp != browser.end())
            {
                cur++;
                cout << *cur << endl;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }

        // prev
        else if(cmd == "prev")
        {
            if(cur != browser.begin())
            {
                cur--;
                cout << *cur << endl;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
    }

    return 0;
}