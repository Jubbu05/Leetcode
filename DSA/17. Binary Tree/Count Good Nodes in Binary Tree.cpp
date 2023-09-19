class Solution {
public:
    void countNode(TreeNode* root, int& count, int curr_max){
        if(root==NULL) return;
        if(root->val>=curr_max){
            count++;
            curr_max = root->val;
        }
        countNode(root->left, count, curr_max);
        countNode(root->right, count, curr_max);
    }
    
    int goodNodes(TreeNode* root) {
        int count = 0;
        if(!root) return count;
        int curr_max = root->val;
        countNode(root, count, curr_max);
        
        return count;
    }
};