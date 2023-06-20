class Solution
{
public:
    int gk;
    int ans;
    void inorder(Node *root)
    {
        if (root == NULL)
            return;
        inorder(root->right);
        gk--;
        if (gk == 0)
            ans = root->val;
        inorder(root->left);
    }
    int kthLargest(Node *root, int k)
    {
        gk = k;
        inorder(root);
        return ans;
    }
};