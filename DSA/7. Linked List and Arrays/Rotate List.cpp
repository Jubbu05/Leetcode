class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        
       for(int i=0; i<k; i++){
           ListNode* temp = head;
           while(temp->next->next != NULL) temp = temp->next;
           ListNode* end = temp->next;
           temp->next = NULL;
           end->next = head;
           head = end;
       }
        return head;
    }
};

//------------------------------------------------------------------------------------

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0) return head;

        ListNode* curr = head;
        int len = 1;
        while(curr->next != NULL){
            curr = curr->next;
            len++;
        }
        curr->next = head; //making circular ll
        k = k % len;
        k = len - k;

        while(k--) curr = curr->next;
        head = curr->next;
        curr->next = NULL;

        return head;
    }
};