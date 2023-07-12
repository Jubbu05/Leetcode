// Brute Force Solution
// Time Complexity : O(m * n)
// Space Complexity : O(1)

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode *temp;
		while(headA != NULL){
			temp = headB;
			while(temp != NULL){
				if(headA == temp){
					return headA;
				}
				temp = temp -> next;
			}
			headA = headA -> next;
		}
		return NULL;
	}
};

//-----------------------------------------------------------------------------------------------

//HashMap Solution
//Time Complexity : O(m + n)
// Space Complexity : O(m)
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		unordered_map<ListNode*, int> m;
		while(headA != NULL){
			m[headA]++;
			headA = headA -> next;
		}
		while(headB != NULL){
			if(m[headB] > 0){ //already present in map
				return headB;
			}
			headB = headB -> next;
		}
		return NULL;
	}
};

//-----------------------------------------------------------------------------------------------

//Two-Pointers Solution
//Time Complexity : O(m + n)
// Space Complexity : O(1)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * temp1 = headA;
        ListNode * temp2 = headB;

        while(temp1!=temp2){
            if(temp1==NULL) temp1=headB;
            else temp1 = temp1->next;

            if(temp2==NULL) temp2=headA;
            else temp2 = temp2->next;
        }
        return temp1;
    }
};