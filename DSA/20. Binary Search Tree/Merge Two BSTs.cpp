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

vector<int> merge(vector<int> a, vector<int> b)
{
    vector<int> ans(a.size() + b.size());

    int i = 0, j = 0, k = 0;

    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
        {
            ans[k++] = a[i++];
        }
        else
        {
            ans[k++] = b[j++];
        }
    }

    while (i < a.size())
    {
        ans[k++] = a[i++];
    }

    while (j < b.size())
    {
        ans[k++] = b[j++];
    }

    return ans;
}

TreeNode<int> *inordertoBST(int s, int e, vector<int> arr)
{
    if (s > e)
    {
        return NULL;
    }
    // Find mid
    int m = (s + e) / 2;

    // Create a new node for mid
    TreeNode<int> *root = new TreeNode<int>(arr[m]);

    // Now call left and right recursion
    root->left = inordertoBST(s, m - 1, arr);
    root->right = inordertoBST(m + 1, e, arr);

    return root;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2)
{
    // Step 1 : Store the inorder
    vector<int> bst1, bst2;

    inorder(root1, bst1);

    inorder(root2, bst2);

    // Step 2 Merge 2 sorted Arrays

    vector<int> mergeArray = merge(bst1, bst2);

    int s = 0, e = mergeArray.size() - 1;

    // Used Merged inorder array to build BST

    return inordertoBST(s, e, mergeArray);
}