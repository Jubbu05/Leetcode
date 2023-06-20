// int findCeil(Node *root, int input)
// {
//     if (root == NULL)
//         return -1;
//     if (root->data == input)
//         return root->data;
//     if (root->data < input)
//         return findCeil(root->right, input);
//     int ceil = findCeil(root->left, input);
//     return (ceil >= input) ? ceil : root->data;
// }

void succe(Node *root, Node *&suc, int key)
{
    suc = NULL;

    while (root != NULL)
    {
        if (key > root->data)
        {
            root = root->right;
        }
        else
        {
            suc = root;
            root = root->left;
        }
    }
}
int findCeil(Node *root, int x)
{
    if (root == NULL)
        return -1;
    Node *suc = NULL;
    succe(root, suc, x);
    if (suc == NULL)
    {
        return -1;
    }
    return suc->data;
}