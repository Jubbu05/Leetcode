// intuition - for every node we will give a range [x < node < y]
class Solution {
public:
    bool isValidInRange(TreeNode* root, long minVal, long maxVal){
        if(root==NULL) return true;
        //out of boundry
        if(root->val >= maxVal || root->val <= minVal) return false;
        bool lh = isValidInRange(root->left, minVal, root->val); 
        bool rh = isValidInRange(root->right, root->val, maxVal);
        return lh && rh;
    }

    bool isValidBST(TreeNode* root) {
        return isValidInRange(root, LONG_MIN, LONG_MAX);
    }
};