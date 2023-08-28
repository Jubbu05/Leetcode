class Solution {
public:
    void postorder(TreeNode* root, vector<int>& ans){
        if(root==NULL) return;
        ans.push_back(root->val);
        postorder(root->left, ans);
        postorder(root->right, ans);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }
};

//Morris Traversal

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;

        while(curr){
            if(curr->left == NULL){
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* prev = curr->left;
                while(prev->right && prev->right != curr){
                    prev = prev->right;
                }
                if(prev -> right == NULL){
                    prev->right = curr;
                    ans.push_back(curr->val);
                    curr = curr->left;
                }
                else{
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};