// class Solution
// {
// public:
//     TreeNode *solver(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> &mp)
//     {
//         if (preStart > preEnd || inStart > inEnd)
//             return NULL;

//         TreeNode *root = new TreeNode(preorder[preStart]);
//         int inRoot = mp[root->val];
//         int numsLeft = inRoot - inStart;

//         root->left = solver(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, mp);
//         root->right = solver(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, mp);
//         return root;
//     }

//     TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
//     {
//         map<int, int> mp;
//         for (int i = 0; i < inorder.size(); i++)
//         {
//             mp[inorder[i]] = i;
//         }

//         TreeNode *root = solver(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
//         return root;
//     }

//     TreeNode *bstFromPreorder(vector<int> &preorder)
//     {
//         vector<int> inorder;
//         for (int i = 0; i < preorder.size(); i++)
//         {
//             inorder.push_back(i);
//         }
//         sort(inorder.begin(), inorder.end()); // now it becomes inorder
//         return buildTree(preorder, inorder);
//     }
// };

class Solution
{
public:
    TreeNode *bstFromPreorder(vector<int> &A)
    {
        int i = 0;
        return build(A, i, INT_MAX);
    }

    TreeNode *build(vector<int> &A, int &i, int bound)
    {
        if (i == A.size() || A[i] > bound)
            return NULL;
        TreeNode *root = new TreeNode(A[i++]);
        root->left = build(A, i, root->val);
        root->right = build(A, i, bound);
        return root;
    }
};