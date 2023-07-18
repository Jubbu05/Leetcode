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