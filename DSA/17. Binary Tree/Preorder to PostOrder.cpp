class Solution
{
public:
    Node *preTopost(int start, int end, int pre[])
    {
        if (start > end)
            return NULL;

        Node *root = newNode(pre[start]);

        int mid = start + 1;

        while (pre[mid] < pre[start] && mid <= end)
            mid++; // all the elements smaller than root will be on left side of root

        mid--; // mid will be the last element smaller than root

        root->left = preTopost(start + 1, mid, pre); // left subtree
        root->right = preTopost(mid + 1, end, pre);  // right subtree

        return root;
    }
    Node *post_order(int pre[], int size)
    {
        if (size == 0)
            return NULL;

        return preTopost(0, size - 1, pre);
    }
};