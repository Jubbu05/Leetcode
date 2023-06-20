class Solution
{
public:
    void dfs(int node, vector<int> adj[], vector<int> &vis)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
                dfs(it, adj, vis);
        }
    }
    int numProvinces(vector<vector<int>> adj, int V)
    {
        // converting ajacency matrix to adjacency list
        vector<int> adjList[V];
        for (int i = 0; i < adj.size(); i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            {
                if (adj[i][j] == 1 && i != j)
                {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        int cnt = 0;
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, adjList, vis);
                cnt++;
            }
        }
        return cnt;
    }
};