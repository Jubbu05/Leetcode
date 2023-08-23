class Solution
{
public:
    int lvl = -1;
    bool b = true;
    void pre(Node *r, int l)
    {
        if (!r || !b)
            return;
        if (!r->left && !r->right)
        {
            if (lvl != -1 && lvl != l)
                b = false;
            else
                lvl = l;
        }
        pre(r->left, l + 1);
        pre(r->right, l + 1);
    }
    bool check(Node *root)
    {
        pre(root, 0);
        return b;
    }
};

//------------------------------------------------

class Solution
{
public:
    set<int> s;
    bool check(Node *root, int l = 0)
    {

        if (root == NULL)
            return true;
        if (!root->left && !root->right)
            s.insert(l);

        check(root->left, l + 1);
        check(root->right, l + 1);

        return s.size() == 1; // if size is 1 then all leaf nodes are at same level
    }
};

//---------------------------------------------------------
class Solution
{
public:
    /*You are required to complete this method*/
    bool isLeaf(Node *root)
    {
        return !root->left && !root->right;
    }
    void inorder(Node *root, vector<int> &ans, int level)
    {
        if (root == NULL)
            return;
        inorder(root->left, ans, level + 1);
        if (isLeaf(root))
        {
            ans.push_back(level);
        }
        inorder(root->right, ans, level + 1);
    }

    bool check(Node *root)
    {
        vector<int> ans;
        if (!root)
            return true;
        inorder(root, ans, 0);

        for (int i = 0; i < ans.size(); i++)
        {
            if (ans[i] != ans[0])
            {
                return false;
            }
        }
        return true;
    }
};
