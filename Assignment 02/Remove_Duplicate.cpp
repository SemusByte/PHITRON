#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
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

void print_linked_list(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";

        tmp = tmp->next;
    }
}


// prothom try kintu failed maybe pore korbo

// void deletedublicate(Node* &head, Node* &tail)
// {
//      Node* tmp = head;
//      Node* tmp1 = tmp->next;

//      while(tmp != NULL)
//      {
//         while(tmp1 != NULL)
//         {
//             if(tmp->val == tmp1->val)
//             {
//                 Node* delNode = tmp1;
//                 tmp->next = tmp->next->next;

//                 if(delNode == tail)
//                 {
//                     tail = tmp1;
//                 }
//                 delete delNode;
//             }

//             tmp1 = tmp1->next;
//         }

//         tmp = tmp->next;
//      }
// }

// frequency array maybe better
void deletedublicate(Node *&head, Node *&tail)
{
    int feq[1001] = {0};

    Node *curr = head;
    Node *prev = NULL;

    while (curr != NULL)
    {
        if (feq[curr->val] == 1)
        {
            prev->next = curr->next;

            if (curr == tail)
            {
                tail = prev;
            }

            Node *deleteNode = curr;

            curr = curr->next;

            delete deleteNode;
        }
        else
        {
            feq[curr->val]++;
            prev = curr;
            curr = curr->next;
        }
    }
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

    deletedublicate(head, tail);

    print_linked_list(head);

    return 0;
}