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
    int size;
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

    int sz = size_linked_list(head);

    if (sz <= 1)
    {
        cout << "0";
    }
    else
    {
        int max = head->val;

        Node *tmp1 = head;

        while (tmp1 != NULL)
        {
            if (tmp1->val > max)
            {
                max = tmp1->val;
            }

            tmp1 = tmp1->next;
        }

        int min = head->val;

        Node *tmp2 = head;

        while (tmp2 != NULL)
        {
            if (tmp2->val < min)
            {
                min = tmp2->val;
            }

            tmp2 = tmp2->next;
        }


        cout << max-min <<endl;
    }

    return 0;
}