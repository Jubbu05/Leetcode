class Solution
{
    // Define a struct to store information about a subtree
    struct S
    {
        bool isBST;     // Indicates if the subtree is a valid BST
        int minVal;     // Minimum value in the subtree
        int maxVal;     // Maximum value in the subtree
        int sum;        // Sum of values in the subtree
    };

    // Helper function to recursively traverse the tree and calculate the maximum sum BST
    S helper(TreeNode *node, int &res)
    {
        // Base case: if node is null, return default values for an empty subtree
        if (!node)
        {
            return {true, INT_MAX, INT_MIN, 0};
        }
        
        // Recursively call helper function for the left and right subtrees
        S l = helper(node->left, res);
        S r = helper(node->right, res);
        
        // Check if the current subtree is a valid BST and update the result if necessary
        if (l.isBST && r.isBST && l.maxVal < node->val && r.minVal > node->val)
        {
            int sum = l.sum + r.sum + node->val;
            res = max(res, sum);
            return {true, min(l.minVal, node->val), max(r.maxVal, node->val), sum};
        }
        else
        {
            // If the current subtree is not a valid BST, return default values
            return {false, 0, 0, 0};
        }
    }

public:
    int maxSumBST(TreeNode *root)
    {
        int res = 0;
        // Call the helper function to calculate the maximum sum BST
        helper(root, res);
        return res;
    }
};
