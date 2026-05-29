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

void print_left_to_right(Node* head)
{
    cout << "L -> ";

    Node* tmp = head;

    while(tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }

    cout << endl;
}

void print_right_to_left(Node* tail)
{
    cout << "R -> ";

    Node* tmp = tail;

    while(tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->prev;
    }

    cout << endl;
}

int size_list(Node* head)
{
    int cnt = 0;

    Node* tmp = head;

    while(tmp != NULL)
    {
        cnt++;
        tmp = tmp->next;
    }

    return cnt;
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
    head->prev = newnode;
    head = newnode;
}

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

void insert_at_any_position(Node* &head, Node* &tail, int idx, int val)
{
    int sz = size_list(head);

    // invalid
    if(idx > sz)
    {
        cout << "Invalid" << endl;
        return;
    }

    // head
    if(idx == 0)
    {
        insert_at_head(head, tail, val);

        print_left_to_right(head);
        print_right_to_left(tail);
        return;
    }

    // tail
    if(idx == sz)
    {
        insert_at_tail(head, tail, val);

        print_left_to_right(head);
        print_right_to_left(tail);
        return;
    }

    // middle
    Node* tmp = head;

    for(int i = 0; i < idx - 1; i++)
    {
        tmp = tmp->next;
    }

    Node* newnode = new Node(val);

    newnode->next = tmp->next;
    tmp->next->prev = newnode;

    newnode->prev = tmp;
    tmp->next = newnode;

    print_left_to_right(head);
    print_right_to_left(tail);
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    int q;
    cin >> q;

    while(q--)
    {
        int x, v;
        cin >> x >> v;

        insert_at_any_position(head, tail, x, v);
    }

    return 0;
}