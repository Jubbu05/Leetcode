//                         curr = root
//                         curr->left->next = curr->right
// if(curr->next == NULL)  curr->right->next = NULL
// else                    curr->right->next = curr->next->left
//                         curr = curr->next
class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL){
            return NULL;
        }
        Node* current=root;
        while(current->left!=NULL){
            
            Node* temp=current;
            while(current!=NULL){
                
                current->left->next=current->right;
                current->right->next = (current->next==NULL) ? NULL : current->next->left;
                current=current->next;
                
            }
            current=temp->left;
        }
        return root;
        
    }
};

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return NULL;
        if(root->left!=NULL) root->left->next=root->right;
        if(root->right!=NULL && root->next!=NULL) root->right->next=root->next->left;

        connect(root->left);
        connect(root->right);
        return root;
    }
};