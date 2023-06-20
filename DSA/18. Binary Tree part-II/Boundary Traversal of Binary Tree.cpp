#include <bits/stdc++.h>

// left boundary except leaf node
// leaf node
// right boundary except leaf node in reverse order

bool isLeaf(TreeNode<int> *root)
{
    return !root->left && !root->right;
}

void addLeftBoundary(TreeNode<int> *root, vector<int> &res)
{
    TreeNode<int> *cur = root->left;
    while (cur)
    {
        if (!isLeaf(cur))
            res.push_back(cur->data);
        if (cur->left != NULL)
            cur = cur->left;
        else
            cur = cur->right;
    }
}
void addRightBoundary(TreeNode<int> *root, vector<int> &res)
{
    TreeNode<int> *cur = root->right;
    vector<int> tmp;
    while (cur)
    {
        if (!isLeaf(cur))
            tmp.push_back(cur->data);
        if (cur->right != NULL)
            cur = cur->right;
        else
            cur = cur->left;
    }
    for (int i = tmp.size() - 1; i >= 0; --i)
    {
        res.push_back(tmp[i]);
    }
}

void addLeaves(TreeNode<int> *root, vector<int> &res)
{
    if (isLeaf(root))
    {
        res.push_back(root->data);
        return;
    }
    if (root->left != NULL)
        addLeaves(root->left, res);
    if (root->right != NULL)
        addLeaves(root->right, res);
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
    vector<int> res;
    if (!root)
        return res;

    if (!isLeaf(root))
        res.push_back(root->data);

    addLeftBoundary(root, res);

    // add leaf nodes
    addLeaves(root, res);

    addRightBoundary(root, res);
    return res;
}
