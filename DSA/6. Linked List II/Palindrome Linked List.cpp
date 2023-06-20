class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* nxt = NULL;
        ListNode* curr = head;

        while(curr != NULL){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        slow->next = reverse(slow->next);
        slow = slow->next;

        while(slow!=NULL){
            if(head->val != slow->val){
                return false;
            }
            else{
                head = head->next;
                slow = slow->next;
            }
        }
        return true;
    }
};