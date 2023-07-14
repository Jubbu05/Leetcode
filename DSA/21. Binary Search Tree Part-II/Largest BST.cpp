// largest element of left subtree should be less than root
// smallest element of right subtree should be greater than root
class Solution
{
public:
    vector<int> solve(Node *root)
    {
        // {BST, SIZE, MIN, Max}
        // BST -> 1/0 - CREATING BST OR NOT
        if (root == NULL)
            return {1, 0, INT_MAX, INT_MIN};

        if (!root->left and !root->right)
            return {1, 1, root->data, root->data}; // leaf node

        auto l = solve(root->left);
        auto r = solve(root->right);

        if (l[0] == 1 && r[0] == 1) // both left and right subtree are BST
        {
            // l[3] - max of left subtree
            // r[2] - min of right subtree
            if (root->data > l[3] && root->data < r[2])
            {
                int x = l[2]; // min of left subtree
                int y = r[3]; // max of right subtree

                x = min(x, root->data);
                y = max(y, root->data);

                return {1, l[1] + r[1] + 1, x, y};
            }
        }

        return {0, max(l[1], r[1]), 0, 0};
    }

    int largestBst(Node *root)
    {
        // Your code here
        vector<int> ans = solve(root);
        return ans[1]; // size
    }
};