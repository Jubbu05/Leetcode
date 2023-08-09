class Solution
{
public:
    int maxLevelSum(TreeNode *root)
    {
        if (root == NULL) return 0;
        queue<TreeNode *> q;
        q.push(root);
        int maxLevel = 1;
        int maxSum = INT_MIN;
        int level = 1;

        while (!q.empty())
        {
            int levelSum = 0;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                levelSum += node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            if (levelSum > maxSum)
            {
                maxSum = levelSum;
                maxLevel = level;
            }
            level++;
        }
        return maxLevel;
    }
};