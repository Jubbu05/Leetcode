class Solution
{
public:
    bool isSametree(TreeNode *s, TreeNode *t)
    {
        if (s == NULL && t == NULL)
        {
            return true;
        }
        if (s == NULL || t == NULL)
        {
            return false;
        }

        else if (s->val == t->val)
        {
            // if value is same then check if both its left and right sub-tree are same
            return isSametree(s->left, t->left) && isSametree(s->right, t->right);
        }
        else
        {
            return false;
        }
    }
    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        if (!s)
        {
            // if main tree is null then return false
            return false;
        }
        else if (isSametree(s, t))
        {
            // check if s and t are same, if yes return true
            return true;
        }
        else
        {
            // if s and t are not same then pass left and right nodes, and check same for that nodes as well as its child nodes.
            return isSubtree(s->left, t) || isSubtree(s->right, t);
        }
    }
};