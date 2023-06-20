class Solution
{
public:
    vector<int> bottomView(Node *root)
    {
        vector<int> ans;
        map<int, int> mp;
        queue<pair<int, Node *>> q;
        q.push({0, root});
        while (!q.empty())
        {
            int line = q.front().first;
            Node *node = q.front().second;
            q.pop();
            mp[line] = node->data;
            if (node->left != NULL)
            {
                q.push({line - 1, node->left});
            }
            if (node->right != NULL)
            {
                q.push({line + 1, node->right});
            }
        }
        for (auto i : mp)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};