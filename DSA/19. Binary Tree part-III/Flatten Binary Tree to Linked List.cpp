class Solution {
  TreeNode * prev = NULL;
  public:
    void flatten(TreeNode * root) {
      if (root == NULL) return;

      flatten(root -> right);
      flatten(root -> left);

      root -> right = prev;
      root -> left = NULL;
      prev = root;
    }

};

class Solution
{
public:
    void flatten(TreeNode *root)
    {
        TreeNode *cur = root;
        while (cur != NULL)
        {
            //Moving to rightmost node of left subtree
            if (cur->left != NULL)
            {
                TreeNode *pre = cur->left;
                while (pre->right != NULL)
                {
                    pre = pre->right;
                }
                pre->right = cur->right; // connecting the righrmost node of left subtree to right subtree
                cur->right = cur->left;
                cur->left = NULL;
            }
            cur = cur->right;
        }
    }
};
