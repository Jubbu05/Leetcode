class Solution
{
public:
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;
        map<int, int> mp;
        queue<pair<int, Node *>> q;
        q.push({0, root});
        while (!q.empty())
        {
            int line = q.front().first;
            Node *node = q.front().second;
            q.pop();

            // If we have already visited this line, then we don't need to push it again
            // we are checking if the line is already present in the map or not
            if (mp.find(line) == mp.end()) // not present if map
            { 
                mp[line] = node->data;
            }

            if (node->left != NULL)
            {
                q.push({line - 1, node->left});
            }
            if (node->right != NULL)
            {
                q.push({line + 1, node->right});
            }
        }
        for (auto it : mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};