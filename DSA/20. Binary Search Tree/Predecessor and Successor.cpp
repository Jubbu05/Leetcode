class Solution
{
public:
    void prede(Node *root, Node *&pre, int key)
    {
        pre = NULL;
        
        while (root != NULL)
        {
            if (key <= root->key)
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
    void succe(Node *root, Node *&suc, int key)
    {
        suc = NULL;
        
        while (root != NULL)
        {
            if (key >= root->key)
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
    void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
    {
        prede(root, pre, key);
        succe(root, suc, key);
    }
};