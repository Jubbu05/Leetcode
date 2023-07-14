class Solution
{
public:
    int sum = 0;
    int inorder(TreeNode *root, int low, int high)
    {
        if (root == NULL) return 0;

        inorder(root->left, low, high);
        if (root->val >= low && root->val <= high) sum += root->val;
        inorder(root->right, low, high);

        return sum;
    }
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        if (!root) return 0;
        return inorder(root, low, high);
    }
};