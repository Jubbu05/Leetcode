class Solution
{
public:
    Node *divide(int N, Node *head)
    {
        Node *even = new Node(0);
        Node *odd = new Node(0);
        Node *e = even;
        Node *o = odd;

        while (head)
        {
            if (head->data % 2 == 0)
            {
                e->next = head;
                e = e->next;
            }
            else
            {
                o->next = head;
                o = o->next;
            }
            head = head->next;
        }

        e->next = odd->next;
        o->next = NULL;

        return even->next;
    }
};