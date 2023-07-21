#include <bits/stdc++.h>

LinkedListNode<int> *moveToFront(LinkedListNode<int> *head)
{
    if (head->next == NULL)
    {
        return head;
    }

    LinkedListNode<int> *curr = head;
    LinkedListNode<int> *prev = NULL;
    while (curr->next != NULL)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    curr->next = head;
    head = curr;
    return curr;
}