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

//------------------------------------------

class Solution {
public:
    int lengthOfLinkedList(ListNode* head) {
    int length = 0;
    while(head != NULL) {
        head = head->next;
        length++;
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

    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        return reverseKGroup(head, 2);
    }
};
