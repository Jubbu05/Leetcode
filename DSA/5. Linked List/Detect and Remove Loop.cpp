Node *removeLoop(Node *head)
{
    if (head == NULL)
    {
        return head;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast->next && fast)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == NULL)
        {
            return head;
        }
        if (slow == fast)
        {
            break;
        }
    }
    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    Node *temp = slow->next;

    while (temp->next != slow)
    {
        temp = temp->next;
    }
    temp->next = NULL;

    return head;
}