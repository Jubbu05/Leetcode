//Function to count number of nodes in BST that lie in the given range.
class Solution{
public:
    int cnt;
    void inorder(Node *root, int l, int h){
        if(root == NULL) return;
        inorder(root->left, l, h);
        
        if(root->data>=l && root->data<=h) cnt++;
        
        inorder(root->right, l, h);
    }
    
    int getCount(Node *root, int l, int h)
    {
      cnt = 0;
      inorder(root,l,h);
      return cnt;
    }
};