// class Solution
// {
// public:
//     void inorder(TreeNode *root, vector<int> &ans)
//     {
//         if (root == NULL)
//             return;
//         inorder(root->left, ans);
//         ans.push_back(root->val);
//         inorder(root->right, ans);
//     }
//     int kthSmallest(TreeNode *root, int k)
//     {
//         vector<int> ans;
//         inorder(root, ans);
//         for (auto it : ans)
//         {
//             k--;
//             if (k == 0)
//                 return it;
//         }
//         return 0;
//     }
// };

class Solution
{
public:
    int gk;
    int ans;
    void inorder(TreeNode *root)
    {
        if (root == NULL)
            return;
        inorder(root->left);
        gk--;
        if (gk == 0)
            ans = root->val;
        inorder(root->right);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        gk = k;
        inorder(root);
        return ans;
    }
};