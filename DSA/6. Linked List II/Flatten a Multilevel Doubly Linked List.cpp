/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution
{
public:
    void func(Node *head, Node *q)
    {

        if (!head)
            return;

        func(head->next, q);
        if (q && !head->next)
        {
            head->next = q;
            q->prev = head;
        }

        if (head->child)
        {
            Node *temp = head->next;
            func(head->child, temp);
            head->next = head->child;
            head->child->prev = head;
            head->child = NULL;
        }

        return;
    }

    Node *flatten(Node *head)
    {

        if (head)
            func(head, NULL);

        return head;
    }
};