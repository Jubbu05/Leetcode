class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int leftMax = maxDepth(root->left);
        int rightMax = maxDepth(root->right);
        return max(leftMax, rightMax) + 1;
    }
};