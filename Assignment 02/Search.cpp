#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int val)
    {
        this->next = NULL;
        this->val = val;
    }
};

void insert_at_tail(Node *&head, Node *&tail, int val)
{
    Node *newnode = new Node(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }

    tail->next = newnode;
    tail = newnode;
}


int findidx(Node* head,int val)
{
    Node* tmp = head;

    int idx = 0;
    int flag = 0;

    while(tmp != NULL)
    {
       idx++;
       if(tmp->val == val)
       {
          flag = 1;
          break;
       }

       tmp = tmp->next;
    }

    if(flag == 0) return -1;
    else return idx-1;
}

int main()
{

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        Node *head = NULL;
        Node *tail = NULL;

        while (true)
        {
            int val;
            cin >> val;
            if (val == -1)
                break;

            insert_at_tail(head, tail, val);
        }

        int v;
        cin>>v;
        int index = findidx(head, v);

        cout << index<< endl;

    }

    return 0;
}