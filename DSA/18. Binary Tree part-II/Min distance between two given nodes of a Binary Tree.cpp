class Solution
{
    Node *leastCommonAncestor(Node *root, int a, int b)
    {
        if (!root)
            return NULL;
        if (root->data == a or root->data == b)
            return root;
        Node *l = leastCommonAncestor(root->left, a, b);
        Node *r = leastCommonAncestor(root->right, a, b);

        if (l and r)
            return root;
        if (l)
            return l;
        return r;
    }
    int solve(Node *root, int a)
    {
        if (!root)
            return 0;
        if (root->data == a)
            return 1;
        int l = solve(root->left, a);
        int r = solve(root->right, a);
        if (!l and !r)
            return 0;
        if (!l)
            return r + 1;
        if (!r)
            return l + 1;
        int minVal = min(l, r);
        return minVal + 1;
    }

public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int findDist(Node *root, int a, int b)
    {
        // Your code here
        Node *lca = leastCommonAncestor(root, a, b);
        int x = solve(lca, a);
        int y = solve(lca, b);
        return (x + y - 2);
    }
};