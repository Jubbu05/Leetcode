class Solution {
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
    void reorderList(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* l2 = reverse(slow->next);
        slow->next = NULL;
        ListNode* l1 = head;
        while(l2 != NULL){
            ListNode* first = l1->next;
            ListNode* second = l2->next;
            l1->next = l2;
            l2->next = first;
            l1 = first;
            l2 = second;
        }
    }
};