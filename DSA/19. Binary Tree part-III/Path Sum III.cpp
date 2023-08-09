class Solution
{
public:
    int res = 0, sum;
    unordered_map<int, int> seen;
    void dfs(TreeNode *root, int partialSum = 0)
    {
        // updating partialSum with the current node
        partialSum += root->val;
        // checking if we already found an interval summing up to that
        res += seen[partialSum - sum];
        // updating seen
        seen[partialSum]++;
        // searching potential left and right branches
        if (root->left)
            dfs(root->left, partialSum);
        if (root->right)
            dfs(root->right, partialSum);
        // clearing seen of the last value, for backtracking purposes
        seen[partialSum]--;
    }
    int pathSum(TreeNode *root, int targetSum)
    {
        sum = targetSum;
        // seen set with initial value 0 will help us match from the root
        seen[0] = 1;
        if (!root)
            return res;
        dfs(root);
        return res;
    }
};

//------------------------------------------------------------------------------------------------

class Solution
{
    int pathSum_a(TreeNode *root, int sum)
    {
        if (root == NULL)
            return 0;
        int res = 0;
        if (root->val == sum)
            res++;
        res += pathSum_a(root->left, sum - root->val);
        res += pathSum_a(root->right, sum - root->val);
        return res;
    }

public:
    int pathSum(TreeNode *root, int sum)
    {
        if (root == nullptr)
            return 0;
        return pathSum(root->left, sum) + pathSum_a(root, sum) + pathSum(root->right, sum);
    }
};