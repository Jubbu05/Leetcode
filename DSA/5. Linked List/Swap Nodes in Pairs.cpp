class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* curr = head->next->next;
        ListNode* prev = head;
        head = head->next; //new head will be the second node
        head->next = prev; //first node will be the second node

        //now we have to swap the remaining nodes
        while(curr != NULL && curr->next != NULL){
            prev->next = curr->next;
            prev = curr;
            ListNode* temp = curr->next->next;
            curr->next->next = curr;
            curr = temp;
        }
        prev->next = curr;
        return head;
    }
};