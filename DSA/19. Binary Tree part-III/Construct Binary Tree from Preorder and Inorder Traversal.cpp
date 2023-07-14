class Solution
{
public:
    TreeNode *solver(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> &mp)
    {
        if (preStart > preEnd || inStart > inEnd)
            return NULL;

        TreeNode *root = new TreeNode(preorder[preStart]);
        int inRoot = mp[root->val]; // L ROOT R
        int numsLeft = inRoot - inStart; // Number of nodes in left

        root->left = solver(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, mp);
        root->right = solver(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, mp);
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }

        TreeNode *root = solver(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
        return root;
    }
};