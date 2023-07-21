void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    Node *slow = head;
    Node *fast = head;

    while (fast->next != head && fast->next->next != head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    *head1_ref = head;
    *head2_ref = slow->next;

    slow->next = head; // first half to make circular again

    if (fast->next == head) // second half to make circular again
        fast->next = *head2_ref; // if even
    else
        fast->next->next = *head2_ref; // if odd
}