class Solution
{
public:
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int solve(Node *node)
    {
        if (!node) return 0;
        int a = solve(node->left);
        int b = solve(node->right);
        int x = node->data;

        node->data = a + b;
        return a + b + x;
    }
    void toSumTree(Node *node)
    {
        solve(node);
    }
};