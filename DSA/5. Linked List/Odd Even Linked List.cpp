// //APPROACH-1
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {        
        if(head == NULL) return head;
        
        ListNode* end = head;
        
        //moving end pointer to end and keeping the count on number of nodes
        int counter = 0;
        while(end->next != NULL){
            end = end->next;
            counter += 1;
        }
        
        counter = counter&1?(counter/2)+1:counter/2; //if counter even we need to do c/2 + 1 number of operations and if odd we need to do c/2 times
        ListNode* temp = head;
        while(counter--){
            //operations
            end->next = temp->next;
            temp->next = temp->next->next;
            end->next->next = NULL;
            //updating the values
            temp = temp->next;
            end = end->next;
        }
        return head;
    }
};


//APPROACH-2
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return head;
        
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* odd_head = head;
        ListNode* even_head = head->next;

        while(even != NULL && even->next != NULL){
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = even_head;
        return odd_head;
    }
};