void inorder(TreeNode<int> *root, vector<int> &in)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}
TreeNode<int> *merge(int s, int e, vector<int> arr)
{
    if (s > e)
    {
        return NULL;
    }
    int mid = (s + e) / 2;
    TreeNode<int> *root = new TreeNode<int>(arr[mid]);
    root->left = merge(s, mid - 1, arr);
    root->right = merge(mid + 1, e, arr);

    return root;
}
TreeNode<int> *balancedBst(TreeNode<int> *root)
{
    vector<int> in;
    inorder(root, in);
    int s = 0;
    int e = in.size() - 1;
    return merge(s, e, in);
}
