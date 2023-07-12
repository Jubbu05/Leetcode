class Solution
{
public:
    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = NULL, *next = NULL, *current = head;
        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
    void reorderList(ListNode *head)
    {
        // find middle of the LL
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        // reversing the second list
        ListNode *l2 = reverse(slow->next); // independent list second
        slow->next = NULL;
        ListNode *l1 = head;
        while (l2 != NULL) // merging the two lists l2 is always smaller or equal to l1
        {
            ListNode *first = l1->next;
            ListNode *second = l2->next;
            l1->next = l2;
            l2->next = first;
            l1 = first;
            l2 = second;
        }
    }
};