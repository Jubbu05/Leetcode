//Recursion
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;

        if(l1->val<=l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        ListNode* head;
        ListNode* tail;

        if(l1->val<=l2->val){
            head = l1;
            tail=l1;
            l1=l1->next;
        }
        else{
            head = l2;
            tail=l2;
            l2=l2->next;
        }

        while(l1!=NULL && l2!=NULL){
            if(l1->val<=l2->val){
                tail->next = l1;
                tail = tail->next;
                l1 = l1->next;
            }
            else{
                tail->next = l2;
                tail = tail->next;
                l2 = l2->next;
            }
        }

        if(l1==NULL) tail->next = l2;
        if(l2==NULL) tail->next = l1;

        return head;
    }
};