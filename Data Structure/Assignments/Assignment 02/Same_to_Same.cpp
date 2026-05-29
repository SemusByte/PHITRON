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

int size_linked_list(Node *head)
{
    int size = 0;
    Node *tmp = head;
    while (tmp != NULL)
    {
        size++;
        tmp = tmp->next;
    }

    return size;
}

int main()
{

    Node *head1 = NULL;
    Node *tail1 = NULL;

    while (true)
    {
        int val;
        cin >> val;
        if (val == -1)
            break;

        insert_at_tail(head1, tail1, val);
    }

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


     int sz1 = size_linked_list(head1);
     int sz = size_linked_list(head);

     if(sz1 != sz)
     {
        cout << "NO";
     }
     else
     {
         int flag = 0;

         while (head != NULL)
         {
            if(head->val != head1->val)
            {
                flag = 1;
                break;
            }
            head = head->next;
            head1 = head1->next;
         }

         if(flag == 0) cout << "YES";
         else cout << "NO";
     }

    

    return 0;
}