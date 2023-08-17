/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> m;
        Node* temp = head;
        while(temp != NULL){
            Node* copy = new Node(temp->val);
            m[temp] = copy;
            temp = temp->next;
        }
        temp = head;
        while(temp != NULL){
            m[temp]->next = m[temp->next];
            m[temp]->random = m[temp->random];
            temp = temp->next;   
        }
        return m[head];
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        
        //creates mapping of cloned list using original list
        Node* temp=head;
        while(temp){
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode->next;
        }

        //assigning random pointers
        temp = head;
        while(temp){
            if(temp->random)
            {
               temp->next->random = temp->random->next;   
            }
            temp=temp->next->next;
        }

        //restore the original linked list
        temp = head;
        Node* newHead = head->next;
        Node* temp2 = head->next;
        while(temp && temp2){
            Node* og = temp2->next;
            temp->next = og;
            if(og){
                temp2->next = og->next;
            }
            temp = temp->next;
            temp2 = temp2->next;
        }
        return newHead;
    }
};