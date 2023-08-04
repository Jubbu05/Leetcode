//O(n) && O(n)
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& ans){
        if(root==NULL) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};

//Morrise Traversal
//O(n) && O(1)

//if left is null then print the current node data. Move to right child.
//before moving to left child, make the rightmost node in left subtree point to current node and after curr = curr->left
//if the rightmost node in left subtree already points to current node then make it point to null again and move to right child curr = curr->right

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

    }
};