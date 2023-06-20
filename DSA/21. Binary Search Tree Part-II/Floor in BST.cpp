void prede(Node *root, Node *&pre, int key)
{
    pre = NULL;

    while (root != NULL)
    {
        if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            pre = root;
            root = root->right;
        }
    }
}
int floor(Node *root, int x)
{
    Node *pre = NULL;
    prede(root, pre, x);
    if (pre == NULL)
    {
        return -1;
    }
    return pre->data;
}