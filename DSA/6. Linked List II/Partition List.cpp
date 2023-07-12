class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *list1 = new ListNode(0);
        ListNode *list2 = new ListNode(0);
        ListNode *l1 = list1; // for iterating list1
        ListNode *l2 = list2; // for iterating list2

        while (head)
        {
            // if value is less than x then add it to list1
            if (head->val < x)
            {
                l1->next = head;
                l1 = l1->next;
            }
            else
            {
                l2->next = head;
                l2 = l2->next;
            }

            head = head->next;
        }

        l1->next = list2->next; // connect list1 to list2
        l2->next = NULL;        // end list2

        return list1->next;
    }
};