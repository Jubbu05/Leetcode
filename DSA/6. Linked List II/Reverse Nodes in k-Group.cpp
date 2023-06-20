class Solution {
public:
    int lengthOfLinkedList(ListNode* head) {
    int length = 0;
    while(head != NULL) {
        length++;
        head = head->next;
    }
    return length;
    }

    ListNode* reverseK(ListNode* head,int k, int length) {
        if(length < k) return head;

        int count = 0;
        ListNode* prev = NULL;
        ListNode* nex = NULL;
        ListNode* curr = head;
        while(curr!=NULL && count<k){
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
            count++;
        }

        if(nex!=NULL){
            head->next = reverseK(nex,k,length-k);
        }

        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head,int k) {
        int length = lengthOfLinkedList(head);
        return reverseK(head,k,length);
    }
};