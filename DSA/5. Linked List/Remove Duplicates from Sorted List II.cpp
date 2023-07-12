class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL) return head;

        ListNode *pseudo = new ListNode(-1);
        pseudo->next = head;    // connecting the list to pseudo node
        ListNode *itr = pseudo; // iterator for iterating over the list
        // itr initially points to -1 coz if the first node is duplicate then we can delete it

        while (itr->next && itr->next->next)
        {
            if (itr->next->val == itr->next->next->val)
            {
                // deleting all the duplicates nodes
                int duplicate = itr->next->val;
                while (itr->next != NULL && itr->next->val == duplicate)
                {
                    itr->next = itr->next->next; // breaking the link
                }
            }
            else
            {
                itr = itr->next;
            }
        }
        return pseudo->next;
    }
};