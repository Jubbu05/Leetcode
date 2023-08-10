class Solution
{
public:
    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        ListNode *cur = new ListNode(0);
        ListNode *temp = cur;
        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val <= l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1 != NULL)
        {
            cur->next = l1;
        }
        if (l2 != NULL)
        {
            cur->next = l2;
        }
        return temp->next;
    }
    ListNode *sortList(ListNode *head)
    {
        // DIVIDE THE LL INTO TWO PART AND THEN CODE FOR MERGE LL TO FORM A SORTED LL

        if (head == NULL || head->next == NULL)
            return head;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = NULL;
        return merge(sortList(head), sortList(fast));
    }
};