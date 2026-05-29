#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int val;
    Node* prev;
    Node* next;

    Node(int val)
    {
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

void insert_at_tail(Node* &head, Node* &tail, int val)
{
    Node* newnode = new Node(val);
    if(tail == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    while(true)
    {
        int val;
        cin>>val;
        if(val == -1)break;
        insert_at_tail(head, tail, val);
    }

    vector<int> v;
    
    Node* tmp = head;
    while(tmp != NULL)
    {
        v.push_back(tmp->val);

        tmp = tmp->next;
    }

    bool flag = true;

    for(int i = 0, j = v.size()-1; i<j; i++,j--)
    {
        if(v[i] != v[j])
        {
            flag = false;
            break;
        }
    }

    if(flag) cout<<"YES"<<endl;
    else cout <<"NO"<<endl;
   
   return 0;
}