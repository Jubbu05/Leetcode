class Solution
{
public:
    vector<int> srt;
    void inorder(TreeNode *r)
    {
        if (r == NULL)
            return;
        inorder(r->left);
        srt.push_back(r->val);
        inorder(r->right);
    }
    bool findTarget(TreeNode *root, int k)
    {
        inorder(root);

        int low = 0, high = srt.size() - 1;
        while (low < high)
        {
            int sum = srt[low] + srt[high];
            if (sum == k)
                return true;
            else if (sum < k)
                low++;
            else
                high--;
        }
        return false;
    }
};

class Solution
{
public:
    unordered_set<int> s;

    bool helper(TreeNode *root, int k)
    {
        if (root == NULL)
            return false;
        if (s.find(k - root->val) != s.end())
            return true;
        s.insert(root->val);

        return helper(root->left, k) || helper(root->right, k);
    }
    bool findTarget(TreeNode *root, int k)
    {
        return helper(root, k);
    }
};