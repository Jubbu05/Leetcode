class Solution
{
public:
    void dfs(int node, vector<int> &ans, vector<int> &visited, vector<int> adj[])
    {
        ans.push_back(node);
        visited[node] = 1;
        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                dfs(it, ans, visited, adj);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> visited(V, 0);
        vector<int> ans;
        dfs(0, ans, visited, adj);
        return ans;
    }
};