#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int val;
    Node* next;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_tail(Node* &head, Node* &tail, int val)
{
    Node* newnode = new Node(val);
    if(head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}

void insert_at_head(Node* &head, Node* &tail, int val)
{
    Node* newnode = new Node(val);
    if(head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    newnode->next = head;
    head = newnode;
}

void delete_at_anypos(Node* &head, Node* &tail, int idx)
{
    if(idx == 0)
    {
        // 0 hole head delete kora lagbo
        Node* delnode = head;
        head = head->next;

        delete delnode;

        if(head == NULL)
        {
            tail = NULL;
        }
        return;
    }


    Node* tmp = head;

    for(int i = 0; i< idx-1; i++)
    {
        tmp = tmp->next;
    }

    Node* deleteNode = tmp->next;
    tmp->next = tmp->next->next;

    //check korbo je tail e cole gelo kina, tahole tail update
    if(deleteNode == tail)
    {
         tail = tmp;
    }

    delete deleteNode;
}

void print_linked_list(Node *head)
{
    while (head != NULL)
    {
        cout << head->val << " ";

        head = head->next;
    }
    cout<< endl;
}

int size_linked_list(Node *head)
{
    int cnt = 0;
    while (head != NULL)
    {
        cnt++;
        head = head->next;
    }

    return cnt;
}


int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    int q;
    cin>>q;
    for(int i = 0; i< q; i++)
    {
        int x, v;
        cin>>x>>v;

        if(x == 0)
        {
            insert_at_head(head,tail, v);
        }
        else if(x == 1)
        {
            insert_at_tail(head, tail, v);
        }
        else if(x == 2)
        {
            int sz = size_linked_list(head);

            if(v >= 0 && v < sz)
            {
             delete_at_anypos(head,tail, v);
            }
        }

      print_linked_list(head);
    }
    
    
    return 0;
}