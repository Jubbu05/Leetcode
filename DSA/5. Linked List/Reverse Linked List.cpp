// Iterative
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *curr = head;
        ListNode *prev = NULL;

        while (curr != NULL)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

// Recursive
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *newHead = reverseList(head->next);
        ListNode *headNext = head->next;
        headNext->next = head;
        head->next = NULL;
        return newHead;
    }
};